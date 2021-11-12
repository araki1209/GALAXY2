#include"GAME.h"
#include "STAGE2.h"
#include"libOne.h"
#include"TRANSITION.h"
STAGE2::STAGE2(class GAME* game) :
    SCENE(game){
}
STAGE2::~STAGE2(){
}
void STAGE2::init() {
	game()->transition()->inTrigger();
}
void STAGE2::draw() {
    clear();
    printSize(300);
	fill(255);
    print("STAGE2");
	game()->transition()->draw();
}
void STAGE2::nextScene() {
	if (isTrigger(KEY_Z)) {
		//game()->transition()->outTrigger();
		//if (game()->transition()->outEndFlag()) {
		    game()->changScene(GAME::STAGE3_ID);
		//}
	}
	else if (isTrigger(KEY_C)) {
		//game()->transition()->outTrigger();
		//if (game()->transition()->outEndFlag()) {
		    game()->changScene(GAME::GAME_OVER_ID);
		//}
	}
}


