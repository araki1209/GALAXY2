#pragma once
#include "SCENE.h"
class STAGE3 :
    public SCENE
{
public:
    STAGE3(class GAME* game);
    ~STAGE3();
    void init();
    void update();
    void draw();
    void nextScene();
};

