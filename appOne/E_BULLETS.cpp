#include "E_BULLETS.h"
#include"GAME.h"
#include"CONTAINER.h"
E_BULLETS::E_BULLETS(class GAME* game) :
	BULLETS(game) {
}
void E_BULLETS::create() {
	SetBullets(game()->container()->enemyMBullet());
}
