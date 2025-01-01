#pragma once

#include "BanGame.h"
using namespace std;

#include "GameObject.h"
#include "Data.h"
#include "Map.h"



class Player : public GameObject
{
public:
	Player();
	~Player();

	void LoadImg(BanGame* banGame, const std::string& imgPath) override;
	void SetFrame();
	
	void HandleInput(BanGame* banGame);
	void Render(BanGame* banGame);

	void Move(MapStruct& map);
	void CheckCollider(MapStruct& map);
	void MoveCamera(MapStruct& map);
	void SetMapXY(const int map_x, const int map_y);

	enum RunType
	{
		RUN_LEFT = -1,
		RUN_RIGHT = 1,
		IDLE_LEFT = 0,
	};

private:
	int width_frame, height_frame;
	int x_pos, y_pos;
	int x_speed, y_speed;

	Input input;
	VECTOR2 sizeFrame[8];
	VECTOR2 posFrame[8];

	int frame;
	int status;
	bool isRight;

	bool isGround;

	int map_x, map_y;
	int comeback_time;

};

