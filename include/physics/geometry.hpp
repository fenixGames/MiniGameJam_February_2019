/**
 * Classes and functions related to geometry, such as Points, vectors
 * and operations between them.
 */

#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP
#include <atomic>

class Point {
public:
	float x;
	float y;

	Point();
	Point(float, float);
	Point(const Point&);

	Point operator + (const Point&);
	Point operator - (const Point&);
};

class Size {
public:
	int width;
	int height;

	Size();
	Size(int, int);
	Size(const Size&);
};
#endif