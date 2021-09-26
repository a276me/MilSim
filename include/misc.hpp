#pragma once

#include <cmath>

class Vector2{
public:
	double x;
	double y;

	Vector2(double x1, double y1);
	Vector2();
};

double getDistance(Vector2 a, Vector2 b);