#pragma once
#include "SCENE.h"
class STAGE1 :
    public SCENE
{
public:
    struct DATA {
    };
public:
    STAGE1(class GAME* game);
    ~STAGE1();
    void init();
    void draw();
    void create();
    void nextScene();
};