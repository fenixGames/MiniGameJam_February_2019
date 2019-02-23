#ifndef DRAGGABLE_NODE_HPP
#define DRAGGABLE_NODE_HPP
#include <nodes/node.hpp>

class DraggableNode : public Node {
protected:
	bool isDragged;
public:
	DraggableNode();
	DraggableNode(const Point&, const Size&);

	void drag();
	void release();
	bool isNodeDragged();

};

#endif // !DRAGGABLE_NODE_HPP
