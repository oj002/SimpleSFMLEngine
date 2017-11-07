#pragma once

#include <SFML/Graphics.hpp>

namespace sse
{
	class InputManager
	{
	public:
		InputManager() {}
		~InputManager() {}

		bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);
		bool IsCursorOnSprite(sf::Sprite object, sf::RenderWindow &window);

		sf::Vector2i GetCursorPosition(sf::RenderWindow &window);

	private:

	};


}
