#include "PLAYER2.h"
#include"GAME.h"
#include"libOne.h"
#include"P_BULLETS.h"
#include"E_BULLETS.h"
#include"HP_GAUGE.h"
#include"CONTAINER.h"
PLAYER2::PLAYER2(class GAME* game) :
	ANIM(game) {
}
void PLAYER2::create() {
	Player2 = game()->container()->player2();
}
void PLAYER2::init() {
	Player2.pos = game()->container()->player2().pos;
	Player2.hp = game()->container()->player2().hp;
	Player2.color = Player2.normalColor;
}
int PLAYER2::normlize(float x, float y) {
	VECTOR2 tmp;
	int mag = sqrt(x * x + y * y);
	tmp.x = x / mag;
	tmp.y = y / mag;
	return tmp.x, tmp.y;
}
void PLAYER2::update() {
	//if (game()->player2()->hp() > 0) {
		move();
		launch();
		collision();
	//}
}
void PLAYER2::move() {
	if (Player2.hp > 0) {
		if (isPress(KEY_A) && Player2.pos.x > Player2.phW) {
			Player2.pos.x -= Player2.advSpeed * delta;
		}
		if (isPress(KEY_D) && Player2.pos.x < width - Player2.phW) {
			Player2.pos.x += Player2.advSpeed * delta;
		}
		if (isPress(KEY_W) && Player2.pos.y > Player2.phH) {
			Player2.pos.y -= Player2.advSpeed * delta;
		}
		if (isPress(KEY_S) && Player2.pos.y < height - Player2.phH) {
			Player2.pos.y += Player2.advSpeed * delta;
		}
	}
}

void PLAYER2::launch() {
	if (Player2.hp > 0) {
		if (isPress(KEY_SPACE)) {
			Player2.triggerErapsedTime += delta;
			if (Player2.triggerErapsedTime >= Player2.triggerInterval) {
				VECTOR2 pos = Player2.pos + Player2.launchVec * Player2.ofsLaunchDist;
				game()->playerBullets()->launch(pos, Player2.launchVec);
				Player2.triggerErapsedTime = 0;
			}
		}
		else {
			Player2.triggerErapsedTime = Player2.triggerInterval;
		}
	}
}
void PLAYER2::collision() {
	if (Player2.invincibleRestTime > 0) {
		Player2.invincibleRestTime -= delta;
	}
	else {
		Player2.color = (Player2.normalColor);
		E_BULLETS* bullets = game()->enemyMBullets();
		float distance = Player2.bcRadius + bullets->bRadius();
		float sqDistance = distance * distance;
		for (int i = bullets->curNum() - 1; i >= 0; i--) {
			VECTOR2 vec = Player2.pos - bullets->pos(i);
			if (Player2.invincibleRestTime <= 0 &&
				sqLength(vec) < sqDistance) {
				if (Player2.hp > 0) {
					Player2.hp--;
				}
				Player2.invincibleRestTime = Player2.invincibleTime;
				Player2.color = (Player2.collisionColor);
				bullets->kill(i);
				i = 0;
			}
		}
	}
}
void PLAYER2::draw() {
	imageColor(Player2.color);
	rectMode(CENTER);
	image(Player2.img, Player2.pos.x, Player2.pos.y, Player2.angle, 0.1f);
	game()->hpGauge()->draw(Player2.pos, Player2.hpGaugeOfst, Player2.hp);
}

