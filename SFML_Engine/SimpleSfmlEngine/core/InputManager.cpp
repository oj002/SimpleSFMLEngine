#include "InputManager.h"

namespace sse
{
	bool InputManager::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow & window)
	{
		if (sf::Mouse::isButtonPressed(button))
		{
			sf::IntRect tempRect(static_cast<int>(object.getPosition().x), static_cast<int>(object.getPosition().y), static_cast<int>(object.getGlobalBounds().width), static_cast<int>(object.getGlobalBounds().height));
			if (tempRect.contains(sf::Mouse::getPosition(window)))
			{
				return true;
			}

		}
		return false;
	}

	bool InputManager::IsCursorOnSprite(sf::Sprite object, sf::RenderWindow & window)
	{
		sf::IntRect tempRect(static_cast<int>(object.getPosition().x), static_cast<int>(object.getPosition().y), static_cast<int>(object.getGlobalBounds().width), static_cast<int>(object.getGlobalBounds().height));
		if (tempRect.contains(sf::Mouse::getPosition(window)))
		{
			return true;
		}
		return false;
	}

	sf::Vector2i InputManager::GetCursorPosition(sf::RenderWindow & window)
	{
		return sf::Mouse::getPosition();
	}
}
