#pragma once
#include "GAME_OBJ.h"
#include "libOne.h"
class BACK_IMG :
    public GAME_OBJ
{
public:
    struct DATA {
        int img1;
        int img2;
        int img3;
        COLOR normalColor;
    };
private:
    struct DATA B_img;
public:
    BACK_IMG(class GAME* game);
    ~BACK_IMG();
    void init();
    void draw();
};

