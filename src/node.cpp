#include <node.hpp>

Node::Node() : Node(Point(0, 0), Size(0, 0))
{
}

Node::Node(const Point& startPoint, const Size& startSize)
{
	this->setPosition(startPoint);
	this->setSize(startSize);
	this->setGraphicResource(NULL);
	this->parent = NULL;
}


SDL_Texture *
Node::getTexture()
{
	SDL_Texture * texture;

	this->mutex.lock();
	if (graphicResource != NULL)
		texture = graphicResource->getTexture();
	this->mutex.unlock();
	return texture;
}

void
Node::setGraphicResource(Graphic * resource) {
	this->mutex.lock();
	graphicResource = resource;
	this->mutex.unlock();
}

void 
Node::fillDimentions(SDL_Rect *rect) {
	Node * root = this;

	rect->w = (int)this->size.width;
	rect->h = (int)this->size.height;

	rect->x = rect->y = 0;
	while (root != NULL) {
		rect->x += (int)root->position.x;
		rect->y += (int)root->position.y;
		root = root->parent;
	}
}

void
Node::setPosition(const Point& point) {
	this->position = point;
}

void
Node::setSize(const Size& size) {
	this->size = size;
}

void
Node::addChild(Node * child) {
	if (child != NULL)
		this->children.push_back(child);
}