#pragma once
#include "GAME_OBJ.h"
#include"libOne.h"
class ENEMYb :
    public GAME_OBJ
{
public:
    struct DATA {
        int img;
        VECTOR2 cenPos;
        int totalNum;
        int curNum;
        float advSpeed;
        float limX;
        float triggerInterval;
        float refWidth;
        float ofsLaunch;
        int initHp;
        //当たり判定
        float bcRadius;
        float invincibleTime;
        float ofsLaunchDist;
        VECTOR2 hpGaugeOfst;
        COLOR collisionColor;
        COLOR normalColor;
    };
    //共通データ
    DATA EnemyB;
    //個別データ
    struct ENEMY {
        VECTOR2 pos;
        float ofsWidth;
        float ofsHeight;
        float triggerErapsedTime;
        float invincibleRestTime;
        int hp;
        COLOR color;
    };
    ENEMY* Enemies;
public:
    ENEMYb(class GAME* game);
    ~ENEMYb();
    void create();
    void init();
    void update();
    void move();
    void launch();
    void collision();
    void draw();
    //ゲッター
    int curNum() { return EnemyB.curNum; }
};

