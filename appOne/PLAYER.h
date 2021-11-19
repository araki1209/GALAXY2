#pragma once
#include "GAME_OBJ.h"
#include"libOne.h"
class PLAYER :
    public GAME_OBJ
{
public:
    struct DATA {
        int img;
        int hp;
        float phW;
        float phH;
        VECTOR2 pos;
        VECTOR2 adv;
        VECTOR2 nor;
        COLOR color;
        float advSpeed;
        float angle;
    };
private:
     DATA Player;
public:
    PLAYER(class GAME* game);
    void create();
    void init();
    void update();
      void move();
      int normlize(float x,float y);
      void launch();
    void draw();
};

