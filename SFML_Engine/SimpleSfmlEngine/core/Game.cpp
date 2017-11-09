#include "Game.h"

namespace sse
{

	Game::Game(unsigned int width, unsigned int height, std::string title, std::function<void(GameDataRef data)> runState)
	{
		this->m_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
		this->m_data->window.setVerticalSyncEnabled(true);

		runState(this->m_data);

		this->Run();
	}

	void Game::Run()
	{

		while (this->m_data->window.isOpen())
		{
			this->m_data->machine.ProcessStateChanges();
			float dt = m_clock.restart().asSeconds();

			this->m_data->machine.GetActiveState()->HandleInput();
			this->m_data->machine.GetActiveState()->Update(dt);


			this->m_data->machine.GetActiveState()->Render(dt);

		}
	}
}