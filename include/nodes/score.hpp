#ifndef SCORE_HPP
#define SCORE_HPP

#include <physics/geometry.hpp>
#include <nodes/node.hpp>

class Score : public Node {
protected:
	int score;
public:
	Score();
	Score(const Point&, const Size&);

	int getScore();
	void addToScore(int points);
};
#endif 