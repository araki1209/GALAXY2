#include"GAME.h"
#include "STAGE3.h"
#include"libOne.h"
#include"TRANSITION.h"
#include"PLAYER.h"
STAGE3::STAGE3(class GAME* game) :
     SCENE(game){
}
STAGE3::~STAGE3(){
}
void STAGE3::init() {
	game()->transition()->inTrigger();
	game()->player()->init();
}
void STAGE3::update() {
	game()->player()->update();
}
void STAGE3::draw() {
    clear();
    printSize(300);
	fill(255);
    print("STAGE3");
	game()->player()->draw();
	game()->transition()->draw();
}
void STAGE3::nextScene() {
	if (isPress(KEY_Z)) {
		game()->transition()->outTrigger();
		if (game()->transition()->outEndFlag()) {
			game()->changScene(GAME::GAME_CLEAR_ID);
		}
	}
	else if (isTrigger(KEY_C)) {
		game()->transition()->outTrigger();
		if (game()->transition()->outEndFlag()) {
			game()->changScene(GAME::GAME_OVER_ID);
		}
	}
}