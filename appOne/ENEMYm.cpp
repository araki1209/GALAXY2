#define _1

#include"CONTAINER.h"
#include"GAME.h"
#include "ENEMYm.h"
#include"P_BULLETS.h"
#include"E_BULLETS.h"
#include"libOne.h"
#include"HP_GAUGE.h"
#ifdef _1
ENEMYm::ENEMYm(class GAME* game) :
	GAME_OBJ(game) {
}
ENEMYm::~ENEMYm(){
	delete[]Enemies;
}
void ENEMYm::create() {
	EnemyM = game()->container()->enemyM();
	Enemies = new ENEMY[EnemyM.totalNum];
}
void ENEMYm::init() {
	//äeìGÇÃèâä˙âª
	float divTheta = 3.1415926f * 2 / EnemyM.totalNum;
	float divInterval = EnemyM.triggerInterval / EnemyM.totalNum;
	for (int i = 0; i < EnemyM.totalNum; i++) {
		Enemies[i].ofsTheta = divTheta * i;
		Enemies[i].triggerErapsedTime = divInterval * i;
		Enemies[i].invincibleRestTime = 0;
		Enemies[i].hp = EnemyM.initHp;
	}
	EnemyM.curNum = EnemyM.totalNum;
}
void ENEMYm::update() {
	if (game()->player()->hp() > 0) {
		move();
		launch();
		collision();
	}
}
void ENEMYm::move() {
	if (EnemyM.cenPos.y < EnemyM.targetPosY) {
		EnemyM.cenPos.y += EnemyM.fallSpeed * delta;
	}
	for (int i = 0; i < EnemyM.curNum; i++) {
		float theta = EnemyM.refTheta + Enemies[i].ofsTheta;
		float px = EnemyM.cenPos.x + cos(theta) * EnemyM.majRadius;
		float py = EnemyM.cenPos.y + sin(theta) * EnemyM.minRadius;
		Enemies[i].pos.x = px;
		Enemies[i].pos.y = py;
	}
	EnemyM.refTheta += EnemyM.ThetaSpeed * delta;
}
void ENEMYm::launch() {
		VECTOR2 playerPos = game()->player()->pos();
		for (int i = 0; i < EnemyM.curNum; i++) {
			Enemies[i].triggerErapsedTime += delta;
			if (Enemies[i].triggerErapsedTime >= EnemyM.triggerInterval) {
				VECTOR2 launchVec = normalize(playerPos - Enemies[i].pos);
				VECTOR2 pos = Enemies[i].pos + launchVec * EnemyM.ofsLaunchDist;
				game()->enemyMBullets()->launch(pos, launchVec);
				Enemies[i].triggerErapsedTime = 0;
			}
		}
}
void ENEMYm::collision() {
	BULLETS* bullets = game()->playerBullets();
	float distance = EnemyM.bcRadius + bullets->bRadius();
	float sqDistance = distance * distance;
	for (int j = EnemyM.curNum - 1; j >= 0; j--) {

		if (Enemies[j].invincibleRestTime > 0) {
			Enemies[j].invincibleRestTime -= delta;
		}
		else {
			Enemies[j].color = (EnemyM.normalColor);
			for (int i = bullets->curNum() - 1; i >= 0; i--) {
				VECTOR2 vec = Enemies[j].pos - bullets->pos(i);
				if (sqLength(vec) < sqDistance) {
					Enemies[j].hp--;
					Enemies[j].invincibleRestTime = EnemyM.invincibleTime;
					Enemies[j].color = (EnemyM.collisionColor);
					if (Enemies[j].hp <= 0) {
						EnemyM.curNum--;
						Enemies[j] = Enemies[EnemyM.curNum];
					}
					bullets->kill(i);
					i = 0;
				}
			}
		}
	}
}
void ENEMYm::draw() {
	for (int i = 0; i < EnemyM.curNum; i++) {
		image(EnemyM.img, Enemies[i].pos.x, Enemies[i].pos.y, 0, 2);
		game()->hpGauge()->draw(Enemies[i].pos, EnemyM.hpGaugeOfst, Enemies[i].hp);
	}
}
#endif