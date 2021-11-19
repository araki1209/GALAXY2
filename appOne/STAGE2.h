#pragma once
#include "SCENE.h"
class STAGE2 :
    public SCENE
{
public:
    STAGE2(class GAME*game);
    ~STAGE2();
    void init();
    void update();
    void draw();
    void nextScene();
};

