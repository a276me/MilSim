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
	std::cout<<BSP<<"is battle speed\n";
	return BSP;
}

Regiment::Regiment(int t, int b){
	if(t == INF){
		BBV = 2;
		BDV = 2;
		BS = 10;
		BSP = 2;
		BBD = 3;

	}else if(t == ARMOR){
		BBV = 5;
		BDV = 2;
		BS = 35;
		BSP = 10;
		BBD = 5;

	}else if(t == ARTILLARY){
		BBV = 1;
		BDV = 1;
		BS = 25;
		BSP = 10;
		BBD = 5;

	}else if(t == MECH_INF){
		BBV = 4;
		BDV = 2;
		BS = 20;
		BSP = 10;
		BBD = 3;

	}else if(t == SF){
		BBV = 1;
		BDV = 1;
		BS = 17;
		BSP = 7;
		BBD = 5;

	}

	battalions = 0;
	for(int i=0; i<b; i++){
		addBattalion();
		
	}
}
