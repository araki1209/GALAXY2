#include"libOne.h"
#include"TITLE.h"
#include"STAGE1.h"
#include"STAGE2.h"
#include"STAGE3.h"
#include"GAME_CLEAR.h"
#include"GAME_OVER.h"
#include"CONTAINER.h"
#include"TRANSITION.h"
#include"PLAYER.h"
#include "GAME.h"

#define _1
#ifdef _1
GAME::GAME(){
    Container = new CONTAINER;
    Scenes[TITLE_ID] = new TITLE(this);
    Scenes[STAGE1_ID] = new STAGE1(this);
    Scenes[STAGE2_ID] = new STAGE2(this);
    Scenes[STAGE3_ID] = new STAGE3(this);
    Scenes[GAME_CLEAR_ID] = new GAME_CLEAR(this);
    Scenes[GAME_OVER_ID] = new GAME_OVER(this);

    Transition = new TRANSITION_FADE(this);

    Player = new PLAYER(this);
}
GAME::~GAME(){
    for (int i = 0; i < NUM_SCENES; i++) {
        delete Scenes[i];
    }
    delete Transition;

    delete Player;
}
void GAME::run() {
    window(1920, 1080, full);

    Container->load();
    Container->loadGraphics();
    Scenes[TITLE_ID]->create();
    Scenes[GAME_CLEAR_ID]->create();
    Scenes[GAME_OVER_ID]->create();

    Transition->create();

    Player->create();

    CurSceneId = TITLE_ID;
    Scenes[CurSceneId]->init();
    initDeltaTime();
    
    while (notQuit) {
        setDeltaTime();
        Scenes[CurSceneId]->proc();
    }
}
void GAME::changScene(SCENE_ID sceneId) {
    CurSceneId = sceneId;
    Scenes[CurSceneId]->init();
}
void GAME::draw() {
    clear(255);
    Player-> draw();
}
#endif
#ifdef _2
GAME::GAME() {
    Container = new CONTAINER;
    Scenes[TITLE_ID] = new TITLE(this);
    Scenes[STAGE1_ID] = new STAGE1(this);
    Scenes[STAGE2_ID] = new STAGE2(this);
    Scenes[STAGE3_ID] = new STAGE3(this);
    Scenes[GAME_CLEAR_ID] = new GAME_CLEAR(this);
    Scenes[GAME_OVER_ID] = new GAME_OVER(this);

    Transition = new TRANSITION_FADE(this);
}
GAME::~GAME() {
    delete Transition;
    for (int i = 0; i < NUM_SCENES; i++) {
        delete Scenes[i];
    }
    delete Container;
}
void GAME::run() {
    window(1920, 1080, full);
    hideCursor();

    Container->load();
    Container->loadGraphics();
    Scenes[TITLE_ID]->create();
    Scenes[GAME_CLEAR_ID]->create();
    Scenes[GAME_OVER_ID]->create();
    
    Transition->create();

    CurSceneId = TITLE_ID;
    Scenes[CurSceneId]->init();
    initDeltaTime();
    while (notQuit) {
        setDeltaTime();
        Scenes[CurSceneId]->proc();
    }
}
void GAME::changScene(SCENE_ID sceneid) {
    CurSceneId = sceneid;
    Scenes[CurSceneId]->init();
}
#endif