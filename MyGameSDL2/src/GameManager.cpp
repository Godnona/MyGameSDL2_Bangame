#include "GameManager.h"


void BanZ::GameManager::Init()
{
	const auto banGame = BanGame::Get();

	position = VECTOR2(WIDTH, HEIGHT);

	// load background
	background = new GameObject();
	background->LoadImg(banGame, PATH_BACKGROUND);

	// load map
	//map = new Map();
	//map->InitFormat(PATH_MAP_FORMAT);
	//map->InitTile(banGame);

	// player
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
	//map->Render(banGame);

	player->Render(banGame);

}

void BanZ::GameManager::Update(float deltaTime, BanGame* banGame)
{
	/*if (banGame->GetPress(KeyBoard::Keys::W))
		position += VECTOR2(0, 1);*/

	player->HandleInput(banGame);

}
