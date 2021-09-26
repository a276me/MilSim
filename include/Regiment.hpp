#pragma once

#include <iostream>
#include <vector>


#define	MECH_INF 	0
#define ARMOR	 	1
#define ARTILLARY	2
#define SF			3
#define INF 		4


class Regiment{

public:
	int type;
	int battalions;

	double BBV;
	double BDV;
	double BS;
	double BBD;
	double BSP;

	void addBattalion();
	int getStrength();
	double getBV();
	double getDV();
	double getBD();
	double getSpeed();

	Regiment(int t, int b);

};