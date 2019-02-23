/**
 * Classes and functions related to geometry, such as Points, vectors
 * and operations between them.
 */

#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP
#include <atomic>

class Point {
public:
	std::atomic<float> x;
	std::atomic<float> y;

	Point();
	Point(float, float);
	Point(const Point&);

	Point operator + (const Point&);
	Point operator - (const Point&);
	Point operator = (const Point&);
};

class Size {
public:
	std::atomic<int> width;
	std::atomic<int> height;

	Size();
	Size(int, int);
	Size(const Size&);

	Size operator= (const Size&);
};
#endif