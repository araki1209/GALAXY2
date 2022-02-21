#include"libOne.h"
#include "GAME_OVER.h"
#include"CONTAINER.h"
#include"GAME.h"
GAME_OVER::GAME_OVER(class GAME* game) :
	SCENE(game) {
}
GAME_OVER::~GAME_OVER() {
}
void GAME_OVER::init() {
	game()->transition()->inTrigger();
}
void GAME_OVER::create() {
	Game_over = game()->container()->game_over();
}
void GAME_OVER::draw() {
	clear();
	image(Game_over.img, 0, 0);
	game()->transition()->draw();
}
void GAME_OVER::nextScene() {
	if (isTrigger(KEY_SPACE)) {
		game()->transition()->outTrigger();
	}
	if (game()->transition()->outEndFlag()) {
		game()->changScene(GAME::TITLE_ID);
	}
}

