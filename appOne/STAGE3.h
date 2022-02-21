#pragma once
#include "SCENE.h"
class STAGE3 :
    public SCENE
{
public:
public:
    struct DATA {
        int img;
        int p1;
        int p2;
        int p3;
        int p4;
        int ep;
    };
private:
    struct DATA Stage3;
public:
    STAGE3(class GAME* game);
    ~STAGE3();
    void init();
    void update();
    void draw();
    void nextScene();
};

