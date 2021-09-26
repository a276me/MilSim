#include "Division.hpp"

std::string Division::getName(){
	return name;
}	

int 		Division::getType(){
	return type;
}	

double		Division::getBD(){
	return BD;
}	

double 		Division::getSpeed(){
	return Speed;
}		

int 		Division::getStrength(){
	return Strength;
}	

int 		Division::getMaxStrength(){
	return MaxStrength;
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
	return BV;
}	
			
double 		Division::getDV(){
	return DV;
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
		
bool		Division::isEngaged(){
	return engaged;
}	
					
void 		Division::setPos(Vector2 p){
	position = p;
}	
	
void 		Division::setStrength(int s){
	Strength = s;
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


Division::Division(int t, Vector2 pos, std::string n){
	type = t;
	position = pos;
	name = n;
}
