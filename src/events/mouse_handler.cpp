#include <SDL.h>
#include <list>
#include <iostream>

#include <events/mouse_handler.hpp>
#include <nodes/slot.hpp>

static bool
isInRange(Node * node, SDL_MouseButtonEvent * ev) {
	SDL_Rect rect;
	SDL_Point point;

	node->fillDimentions(&rect);

	point.x = ev->x;
	point.y = ev->y;

	return SDL_PointInRect(&point, &rect);
}

MouseDownHandler::MouseDownHandler(Node * node, Node * finalContainer) :
	EventHandler(SDL_MOUSEBUTTONDOWN) {
	this->node = node;
	this->finalContainer = finalContainer;
}

void
MouseDownHandler::handle(SDL_Event * ev) {
	std::list<Node *>::iterator itNodes;
	std::list<Node *> * slots = this->node->getChildren();
	Slot * node;

	for (itNodes = slots->begin(); itNodes != slots->end(); itNodes++) {
		if (typeid(**itNodes) == typeid(Slot)) {
			node = (Slot *)* itNodes;
			if (isInRange(node, (SDL_MouseButtonEvent *)ev)) {
				Slot * clone = node->clone();
				clone->drag();
				this->finalContainer->addChild(clone);
			}
		}
	}
}


MouseUpHandler::MouseUpHandler(Node *container) :
	EventHandler(SDL_MOUSEBUTTONUP) {
	this->node = container;
}

void
MouseUpHandler::handle(SDL_Event * ev) {
	std::list<Node *>::iterator itNodes;
	std::list<Node *> * slots = this->node->getChildren();
	Slot * node;

	for (itNodes = slots->begin(); itNodes != slots->end(); itNodes++) {
		if (typeid(**itNodes) == typeid(Slot)) {
			node = (Slot *)* itNodes;
			if (node->isNodeDragged()) {
				
				node->release();
			}
		}
	}
}

MouseMotionHandler::MouseMotionHandler(Node * node):
	EventHandler(SDL_MOUSEMOTION) {
	this->node = node;
}

void
MouseMotionHandler::handle(SDL_Event *ev) {
	std::list<Node *>::iterator itNodes;
	std::list<Node *> * slots = this->node->getChildren();
	Slot * node;
	SDL_MouseMotionEvent motionEvent = ev->motion;

	for (itNodes = slots->begin(); itNodes != slots->end(); itNodes++) {
		if (typeid(**itNodes) == typeid(Slot)) {
			node = (Slot *)* itNodes;
			if (node->isNodeDragged()) {
				
				node->setPosition(Point(motionEvent.x, motionEvent.y));
			}
		}
	}
}