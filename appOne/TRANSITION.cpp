#include "TRANSITION.h"
#include"GAME.h"
#define _1
#ifdef _1
TRANSITION::TRANSITION(class GAME* game)
	:GAME_OBJ(game)
	,State(STATE::OUT_END) {
}
TRANSITION::~TRANSITION() {
}
void TRANSITION::inTrigger() {
	if (State == STATE::OUT_END) {
		State = STATE::IN_TRIGGER;
	}
}
void TRANSITION::outTrigger() {
	if (State == STATE::IN_END) {
		State = STATE::OUT_TRIGGER;
	}
}
void TRANSITION::draw() {
	if (State == STATE::IN_END ||
		State == STATE::OUT_END) {
		return;
	}
	switch(State) {
	case STATE::IN_TRIGGER:
	    inTriggerProc();
		State = STATE::IN_NOW;
		break;
	case STATE::IN_NOW:
		if (inProc()) {
			State = STATE::IN_END;
		}
		break;
	case STATE::OUT_TRIGGER:
		outTriggerProc();
		State = STATE::OUT_NOW;
		break;
	case STATE::OUT_NOW:
		if (outProc()) {
			State = STATE::OUT_END;
		}
		break;
	}
}
void TRANSITION::create(){}
void TRANSITION::inTriggerProc(){}
bool TRANSITION::inProc() {
	return true;
}
void TRANSITION::outTriggerProc(){}
bool TRANSITION::outProc() {
	return true;
}
bool TRANSITION::inEndFlag() {
	return(State == STATE::IN_END);
}
bool TRANSITION::outEndFlag() {
	return(State == STATE::OUT_END);
}
#endif
#ifdef _2
TRANSITION::TRANSITION(class GAME* game)
	:GAME_OBJ(game),
	State(STATE::OUT_END) {
}
TRANSITION::~TRANSITION() {
}
void TRANSITION::inTrigger() {
	if (State == STATE::OUT_END) {
		State = STATE::IN_TRIGGER;
	}
}
void TRANSITION::outTrigger() {
	if (State == STATE::IN_END) {
		State = STATE::OUT_TRIGGER;
	}
}
void TRANSITION::draw() {
	if (State == STATE::IN_END ||
		State == STATE::OUT_END) {
		return;
	}
	switch (State) {
	case STATE::IN_TRIGGER:
		inTriggerProc();
		State = STATE::IN_NOW;
		break;
	case STATE::IN_NOW:
		if (inProc()) {
			State = STATE::IN_END;
		}
		break;
	case STATE::OUT_TRIGGER:
		outTriggerProc();
		State = STATE::OUT_NOW;
		break;
	case STATE::OUT_NOW:
		if (outProc()) {
			State = STATE::OUT_END;
		}
		break;
	}
}
//派生クラスでのオーバーロード
void TRANSITION::create() {}
void TRANSITION::inTriggerProc() {}
bool TRANSITION::inProc() {
	return true;
}
void TRANSITION::outTriggerProc() {}
bool TRANSITION::outProc() {
	return true;
}
//inまたはoutが終了したかどうか
bool TRANSITION::inEndFlag() {
	return (State == STATE::IN_END);
}
bool TRANSITION::outEndFlag() {
	return (State == STATE::OUT_END);
}

#endif