#include "CONTAINER.h"
#include"libOne.h"
void CONTAINER::load() {
	setData();
}
void CONTAINER::setData() {
	Data.title.backColor = COLOR(0, 0, 0);
	Data.title.textColor = COLOR(0, 255, 0);
	Data.title.textSize = 300;
	Data.title.pos.x = 0;
	Data.title.pos.y = 300;
	//strcpy_s(Data.title.str, "GALAXY");

	Data.game_clear.pos.x = 0;
	Data.game_clear.pos.y = 0;
	//トランジション
	Data.transition_fade.color = COLOR(255, 255, 255);
	Data.transition_fade.color.a = 255;
	Data.transition_fade.pos1.x = 0;
	Data.transition_fade.pos1.y = 0;
	Data.transition_fade.pos2.x = width;
	Data.transition_fade.pos2.y = height;
	Data.transition_fade.colorMode = 255;
	Data.transition_fade.time = 2.0f;

	//プレイヤー
	Data.player.color = (0, 0, 0);
	Data.player.hp = 10;
	Data.player.phW = 35;
	Data.player.phH = 25;
	Data.player.pos.x = width / 2;
	Data.player.pos.y = height - 100;
	Data.player.advSpeed = 300;
	Data.player.adv.x =0;
	Data.player.adv.y = 0;
	Data.player.nor.x = 0;
	Data.player.nor.y = 0;
	Data.player.angle = 0;


}
void CONTAINER::loadGraphics() {
	Data.title.img = loadImage("assets\\haikei.png");
	Data.game_clear.img = loadImage("assets\\adf.png");
	Data.player.img = loadImage("assets\\kitai1.png");
}