#pragma once
#include"GAME.h"
#include"TITLE.h"
#include"GAME_CLEAR.h"
#include"GAME_OVER.h"
#include"BACK_IMG.h"
#include"PLAYER.h"
#include"PLAYER2.h"
#include"ENEMYm.h"
#include"ENEMYb.h"
#include "BULLETS.h"
#include"BOSS.h"
#include"STAGE1.h"
#include"HP_GAUGE.h"
#include"PLAYERCHANGE.h"
#include"TRANSITION_FADE.h"
class CONTAINER
{
	struct DATA {
		TITLE::DATA title;
		STAGE1::DATA stage1;
		GAME_CLEAR::DATA game_clear;
		GAME_OVER::DATA game_over;
		BACK_IMG::DATA back_img;
		PLAYERCHANGE::DATA pchange;

		PLAYER::DATA player;
		PLAYER2::DATA player2;
		ENEMYm::DATA enemyM;
		ENEMYb::DATA enemyB;
		BOSS::DATA boss;

		BULLETS::DATA playerBullet;
		BULLETS::DATA enemyMBullet;

		HP_GAUGE::DATA hpGauge;
		TRANSITION_FADE::DATA transition_fade;
	};
	DATA Data;
public:
	void load();
	void loadGraphics();
	void setData();

	const TITLE::DATA& title() { return Data.title; }
	const STAGE1::DATA& stage1() { return Data.stage1; }
	const GAME_CLEAR::DATA& game_clear(){ return Data.game_clear; }
	const GAME_OVER::DATA& game_over() { return Data.game_over; }

	const BACK_IMG::DATA& back_img() { return Data.back_img; }

	const PLAYERCHANGE::DATA& playerchange() { return Data.pchange; }

	const PLAYER::DATA& player() { return Data.player; }
	const PLAYER2::DATA& player2() { return Data.player2; }
	const ENEMYm::DATA& enemyM() { return Data.enemyM; }
	const ENEMYb::DATA& enemyB() { return Data.enemyB; }
	const BOSS::DATA& boss() { return Data.boss; }

	const BULLETS::DATA& playerBullet() { return Data.playerBullet; }
	const BULLETS::DATA& enemyMBullet() { return Data.enemyMBullet; }

	const HP_GAUGE::DATA& hpGauge() { return Data.hpGauge; }
	const TRANSITION_FADE::DATA& transition_fade() { return Data.transition_fade; }
};

