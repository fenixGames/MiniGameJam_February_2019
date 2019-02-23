#include <window.hpp>
#include <scene.hpp>
#include <viewport.hpp>
#include <event_handler.hpp>

const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;

const int MAIN_FIELD_WIDTH = 1520;
const int MAIN_FIELD_HEIGHT = 1080;

void
setEventHandlers(EventController * controller) {
	controller->addEventHandler(new QuitHandler());
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

	setEventHandlers(&evController);

	first.setRenderer(win.getRenderer());
	first.addViewport(&scene);
	first.evController = &evController;

	win.sceneList.push_back(&first);
	win.start();
	return 0;
}