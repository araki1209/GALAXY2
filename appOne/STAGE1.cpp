#include"libOne.h"
#include "STAGE1.h"
#include"TRANSITION.h"
#include"GAME.h"
#include"PLAYER.h"
STAGE1::STAGE1(class GAME* game) :
	SCENE(game) {
}
STAGE1::~STAGE1() {
}
void STAGE1::init() {
	game()->player()->init();
	game()->transition()->inTrigger();
}
void STAGE1::create() {
}
void STAGE1::update(){
	game()->player()->update();
}
void STAGE1::draw() {
	clear();
	//printSize(300);
	//fill(255);
	//print("STAGE1");
	game()->player()->draw();
	game()->transition()->draw();
}
void STAGE1::nextScene() {
	if (isPress(KEY_Z)) {
		game()->transition()->outTrigger();
		if (game()->transition()->outEndFlag()){
		    game()->changScene(GAME::STAGE2_ID);
		}
	}

	else if (isTrigger(KEY_C)) {
	     game()->transition()->outTrigger();
	     if (game()->transition()->outEndFlag()) {
			  game()->changScene(GAME::GAME_OVER_ID);
		 }
	}
}
