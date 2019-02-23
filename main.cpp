#include <window.hpp>
#include <scene.hpp>
#include <viewport.hpp>
#include <event_handler.hpp>

const int SCREEN_WIDTH = 1920;
const int SCREEN_HEGHT = 1080;

void
setEventHandlers(EventController * controller) {
	controller->addEventHandler(new QuitHandler());
}

int
main(int argc, char ** argv) {
	Window win(SCREEN_WIDTH, SCREEN_HEGHT, "MiniGame Jam February 2019");
	Scene first;
	EventController evController;

	setEventHandlers(&evController);

	first.setRenderer(win.getRenderer());
	first.evController = &evController;

	win.sceneList.push_back(&first);
	win.start();
	return 0;
}