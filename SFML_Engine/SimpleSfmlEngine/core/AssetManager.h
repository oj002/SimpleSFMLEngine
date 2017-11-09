#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

namespace sse
{
	class AssetManager
	{
	public:
		AssetManager() {}
		~AssetManager() {}

		void LoadTexture(std::string name, std::string path);
		sf::Texture &GetTexture(std::string name);


		void LoadFont(std::string name, std::string path);
		sf::Font &GetFont(std::string name);


		void LoadSoundBuffer(std::string name, std::string path);
		sf::SoundBuffer &GetSoundBuffer(std::string name);

		void LoadShaderFile(std::string name, std::string path);
		sf::Shader &GetShader(std::string name);
		

	private:
		std::map<std::string, sf::Texture> m_textures;
		std::map<std::string, sf::Font> m_fonts;
		std::map<std::string, sf::SoundBuffer> m_soundBuffer;
		std::map<std::string, sf::Shader> m_shaders;
	};
}