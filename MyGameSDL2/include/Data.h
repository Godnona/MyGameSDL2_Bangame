#pragma once
#ifndef DATA_H
#define DATA_H


#include "stdio.h"
#include "BanGame.h"
#include <iostream>
#include <string>
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

#define PATH_MAP "assets/images/map/Tileset%d.png"

	// ============== PATH ==============
	const std::string PATH_BACKGROUND = "assets/images/map/bg1.png";
	const std::string PATH_MAP_FORMAT = "assets/images/map/mapFormat.txt";
	#define PATH_MAP_IMG "assets/images/map/Tileset%d.png"
}

#endif // DATA_H