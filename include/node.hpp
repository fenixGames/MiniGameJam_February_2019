/**
 * Nodes are everything that forms part of a scene.
 * It can be a light, a character, a npc or a camera.
 */

#ifndef NODE_HPP
#define NODE_HPP

#include <mutex>
#include <list>
#include <SDL.h>

#include <physics/geometry.hpp>
#include <graphics/graphic.hpp>

class Node {
protected:
	std::mutex mutex;

	Graphic * graphicResource;
	Point position;
	Size size;

	/* A node uses relative coordinates, 
	   so we need to keep track of the ancestory to
	   calculate the absolute coordinates.
	 */
	Node * parent;
	std::list<Node *> children;
public:

	Node();
	Node(const Point&, const Size&);

	void setPosition(const Point&);
	void setSize(const Size&);

	SDL_Texture * getTexture();
	void setGraphicResource(Graphic *);
	void fillDimentions(SDL_Rect *);

	void addChild(Node *);
};
#endif