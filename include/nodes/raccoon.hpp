#ifndef RACCOON_HPP
#define RACCOON_HPP
#include <physics/geometry.hpp>
#include <nodes/node.hpp>

class RaccoonHolder : public Node {
public:
	RaccoonHolder();
	RaccoonHolder(const Point&, const Size&);

	virtual void act() override;
};
#endif