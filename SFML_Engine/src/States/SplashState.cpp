#include "SplashState.h"
#include "../DEFINITIONS.h"
#include <iostream>

namespace sse
{
	SplashState::SplashState(GameDataRef data)
		: m_data(data)
	{
	}

	void SplashState::Init()
	{
		m_data->assets.LoadShaderFile("test", "Resources/shaders/Basic.shader");
		

		m_data->assets.LoadTexture("t0", "Resources/res/player_0.png");
		m_data->assets.LoadTexture("t1", "Resources/res/player_1.png");
		m_data->assets.LoadTexture("t2", "Resources/res/player_2.png");

		m_data->assets.LoadTexture("t3", "Resources/res/logo.png");

		m_anmation["Hello"].emplace_back(m_data->assets.GetTexture("t0"), 0.1f);
		m_anmation["Hello"].emplace_back(m_data->assets.GetTexture("t1"), 0.1f);
		m_anmation["Hello"].emplace_back(m_data->assets.GetTexture("t2"), 0.1f);

		m_anmation["HelloFast"].emplace_back(m_data->assets.GetTexture("t0"), 0.01f);
		m_anmation["HelloFast"].emplace_back(m_data->assets.GetTexture("t1"), 0.01f);
		m_anmation["HelloFast"].emplace_back(m_data->assets.GetTexture("t2"), 0.01f);

		m_anmation.SetActiveAnimation("Hello");
		m_anmation.scale(4.0, 4.0);

		m_background.setTexture(m_data->assets.GetTexture("t3"));

		m_data->assets.GetShader("test").setUniform("texture", sf::Shader::CurrentTexture);
		
	}

	void SplashState::HandleInput()
	{
		sf::Event event;

		while (m_data->window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				m_data->window.close();
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			m_anmation.SetActiveAnimation("HelloFast");
		}
		float x = static_cast<float>(sf::Mouse::getPosition(m_data->window).x) / m_data->window.getSize().x;
		float y = static_cast<float>(sf::Mouse::getPosition(m_data->window).y) / m_data->window.getSize().y;
		m_data->assets.GetShader("test").setUniform("pixel_threshold", (x + y) / 30.0f);
	}

	void SplashState::Update(float dt)
	{
		m_anmation.Update();


		if (m_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
		{
			//m_data->machine.AddState(StateRef(new GameState(m_data)), true);
		}
	}

	void SplashState::Render(float dt)
	{
		m_data->window.clear();

		m_data->window.draw(m_background, &m_data->assets.GetShader("test"));
		m_data->window.draw(m_anmation, &m_data->assets.GetShader("test"));

		m_data->window.display();
	}
}