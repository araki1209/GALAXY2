#pragma once
#include "SCENE.h"
#include"libone.h"
class TITLE :
    public SCENE
{
public:
    struct DATA {
        COLOR backColor;
        COLOR textColor;
        float textSize;
        VECTOR2 pos;
        //char str[16];
        int img;
        int p_data;
    };
private:
    DATA Title;
public:
    TITLE(class GAME* game);
    ~TITLE();
    void init();
    void draw();
    void create();
    void nextScene();
    int p_Data() { return Title.p_data; }
};

