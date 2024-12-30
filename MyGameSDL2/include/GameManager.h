#pragma once  
#include "BanGame.h"  

#include <iostream> 
#include <string>
#include <sstream>

#include "Data.h"  
#include "GameObject.h"  
#include "Map.h"  

namespace BanZ {  
	class GameManager {  
	public:  
		GameManager() = default;
		~GameManager() = default;  

		void Init();  
		void Update(float deltaTime, BanGame* banGame);  
		void Render() const;  

	private:  
		VECTOR2 position;  
		COLOR color;  

	private:  
		GameObject* background;  
		Map* map;

		pAnimation runLeftAnim;
		pAnimation runRightAnim;

		pAnimator manageAnim;
		
	};  
}