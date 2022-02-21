#pragma once
#include "GAME_OBJ.h"
#include"libOne.h"
class PLAYER4 :
    public GAME_OBJ
{
public:
    struct DATA {
        int img;
        float phW;
        float phH;
        VECTOR2 pos;
        VECTOR2 adv;
        VECTOR2 nor;
        float advSpeed;
        float angle;
        //launch
        VECTOR2 launchVec;
        float triggerErapsedTime;
        float triggerInterval;
        float ofsLaunchDist;
        //colision
        float bcRadius;
        float invincibleTime;
        float invincibleRestTime;
        int hp;
        VECTOR2 hpGaugeOfst;
        COLOR collisionColor;
        COLOR normalColor;
        COLOR color;
    };
private:
    DATA Player4;
public:
    PLAYER4(class GAME* game);
    void create();
    void init();
    void update();
    void move();
    void collision();
    int normlize(float x, float y);
    void launch();
    void draw();
    VECTOR2 pos() { return Player4.pos; }
    int hp() { return Player4.hp; }
};

