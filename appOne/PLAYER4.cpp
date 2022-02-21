#include "PLAYER4.h"
#include"GAME.h"
#include"libOne.h"
#include"P_BULLETS.h"
#include"E_BULLETS.h"
#include"HP_GAUGE.h"
#include"CONTAINER.h"
PLAYER4::PLAYER4(class GAME* game) :
	GAME_OBJ(game) {
}
void PLAYER4::create() {
	Player4 = game()->container()->player4();
}
void PLAYER4::init() {
	Player4.pos = game()->container()->player4().pos;
	Player4.hp = game()->container()->player4().hp;
	Player4.color = Player4.normalColor;
}
int PLAYER4::normlize(float x, float y) {
	VECTOR2 tmp;
	int mag = sqrt(x * x + y * y);
	tmp.x = x / mag;
	tmp.y = y / mag;
	return tmp.x, tmp.y;
}
void PLAYER4::update() {
	//if (game()->PLAYER4()->hp() > 0) {
	move();
	launch();
	collision();
	//}
}
void PLAYER4::move() {
	if (Player4.hp > 0) {
		if (isPress(KEY_A) && Player4.pos.x > Player4.phW) {
			Player4.pos.x -= Player4.advSpeed * delta;
		}
		if (isPress(KEY_D) && Player4.pos.x < width - Player4.phW) {
			Player4.pos.x += Player4.advSpeed * delta;
		}
		if (isPress(KEY_W) && Player4.pos.y > Player4.phH) {
			Player4.pos.y -= Player4.advSpeed * delta;
		}
		if (isPress(KEY_S) && Player4.pos.y < height - Player4.phH) {
			Player4.pos.y += Player4.advSpeed * delta;
		}
	}
}

void PLAYER4::launch() {
	if (Player4.hp > 0) {
		if (isPress(KEY_SPACE)) {
			Player4.triggerErapsedTime += delta;
			if (Player4.triggerErapsedTime >= Player4.triggerInterval) {
				VECTOR2 pos = Player4.pos + Player4.launchVec * Player4.ofsLaunchDist;
				game()->playerBullets()->launch(pos, Player4.launchVec);
				Player4.triggerErapsedTime = 0;
			}
		}
		else {
			Player4.triggerErapsedTime = Player4.triggerInterval;
		}
	}
}
void PLAYER4::collision() {
	if (Player4.invincibleRestTime > 0) {
		Player4.invincibleRestTime -= delta;
	}
	else {
		Player4.color = (Player4.normalColor);
		E_BULLETS* bullets = game()->enemyMBullets();
		float distance = Player4.bcRadius + bullets->bRadius();
		float sqDistance = distance * distance;
		for (int i = bullets->curNum() - 1; i >= 0; i--) {
			VECTOR2 vec = Player4.pos - bullets->pos(i);
			if (Player4.invincibleRestTime <= 0 &&
				sqLength(vec) < sqDistance) {
				if (Player4.hp > 0) {
					Player4.hp--;
				}
				Player4.invincibleRestTime = Player4.invincibleTime;
				Player4.color = (Player4.collisionColor);
				bullets->kill(i);
				i = 0;
			}
		}
	}
}
void PLAYER4::draw() {
	imageColor(Player4.color);
	rectMode(CENTER);
	image(Player4.img, Player4.pos.x, Player4.pos.y, Player4.angle, 0.1f);
	game()->hpGauge()->draw(Player4.pos, Player4.hpGaugeOfst, Player4.hp);
}


