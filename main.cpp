#include <iostream>

#include <window.hpp>
#include <scene.hpp>
#include <viewport.hpp>
#include <event_handler.hpp>
#include <node.hpp>
#include <score.hpp>
#include <raccoon.hpp>
#include <graphics/sprite.hpp>
#include <graphics/text.hpp>

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

#define MAIN_FIELD_WIDTH 1520
#define MAIN_FIELD_HEIGHT 1080

#define UI_WIDTH	SCREEN_WIDTH - MAIN_FIELD_WIDTH
#define UI_HEIGHT	SCREEN_HEIGHT

#define TURTLE_WIDTH	100
#define TURTLE_HEIGHT	100

#define RACCOON_WIDTH	100
#define RACCOON_HEIGHT	100

void
addRaccoons(Scene * scene, SDL_Renderer *renderer, int amount) {
	int startX = (MAIN_FIELD_WIDTH - amount * RACCOON_WIDTH) / 2;
	RaccoonHolder * raccoonHolder = new RaccoonHolder(
		Point(),
		Size(amount * RACCOON_WIDTH, RACCOON_HEIGHT));
	Sprite * raccoonSprite = new Sprite("resources/raccoon.png", Color(0xFFFFFF), renderer);

	for (int idx = 0; idx < amount; idx++) {
		Node * raccoon = new Node(
			Point(startX + idx * RACCOON_WIDTH, 0.0), 
			Size(RACCOON_WIDTH, RACCOON_HEIGHT));
		raccoon->setGraphicResource(raccoonSprite);
		raccoonHolder->addChild(raccoon);
	}
	scene->nodes.push_back(raccoonHolder);
}

void
setEventHandlers(EventController * controller) {
	controller->addEventHandler(new QuitHandler());
}

void
addNodesToScene(Scene *scene, SDL_Renderer * renderer) {
	Node * inventory = new Node(Point(MAIN_FIELD_WIDTH, 0), Size(UI_WIDTH, UI_HEIGHT));
	Node * background = new Node(Point(0, 0), Size(MAIN_FIELD_WIDTH, MAIN_FIELD_HEIGHT));
	Node * turtleQueen = new Node(
		Point(MAIN_FIELD_WIDTH / 2, MAIN_FIELD_HEIGHT - TURTLE_HEIGHT),
		Size(TURTLE_WIDTH, TURTLE_HEIGHT));
//	Score * score = new Score(Point(0,0), Size(100, 100));

//	score->setGraphicResource(new Text(std::string("arial.ttf"), Color(0x0), 24, renderer));
	turtleQueen->setGraphicResource(
		new Sprite("resources/queen.png", Color(0xFFFFFF), renderer));
	inventory->setGraphicResource(
		new Sprite("resources/ui.png", Color(0xFFFFFF), renderer));
//	inventory->addChild(score);
	scene->nodes.push_back(inventory);

	background->setGraphicResource(
		new Sprite("resources/background.png", Color(0xFFFFFF), renderer));
	scene->nodes.push_back(background);
	scene->nodes.push_back(turtleQueen);

	addRaccoons(scene, renderer, 10);
}

int
main(int argc, char ** argv) {
	try {
		Window win(SCREEN_WIDTH, SCREEN_HEIGHT, "MiniGame Jam February 2019");
		Scene first;
		EventController evController;
		Viewport scene(
			Point(0, 0),
			Size(MAIN_FIELD_WIDTH, MAIN_FIELD_HEIGHT),
			win.getRenderer());
		Viewport ui(
			Point(MAIN_FIELD_WIDTH, 0),
			Size(UI_WIDTH, UI_HEIGHT),
			win.getRenderer());

		setEventHandlers(&evController);
		addNodesToScene(&first, win.getRenderer());

		first.setRenderer(win.getRenderer());

		first.addViewport(&scene);
		first.addViewport(&ui);
		first.evController = &evController;

		win.sceneList.push_back(&first);
		win.start();
	}
	catch (std::exception ex) {
		std::cout << "Exception caught: " << ex.what() << std::endl;
	}
	return 0;
}
