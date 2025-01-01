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
	
	// render map
	map->Render(banGame);

	// render player
	player->Render(banGame);

}

void BanZ::GameManager::Update(float deltaTime, BanGame* banGame)
{

	player->HandleInput(banGame);

	map_data = map->GetMap();
	player->Move(map_data);

}
