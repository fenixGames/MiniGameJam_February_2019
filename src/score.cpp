#include <score.hpp>
#include <graphics/text.hpp>

Score::Score() : Score(Point(0, 0), Size(0, 0)){
}

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

	std::string text = "";
	text += this->score;
	Text * textResource = (Text *)this->graphicResource;
	textResource->setText(text);
}
