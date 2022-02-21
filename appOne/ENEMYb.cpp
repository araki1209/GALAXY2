#include "ENEMYb.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"E_BULLETS.h"
#include"P_BULLETS.h"
#include"HP_GAUGE.h"
ENEMYb::ENEMYb(class GAME* game) :
	GAME_OBJ(game) {
}
ENEMYb::~ENEMYb() {
	delete[]Enemies;
}
void ENEMYb::create() {
	EnemyB = game()->container()->enemyB();
	Enemies = new ENEMY[EnemyB.totalNum];
}
void ENEMYb::init(){

	float divEnemyPosW = width / EnemyB.totalNum;
	float divEnemyPosH = (height / 2) / EnemyB.totalNum;
	float divInterval = EnemyB.triggerInterval / EnemyB.totalNum;

	for (int i = 0; i < EnemyB.totalNum; i++) {
		Enemies[i].ofsWidth = divEnemyPosW * i;
		Enemies[i].ofsHeight = divEnemyPosH * i;
		Enemies[i].triggerErapsedTime = divInterval;
		Enemies[i].invincibleRestTime = 0;
		Enemies[i].hp = EnemyB.initHp;
	}
	EnemyB.curNum = EnemyB.totalNum;
}
void ENEMYb::update(){
	move();
	launch();
	collision();
}
void ENEMYb::move() {

	for (int i = 0; i < EnemyB.totalNum; i++) {
		
		float px = EnemyB.cenPos.x + Enemies[i].ofsWidth;
		float py = EnemyB.cenPos.y + Enemies[i].ofsHeight;

		Enemies[i].pos.x = px;
		Enemies[i].pos.y = py;

		EnemyB.cenPos.x += EnemyB.advSpeed * delta;


		if (EnemyB.cenPos.x >= EnemyB.limX || EnemyB.cenPos.x <=0) {
			EnemyB.advSpeed = EnemyB.advSpeed * -1;
		}
	}
}
void ENEMYb::launch(){
	VECTOR2 playerPos = game()->player()->pos();
	for (int i = 0; i < EnemyB.curNum; i++) {
		Enemies[i].triggerErapsedTime += delta;
		if (Enemies[i].triggerErapsedTime >= EnemyB.triggerInterval) {
			VECTOR2 launchVec = normalize(playerPos - Enemies[i].pos);
			VECTOR2 pos = Enemies[i].pos + launchVec * EnemyB.ofsLaunchDist;
			game()->enemyMBullets()->launch(pos, launchVec);
			Enemies[i].triggerErapsedTime = 0;
		}
	}
}
void ENEMYb::collision(){
	BULLETS* bullets = game()->playerBullets();
	float distance = EnemyB.bcRadius + bullets->bRadius();
	float sqDistance = distance * distance;
	for (int j = EnemyB.curNum - 1; j >= 0; j--) {

		if (Enemies[j].invincibleRestTime > 0) {
			Enemies[j].invincibleRestTime -= delta;
		}
		else {
			Enemies[j].color = (EnemyB.normalColor);
			for (int i = bullets->curNum() - 1; i >= 0; i--) {
				VECTOR2 vec = Enemies[j].pos - bullets->pos(i);
				if (sqLength(vec) < sqDistance) {
					Enemies[j].hp--;
					Enemies[j].invincibleRestTime = EnemyB.invincibleTime;
					Enemies[j].color = (EnemyB.collisionColor);
					if (Enemies[j].hp <= 0) {
						EnemyB.curNum--;
						Enemies[j] = Enemies[EnemyB.curNum];
					}
					bullets->kill(i);
					i = 0;
				}
			}
		}
	}
}
void ENEMYb::draw(){
	for (int i = 0; i < EnemyB.curNum; i++) {
		image(EnemyB.img, Enemies[i].pos.x, Enemies[i].pos.y, 0, 2);
		game()->hpGauge()->draw(Enemies[i].pos, EnemyB.hpGaugeOfst, Enemies[i].hp);
	}
}