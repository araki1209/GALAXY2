#pragma once
#include "GAME_OBJ.h"
#include"libOne.h"
class BOSS :
    public GAME_OBJ
{
public:
    struct DATA {
        int img;
        int totalNum;
        int curNum;
        VECTOR2 cenPos;
        VECTOR2 mmntPos;
        float advSpeedX;
        float advSpeedY;
        float triggerInterval;
        float ofstLaunchDist;
        //collision
        float bcRadius;
        float invincibleTime;
        int initHp;
        VECTOR2 hpGaugeOfst;
        COLOR collisionColor;
        COLOR normalColor;
    };
private:
    //共通データ
    DATA Boss;
    //単体データ配列
    struct BOSSES {
        VECTOR2 pos;
        float ofstTheta;
        float triggerErapsedTime;
        float invincibleRestTime;
        int hp;
        COLOR color;
    };
    BOSSES* Bosses;
public:
    BOSS(class GAME* game);
    ~BOSS();
    void create();
    void init();
    void update();
    void move();
    void launch();
    void collision();
    void draw();
    int curNum() { return Boss.curNum; }
};
