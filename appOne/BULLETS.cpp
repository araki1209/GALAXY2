#include "BULLETS.h"
#include"PLAYER.h"
#include"GAME.h"
BULLETS::BULLETS(class GAME* game) :
	GAME_OBJ(game) {
}
BULLETS::~BULLETS() {
}
void BULLETS::SetBullets(const BULLETS::DATA& data) {
	Bullet = data;
	Bullets = new BULLET[Bullet.totalNum];
}
void BULLETS::init() {
	Bullet.curNum = 0;
}
void BULLETS::launch(const VECTOR2& pos, const VECTOR2& vec) {
	if (Bullet.curNum < Bullet.totalNum) {
		int i = Bullet.curNum;
		Bullets[i].pos = pos;
		Bullets[i].vec = vec;
		Bullets[i].angle = 0;
		Bullet.curNum++;
	}
}
void BULLETS::update() {
		for (int i = Bullet.curNum - 1; i >= 0; i--) {
			Bullets[i].pos += Bullets[i].vec * (Bullet.advSpeed * delta);
			Bullets[i].angle += Bullet.angSpeed * delta;
			if (Bullets[i].pos.y<-Bullet.bRadius ||
				Bullets[i].pos.y>height + Bullet.bRadius ||
				Bullets[i].pos.x<-Bullet.bRadius ||
				Bullets[i].pos.x>width + Bullet.bRadius) {
				kill(i);
			}
		}
}
void BULLETS::kill(int i) {
	Bullet.curNum--;
	Bullets[i] = Bullets[Bullet.curNum];
}
void BULLETS::draw() {
	for (int i = 0; i < Bullet.curNum; i++) {
		image(Bullet.img, Bullets[i].pos.x, Bullets[i].pos.y, Bullets[i].angle, 0.05);
	}
}