#include "Game.h"

namespace sse
{

	Game::Game(unsigned int width, unsigned int height, std::string title, std::function<void(GameDataRef data)> runState)
	{
		this->m_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
		
		//this->m_data->machine.AddState(StateRef(new SplashState(this->m_data)));
		runState(this->m_data);

		this->Run();
	}

	void Game::Run()
	{
		float newTime, frameTime, interpolation;

		float currentTime = this->m_clock.getElapsedTime().asSeconds();
		float accumulator = 0.0f;

		while (this->m_data->window.isOpen())
		{
			this->m_data->machine.ProcessStateChanges();

			newTime = this->m_clock.getElapsedTime().asSeconds();
			frameTime = newTime - currentTime;

			if (frameTime > 0.25f)
			{
				frameTime = 0.25f;
			}

			currentTime = newTime;
			accumulator += frameTime;

			while (accumulator >= dt)
			{
				this->m_data->machine.GetActiveState()->HandleInput();
				this->m_data->machine.GetActiveState()->Update(dt);

				accumulator -= dt;
			}

			interpolation = accumulator / dt;
			this->m_data->machine.GetActiveState()->Render(interpolation);

		}
	}
}