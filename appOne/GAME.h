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
	class TRANSITION* transition() { return Transition; }
private:
	class SCENE * Scenes[NUM_SCENES];
	SCENE_ID CurSceneId;
	class TRANSITION* Transition = nullptr;
public:
	GAME();
	~GAME();
	void run();
	void changScene(SCENE_ID sceneId);
};

