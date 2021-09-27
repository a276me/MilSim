#include <raylib.h>
#include <iostream>
#include <vector>
#include <random>
#include <ctime>

#include "Division.hpp"
#include "Regiment.hpp"
#include "misc.hpp"
#include "graphics.hpp"

int TIME = 0;
static std::vector<Division> divisions;

void toggleEngaged(){
	for(int i = 0; i<divisions.size();i++){
		bool e = false;
		for(int j = 0; j<divisions.size();j++){
			if(i == j){continue;}
			if(getDistance(divisions[i].getPos(), divisions[j].getPos()) < divisions[i].getBD()+divisions[j].getBD() && divisions[i].team != divisions[j].team){
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
				if(getDistance(divisions[i].getPos(), divisions[j].getPos()) < divisions[i].getBD()+divisions[j].getBD() && divisions[i].team != divisions[j].team){
					std::cout<<"engagment detected between "<<divisions[i].getName()<<" and "<<divisions[j].getName()<<"\n";
					fight(&divisions[i], &divisions[j]);
				}
			}

		}
}

int main(){

	initRL();

	Division div1 = Division(ARMORED_DIV, {0,0}, std::string("Div A"), 0);
	div1.addRegiment(ARMOR,2);
	div1.addRegiment(INF, 7);

	Division div2 = Division(ARMORED_DIV, {0,10}, std::string("Div B"), 1);
	div2.addRegiment(MECH_INF,3);
	div2.addRegiment(ARMOR, 1);

	Division div3 = Division(ARMORED_DIV, {-10,0}, std::string("Div C"), 1);
	div3.addRegiment(MECH_INF,3);
	div3.addRegiment(ARMOR, 2);


	divisions.push_back(div1);
	divisions.push_back(div2);
	divisions.push_back(div3);

	srand(time(0));

	while (!WindowShouldClose()) {
		TIME++;
		//look for engagements
		findEngagements();
		toggleEngaged();
		for(int i=0;i<divisions.size(); i++){
			std::cout<<divisions[i].getName()<<"; "<<divisions[i].getStrength()<<"; "<<divisions[i].getOrg()<<"; "<<divisions[i].engaged<<";\n";
		}
		std::cout << divisions.size()<<"\n";
		removeAndHeal();

		drawScreen();

		
	}

	
	endRL();

	return 0;
}
