#pragma once
class GAME
{
//�R���e�i
private:
	class CONTAINER* Container;
public:
	class CONTAINER* container() { return Container; }
//�V�[��
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
private:
	class SCENE* Scenes[NUM_SCENES];
	SCENE_ID CurSceneId;
	class TRANSITION* Transition = nullptr;
public:
	void changScene(SCENE_ID sceneId);
	class TRANSITION* transition() { return Transition; }
//�L�����N�^�[
private:
	class PLAYER* Player;
public:
	void draw();
	class PLAYER* player() { return Player; }
public:
	GAME();
	~GAME();
	void run();
};

