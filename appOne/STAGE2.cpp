#include"GAME.h"
#include "STAGE2.h"
#include"libOne.h"
#include"TRANSITION.h"
#include"PLAYER.h"
STAGE2::STAGE2(class GAME* game) :
    SCENE(game){
}
STAGE2::~STAGE2(){
}
void STAGE2::init() {
	game()->transition()->inTrigger();
	game()->player()->init();
}
void STAGE2::update() {
	game()->player()->update();
}
void STAGE2::draw() {
    clear();
    printSize(300);
	fill(255);
    print("STAGE2");
	game()->player()->draw();
	game()->transition()->draw();

}
void STAGE2::nextScene() {
	if (isPress(KEY_Z)) {
		game()->transition()->outTrigger();
		if (game()->transition()->outEndFlag()) {
			game()->changScene(GAME::STAGE3_ID);
		}
	}
	else if (isTrigger(KEY_C)) {
		game()->transition()->outTrigger();
		if (game()->transition()->outEndFlag()) {
			game()->changScene(GAME::GAME_OVER_ID);
		}
	}
}


