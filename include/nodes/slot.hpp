#ifndef SLOT_HPP
#define SLOT_HPP

#include <nodes/draggable_node.hpp>

class Slot : public DraggableNode {
protected:
	int cost;
	int health;
public:
	Slot(int, int);
	Slot(const Point&, const Size&, const int, const int);

	int getCost();
	int getHealth();

	Slot * clone();
	virtual void act() override;
};
#endif