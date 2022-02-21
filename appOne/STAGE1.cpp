#include"libOne.h"
#include"SCENE.h"
#include "STAGE1.h"
#include"GAME.h"
#include"PLAYER.h"
#include"PLAYER2.h"
#include"PLAYER3.h"
#include"PLAYER4.h"
#include"P_BULLETS.h"
#include"ENEMYm.h"
#include"E_BULLETS.h"
#include"TITLE.h"
#include"BACK_IMG.h"
#include"PLAYERCHANGE.h"
#include"TRANSITION.h"
STAGE1::STAGE1(class GAME* game):
	SCENE(game) {
}
STAGE1::~STAGE1() {
}
void STAGE1::create() {
}
void STAGE1::init() {
	game()->player()->init();
	game()->player2()->init();
	game()->player3()->init();
	game()->player4()->init();
	game()->playerBullets()->init();
	game()->enemiesM()->init();
	game()->enemyMBullets()->init();
	game()->transition()->inTrigger();
	Stage1.ep = 0;
}
void STAGE1::update(){
	if (Stage1.ep != 0) {
		if (Stage1.ep == 1) {
			game()->player()->update();
		}
		else if (Stage1.ep == 2) {
			game()->player2()->update();
		}
		else if (Stage1.ep == 3) {
			game()->player3()->update();
		}
		else if (Stage1.ep == 4) {
			game()->player4()->update();
		}
		game()->playerBullets()->update();
		game()->enemiesM()->update();
		game()->enemyMBullets()->update();
	}
	else {
		if (isTrigger(KEY_Z)) {
			Stage1.ep = 1;
		}
		else if (isTrigger(KEY_X)) {
			Stage1.ep = 2;
		}
		else if (isTrigger(KEY_C)) {
			Stage1.ep = 3;
		}
		else if (isTrigger(KEY_P)) {
			Stage1.ep = 4;
		}
	}
}
void STAGE1::draw() {
	clear();
	game()->back_img()->draw();
	if (Stage1.ep != 0) {
		if (Stage1.ep == 1) {
			game()->player()->draw();
		}
		else if (Stage1.ep == 2) {
			game()->player2()->draw();
		}
		else if (Stage1.ep == 3) {
			game()->player3()->draw();
		}
		else if (Stage1.ep == 4) {
			game()->player4()->draw();
		}
		game()->enemyMBullets()->draw();
		game()->playerBullets()->draw();
		game()->enemiesM()->draw();
	}
		game()->transition()->draw();
}
void STAGE1::nextScene() {
	if (game()->enemiesM()->curNum()<=0) {
		game()->transition()->outTrigger();
		if (game()->transition()->outEndFlag()){
		    game()->changScene(GAME::STAGE2_ID);
		}
	}

	else if (game()->player()->hp()<=0||game()->player2()->hp() <= 0||
		     game()->player3()->hp() <= 0||game()->player4()->hp()<=0){
	     game()->transition()->outTrigger();
	     if (game()->transition()->outEndFlag()) {
			  game()->changScene(GAME::GAME_OVER_ID);
		 }
	}
}
int STAGE1::no() {
	return Stage1.no;
}
