/**
 * Scene management.
 */

#ifndef SCENE_HPP
#define SCENE_HPP

#include <list>

#include <SDL.h>

#include <node.hpp>
#include <event_handler.hpp>
#include <viewport.hpp>

class Scene {
protected:
	bool finished;

	std::list<Viewport *> viewports;
	SDL_Renderer * renderer;
public:
	EventController * evController;
	std::list<Node *> nodes;

	Scene();
	bool isFinished(void);
	void draw();

	void addViewport(Viewport *);
	void setRenderer(SDL_Renderer*);
};

#endif