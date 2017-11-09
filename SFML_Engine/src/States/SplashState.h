#pragma once

#include <SFML/Graphics.hpp>
#include "../../SimpleSfmlEngine/engine.h"
#include "../../SimpleSfmlEngine/core/AnimatedSprite.h"

namespace sse
{
	class SplashState : public State
	{
	public:
		SplashState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Render(float dt);

	private:
		GameDataRef m_data;
		sf::Clock m_clock;
		sf::Sprite m_background;
		AnimatedSprite m_anmation;
	};
}