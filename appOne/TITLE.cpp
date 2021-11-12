#include"libOne.h"
#include"CONTAINER.h"
#include "TITLE.h"
#include"GAME.h"
#include"TRANSITION.h"
TITLE::TITLE(class GAME* game) :
	SCENE(game){
}
TITLE::~TITLE(){
}
void TITLE::init() {
	game()->transition()->inTrigger();
}
void TITLE::create() {
	Title = game()->container()->title();
}
void TITLE:: draw(){
	clear(Title.backColor);
	fill(Title.textColor);
    textSize(Title.textSize);
	//text(Title.str,Title.pos.x,Title.pos.y);
	image(Title.img, 0, 0,0,1);
	game()->transition()->draw();
}
void TITLE::nextScene(){
	if (isTrigger(KEY_Z)) {
		game()->transition()->outTrigger();
	}
	if (game()->transition()->outEndFlag()) {
		game()->changScene(GAME::STAGE1_ID);	
	}
}
