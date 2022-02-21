#include "PLAYER3.h"
#include"GAME.h"
#include"libOne.h"
#include"P_BULLETS.h"
#include"E_BULLETS.h"
#include"HP_GAUGE.h"
#include"CONTAINER.h"
PLAYER3::PLAYER3(class GAME* game) :
	GAME_OBJ(game) {
}
void PLAYER3::create() {
	Player3 = game()->container()->player3();
}
void PLAYER3::init() {
	Player3.pos = game()->container()->player3().pos;
	Player3.hp = game()->container()->player3().hp;
	Player3.color = Player3.normalColor;
}
int PLAYER3::normlize(float x, float y) {
	VECTOR2 tmp;
	int mag = sqrt(x * x + y * y);
	tmp.x = x / mag;
	tmp.y = y / mag;
	return tmp.x, tmp.y;
}
void PLAYER3::update() {
	//if (game()->PLAYER3()->hp() > 0) {
	move();
	launch();
	collision();
	//}
}
void PLAYER3::move() {
	if (Player3.hp > 0) {
		if (isPress(KEY_A) && Player3.pos.x > Player3.phW) {
			Player3.pos.x -= Player3.advSpeed * delta;
		}
		if (isPress(KEY_D) && Player3.pos.x < width - Player3.phW) {
			Player3.pos.x += Player3.advSpeed * delta;
		}
		if (isPress(KEY_W) && Player3.pos.y > Player3.phH) {
			Player3.pos.y -= Player3.advSpeed * delta;
		}
		if (isPress(KEY_S) && Player3.pos.y < height - Player3.phH) {
			Player3.pos.y += Player3.advSpeed * delta;
		}
	}
}

void PLAYER3::launch() {
	if (Player3.hp > 0) {
		if (isPress(KEY_SPACE)) {
			Player3.triggerErapsedTime += delta;
			if (Player3.triggerErapsedTime >= Player3.triggerInterval) {
				VECTOR2 pos = Player3.pos + Player3.launchVec * Player3.ofsLaunchDist;
				game()->playerBullets()->launch(pos, Player3.launchVec);
				Player3.triggerErapsedTime = 0;
			}
		}
		else {
			Player3.triggerErapsedTime = Player3.triggerInterval;
		}
	}
}
void PLAYER3::collision() {
	if (Player3.invincibleRestTime > 0) {
		Player3.invincibleRestTime -= delta;
	}
	else {
		Player3.color = (Player3.normalColor);
		E_BULLETS* bullets = game()->enemyMBullets();
		float distance = Player3.bcRadius + bullets->bRadius();
		float sqDistance = distance * distance;
		for (int i = bullets->curNum() - 1; i >= 0; i--) {
			VECTOR2 vec = Player3.pos - bullets->pos(i);
			if (Player3.invincibleRestTime <= 0 &&
				sqLength(vec) < sqDistance) {
				if (Player3.hp > 0) {
					Player3.hp--;
				}
				Player3.invincibleRestTime = Player3.invincibleTime;
				Player3.color = (Player3.collisionColor);
				bullets->kill(i);
				i = 0;
			}
		}
	}
}
void PLAYER3::draw() {
	imageColor(Player3.color);
	rectMode(CENTER);
	image(Player3.img, Player3.pos.x, Player3.pos.y, Player3.angle, 0.1f);
	game()->hpGauge()->draw(Player3.pos, Player3.hpGaugeOfst, Player3.hp);
}


