#include "HP_GAUGE.h"
#include"GAME.h"
#include"CONTAINER.h"
HP_GAUGE::HP_GAUGE(class GAME* game) :
	GAME_OBJ(game) {
}
void HP_GAUGE::create() {
	HpGauge = game()->container()->hpGauge();
}
void HP_GAUGE::draw(VECTOR2 pos, VECTOR2 ofst, int hp) {
	if (hp > 1) {
		fill(HpGauge.safeColor);
	}
	else {
		fill(HpGauge.dangerColor);
	}
	pos += ofst;
	rect(pos.x, pos.y, hp * HpGauge.coWidth, HpGauge.hi);
}
