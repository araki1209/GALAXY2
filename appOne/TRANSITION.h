#pragma once
#include "GAME_OBJ.h"
class TRANSITION :
    public GAME_OBJ
{
private:
    enum class STATE {
        IN_TRIGGER,IN_NOW,IN_END,
        OUT_TRIGGER,OUT_NOW,OUT_END
    };
    STATE State;
public:
    TRANSITION(class GAME* game);
    virtual ~TRANSITION();
    virtual void create();
    void inTrigger();
    void outTrigger();
    void draw();
        virtual void inTriggerProc();
        virtual bool inProc();
        virtual void outTriggerProc();
        virtual bool outProc();
    bool inEndFlag();
    bool outEndFlag();

};


