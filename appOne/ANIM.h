#pragma once
#include "GAME_OBJ.h"
#include"libOne.h"
class ANIM :
    public GAME_OBJ
{
public:
    ANIM(class GAME* game);
    virtual void create();
    virtual void init();
    virtual void update();
    virtual void move();
    virtual void collision();
    virtual void launch();
    virtual void draw();
};

