#include"GAME.h"
#include"BACK_IMG.h"
#include "STAGE2.h"
#include"libOne.h"
#include"PLAYER.h"
#include"PLAYER2.h"
#include"PLAYER3.h"
#include"PLAYER4.h"
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
	game()->player2()->init();
	game()->player3()->init();
	game()->player4()->init();
	game()->playerBullets()->init();
	game()->enemiesB()->init();
	game()->enemyMBullets()->init();
	game()->transition()->inTrigger();
	Stage2.ep = 0;
}
void STAGE2::update() {
	if (Stage2.ep != 0) {
		if (Stage2.ep == 1) {
			game()->player()->update();
		}
		else if (Stage2.ep == 2) {
			game()->player2()->update();
		}
		else if (Stage2.ep == 3) {
			game()->player3()->update();
		}
		else if (Stage2.ep == 4) {
			game()->player4()->update();
		}
		game()->enemiesB()->update();
		game()->playerBullets()->update();
		game()->enemyMBullets()->update();
	}
	else {
		if (isTrigger(KEY_Z)) {
			Stage2.ep = 1;
		}
		else if (isTrigger(KEY_X)) {
			Stage2.ep = 2;
		}
		else if (isTrigger(KEY_C)) {
			Stage2.ep = 3;
		}
		else if (isTrigger(KEY_P)) {
			Stage2.ep = 4;
		}
	}
}
void STAGE2::draw() {
	rectMode(CENTER);
    clear();
	game()->back_img()->draw();
	if (Stage2.ep != 0) {
		if (Stage2.ep == 1) {
			game()->player()->draw();
		}
		else if (Stage2.ep == 2) {
			game()->player2()->draw();
		}
		else if (Stage2.ep == 3) {
			game()->player3()->draw();
		}
		else if (Stage2.ep == 4) {
			game()->player4()->draw();
		}
		game()->enemiesB()->draw();
		game()->playerBullets()->draw();
		game()->enemyMBullets()->draw();
	}
	game()->transition()->draw();

}
void STAGE2::nextScene() {
	if (game()->enemiesB()->curNum()<=0) {
		game()->transition()->outTrigger();
		if (game()->transition()->outEndFlag()) {
			game()->changScene(GAME::STAGE3_ID);
		}
	}
	else if (game()->player()->hp()<=0||game()->player2()->hp() <= 0||
		game()->player3()->hp() <= 0||game()->player4()->hp()<=0) {
		game()->transition()->outTrigger();
		if (game()->transition()->outEndFlag()) {
			game()->changScene(GAME::GAME_OVER_ID);
		}
	}
}


