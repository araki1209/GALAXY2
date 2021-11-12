#include"libOne.h"
#include "GAME_OVER.h"
#include"CONTAINER.h"
#include"GAME.h"
GAME_OVER::GAME_OVER(class GAME* game) :
	SCENE(game) {
}
GAME_OVER::~GAME_OVER() {
}
void GAME_OVER::create() {
	Game_over = game()->container()->game_over();
}
void GAME_OVER::draw() {
	clear();
	printSize(300);
	print("Game over");
}
void GAME_OVER::nextScene() {
	if (isTrigger(KEY_SPACE)) {
		game()->changScene(GAME::TITLE_ID);
	}
}

