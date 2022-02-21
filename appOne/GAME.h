#pragma once
class GAME
{
//コンテナ
private:
	class CONTAINER* Container;
public:
	class CONTAINER* container() { return Container; }
//シーン
public:
	enum SCENE_ID {
		TITLE_ID,
		STAGE1_ID,
		STAGE2_ID,
		STAGE3_ID,
		GAME_CLEAR_ID,
		GAME_OVER_ID,
		NUM_SCENES
	};
//キャラ
public:
	enum PLAYER_ID {
		PLAYER1_ID = 1,
		PLAYER2_ID=2,
		PLAYER3_ID=3,
		PLAYER4_ID=4,
		NUM_PLAYER=4
	};
private:
	class SCENE* Scenes[NUM_SCENES];
	class ANIM* Anims[NUM_PLAYER];
	SCENE_ID CurSceneId;
	PLAYER_ID CurPlayerId;
	class BACK_IMG * Back_img = 0;
	class TRANSITION* Transition = nullptr;
	
public:
	void changScene(SCENE_ID sceneId);
	class BACK_IMG* back_img() { return Back_img; }
	class TRANSITION* transition() { return Transition; }
	class STAGE1* stage1();
//キャラクター
private:
	class PLAYER* Player;
	class PLAYER2* Player2;
	class PLAYER3* Player3;
	class PLAYER4* Player4;
	class P_BULLETS* PlayerBullets;
	class ENEMYm* EnemiesM;
	class ENEMYb* EnemiesB;
	class E_BULLETS* EnemyMBullets;
	class BOSS* Bosses;
	class TITLE* Title;
	class PLAYERCHANGE* Playerchange;
	class HP_GAUGE* HpGauge;
public:
	void draw();
	class PLAYER* player() { return Player; }
	class PLAYER2* player2() { return Player2; }
	class PLAYER3* player3() { return Player3; }
	class PLAYER4* player4() { return Player4; }
	class P_BULLETS* playerBullets() { return PlayerBullets; }
	class ENEMYm * enemiesM() { return EnemiesM; }
	class ENEMYb* enemiesB() { return EnemiesB; }
	class BOSS* bosses() { return Bosses; }
	class E_BULLETS* enemyMBullets() { return EnemyMBullets; }
	class HP_GAUGE* hpGauge() { return HpGauge; }
	class TITLE* title() { return Title; }
	class PLAYERCHANGE* playerchange() { return Playerchange; }
public:
	GAME();
	~GAME();
	void run();
};

