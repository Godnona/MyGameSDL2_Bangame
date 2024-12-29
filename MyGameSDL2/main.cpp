#include "BanGame.h"
using namespace BanZ;

#include "GameManager.h"

GameManager* gameManager;

void sceneInit()
{
    gameManager = new GameManager();
    gameManager->Init();
}

void sceneUpdate(const float& elapsedTime, BanGame* bangame)
{
    gameManager->Update(elapsedTime, bangame);
}

void sceneRender()
{
    gameManager->Render();
}



int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    auto banGame = BanGame::Get();
    banGame->CreateGameWindow(hInstance, nCmdShow, L"Game SDL new Engine", L"gamewindow", WIDTH, HEIGHT);
    BanGame::Get()->CreateCamera(WIDTH, HEIGHT, 0.1f, 1000);

    auto Init = std::bind(&sceneInit);
    auto Update = std::bind(&sceneUpdate, std::placeholders::_1, banGame);
    auto Render = std::bind(&sceneRender);

    banGame->GameRun(Init, Update, Render);

	if (gameManager != nullptr)
		delete gameManager;
    delete banGame;
    return 0;
}