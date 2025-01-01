#include "Player.h"


Player::Player()
{
	width_frame = 0; height_frame = 0;

	x_pos = 32; y_pos = HEIGHT - 64;

	x_speed = 0; y_speed = 0;

	frame = 0;
	status = 0;

	isRight = true;

	map_x = 0; map_y = 0;
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

	pos.x = x_pos - map_x;
	pos.y = y_pos - map_y;

	VECTOR3 positionGlobal = VECTOR3(pos.x, pos.y, 0.0f);
	VECTOR2 sizeGlobal = VECTOR2(BLOCK_SIZE, BLOCK_SIZE);

	banGame->DrawPartialTexture(sprite,
								positionGlobal, posFrame[frame],
								sizeFrame[frame], sizeGlobal,
								{0, 0, 0});

}

void Player::Move(MapStruct& map)
{
	x_speed = 0;
	y_speed += -SPEED_GRAVITY;
	if (y_speed >= -SPEED_GRAVITY)
		y_speed = -MAX_GRAVITY;

	if (input.left == 1)
		x_speed += -SPEED_PLAYER;
	else if (input.right == 1)
		x_speed += SPEED_PLAYER;

	if (input.jump == 1)
	{
		if (isGround == true)
		{
			y_speed += JUMP_FORCE;
			isGround = false;
		}

		input.jump = 0;
	}

	CheckCollider(map);
	MoveCamera(map);

}

void Player::CheckCollider(MapStruct& map)
{
	int x1 = 0, y1 = 0;
	int x2 = 0, y2 = 0;

	// Check horizontal
	int height_min = height_frame < BLOCK_SIZE ? height_frame : BLOCK_SIZE;
	x1 = (x_pos + x_speed) / BLOCK_SIZE;
	x2 = (x_pos + x_speed + width_frame - 1) / BLOCK_SIZE;

	y1 = y_pos / BLOCK_SIZE;
	y2 = (y_pos + height_min - 1) / BLOCK_SIZE;

	if (x1 >= 0 && x2 < MAX_MAP_X && y1 >= 0 && y2 < MAX_MAP_Y)
	{
		if (x_speed > 0)
		{
			if (map.status[y1][x2] > 0 || map.status[y2][x2] > 0)
			{
				x_pos = x2 * BLOCK_SIZE;
				x_pos -= width_frame + 1;
				x_speed = 0;
			}
		}
		else if (x_speed < 0)
		{
			if (map.status[y1][x1] != 0 || map.status[y2][x1] != 0)
			{
				x_pos = (x1 + 1) * BLOCK_SIZE;
				x_speed = 0;
			}
		}
	}

	// Check Vertical
	int width_min = width_frame < BLOCK_SIZE ? width_frame : BLOCK_SIZE;
	x1 = x_pos / BLOCK_SIZE;
	x2 = (x_pos + width_min) / BLOCK_SIZE;

	y1 = (y_pos + y_speed) / BLOCK_SIZE;
	y2 = (y_pos + y_speed + height_frame - 1) / BLOCK_SIZE;

	if (x1 >= 0 && x2 < MAX_MAP_X && y1 >= 0 && y2 < MAX_MAP_Y)
	{
		if (y_speed > 0)
		{
			if (map.status[y2][x1] > 0 || map.status[y2][x2] > 0)
			{
				y_pos = y2 * BLOCK_SIZE;
				y_pos -= height_frame + 1;
				
				y_speed = 0;
			}
		}
		else if (y_speed < 0)
		{
			if (map.status[y1][x1] > 0 || map.status[y1][x2] > 0)
			{
				y_pos = (y1 + 1) * BLOCK_SIZE;
				y_speed = 0;
				isGround = true;
			}
		}
	}

	// if we don't collide with obejct, we will move
	x_pos += x_speed;
	y_pos += y_speed;

	if (x_pos < 0) x_pos = 0;
	else if (x_pos + width_frame > map.end_x) x_pos = map.end_x - width_frame;
}

void Player::MoveCamera(MapStruct& map)
{
	map.start_x = x_pos - (WIDTH / 2); // Qua 1/2 map -> move map
	if (map.start_x < 0) 
		map.start_x = 0;
	else if (map.start_x + WIDTH > map.end_x) 
		map.start_x = map.end_x - WIDTH;

	// Bug map y
	//map.start_y = y_pos - (HEIGHT / 2);
	//if (map.start_y < 0) 
	//	map.start_y = 0;
	//else if (map.start_y + HEIGHT > map.end_y) 
	//	map.start_y = map.end_y - HEIGHT;
	//
}

void Player::SetMapXY(const int map_x, const int map_y)
{
	this->map_x = map_x;
	this->map_y = map_y;
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

	if (banGame->GetPress(KeyBoard::Keys::Space))
	{
		input.jump = 1;

	}
}