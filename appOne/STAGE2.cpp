#include"GAME.h"
#include"BACK_IMG.h"
#include "STAGE2.h"
#include"libOne.h"
#include"PLAYER.h"
#include"ENEMYb.h"
#include"P_BULLETS.h"
#include"E_BULLETS.h"
#include"TRANSITION.h"
STAGE2::STAGE2(class GAME* game) :
    SCENE(game){
}
STAGE2::~STAGE2(){
}
void STAGE2::init() {
	game()->player()->init();
	game()->playerBullets()->init();
	game()->enemiesB()->init();
	game()->enemyMBullets()->init();
	game()->transition()->inTrigger();
}
void STAGE2::update() {
	game()->player()->update();
	game()->enemiesB()->update();
	game()->playerBullets()->update();
	game()->enemyMBullets()->update();
}
void STAGE2::draw() {
	rectMode(CENTER);
    clear();
	game()->back_img()->draw();
	game()->player()->draw();
	game()->enemiesB()->draw();
	game()->playerBullets()->draw();
	game()->enemyMBullets()->draw();
	game()->transition()->draw();

}
void STAGE2::nextScene() {
	if (game()->enemiesB()->curNum()<=0) {
		game()->transition()->outTrigger();
		if (game()->transition()->outEndFlag()) {
			game()->changScene(GAME::STAGE3_ID);
		}
	}
	else if (game()->player()->hp()<=0) {
		game()->transition()->outTrigger();
		if (game()->transition()->outEndFlag()) {
			game()->changScene(GAME::GAME_OVER_ID);
		}
	}
}


