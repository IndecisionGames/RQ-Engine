#pragma once

#include "RQ_include.h"

namespace RQEngine {

	class ResourceManager {

	public:
		ResourceManager();
		~ResourceManager();

		static void cleanUp();

		bool loadTexture(const std::string &filepath, const std::string &textureName, bool smooth = false);

		// TODO: Refactor to sprite's wrapper class
		static sf::Sprite createSprite(const std::string &textureName,
			int originX = -1, int originY = -1, int width = -1, int height = -1);

	private:
		static std::unordered_map<std::string, sf::Texture> textureMap;
	};






}