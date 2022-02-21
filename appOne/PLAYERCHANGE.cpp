#include "PLAYERCHANGE.h"
#include"libOne.h"
#include"GAME.h"
#include"CONTAINER.h"
PLAYERCHANGE::PLAYERCHANGE(class GAME* game):
	GAME_OBJ(game) {
}
void PLAYERCHANGE::create(){}
void PLAYERCHANGE::init(){
	pc.P1 = 0;
	pc.P2 = 1;
}
void PLAYERCHANGE::pchange(){
	if (isPress(KEY_Z)) {
		pc.pData = pc.P1;
	}
	if (isPress(KEY_X)) {
		pc.pData = pc.P2;
	}
}