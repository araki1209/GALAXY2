#pragma once
class GAME_OBJ
{
private:
	class GAME* Game = 0;
public:
	GAME_OBJ(class GAME* game);
	virtual ~GAME_OBJ();
	class GAME* game() {
		return Game;
	}
};

