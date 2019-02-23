#ifndef SLOT_HPP
#define SLOT_HPP

#include <nodes/node.hpp>

class Slot : public Node {
protected:
	int cost;
	int health;
public:
	Slot(int, int);
	Slot(const Point&, const Size&, const int, const int);

	int getCost();
	int getHealth();

	virtual void act() override;
};
#endif