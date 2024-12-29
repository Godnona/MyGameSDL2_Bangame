#include "GameObject.h"

BanZ::GameObject::GameObject()
{
	this->size = { 32, 32 };
	this->pos = { 0, 0 };
	this->sprite = nullptr;
}

void BanZ::GameObject::LoadImg(BanGame* banGame, const std::string& imgPath)
{
	sprite = banGame->CreateTexture(imgPath);
}

void BanZ::GameObject::RenderImg(BanGame* banGame)
{
	
	banGame->DrawSprite(sprite, { pos.x, pos.y, 0 }, size, { 0, 0, 0 });
}

void BanZ::GameObject::RenderImg(BanGame* banGame, VECTOR2 pos, VECTOR2 size)
{
	banGame->DrawSprite(sprite, { pos.x, pos.y, 0 }, size, { 0, 0, 0 });
}


// =============================================================
//                           Get Set                          //
// =============================================================
void BanZ::GameObject::setPos(const int& x, const int& y)
{
	pos.x = x;
	pos.y = y;
}

void BanZ::GameObject::setSize(const int& w, const int& h)
{
	size.x = w;
	size.y = h;
}

VECTOR2 BanZ::GameObject::getPos()
{
	return pos;
}

VECTOR2 BanZ::GameObject::getSize()
{
	return size;
}

pSprite BanZ::GameObject::getImg()
{
	return sprite;
}
