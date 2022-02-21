#pragma once
#include "SCENE.h"
class STAGE1 :
    public SCENE
{
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
    struct DATA Stage1;
public:
    STAGE1(class GAME* game);
    ~STAGE1();
    void init();
    void create();
    void update();
    void draw();
    void nextScene();
    int no();
};