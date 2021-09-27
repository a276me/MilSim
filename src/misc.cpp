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