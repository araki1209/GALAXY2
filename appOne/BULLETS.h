#pragma once
#include "GAME_OBJ.h"
#include"libOne.h"
class BULLETS :
    public GAME_OBJ
{
public:
    struct DATA {
        int img;
        int totalNum;
        int curNum;
        float advSpeed;
        float angSpeed;
        float bRadius;
    };
private:
    //共通データ
    DATA Bullet;
    //単体データ
    struct BULLET {
        VECTOR2 pos;
        VECTOR2 vec;
        float angle;
    };
    BULLET* Bullets;
protected:
    void SetBullets(const BULLETS::DATA& data);
public:
    BULLETS(class GAME* game);
    ~BULLETS();
    void init();
    void launch(const VECTOR2& pos, const VECTOR2& vec);
    void update();
    void kill(int i);
    void draw();
    VECTOR2 pos(int i) { return Bullets[i].pos; }
    float bRadius() { return Bullet.bRadius; }
    int curNum() { return Bullet.curNum; }
};

