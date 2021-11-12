#pragma once
#include "SCENE.h"
class GAME_OVER :
    public SCENE
{
public:
    struct DATA {
        int ima;
        VECTOR2 pos;
    };
private:
    struct DATA Game_over;
public:
    GAME_OVER(class GAME* game);
    ~GAME_OVER();
    void draw();
    void create();
    void nextScene();
};
