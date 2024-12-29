#pragma once

#include "BanGame.h"
using namespace BanZ;

#include "Data.h"

namespace BanZ {

	class GameObject
	{
	public:
		GameObject();
		~GameObject() = default;

		virtual void LoadImg(BanGame* banGame, const std::string& imgPath);
		void RenderImg(BanGame* banGame);
		void RenderImg(BanGame* banGame, VECTOR2 pos, VECTOR2 size);

		void setPos(const int& x, const int& y);
		void setSize(const int& w, const int& h);

		VECTOR2 getPos();
		VECTOR2 getSize();
		pSprite getImg();


	protected:
		
		pSprite sprite;
		VECTOR2 pos;
		VECTOR2 size;

	};
}