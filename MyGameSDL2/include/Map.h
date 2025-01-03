#pragma once

#include "BanGame.h"
using namespace BanZ;

#include "GameObject.h"

namespace BanZ
{
	typedef struct {

		int start_x;
		int start_y;

		int end_x;
		int end_y;

		int status[MAX_MAP_Y][MAX_MAP_X];
		std::string mapFormatPath;


	}MapStruct;

	class ObjectMap : public GameObject
	{
	public:
		ObjectMap() = default;
		~ObjectMap() { ; };
	};

	class Map
	{
	public:
		Map();
		~Map();

		void InitFormat(const std::string& imgPath);
		void InitTile(BanGame* banGame);
		void Update(float deltaTime, BanGame* banGame);
		void Render(BanGame* banGame);

		void SetMapData(MapStruct& mapStruct);
		MapStruct GetMapData();

	private:

		MapStruct dataMap;
		ObjectMap* objMap[MAX_MAP_FORMAT];
		
	};
}
