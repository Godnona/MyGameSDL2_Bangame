#include "GameManager.h"


void BanZ::GameManager::Init()
{
	const auto banGame = BanGame::Get();


	// load background
	background = new GameObject();
	background->LoadImg(banGame, PATH_BACKGROUND);

	// load map
	map = new Map();
	map->InitFormat(PATH_MAP_FORMAT);
	map->InitTile(banGame);
	
}

void BanZ::GameManager::Render() const
{
	const auto banGame = BanGame::Get();

	// render background
	background->RenderImg(banGame, { WIDTH / 2, HEIGHT / 2 }, { WIDTH, HEIGHT });
	
	// render map
	map->Render(banGame);

}

void BanZ::GameManager::Update(float deltaTime, BanGame* banGame)
{
	
}
