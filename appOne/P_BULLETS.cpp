#include "P_BULLETS.h"
#include"GAME.h"
#include"CONTAINER.h"
P_BULLETS::P_BULLETS(class GAME* game) :
	BULLETS(game) {
}
void P_BULLETS::create() {
	SetBullets(game()->container()->playerBullet());
}
