#include "Map.h"

BanZ::Map::Map()
{
	for (int i = 0; i < MAX_MAP_FORMAT; ++i) {
		objMap[i] = new ObjectMap();
	}
}

BanZ::Map::~Map()
{
}

void BanZ::Map::InitFormat(const std::string& filePath)
{
	// ================ Init Size of Map ================

	FILE* file;
	fopen_s(&file, filePath.c_str(), "rb");
	if (file == NULL) return;

	dataMap.end_x = 0;
	dataMap.end_y = 0;
	for (int i = 0; i < MAX_MAP_Y; i++)
	{
		for (int j = 0; j < MAX_MAP_X; j++)
		{
			// Write data from file to status
			fscanf_s(file, "%d", &dataMap.status[i][j]);

			// Get maximum blocks
			int tmp = dataMap.status[i][j];
			if (tmp > 0)
			{
				if (j > dataMap.end_x)
					dataMap.end_x = j;
				if (i > dataMap.end_y)
					dataMap.end_y = i;
			}
		}
	}

	// Calculate position
	dataMap.start_x = 0;
	dataMap.start_y = 0;
	dataMap.end_x = (dataMap.end_x + 1) * BLOCK_SIZE;
	dataMap.end_y = (dataMap.end_y + 1) * BLOCK_SIZE;

	dataMap.mapFormatPath = filePath;
	fclose(file);
}

void BanZ::Map::InitTile(BanGame* banGame)
{
	char filePath[MAX_PATH];
	FILE* file;

	for (int i = 1; i < MAX_MAP_FORMAT; i++)
	{
		// Get path img
		sprintf_s(filePath, MAX_PATH, PATH_MAP_IMG, i);

		// Try opening file
		fopen_s(&file, filePath, "rb");
		if (file == NULL) continue;
		fclose(file);

		objMap[i]->LoadImg(banGame, filePath);
		
	}
}

void BanZ::Map::Update(float deltaTime, BanGame* banGame)
{
}

void BanZ::Map::Render(BanGame* banGame)
{
	int x1 = 0, x2 = 0;
	int y1 = 0, y2 = 0;
	int block_x = 0, block_y = 0;

	// Get pos
	x1 = (dataMap.start_x % BLOCK_SIZE) * -1;
	x2 = x1 + WIDTH + ((x1 == 0) ? 0 : BLOCK_SIZE);

	y1 = (dataMap.start_y % BLOCK_SIZE) * -1;
	y2 = y1 + HEIGHT + (y1 == 0 ? 0 : BLOCK_SIZE);


	// Get index block
	block_x = dataMap.start_x / BLOCK_SIZE; 
	block_y = dataMap.start_y / BLOCK_SIZE; 

	for (int i = y1; i < y2; i += BLOCK_SIZE)
	{
		block_x = dataMap.start_x / BLOCK_SIZE;
		for (int j = x1; j < x2; j += BLOCK_SIZE)
		{
			int val = dataMap.status[block_y][block_x];
			if (val > 0 && val < MAX_MAP_FORMAT)
			{
				objMap[val]->setPos(j, i);
				objMap[val]->setSize(BLOCK_SIZE, BLOCK_SIZE);
				objMap[val]->RenderImg(banGame);
			}
			block_x++;
		}
		block_y++;
	}

}
