#include "ResourceManager.hpp"

using namespace RQEngine;
//
// A Resource Manager which will help with loading, storing
// and retrieving resources such as textures (soon also sound and fonts)
//
std::unordered_map<std::string, sf::Texture> ResourceManager::textureMap;

ResourceManager::ResourceManager() {}
ResourceManager::~ResourceManager() {}

void ResourceManager::cleanUp() {
	textureMap.clear();
}

bool ResourceManager::loadTexture(const std::string &filepath, const std::string &textureName, bool smooth) {
	sf::Texture newTexture;
	if (!newTexture.loadFromFile(filepath))
	{
		printf("Unable to load texture from %s!\n", filepath.c_str());
		return false;
	}
	newTexture.setSmooth(smooth);
	textureMap.insert_or_assign(textureName, newTexture);
	return true;
}

// TODO: Refactor to sprite's wrapper class (entity)
sf::Sprite ResourceManager::createSprite(const std::string &textureName,
	int originX, int originY, int width, int height) {
	sf::Sprite newSprite;

	auto textureIt = textureMap.find(textureName);
	if (textureIt == textureMap.end()) {
		printf("Unable to load texture %s!\n", textureName.c_str());
	}
	else {
		newSprite.setTexture(textureIt->second);
		if (originX != -1 && originY != -1 && width != -1 && height != -1) {
			newSprite.setTextureRect(sf::IntRect(originX, originY, width, height));
		}
	}
	return newSprite;
}