#pragma once
#include "SCENE.h"
class STAGE2 :
    public SCENE
{
public:
    STAGE2(class GAME*game);
    ~STAGE2();
    void init();
    void draw();
    void nextScene();
};

