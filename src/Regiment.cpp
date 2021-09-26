#include <iostream>
#include "Regiment.hpp"

void 	Regiment::addBattalion(){
	if(BS * (battalions+1) <=70){
		battalions++;
		std::cout<<"bat added\n";
	}
}
int 	Regiment::getStrength(){
	return BS * battalions;
}
double 	Regiment::getBV(){
	return BBV * battalions;
}
double 	Regiment::getDV(){
	return BDV * battalions;
}
double 	Regiment::getBD(){
	return BBD * battalions;
}
double 	Regiment::getSpeed(){
	return BSP * battalions;
}

Regiment::Regiment(int t, int b){
	if(t == INF){
		BBV = 20;
		BDV = 20;
		BS = 10;
		BSP = 5;
		BBD = 3;

	}else if(t == ARMOR){
		BBV = 50;
		BDV = 20;
		BS = 35;
		BSP = 20;
		BBD = 5;

	}else if(t == ARTILLARY){
		BBV = 10;
		BDV = 10;
		BS = 25;
		BSP = 20;
		BBD = 5;

	}else if(t == MECH_INF){
		BBV = 40;
		BDV = 20;
		BS = 20;
		BSP = 20;
		BBD = 3;

	}else if(t == SF){
		BBV = 10;
		BDV = 10;
		BS = 35;
		BSP = 7;
		BBD = 5;

	}

	battalions = 0;
	for(int i=0; i<b; i++){
		addBattalion();
		
	}
}
