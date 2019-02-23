#include <window.hpp>
#include <scene.hpp>
#include <viewport.hpp>
#include <event_handler.hpp>
#include <node.hpp>
#include <graphics/sprite.hpp>

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

#define MAIN_FIELD_WIDTH 1520
#define MAIN_FIELD_HEIGHT 1080

#define UI_WIDTH	SCREEN_WIDTH - MAIN_FIELD_WIDTH
#define UI_HEIGHT	SCREEN_HEIGHT

void
setEventHandlers(EventController * controller) {
	controller->addEventHandler(new QuitHandler());
}

void
addNodesToScene(Scene *scene, SDL_Renderer * renderer) {
	Node * inventory = new Node(Point(MAIN_FIELD_WIDTH, 0), Size(UI_WIDTH, UI_HEIGHT));
	Node * background = new Node(Point(0, 0), Size(MAIN_FIELD_WIDTH, MAIN_FIELD_HEIGHT));

	inventory->setGraphicResource(
		new Sprite("resources/ui.png", Color(0xFFFFFF), renderer));
	scene->nodes.push_back(inventory);

	background->setGraphicResource(
		new Sprite("resources/background.png", Color(0xFFFFFF), renderer));
	scene->nodes.push_back(background);
}

int
main(int argc, char ** argv) {
	Window win(SCREEN_WIDTH, SCREEN_HEIGHT, "MiniGame Jam February 2019");
	Scene first;
	EventController evController;
	Viewport scene(
		Point(0,0),
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
	return 0;
}
