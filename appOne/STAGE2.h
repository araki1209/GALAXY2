#pragma once
#include "SCENE.h"
class STAGE2 :
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
        int no;
    };
private:
    struct DATA Stage2;
public:
    STAGE2(class GAME*game);
    ~STAGE2();
    void init();
    void update();
    void draw();
    void nextScene();
};

