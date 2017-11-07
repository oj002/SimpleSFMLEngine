#include <SFML\Graphics.hpp>
#include <string>
#include <vector>

namespace sse
{
	class Animation
	{
	public:
		Animation(std::string path, sf::IntRect firstFrame, size_t numFrames, float animationSpeed)
			: m_frameSize(firstFrame)
			, m_numFrames(numFrames)
			, m_animationSpeed(animationSpeed)
		{
			m_frames.loadFromFile(path);
			m_currentFrame.setTexture(m_frames);
			m_currentFrame.setTextureRect(firstFrame);
		}


		void Update(float dt)
		{
			if (m_currentTime < m_animationSpeed)
			{
				m_currentTime += dt;
			}
			else
			{
				m_currentTime = 0.0f;
			}

		}

		sf::Sprite GetCurrentFrame()
		{
			return m_currentFrame;
		}

	private:
		sf::Texture m_frames;
		sf::Sprite m_currentFrame;
		sf::IntRect m_frameSize;
		size_t m_numFrames;
		float m_currentTime;
		float m_animationSpeed;
	};
}