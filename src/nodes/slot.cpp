#include <nodes/slot.hpp>

Slot::Slot(int cost, int health) : 
	Slot(Point(), Size(), cost, health) {

}

Slot::Slot(const Point& position, const Size& size, const int cost, const int health) :
	Node(position, size) {
	this->cost = cost;
	this->health = health;
}

int
Slot::getCost() {
	return this->cost;
}

int
Slot::getHealth() {
	return this->health;
}

void
Slot::act() {
}