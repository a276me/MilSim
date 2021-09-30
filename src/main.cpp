#include <raylib.h>
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <cmath>

#include "main.hpp"
#include "Division.hpp"
#include "Regiment.hpp"
#include "misc.hpp"
#include "graphics.hpp"


void moveDivs(){

	for(int i = 0; i<divisions.size();i++){
		if(!divisions[i].engaged && divisions[i].moving){
			Vector2 p = divisions[i].position;
			Vector2 t = divisions[i].getTarget();
			double theta = 0.0;
			double d = getDistance(p,t);
			double dx = p.x-t.x;
			double dy = p.y-t.y;
			double s = divisions[i].getSpeed();
			if(dx >= 0){
					theta = asin(dy/d);
			} else{
				if(dy >=0){
					theta = acos(dx/d);
				}else{
					theta = (acos(dy/d)+(PI-acos(dy/d)));
				}
			}

			float cx = (float)(p.x-s*cos(theta)/30);
			float cy = (float)(p.y-s*sin(theta)/30);


			dx = t.x-p.x;
			dy = t.y-p.y;
			if(dx > 0){
				theta = asin(dy/d);
				cx = (float)(p.x+s*cos(theta)/30);
				cy = (float)(p.y+s*sin(theta)/30);
			}

			std::cout<<"Moving\n";
			std::cout<<(theta*180/PI)<<"\n";
			std::cout<<(sin(theta))<<"\n";
			std::cout<<(cos(theta))<<"\n";
			std::cout<<s<<" is battle speed\n";
			divisions[i].position = (Vector2){cx, cy};

			if(getDistance(divisions[i].position, divisions[i].getTarget()) < s/30){
				
				divisions[i].setTarget((Vector2){{0}, {0}});
				divisions[i].moving = false;
			}
		}
	}

}

void toggleEngaged(){
	for(int i = 0; i<divisions.size();i++){
		bool e = false;
		for(int j = 0; j<divisions.size();j++){
			if(i == j){continue;}
			if(getDistance(divisions[i].getPos(), divisions[j].getPos()) < divisions[i].getBD()/2+divisions[j].getBD()/2 && divisions[i].team != divisions[j].team){
				e = true;
			}
		}
		divisions[i].engaged = e;
	}
}


void removeAndHeal(){
	for(int i = 0; i<divisions.size(); i++){
		if(divisions[i].getStrength() <=0){
			std::cout<<"removing\n";
			divisions.erase(divisions.begin() + i);
			std::cout<<divisions[i].getName()<<" destroyed\n";
			continue;
		}
		if(!divisions[i].engaged){
			divisions[i].setStrength(divisions[i].getStrength()+5);
			divisions[i].setOrg(divisions[i].getOrg()+5);
		}
	}
}

void fallBack(Division *a, Division *b){	// a is falling back, b is advancing
	Vector2 p = a->position;
	Vector2 t = b->position;
	double theta = 0.0;
	double d = getDistance(p,t);
	double dx = p.x-t.x;
	double dy = p.y-t.y;
	double s = a->getSpeed();
	if(dx >= 0){
			theta = asin(dy/d);
	} else{
		if(dy >=0){
			theta = acos(dx/d);
		}else{
			theta = (acos(dy/d)+(PI-acos(dy/d)));
		}
	}

	float cx = (float)(p.x+s*cos(theta)/5);
	float cy = (float)(p.y+s*sin(theta)/5);


	dx = t.x-p.x;
	dy = t.y-p.y;
	if(dx > 0){
		theta = asin(dy/d);
		cx = (float)(p.x-s*cos(theta)/5);
		cy = (float)(p.y-s*sin(theta)/5);
	}
	a->position = (Vector2){cx, cy};


}


void fight(Division *a, Division *b){		// a is attacking, b is defending


	if(a->getStrength()<=0 || b->getStrength() <=0){
		return;
	}

	

	int n = rand()%(int)(a->getBV()+b->getDV());

	if(n < a->getBV()){
		// a won
		a->setStrength(a->getStrength()-b->getDV()*(n/a->getBV()));
		b->setStrength(b->getStrength()-a->getBV()*(n/a->getBV()));
		b->setOrg(b->getOrg()-10);
		fallBack(b, a);
	}else{
		// b won
		a->setStrength(a->getStrength()-b->getDV()*((n-a->getBV())/b->getBV()));
		b->setStrength(b->getStrength()-a->getBV()*((n-a->getBV())/b->getBV()));
		a->setOrg(a->getOrg()-10);
		// fallBack(a, b);
	}

}

void findEngagements(){
	for(int i = divisions.size()-1; i>=0; i--){
		int e = 0;
			for(int j = 0; j<i; j++){
				if(getDistance(divisions[i].getPos(), divisions[j].getPos()) < divisions[i].getBD()/2+divisions[j].getBD()/2 && divisions[i].team != divisions[j].team){
					std::cout<<"engagment detected between "<<divisions[i].getName()<<" and "<<divisions[j].getName()<<"\n";
					if(divisions[i].moving && !divisions[j].moving) fight(&divisions[i], &divisions[j]);
					else fight(&divisions[i], &divisions[j]);

				}
			}

		}
}

int main(){

	initRL();

	Division div1 = Division(MECH_INFANTRY_DIV, (Vector2){0,-20}, std::string("1st Infantry Division"), 1);
	div1.addRegiment(ARMOR,2);
	div1.addRegiment(INF, 7);
	// div1.setTarget((Vector2) {0,0});

	Division div2 = Division(ARMORED_DIV, (Vector2){0,20}, std::string("107th Armored Division"), 1);
	div2.addRegiment(MECH_INF,3);
	div2.addRegiment(ARMOR, 2);
	div2.addRegiment(ARMOR, 2);
	// div2.setTarget((Vector2){0,0});

	Division div3 = Division(ARMORED_DIV, (Vector2){100,0}, std::string("Div C"), 0);
	div3.addRegiment(INF,7);
	div3.addRegiment(INF,7);
	div3.addRegiment(ARMOR, 2);
	div3.setTarget((Vector2){-200,0});

	Division div4 = Division(INFANTRY_DIV, (Vector2){-100,100}, std::string("Div C"), 1);
	div4.addRegiment(INF,7);
	div4.addRegiment(ARMOR, 2);
	div4.setTarget((Vector2){0,200});


	divisions.push_back(div1);
	divisions.push_back(div2);
	divisions.push_back(div3);
	divisions.push_back(div4);

	srand(time(0));
	

	while (!WindowShouldClose()) {
		if(IsKeyDown(KEY_TAB)) SetTargetFPS(60*SPEED);
		else	SetTargetFPS(60);

		if(IsKeyDown(KEY_SPACE)){
			TIME++;
			//look for engagements
			toggleEngaged();
			if(TIME%(30) == 0){
				
				findEngagements();
				for(int i=0;i<divisions.size(); i++){
					std::cout<<divisions[i].getName()<<"; "<<divisions[i].getStrength()<<"; "<<divisions[i].getOrg()<<"; "<<divisions[i].engaged<<"; "<<divisions[i].position.x<<"; "<<divisions[i].position.y<<";\n";
				}
				std::cout << divisions.size()<<"\n";
				removeAndHeal();
				
			}
			
			
			moveDivs();
		}

		drawScreen();

		
	}

	
	endRL();

	return 0;
}
