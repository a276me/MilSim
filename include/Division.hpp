#pragma once

#define ARMORED_DIV 1
#define INFANTRY_DIV 2
#define MECH_INFANTRY_DIV 3



#include <iostream>
#include <vector>
#include <misc.hpp>
#include <raylib.h>
#include <Regiment.hpp>

class Division{
public:
	std::string getName();			//returns name of division eg. 1st armored division
	int getType();					//returns type of division eg. Armored, Mechanized Infantry, Infantry
	double		getBD();			//returns the battle diameter of the division
	double 		getSpeed();			//returns the max speed of the division
	int 		getStrength();		//returns the strength value of the division
	int 		getMaxStrength();	//returns the Max strength value of the division
	int 		getNumReg();		//returns the number of regiments
	std::vector<Regiment> getRegs();			//returns the array of regiments
	double 		getOrg();			//returns the organization value of the division
	double 		getBV();			//returns the breakthrough value of the division
	double 		getDV();			//returns the defensive value of the division
	double		getX();				//returns X coordinates on map
	double		getY(); 			//returns Y coordinates on map
	Vector2		getPos();			//returns vector position
	Vector2		getTarget();		//returns the target of the division for movement
	void 		setPos(Vector2 p);	//sets the position of the division
	void 		setOrg(double o);	//sets organization fo division
	void		moveTo(Vector2 p);	//sets movement target to p
	void		setRegiments(std::vector<Regiment> r);	//sets regiments
	void		addRegiment(int t, int b);
	void		setStrength(int s);

				Division(int t, Vector2 pos, std::string n, int te);

	int team;						//the team number; 0 is blue, 1 is red
	bool		engaged;
	


private:
	Vector2		position;
	Vector2		target;
	std::vector<Regiment> regiments;
	double		Speed;
	int			Strength;
	double		Organization;
	double		BV;
	double		DV;
	std::string name;
	int 		type;
	


};