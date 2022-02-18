#pragma once
#include "GAME_OBJ.h"
class PLAYERCHANGE :
    public GAME_OBJ
{
public:
    struct DATA {
        int P1 = 0;
        int P2 = 1;
        int pData = 0;
    };
    DATA pc;
public:
    PLAYERCHANGE(class GAME* game);
    void pchange();
    int repChange() { return pc.pData;}
};

