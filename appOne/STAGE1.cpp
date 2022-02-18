#include"libOne.h"
#include"SCENE.h"
#include "STAGE1.h"
#include"GAME.h"
#include"PLAYER.h"
#include"PLAYER2.h"
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
	if (game()->title()->p_Data() != 0) {
		game()->player()->init();
	}
	else {
		game()->player2()->init();
	}
	game()->player()->init();
	game()->player2()->init();
	game()->playerBullets()->init();
	game()->enemiesM()->init();
	game()->enemyMBullets()->init();
	game()->transition()->inTrigger();
}
void STAGE1::update(){
	if (game()->title()->p_Data() != 0) {
		game()->player()->update();
	}
	else {
		game()->player2()->update();
	}
	//switch (game()->title()->p_Data()) {
	//case 0:game()->player()->update();
	//	break;
	//case 1:game()->player2()->update(); 
	//	break;
	//}
	game()->playerBullets()->update();
	game()->enemiesM()->update();
	game()->enemyMBullets()->update();
}
void STAGE1::draw() {
	clear();
	game()->back_img()->draw();
	if (game()->playerchange()->repChange() !=0) {
		game()->player()->draw();
	}
	else {
		game()->player2()->draw();
	}
	//switch (game()->title()->p_Data()) {
	//case 0:game()->player()->draw(); 
	//	break;
	//case 1:game()->player2()->draw();
	//	break;
	//}
	game()->enemyMBullets()->draw();
	game()->playerBullets()->draw();
	game()->enemiesM()->draw();
	game()->transition()->draw();
}
void STAGE1::nextScene() {
	if (game()->enemiesM()->curNum()<=0) {
		game()->transition()->outTrigger();
		if (game()->transition()->outEndFlag()){
		    game()->changScene(GAME::STAGE2_ID);
		}
	}

	else if (game()->player()->hp()<=0) {
	     game()->transition()->outTrigger();
	     if (game()->transition()->outEndFlag()) {
			  game()->changScene(GAME::GAME_OVER_ID);
		 }
	}
}
int STAGE1::no() {
	return Stage1.no;
}
