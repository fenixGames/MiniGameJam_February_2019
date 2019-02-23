#include <physics/geometry.hpp>

Point::Point(): Point(0.0, 0.0) {
}

Point::Point(float x, float y) {
	this->x = x;
	this->y = y;
}

Point::Point(const Point& point): Point(point.x, point.y) {
}

Point
Point::operator+(const Point& point) {
	return Point(x + point.x, y + point.y);
}

Point
Point::operator-(const Point& point) {
	return Point(x - point.x, y - point.y);
}

Point
Point::operator=(const Point& point) {
	if (this != &point) {
		this->x = point.x;
		this->y = point.y;
	}
	return *this;
}

Size::Size(): Size(0, 0) {
}

Size::Size(const Size& size) : Size(size.width, size.height) {
}

Size::Size(int width, int height) {
	this->width = width;
	this->height = height;
}

Size
Size::operator=(const Size& size) {
	if (this != &size) {
		this->width = width;
		this->height = height;
	}
	return *this;
}