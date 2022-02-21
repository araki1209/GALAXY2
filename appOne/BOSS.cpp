#include "BOSS.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"E_BULLETS.h"
#include"P_BULLETS.h"
BOSS::BOSS(class GAME* game) :
	GAME_OBJ(game) {
}
BOSS::~BOSS() {
	delete[]Bosses;
}
void BOSS::create() {
	Boss = game()->container()->boss();
	Bosses = new BOSSES[Boss.totalNum];
}
void BOSS::init() {
	Boss.cenPos.x = width / 2;
	Boss.cenPos.y = 100;
	float divInterval = Boss.triggerInterval / Boss.totalNum;
	for (int i = 0; i < Boss.totalNum; i++) {
		Bosses[i].triggerErapsedTime = divInterval * i;
		Bosses[i].invincibleRestTime = 0;
		Bosses[i].hp = Boss.initHp;
	}
	Boss.curNum = Boss.totalNum;
}
void BOSS::update() {
	move();
	launch();
	collision();
}
void BOSS::move() {
	for (int i = 0; i < Boss.curNum; i++) {
		Bosses[i].pos.x += Boss.advSpeedX * delta;
		Bosses[i].pos.y += Boss.advSpeedY * delta ;
		if (Bosses[i].pos.x >= width|| Bosses[i].pos.x <= 0) {
			Boss.advSpeedX = Boss.advSpeedX * -1;
		}
		if (Bosses[i].pos.y <= 0 || Bosses[i].pos.y >= height/2) {
			Boss.advSpeedY = Boss.advSpeedY * -1;
		}
	}
}
void BOSS::launch() {
	VECTOR2 playerPos = game()->player()->pos();
	for (int i = 0; i < Boss.curNum; i++) {
		Bosses[i].triggerErapsedTime += delta;
		if (Bosses[i].triggerErapsedTime >= Boss.triggerInterval) {
			VECTOR2 launchVec = normalize(playerPos - Bosses[i].pos);
			VECTOR2 pos = Bosses[i].pos + launchVec * Boss.ofstLaunchDist;
			game()->enemyMBullets()->launch(pos, launchVec);
			Bosses[i].triggerErapsedTime = 0;
		}
	}
}
void BOSS::collision() {
	BULLETS* bullets = game()->playerBullets();
	float distance = Boss.bcRadius + bullets->bRadius();
	float sqDistance = distance * distance;
	for (int j = Boss.curNum - 1; j >= 0; j--) {

		if (Bosses[j].invincibleRestTime > 0) {
			Bosses[j].invincibleRestTime -= delta;
		}
		else {
			Bosses[j].color = (Boss.normalColor);
			for (int i = bullets->curNum() - 1; i >= 0; i--) {
				VECTOR2 vec = Bosses[j].pos - bullets->pos(i);
				if (sqLength(vec) < sqDistance) {
					Bosses[j].hp--;
					Bosses[j].invincibleRestTime = Boss.invincibleTime;
					Bosses[j].color = (Boss.collisionColor);
					if (Bosses[j].hp <= 0) {
						Boss.curNum--;
						Bosses[j] = Bosses[Boss.curNum];
					}
					bullets->kill(i);
					i = 0;
				}
			}
		}
	}
}
void BOSS::draw() {
	for (int i = 0; i < Boss.totalNum; i++) {
		image(Boss.img, Bosses[i].pos.x, Bosses[i].pos.y, 0, 0.7);
		game()->hpGauge()->draw(Bosses[i].pos, Boss.hpGaugeOfst, Bosses[i].hp);

	}
}
