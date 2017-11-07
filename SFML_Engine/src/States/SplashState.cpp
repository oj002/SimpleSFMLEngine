#include "SplashState.h"
#include "../DEFINITIONS.h"


namespace sse
{
	SplashState::SplashState(GameDataRef data)
		: m_data(data)
	{
	}

	void SplashState::Init()
	{
		m_data->assets.LoadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);
		m_data->assets.LoadShaderFile("BasicShader", "Resources/shaders/Basic.shader");

		m_background.setTexture(m_data->assets.GetTexture("Splash State Background"));
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
	}

	void SplashState::Update(float dt)
	{
		if (m_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
		{
			//m_data->machine.AddState(StateRef(new GameState(m_data)), true);
		}
	}

	void SplashState::Render(float dt)
	{
		m_data->window.clear();
		m_background.move(-0.00005f, -0.00005f);
		m_data->window.draw(m_background, &m_data->assets.GetShader("BasicShader"));

		m_data->window.display();
	}
}