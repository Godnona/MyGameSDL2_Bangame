#include "GameManager.h"


void BanZ::GameManager::Init()
{
	const auto banGame = BanGame::Get();

	position = VECTOR2(WIDTH, HEIGHT);

	// load background
	background = new GameObject();
	background->LoadImg(banGame, PATH_BACKGROUND);

	// load map
	map = new Map();
	map->InitFormat(PATH_MAP_FORMAT);
	map->InitTile(banGame);

	// load player
	player = new Player();
	
	player->LoadImg(banGame, PATH_PLAYER_RUN_RIGHT);
	player->SetFrame();

}

void BanZ::GameManager::Render() const
{
	const auto banGame = BanGame::Get();

	// render background
	background->RenderImg(banGame, { position.x / 2, position.y / 2 }, { WIDTH, HEIGHT });
	
	

	// render player
	player->Render(banGame);

	// render map
	map->Render(banGame);

}

void BanZ::GameManager::Update(float deltaTime, BanGame* banGame)
{
	timer.start();

	player->HandleInput(banGame);

	map_data = map->GetMapData();
	player->SetMapXY(map_data.start_x, map_data.start_y);
	player->Move(map_data);

	map->SetMapData(map_data);


	int realTime = timer.getTicks();
	int timeOneFrame = 1000 / FPS; // ms

	if (realTime < timeOneFrame)
	{
		int numDelay = timeOneFrame - realTime;
		if(numDelay > 0)
			std::this_thread::sleep_for(std::chrono::milliseconds(numDelay)); // ms
	}

}
