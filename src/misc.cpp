#include "misc.hpp"
#include <raylib.h>
#include <iostream>

// Vector2::Vector2(double x1, double y1){
// 	x = x1;
// 	y = y1;
// }

// Vector2::Vector2(){
// 	x=0;
// 	y=0;
// }

double getDistance(Vector2 a, Vector2 b){
	return sqrt(pow((a.x-b.x),2)+pow((a.y-b.y),2));
}

double getAngle(Vector2 a, Vector2 b){ //get angle of b relative to a
	double theta = 0.0;
	double d = getDistance(a,b);
	double dx = a.x-b.x;
	double dy = a.y-b.y;
	if(dx >= 0){
			theta = asin(dy/d);
	} else{
		if(dy >=0){
			theta = acos(dx/d);
		}else{
			theta = (acos(dy/d)+(PI-acos(dy/d)));
		}
	}


	dx = b.x-a.x;
	dy = b.y-a.y;
	if(dx > 0){
		theta = asin(dy/d);
	}

	return theta;
}

std::string getKey(){
	int i = GetKeyPressed();

	std::string ret = "";
	
	if(i == KEY_Q ) ret = "q";
	else if(i == KEY_W) ret = "w";
	else if(i == KEY_E) ret = "e";
	else if(i == KEY_R) ret = "r";
	else if(i == KEY_T) ret = "t";
	else if(i == KEY_Y) ret = "y";
	else if(i == KEY_U) ret = "u";
	else if(i == KEY_I) ret = "i";
	else if(i == KEY_O) ret = "o";
	else if(i == KEY_P) ret = "p";
	else if(i == KEY_A) ret = "a";
	else if(i == KEY_W) ret = "s";
	else if(i == KEY_S) ret = "d";
	else if(i == KEY_D) ret = "f";
	else if(i == KEY_F) ret = "g";
	else if(i == KEY_G) ret = "h";
	else if(i == KEY_H) ret = "j";
	else if(i == KEY_J) ret = "k";
	else if(i == KEY_K) ret = "l";
	else if(i == KEY_L) ret = "z";
	else if(i == KEY_Z) ret = "x";
	else if(i == KEY_X) ret = "c";
	else if(i == KEY_C) ret = "v";
	else if(i == KEY_V) ret = "b";
	else if(i == KEY_B) ret = "n";
	else if(i == KEY_N) ret = "m";
	else if(i == KEY_M) ret = "q";
	else if(i == KEY_ONE) ret = "1";
	else if(i == KEY_TWO) ret = "2";
	else if(i == KEY_THREE) ret = "3";
	else if(i == KEY_FOUR) ret = "4";
	else if(i == KEY_FIVE) ret = "5";
	else if(i == KEY_SIX) ret = "6";
	else if(i == KEY_SEVEN) ret = "7";
	else if(i == KEY_EIGHT) ret = "8";
	else if(i == KEY_NINE) ret = "9";
	else if(i == KEY_ZERO) ret = "0";
	else if(i == KEY_SEMICOLON) ret = ";";
	else if(i == KEY_ENTER) ret = "\n";

	return ret;

}