#pragma once

#include <raylib.h>
#include <cmath>
#include <iostream>

// class Vector2{
// public:
// 	double x;
// 	double y;

// 	Vector2(double x1, double y1);
// 	Vector2();
// };

double getDistance(Vector2 a, Vector2 b);
double getAngle(Vector2 a, Vector2 b);
std::string getKey();