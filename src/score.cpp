#include <score.hpp>

Score::Score(const Point &position, const Size &size): 
	Node(position, size){
	this->score = 0;
}

int
Score::getScore() {
	return this->score;
}

void
Score::addToScore(int points) {
	this->score += points;
}
