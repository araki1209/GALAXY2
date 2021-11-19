#include "PLAYER.h"
#include"GAME.h"
#include"libOne.h"
#include"CONTAINER.h"
PLAYER::PLAYER(class GAME* game):
	GAME_OBJ(game) {
}
void PLAYER::create(){
	Player = game()->container()->player();
}
void PLAYER::init() {
	Player.pos = game()->container()->player().pos;
}
int PLAYER::normlize(float x,float y){
        VECTOR2 tmp;
	    int mag = sqrt(x * x + y * y);
		tmp.x = x / mag;
	    tmp.y = y / mag;
		return tmp.x, tmp.y;
	}
void PLAYER::update() {
	move();
	launch();
}
void PLAYER::move() {
	//Player.adv.x = Player.advSpeed;
	//Player.adv.y = Player.advSpeed;
	//Player.nor = normlize(Player.adv.x, Player.adv.y);
	//Player.pos.x += Player.nor.x * delta;
	//Player.pos.y += Player.nor.y * delta;
	if (isPress(KEY_A) && Player.pos.x >Player.phW) {
		Player.pos.x -= Player.advSpeed*delta;
	}
    if (isPress(KEY_D) && Player.pos.x < width - Player.phW) {
		//Player.pos.x += Player.advSpeed * delta;
		Player.pos.x += Player.advSpeed * delta;
	}
	if (isPress(KEY_W) && Player.pos.y > Player.phH) {
		//Player.pos.y -= Player.advSpeed * delta;
		Player.pos.y -= Player.advSpeed * delta;
	}
	if (isPress(KEY_S) && Player.pos.y < height - Player.phH) {
		//Player.pos.y += Player.advSpeed * delta;
		Player.pos.y += Player.advSpeed * delta;
	}
	
}

void PLAYER::launch() {

}
void PLAYER::draw() {
	//imageColor(Player.color);
	rectMode(CENTER);
	image(Player.img, Player.pos.x, Player.pos.y, Player.angle,0.05f);
}
