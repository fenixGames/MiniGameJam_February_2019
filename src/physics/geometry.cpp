#include <physics/geometry.hpp>

Point::Point(): Point(0.0, 0.0) {
}

Point::Point(float x, float y) {
	this->x.exchange(x);
	this->y.exchange(y);
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
		this->x.exchange(point.x);
		this->y.exchange(point.y);
	}
	return *this;
}

Size::Size(): Size(0, 0) {
}

Size::Size(const Size& size) : Size(size.width, size.height) {
}

Size::Size(int width, int height) {
	this->width.exchange(width);
	this->height.exchange(height);
}

Size
Size::operator=(const Size& size) {
	if (this != &size) {
		this->width.exchange(size.width);
		this->height.exchange(size.height);
	}
	return *this;
}