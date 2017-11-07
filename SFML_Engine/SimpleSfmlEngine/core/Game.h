#pragma once

#include <memory>
#include <string>
#include <functional>
#include <SFML/Graphics.hpp>
#include "StateMachine.h"
#include "AssetManager.h"
#include "InputManager.h"

namespace sse
{
	struct GameData
	{
		StateMachine machine;
		sf::RenderWindow window;
		AssetManager assets;
		InputManager input;
	};

	typedef std::shared_ptr<GameData> GameDataRef;

	class Game
	{
	public:
		Game(unsigned int width, unsigned int height, std::string title, std::function<void(GameDataRef data)> runState);

	private:
		const float dt = 1.0f / 60.0f;
		sf::Clock m_clock;

		GameDataRef m_data = std::make_shared<GameData>();

		void Run();
	};
}
