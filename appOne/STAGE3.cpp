#include"GAME.h"
#include "STAGE3.h"
#include"libOne.h"
STAGE3::STAGE3(class GAME* game) :
     SCENE(game){
}
STAGE3::~STAGE3(){}
void STAGE3::draw() {
    clear();
    printSize(300);
    print("STAGE3");
}
void STAGE3::nextScene() {
	if (isTrigger(KEY_Z)) {
		game()->changScene(GAME::GAME_CLEAR_ID);
	}
	if (isTrigger(KEY_C)) {
		game()->changScene(GAME::GAME_OVER_ID);
	}
}