/**
 * Definitions of event handling.
 *
 * This module defines the EventHandler class and
 * the Event class also.
 */

#ifndef EVENT_HANDLER_HPP
#define EVENT_HANDLER_HPP

#include <SDL.h>
#include <list>

class EventHandler {
protected:
	SDL_EventType type;
public:
	EventHandler(SDL_EventType);

	SDL_EventType getType();
	virtual void handle(SDL_Event *) = 0;
};

class QuitHandler : public EventHandler {
public:
	QuitHandler();

	virtual void handle(SDL_Event *);
};

class EventController {
protected:
	std::list<EventHandler *> eventHandlers;
public:
	void addEventHandler(EventHandler *);
	bool isEventHandlerAdded(SDL_EventType);

	void handleEvents();
};
#endif