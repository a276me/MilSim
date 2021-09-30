#include "misc.hpp"
#include <raylib.h>

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