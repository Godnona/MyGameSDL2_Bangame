#include "Player.h"


Player::Player()
{
	width_frame = 0; width_frame = 0;

	x_pos = 32; y_pos = HEIGHT - 64;

	x_speed = 0; y_speed = 0;

	frame = 0;
	status = 0;

	isRight = true;
}

Player::~Player()
{
}

void Player::LoadImg(BanGame* banGame, const std::string& imgPath)
{
	GameObject::LoadImg(banGame, imgPath);
	width_frame = WIDTH_FRAME;
	height_frame = HEIGHT_FRAME;
}

void Player::SetFrame()
{
	if (width_frame != 0 && height_frame != 0)
	{
		for (int i = 0; i < 8; i++)
		{
			posFrame[i].x = i * width_frame;
			posFrame[i].y = 0;

			sizeFrame[i].x = width_frame;
			sizeFrame[i].y = height_frame;
		}
	}
}

void Player::Render(BanGame* banGame)
{
	if (status == RUN_LEFT)
		LoadImg(banGame, PATH_PLAYER_RUN_LEFT);
	else if (status == RUN_RIGHT)
		LoadImg(banGame, PATH_PLAYER_RUN_RIGHT);
	else if (status == IDLE_LEFT && isRight == false)
		LoadImg(banGame, PATH_PLAYER_IDLE_LEFT);
	else if (status == IDLE_LEFT && isRight == true)
		LoadImg(banGame, PATH_PLAYER_IDLE_RIGHT);

	if (input.left == 1 || input.right || input.idle)
		frame++;
	else frame = 0;

	if (frame >= 8) frame = 0;

	pos.x = x_pos;
	pos.y = y_pos;

	VECTOR3 positionGlobal = VECTOR3(pos.x, pos.y, 0.0f);
	VECTOR2 sizeGlobal = VECTOR2(BLOCK_SIZE * 3, BLOCK_SIZE * 3);

	banGame->DrawPartialTexture(sprite,
								positionGlobal, posFrame[frame],
								sizeFrame[frame], sizeGlobal,
								{0, 0, 0});

}

void Player::HandleInput(BanGame* banGame)
{
	if (banGame->GetPress(KeyBoard::Keys::D))
	{
		status = RUN_RIGHT;
		input.idle = 0;
		input.left = 0;
		input.right = 1;
		isRight = true;
		
	}
	else if (banGame->GetPress(KeyBoard::Keys::A))
	{
		status = RUN_LEFT;
		input.idle = 0;
		input.left = 1;
		input.right = 0;
		isRight = false;
	}

	else if (banGame->GetRelease(KeyBoard::Keys::D))
	{
		status = IDLE_LEFT;
		input.idle = 1;
		input.right = 0;
		isRight = true;

	}
	else if (banGame->GetRelease(KeyBoard::Keys::A))
	{
		status = IDLE_LEFT;
		input.idle = 1;
		input.left = 0;
		isRight = false;
	}
	else
	{
		status = IDLE_LEFT;
		input.idle = 1;
	}
}
