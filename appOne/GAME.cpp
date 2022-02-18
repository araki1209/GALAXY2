#include"common.h"
#include"framework.h"
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
#include"PLAYER2.h"
#include"P_BULLETS.h"
#include"ENEMYm.h"
#include"ENEMYb.h"
#include"BOSS.h"
#include"E_BULLETS.h"
#include"PLAYERCHANGE.h"
#include"HP_GAUGE.h"
#include "GAME.h"

#define _1
#ifdef _1
GAME::GAME(){
    Container = new CONTAINER;
    Title = new TITLE(this);
    Scenes[TITLE_ID] = new TITLE(this);
    Scenes[STAGE1_ID] = new STAGE1(this);
    Scenes[STAGE2_ID] = new STAGE2(this);
    Scenes[STAGE3_ID] = new STAGE3(this);
    Scenes[GAME_CLEAR_ID] = new GAME_CLEAR(this);
    Scenes[GAME_OVER_ID] = new GAME_OVER(this);


    Back_img = new BACK_IMG(this);

    Transition = new TRANSITION_FADE(this);

    Player = new PLAYER(this);
    Player2 = new PLAYER2(this);
    PlayerBullets = new P_BULLETS(this);

    EnemiesM = new ENEMYm(this);
    EnemiesB = new ENEMYb(this);
    Bosses = new BOSS(this);
    EnemyMBullets = new E_BULLETS(this);
    Playerchange = new PLAYERCHANGE(this);
    HpGauge = new HP_GAUGE(this);


}
GAME::~GAME(){
    for (int i = 0; i < NUM_SCENES; i++) {
        delete Scenes[i];
    }
    delete Back_img;
    delete Transition;

    delete Player;
    delete Player2;
    delete PlayerBullets;
    delete EnemiesM;
    delete EnemiesB;
    delete Bosses;
    delete EnemyMBullets;
    delete Playerchange;
    delete HpGauge;

    delete Container;
}
void GAME::run() {
    window(1920, 1080, full);

    Container->load();
    Container->loadGraphics();
    Scenes[TITLE_ID]->create();
    Scenes[GAME_CLEAR_ID]->create();
    Scenes[GAME_OVER_ID]->create();

    Transition->create();
    HpGauge->create();

   
    Player->create();
    Player2->create();
    EnemiesM->create();
    EnemiesB->create();
    Bosses->create();

    PlayerBullets -> create();
    EnemyMBullets->create();
    
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
}
STAGE1* GAME::stage1() {
    return dynamic_cast<STAGE1*>(Scenes[STAGE1_ID]);
}
#endif