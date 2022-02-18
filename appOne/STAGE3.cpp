#include"GAME.h"
#include "STAGE3.h"
#include"BACK_IMG.h"
#include"libOne.h"
#include"TRANSITION.h"
#include"PLAYER.h"
#include"BOSS.h"
#include"P_BULLETS.h"
#include"E_BULLETS.h"
STAGE3::STAGE3(class GAME* game) :
     SCENE(game){
}
STAGE3::~STAGE3(){
}
void STAGE3::init() {
	game()->transition()->inTrigger();
	game()->player()->init();
	game()->bosses()->init();
	game()->enemyMBullets()->init();
}
void STAGE3::update() {
	game()->player()->update();
	game()->playerBullets()->update();
	game()->bosses ()->update();
	game()->enemyMBullets()->update();
}
void STAGE3::draw() {
    clear();
	game()->back_img()->draw();
	game()->player()->draw();
	game()->playerBullets()->draw();
	game()->bosses()->draw();
	game()->enemyMBullets()->draw();
	game()->transition()->draw();
}
void STAGE3::nextScene() {
	if (isTrigger(KEY_Z)/*game()->bosses()->curNum()*/) {
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