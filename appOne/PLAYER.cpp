#include "PLAYER.h"
#include"GAME.h"
#include"libOne.h"
#include"P_BULLETS.h"
#include"E_BULLETS.h"
#include"HP_GAUGE.h"
#include"CONTAINER.h"
PLAYER::PLAYER(class GAME* game):
	ANIM(game) {
}
void PLAYER::create(){
	Player = game()->container()->player();
}
void PLAYER::init() {
	Player.pos = game()->container()->player().pos;
	Player.hp = game()->container()->player().hp;
	Player.color = Player.normalColor;
}
int PLAYER::normlize(float x,float y){
        VECTOR2 tmp;
	    int mag = sqrt(x * x + y * y);
		tmp.x = x / mag;
	    tmp.y = y / mag;
		return tmp.x, tmp.y;
	}
void PLAYER::update() {
	if (game()->player()->hp() > 0) {
		move();
		launch();
		collision();
	}
}
void PLAYER::move() {
	if (Player.hp > 0) {
		if (isPress(KEY_A) && Player.pos.x > Player.phW) {
			Player.pos.x -= Player.advSpeed * delta;
		}
		if (isPress(KEY_D) && Player.pos.x < width - Player.phW) {
			Player.pos.x += Player.advSpeed * delta;
		}
		if (isPress(KEY_W) && Player.pos.y > Player.phH) {
			Player.pos.y -= Player.advSpeed * delta;
		}
		if (isPress(KEY_S) && Player.pos.y < height - Player.phH) {
			Player.pos.y += Player.advSpeed * delta;
		}
	}
}

void PLAYER::launch() {
	if (Player.hp > 0) {
		if (isPress(KEY_SPACE)) {
			Player.triggerErapsedTime += delta;
			if (Player.triggerErapsedTime >= Player.triggerInterval) {
				VECTOR2 pos = Player.pos + Player.launchVec * Player.ofsLaunchDist;
				game()->playerBullets()->launch(pos, Player.launchVec);
				Player.triggerErapsedTime = 0;
			}
		}
		else {
			Player.triggerErapsedTime = Player.triggerInterval;
		}
	}
}
void PLAYER::collision() {
	if (Player.invincibleRestTime > 0) {
		Player.invincibleRestTime -= delta;
	}
	else {
		Player.color = (Player.normalColor);
		E_BULLETS* bullets = game()->enemyMBullets();
		float distance = Player.bcRadius + bullets->bRadius();
		float sqDistance = distance * distance;
		for (int i = bullets->curNum() - 1; i >= 0; i--) {
			VECTOR2 vec = Player.pos - bullets->pos(i);
			if (Player.invincibleRestTime <= 0 &&
				sqLength(vec) < sqDistance) {
				if (Player.hp > 0) {
					Player.hp--;
				}
				Player.invincibleRestTime = Player.invincibleTime;
				Player.color = (Player.collisionColor);
				bullets->kill(i);
				i = 0;
			}
		}
	}
}
void PLAYER::draw() {
	imageColor(Player.color);
	rectMode(CENTER);
	image(Player.img, Player.pos.x, Player.pos.y, Player.angle,0.1f);
	game()->hpGauge()->draw(Player.pos, Player.hpGaugeOfst, Player.hp);
}
