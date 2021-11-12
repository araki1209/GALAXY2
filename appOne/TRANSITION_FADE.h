#pragma once
#include "TRANSITION.h"
#include"libOne.h"
class TRANSITION_FADE :
    public TRANSITION
{
public:
    struct DATA {
        COLOR color;
        float colorMode;
        float time;
        VECTOR2 pos1;
        VECTOR2 pos2;
    };
private:
    DATA Transition;
public:
    TRANSITION_FADE(class GAME* game);
    void create();
    void inTriggerProc();
    bool inProc();
    void outTriggerProc();
    bool outProc();
};

