#pragma once
#include "SCENE.h"
#include"libOne.h"
class GAME_CLEAR :
    public SCENE
{
public:
    struct DATA {
        int img;
        VECTOR2 pos;
    };
private:
    struct DATA Game_clear;
public:
    GAME_CLEAR(class GAME* game);
    ~GAME_CLEAR();
    void create();
    void init();
    void draw();
    void nextScene();
};
