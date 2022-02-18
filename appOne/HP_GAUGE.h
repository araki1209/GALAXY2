#pragma once
#include "GAME_OBJ.h"
#include"libOne.h"
class HP_GAUGE :
    public GAME_OBJ
{
public:
    struct DATA {
        COLOR safeColor;
        COLOR dangerColor;
        float coWidth;
        float hi;
    };
private:
    DATA HpGauge;
public:
    HP_GAUGE(class GAME* game);
    void create();
    void draw(VECTOR2 pos, VECTOR2 ofst, int hp);
};

