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
			double dx = t.x-p.x;
			double dy = t.y-p.y;
			double s = divisions[i].getSpeed();
			if(dx >= 0){
					theta = asin(dy/d);
			} else{
				if(dy >=0){
					theta = acos(dx/d);
				}else{
					theta = acos(dy/d)+(PI-acos(dy/d));
				}
			}
			std::cout<<"Moving\n";
			std::cout<<theta<<"\n";
			std::cout<<(cos(theta))<<"\n";
			std::cout<<s<<" is battle speed\n";
			divisions[i].position = (Vector2){(float)(p.x+s*cos(theta)/60), (float)(p.y+s*sin(theta)/60)};

			if(getDistance(divisions[i].position, divisions[i].getTarget()) < s/30){
				divisions[i].moving = false;
				divisions[i].setTarget((Vector2){{0}, {0}});
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
	}else{
		// b won
		a->setStrength(a->getStrength()-b->getDV()*((n-a->getBV())/b->getBV()));
		b->setStrength(b->getStrength()-a->getBV()*((n-a->getBV())/b->getBV()));
		a->setOrg(a->getOrg()-10);
	}

}

void findEngagements(){
	for(int i = divisions.size()-1; i>=0; i--){
		int e = 0;
			for(int j = 0; j<i; j++){
				if(getDistance(divisions[i].getPos(), divisions[j].getPos()) < divisions[i].getBD()/2+divisions[j].getBD()/2 && divisions[i].team != divisions[j].team){
					std::cout<<"engagment detected between "<<divisions[i].getName()<<" and "<<divisions[j].getName()<<"\n";
					fight(&divisions[i], &divisions[j]);
				}
			}

		}
}

int main(){

	initRL();

	Division div1 = Division(MECH_INFANTRY_DIV, (Vector2){0,0}, std::string("1st Infantry Division"), 0);
	div1.addRegiment(ARMOR,2);
	div1.addRegiment(INF, 7);

	Division div2 = Division(ARMORED_DIV, (Vector2){0,100}, std::string("Div B"), 0);
	div2.addRegiment(MECH_INF,3);
	div2.addRegiment(ARMOR, 1);
	div2.setTarget((Vector2){-20,0});

	Division div3 = Division(ARMORED_DIV, (Vector2){-100,0}, std::string("Div C"), 1);
	div3.addRegiment(MECH_INF,3);
	div3.addRegiment(ARMOR, 2);
	div3.setTarget((Vector2){0,0});


	divisions.push_back(div1);
	divisions.push_back(div2);
	divisions.push_back(div3);

	srand(time(0));

	while (!WindowShouldClose()) {
		TIME++;
		//look for engagements
		toggleEngaged();
		if(TIME%30 == 0){
			
			findEngagements();
			for(int i=0;i<divisions.size(); i++){
				std::cout<<divisions[i].getName()<<"; "<<divisions[i].getStrength()<<"; "<<divisions[i].getOrg()<<"; "<<divisions[i].engaged<<"; "<<divisions[i].position.x<<"; "<<divisions[i].position.y<<";\n";
			}
			std::cout << divisions.size()<<"\n";
			removeAndHeal();
			
		}
		
		moveDivs();

		drawScreen();

		
	}

	
	endRL();

	return 0;
}
