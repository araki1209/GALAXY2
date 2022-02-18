#pragma once
#include "GAME_OBJ.h"
#include"BULLETS.h"
#include"libOne.h"
class P_BULLETS :
    public BULLETS
{
public:
    P_BULLETS(class GAME* game);
    void create();
};

