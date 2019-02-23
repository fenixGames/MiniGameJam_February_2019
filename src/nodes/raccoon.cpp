#include <nodes/raccoon.hpp>

RaccoonHolder::RaccoonHolder() : RaccoonHolder(Point(), Size()) {
}

RaccoonHolder::RaccoonHolder(const Point& position, const Size& size) :
	Node(position, size) {
}

void
RaccoonHolder::act() {
	this->position.y += 1.0;
}