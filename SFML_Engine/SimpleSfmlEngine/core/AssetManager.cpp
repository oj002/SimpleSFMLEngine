#include "AssetManager.h"
#include <fstream>
#include <sstream>
#include <iostream>

namespace sse
{

	void AssetManager::LoadTexture(std::string name, std::string path)
	{
		sf::Texture tex;

		if (tex.loadFromFile(path))
		{
			this->m_textures[name] = tex;
		}
	}

	sf::Texture & AssetManager::GetTexture(std::string name)
	{
		return this->m_textures[name];
	}

	void AssetManager::LoadFont(std::string name, std::string path)
	{
		sf::Font font;

		if (font.loadFromFile(path))
		{
			this->m_fonts[name] = font;
		}
	}

	sf::Font & AssetManager::GetFont(std::string name)
	{
		return this->m_fonts[name];
	}

	void AssetManager::LoadSoundBuffer(std::string name, std::string path)
	{
		sf::SoundBuffer soundBuffer;

		if (soundBuffer.loadFromFile(path))
		{
			this->m_soundBuffer[name] = soundBuffer;
		}
	}

	sf::SoundBuffer & AssetManager::GetSoundBuffer(std::string name)
	{
		return this->m_soundBuffer[name];
	}

	void AssetManager::LoadShaderFile(std::string name, std::string path)
	{
		std::ifstream fin(path);

		enum class ShaderType
		{
			NONE = -1, VERTEX = 0, FRAGMENT = 1
		};

		std::string line;
		std::stringstream ss[2];
		ShaderType type = ShaderType::NONE;
		while (std::getline(fin, line))
		{
			if (line.find("#shader") != std::string::npos)
			{
				if (line.find("vertex") != std::string::npos)
				{
					type = ShaderType::VERTEX;
				}
				else if (line.find("fragment") != std::string::npos)
				{
					type = ShaderType::FRAGMENT;
				}
			}
			else
			{
				ss[(int)type] << line << '\n';
			}
		}

		std::cout << ss[0].str() << ss[1].str();

		m_shaders[name].loadFromMemory(ss[0].str(), ss[1].str());
	}

	sf::Shader & AssetManager::GetShader(std::string name)
	{
		return this->m_shaders[name];
	}
}