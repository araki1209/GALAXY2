#include"libOne.h"
#include "GAME_CLEAR.h"
#include"CONTAINER.h"
#include"GAME.h"
GAME_CLEAR::GAME_CLEAR(class GAME* game) :
	SCENE(game) {
}
GAME_CLEAR::~GAME_CLEAR() {
}
void GAME_CLEAR::init() {
	game()->transition()->inTrigger();
}
void GAME_CLEAR::create() {
	Game_clear = game()->container()->game_clear();
}
void GAME_CLEAR::draw() {
	clear();
	printSize(300);
	fill(255);
	print("CLEAR");
	//image(Game_clear.img, 800, 500, 0, 1);
	game()->transition()->draw();
}
void GAME_CLEAR::nextScene() {
	if (isTrigger(KEY_SPACE)) {
		game()->transition()->outTrigger();
	}
	if (game()->transition()->outEndFlag()){
		game()->changScene(GAME::TITLE_ID);
	}
}
