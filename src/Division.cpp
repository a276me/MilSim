#include "Division.hpp"

std::string getName();			//returns name of division eg. 1st armored division
int getType();					//returns type of division eg. Armored, Mechanized Infantry, Infantry
double		getBD();			//returns the battle diameter of the division
double 		getSpeed();			//returns the max speed of the division
int 		getStrength();		//returns the strength value of the division
int 		getMaxStrength();	//returns the Max strength value of the division
int 		getNumReg();		//returns the number of regiments
std::vector getRegs();			//returns the array of regiments
double 		getOrg();			//returns the organization value of the division
double 		getBV();			//returns the breakthrough value of the division
double 		getDv();			//returns the defensive value of the division
double		getX();				//returns X coordinates on map
double		getY(); 			//returns Y coordinates on map
Vector2		getPos();			//returns vector position
Vector2		getTarget();		//returns the target of the division for movement
bool		isEngaged();		//return whether the division is engaged in battle
void		move();				//moves the division forwards a frame
void 		setPos(Vector2 p);	//sets the position of the division
void 		setStrength(int s);	//sets strength of the division;
void 		setOrg(double o);	//sets organization fo division
void		moveTo(Vector2 p);	//sets movement target to p
void		setRegiments(std::vector)	//sets regiments