#pragma once
#include"GAME.h"
#include"TITLE.h"
#include"GAME_CLEAR.h"
#include"GAME_OVER.h"
#include"TRANSITION_FADE.h"
class CONTAINER
{
	struct DATA {
		TITLE::DATA title;
		GAME_CLEAR::DATA game_clear;
		GAME_OVER::DATA game_over;
		TRANSITION_FADE::DATA transition_fade;
	};
	DATA Data;
public:
	void load();
	void loadGraphics();
	void setData();
	const TITLE::DATA& title() { return Data.title; }
	const GAME_CLEAR::DATA& game_clear(){ return Data.game_clear; }
	const GAME_OVER::DATA& game_over() { return Data.game_over; }
	const TRANSITION_FADE::DATA& transition_fade() { return Data.transition_fade; }
};

