#include"GAME.h"
#include "STAGE3.h"
#include"BACK_IMG.h"
#include"libOne.h"
#include"TRANSITION.h"
#include"PLAYER.h"
#include"PLAYER2.h"
#include"PLAYER3.h"
#include"PLAYER4.h"
#include"BOSS.h"
#include"P_BULLETS.h"
#include"E_BULLETS.h"
STAGE3::STAGE3(class GAME* game) :
     SCENE(game){
}
STAGE3::~STAGE3(){
}
void STAGE3::init() {
	game()->player()->init();
	game()->player2()->init();
	game()->player3()->init();
	game()->player4()->init();
	game()->bosses()->init();
	game()->enemyMBullets()->init();
	game()->transition()->inTrigger();
	Stage3.ep = 0;
}
void STAGE3::update() {
	if (Stage3.ep != 0) {
		if (Stage3.ep == 1) {
			game()->player()->update();
		}
		else if (Stage3.ep == 2) {
			game()->player2()->update();
		}
		else if (Stage3.ep == 3) {
			game()->player3()->update();
		}
		else if (Stage3.ep == 4) {
			game()->player4()->update();
		}
		game()->playerBullets()->update();
		game()->bosses()->update();
		game()->enemyMBullets()->update();
	}
	else {
		if (isTrigger(KEY_Z)) {
			Stage3.ep = 1;
		}
		else if (isTrigger(KEY_X)) {
			Stage3.ep = 2;
		}
		else if (isTrigger(KEY_C)) {
			Stage3.ep = 3;
		}
		else if (isTrigger(KEY_P)) {
			Stage3.ep = 4;
		}
	}
}
void STAGE3::draw() {
    clear();
	game()->back_img()->draw();
	if (Stage3.ep != 0) {
		if (Stage3.ep == 1) {
			game()->player()->draw();
		}
		else if (Stage3.ep == 2) {
			game()->player2()->draw();
		}
		else if (Stage3.ep == 3) {
			game()->player3()->draw();
		}
		else if (Stage3.ep == 4) {
			game()->player4()->draw();
		}
		game()->playerBullets()->draw();
		game()->bosses()->draw();
		game()->enemyMBullets()->draw();
	}
	game()->transition()->draw();
}
void STAGE3::nextScene() {
	if (game()->bosses()->curNum() <= 0) {
		game()->transition()->outTrigger();
		if (game()->transition()->outEndFlag()) {
			game()->changScene(GAME::GAME_CLEAR_ID);
		}
	}
	else if (game()->player()->hp() <= 0|| game()->player2()->hp() <= 0||
		     game()->player3()->hp()<=0||game()->player4()->hp() <= 0) {
		game()->transition()->outTrigger();
		if (game()->transition()->outEndFlag()) {
			game()->changScene(GAME::GAME_OVER_ID);
		}
	}
	
}