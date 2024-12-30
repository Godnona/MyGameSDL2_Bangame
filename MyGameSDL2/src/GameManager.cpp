#include "GameManager.h"


void BanZ::GameManager::Init()
{
	const auto banGame = BanGame::Get();

	// load background
	background = new GameObject();
	background->LoadImg(banGame, PATH_BACKGROUND);

	// load map
	//map = new Map();
	//map->InitFormat(PATH_MAP_FORMAT);
	//map->InitTile(banGame);

	// init anim
	manageAnim = banGame->CreateAnimator();
	runLeftAnim = banGame->CreateAnimation("RunLeft", PATH_PLAYER_RUN_LEFT);
	banGame->AddAnimationToAnimator(manageAnim, runLeftAnim);
	banGame->SetAnimation(manageAnim, PLAYERSTATE::RUN_LEFT, false);

}

void BanZ::GameManager::Render() const
{
	const auto banGame = BanGame::Get();

	// render background
	background->RenderImg(banGame, { WIDTH / 2, HEIGHT / 2 }, { WIDTH, HEIGHT });
	
	// render map
	//map->Render(banGame);

	// render anim
	banGame->PlayAnimation(manageAnim, { WIDTH / 2, HEIGHT / 2 }, BLOCK_SIZE, 0, {1.0f, 1.0f, 0.0f, 1.0f});

}

void BanZ::GameManager::Update(float deltaTime, BanGame* banGame)
{
	// update anim
	banGame->UpdateAnimation(manageAnim, deltaTime);
}
