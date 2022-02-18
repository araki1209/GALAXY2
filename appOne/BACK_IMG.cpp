#include "BACK_IMG.h"
#include"libOne.h"
#include"GAME.h"
BACK_IMG::BACK_IMG(class GAME* game) :
	GAME_OBJ(game) {
}
BACK_IMG::~BACK_IMG() {
}
void BACK_IMG::init() {
}
void BACK_IMG::draw() {
	clear();
	fill(B_img.normalColor);\
	rectMode(CENTER);
	if (game()->GAME::STAGE1_ID) {
		image(B_img.img1, width/2, height/2, 0);
	}
	else if (game()->GAME::STAGE2_ID) {
		image(B_img.img1, width/2, height/2, 0);
	}
	else if (game()->GAME::STAGE3_ID) {
		image(B_img.img1, width / 2, height / 2, 0);
	}
}
