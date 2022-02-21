#include"libOne.h"
#include"CONTAINER.h"
#include "TITLE.h"
#include"ENEMYm.h"
#include"GAME.h"
#include"PLAYERCHANGE.h"
#include"TRANSITION.h"
TITLE::TITLE(class GAME* game) :
	SCENE(game){
}
TITLE::~TITLE(){
}
void TITLE::create() {
	Title = game()->container()->title();
}
void TITLE::init() {
	game()->transition()->inTrigger();
}
void TITLE::draw(){	
	clear(Title.backColor);
	fill(Title.textColor);
    textSize(Title.textSize);
	image(Title.img, 0, 0,0,1);
	game()->transition()->draw();
}
void TITLE::nextScene(){
	if (isTrigger(KEY_Z)) {
		game()->playerchange();
		game()->transition()->outTrigger();
	}
	if (game()->transition()->outEndFlag()) {
		game()->changScene(GAME::STAGE1_ID);
	}
}
