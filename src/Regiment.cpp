#include "Regiment.hpp"

void 	Regiment::addBattalion(){
	battalions++;
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
	battalions = b;
	if(t == INF){
		BBV = 20;
		BDV = 20;
		BS = 20;
		BBD = 30;

	}
}
