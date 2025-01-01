#pragma once
#ifndef DATA_H
#define DATA_H


#include "stdio.h"
#include "BanGame.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
#include <chrono>
#include <thread>

namespace BanZ
{
	// ============== SCREEN ==============
	const int WIDTH = 1280;
	const int HEIGHT = 800;

	// ============== MAP ==============
	const int MAX_MAP_X = 69;
	const int MAX_MAP_Y = 26;
	const int BLOCK_SIZE = 32;
	const int MAX_MAP_FORMAT = 12;

	// ============== Num Animation ==============
	enum PLAYERSTATE
	{
		IDLE_LEFT,
		IDLE_RIGHT,
		RUN_LEFT,
		RUN_RIGHT
	};

	// ============== PATH ==============
	extern std::string PATH_BACKGROUND;
	extern std::string PATH_MAP_FORMAT;
	extern const char* PATH_MAP_IMG;

	extern std::string PATH_PLAYER_RUN_LEFT;
	extern std::string PATH_PLAYER_RUN_RIGHT;
	extern std::string PATH_PLAYER_IDLE_LEFT;
	extern std::string PATH_PLAYER_IDLE_RIGHT;

	// ============== PLAYER ==============
	extern int WIDTH_FRAME;
	extern int HEIGHT_FRAME;
	extern float MAX_GRAVITY;
	extern float SPEED_GRAVITY;
	extern float SPEED_PLAYER;
	extern float JUMP_FORCE;

	extern float FPS;


	// ============== Input ==============
	typedef struct
	{
		int idle;
		int left;
		int right;
		int up;
		int down;
		int jump;
	} Input;
}

#endif // DATA_H