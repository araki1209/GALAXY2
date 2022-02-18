#pragma once
#include "GAME_OBJ.h"
#include"libOne.h"
class ENEMYm :
    public GAME_OBJ
{
public:
    struct DATA{
        int img;
        VECTOR2 cenPos;
        int curNum;
        //楕円運動
        int totalNum;
        float majRadius;
        float minRadius;
        float fallSpeed;
        float targetPosY;
        float refTheta;
        float refThetaSpeed;
        //
        float advSpeed;
        float arrivalY;
        float ThetaSpeed;
        float triggerInterval;
        float refWidth;
        float ofsLaunchDist;
        int initHp;
        //当たり判定
        float bcRadius = 0;
        float invincibleTime = 0;
        COLOR collisionColor;
        COLOR normalColor;
        VECTOR2 hpGaugeOfst;

    };
private:
    //共通データ
     DATA EnemyM;
     //単体データ
     struct ENEMY {
         VECTOR2 pos;
         float ofsTheta;
         float ofsWidth;
         float invincibleRestTime;
         float triggerErapsedTime;
         int hp;
         COLOR color;
     };
     ENEMY* Enemies;
public:
    ENEMYm(class GAME* game);
    ~ENEMYm();
    void create();
    void init();
    void update();
       void move();
       void launch();
       void collision();
    void draw();
    //ゲッター
    int curNum() { return EnemyM.curNum; }
};

