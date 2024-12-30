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

	// player run left
	extern std::vector<std::string> PATH_PLAYER_RUN_LEFT;
	// player run right
	extern std::vector<std::string> PATH_PLAYER_RUN_RIGHT;
}

#endif // DATA_H