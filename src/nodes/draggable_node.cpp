#include <nodes/draggable_node.hpp>

DraggableNode::DraggableNode() :
	DraggableNode(Point(), Size()) {
}

DraggableNode::DraggableNode(const Point& position, const Size& size) :
	Node(position, size) {
}

void
DraggableNode::drag() {
	this->isDragged = true;
	this->startPoint = this->position;
}

void
DraggableNode::release() {
	this->isDragged = false;
	this->setPosition(this->startPoint);
}

bool 
DraggableNode::isNodeDragged() {
	return this->isDragged;
}
