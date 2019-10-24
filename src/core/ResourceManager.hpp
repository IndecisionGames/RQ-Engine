#pragma once

#include "RQ_include.h"

namespace RQEngine {

	class ResourceManager {

	public:
		ResourceManager();
		~ResourceManager();

		bool loadTexture(const std::string &filepath, const std::string &textureName, bool smooth = false);

		bool createSprite(const std::string &spriteName, const std::string &textureName,
			int originX, int originY, int width, int height);

		static sf::Sprite* getSprite(const std::string& spriteName);

	private:
		static std::unordered_map<std::string, sf::Texture> *textureMap;
		static std::unordered_map<std::string, sf::Sprite> *spriteMap;
	};






}