#ifndef MOUSE_HANDLER
#define MOUSE_HANDLER
#include <SDL.h>
#include <physics/geometry.hpp>
#include <nodes/node.hpp>
#include <events/event_handler.hpp>

class MouseDownHandler : public EventHandler {
protected:
	Node * node;
	Node * finalContainer;
public:
	MouseDownHandler(Node *, Node * finalContainer);
	virtual void handle(SDL_Event *);
};

class MouseUpHandler : public EventHandler {
protected:
	Node * node;
	Node * finalContainer;
public:
	MouseUpHandler(Node *);
	virtual void handle(SDL_Event *);
};

class MouseMotionHandler : public EventHandler {
protected:
	Node * node;
public:
	MouseMotionHandler(Node *);
	virtual void handle(SDL_Event *);
};
#endif // !MOUSE_HANDLER
