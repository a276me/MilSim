#include "Division.hpp"
#include "Battalion.hpp"

std::string Division::getName(){
	return name;
}	

int Division::getType(){
	return type;
}	

double	Division::getBD(){
	int S = 0;
	for(int i=0; i<regiments.size(); i++){
		S += regiments[i].getBD();
	}
	return S;
}	

double 	Division::getSpeed(){
	int S = 0;
	for(int i=0; i<regiments.size(); i++){
		if(S >regiments[i].getSpeed()){
			S = regiments[i].getSpeed();
		}
	}
	return S;
}		

int 		Division::getStrength(){
	return Strength;
}	

int Division::getMaxStrength(){
	int S = 0;
	for(int i=0; i<regiments.size(); i++){
		S += regiments[i].getStrength();
	}
	return S;
}	
	
int 		Division::getNumReg(){
	return regiments.size();
}	
		
std::vector<Regiment> Division::getRegs(){
	return regiments;
}	
			
double 		Division::getOrg(){
	return Organization;
}	
	

double 		Division::getBV(){
	int S = 0;
	for(int i=0; i<regiments.size(); i++){
		S += regiments[i].getBV();
	}
	return S;
}	

			
double 		Division::getDV(){
	int S = 0;
	for(int i=0; i<regiments.size(); i++){
		S += regiments[i].getDV();
	}
	return S;
}	
		

double		Division::getX(){
	return position.x;
}	
				
double		Division::getY(){
	return position.y;
}	
			
Vector2		Division::getPos(){
	return position;
}	
	
Vector2		Division::getTarget(){
	return target;
}	
			
					
void 		Division::setPos(Vector2 p){
	position = p;
}	
		
	
void 		Division::setOrg(double o){
	Organization = o;
}	
	
void		Division::moveTo(Vector2 p){
	target = p;
}	
	
void		Division::setRegiments(std::vector<Regiment> r){
	regiments = r;
}

void		Division::addRegiment(int t, int b){
	Regiment r = Regiment(t,b);
	if(getMaxStrength()+r.getStrength() <= 300){
		regiments.push_back(r);
		Strength = getMaxStrength();
	}

}	

void Division::setStrength(int s){
	Strength = s;
}


Division::Division(int t, Vector2 pos, std::string n, int te){
	type = t;
	position = pos;
	name = n;
	team = te;
	Strength = 0;
	Organization = 100;
}
