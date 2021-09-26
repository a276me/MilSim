#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include <random>
#include <ctime>

#include "Division.hpp"
#include "Regiment.hpp"
#include "misc.hpp"

int TIME = 0;
std::vector<Division> divisions = {};


void fight(Division *a, Division *b){		// a is attacking, b is defending

	a->engaged = true;
	b->engaged = true;

	if(a->getStrength()<=0 || b->getStrength() <=0){
		return;
	}

	srand(time(0));

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
				if(getDistance(divisions[i].getPos(), divisions[j].getPos()) < divisions[i].getBD()+divisions[j].getBD()){
					std::cout<<"engagment detected between "<<divisions[i].getName()<<" and "<<divisions[j].getName()<<"\n";
					fight(&divisions[i], &divisions[j]);
					e = 1;
				}
			}
		if(!e){
			division[i].engaged = false;
		}
		}
}

int main(){


	// divisions.push_back(Division(ARMORED_DIV, Vector2(0.0,0.0), std::string("1st Armored Division"), 0));
	// divisions[0].addRegiment(ARMOR, 3);

	// std::cout<<"The 1st Armored Division has been deployed!\n";
	// std::cout<<"has "<<divisions[0].getNumReg()<<" regiments with a total of "<<divisions[0].getMaxStrength()<<" Strength\n";
	// std::cout<<"has a BD of "<<divisions[0].getBD()<<"\n";

	Division div1 = Division(ARMORED_DIV, Vector2(0,0), std::string("1st Armored Division"), 0);
	div1.addRegiment(ARMOR,2);
	div1.addRegiment(INF, 7);
	std::cout<<div1.getBD()<<"\n";

	Division div2 = Division(ARMORED_DIV, Vector2(10,0), std::string("102nd Mechanized Infantry Division"), 1);
	div2.addRegiment(MECH_INF,3);
	div2.addRegiment(ARMOR, 1);
	std::cout<<div2.getBD()<<"\n";
	std::cout<<div1.getBV()<< "; "<<div1.getDV()<<"\n";
	std::cout<<div2.getBV()<< "; "<<div2.getDV()<<"\n";

	divisions.push_back(div1);
	divisions.push_back(div2);


	while(true){
		TIME++;
		
		if(TIME%10000000000000000== 0){
			//look for engagements
			findEngagements();
			for(int i=0;i<divisions.size(); i++){
				std::cout<<divisions[i].getName()<<"; "<<divisions[i].getStrength()<<"; "<<divisions[i].getOrg()<<";\n";
			}
			
		


		}
	}


	return 0;
}
