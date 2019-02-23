#include <iostream>

#include <window.hpp>
#include <scene.hpp>
#include <viewport.hpp>
#include <events/event_handler.hpp>
#include <events/mouse_handler.hpp>
#include <nodes/node.hpp>
#include <nodes/score.hpp>
#include <nodes/raccoon.hpp>
#include <nodes/slot.hpp>
#include <graphics/sprite.hpp>
#include <graphics/text.hpp>

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

#define MAIN_FIELD_WIDTH 1800
#define MAIN_FIELD_HEIGHT 1080
#define MAIN_FIELD_SIZE	Size(MAIN_FIELD_WIDTH, MAIN_FIELD_HEIGHT)

#define UI_WIDTH	SCREEN_WIDTH - MAIN_FIELD_WIDTH
#define UI_HEIGHT	SCREEN_HEIGHT

#define TURTLE_WIDTH	100
#define TURTLE_HEIGHT	100

#define RACCOON_WIDTH	100
#define RACCOON_HEIGHT	100

#define SLOT_SIZE		Size(100, 100)

#define COLOR_WHITE		Color(0xFFFFFF)

void
addRaccoons(Scene * scene, SDL_Renderer *renderer, int amount) {
	int startX = (MAIN_FIELD_WIDTH - amount * RACCOON_WIDTH) / 2;
	RaccoonHolder * raccoonHolder = new RaccoonHolder(
		Point(),
		Size(amount * RACCOON_WIDTH, RACCOON_HEIGHT));
	Sprite * raccoonSprite = new Sprite("resources/raccoon.png", COLOR_WHITE, renderer);

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
createInventary(Scene *scene, SDL_Renderer *renderer) {
	Node * inventory = new Node(Point(MAIN_FIELD_WIDTH, 0), Size(UI_WIDTH, UI_HEIGHT));
	Score * score = new Score(Point(0, 0), Size(100, 100));
	Slot * tower = new Slot(Point(0, 100), SLOT_SIZE, 0, 100);
	MouseDownHandler * mouseDownEventHandler = new MouseDownHandler(inventory);
	MouseMotionHandler * mouseMotionEventHandler = new MouseMotionHandler(inventory);
	MouseUpHandler * mouseUpEventHandler = new MouseUpHandler(inventory, scene->nodes.front());

	scene->evController->addEventHandler(mouseDownEventHandler);
	scene->evController->addEventHandler(mouseUpEventHandler);
	scene->evController->addEventHandler(mouseMotionEventHandler);

	tower->setGraphicResource(new Sprite("resources/tower.png", COLOR_WHITE, renderer));
	//	score->setGraphicResource(new Text(std::string("arial.ttf"), Color(0x0), 24, renderer));
	inventory->setGraphicResource(
		new Sprite("resources/ui.png", COLOR_WHITE, renderer));
	inventory->addChild(score);
	inventory->addChild(tower);
	scene->nodes.push_back(inventory);
}

void
addNodesToScene(Scene *scene, SDL_Renderer * renderer) {
	Node * background = new Node(Point(0, 0), MAIN_FIELD_SIZE);
	Node * turtleQueen = new Node(
		Point(MAIN_FIELD_WIDTH / 2, MAIN_FIELD_HEIGHT - TURTLE_HEIGHT),
		Size(TURTLE_WIDTH, TURTLE_HEIGHT));
	
	turtleQueen->setGraphicResource(
		new Sprite("resources/queen.png", COLOR_WHITE, renderer));

	background->setGraphicResource(
		new Sprite("resources/background.png", COLOR_WHITE, renderer));
	scene->nodes.push_back(background);
	background->addChild(turtleQueen);

	addRaccoons(scene, renderer, 10);
	createInventary(scene, renderer);
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


		first.addViewport(&scene);
		first.addViewport(&ui);
		first.evController = &evController;

		setEventHandlers(&evController);
		addNodesToScene(&first, win.getRenderer());

		first.setRenderer(win.getRenderer());


		win.sceneList.push_back(&first);
		win.start();
	}
	catch (std::exception ex) {
		std::cout << "Exception caught: " << ex.what() << std::endl;
	}
	return 0;
}
