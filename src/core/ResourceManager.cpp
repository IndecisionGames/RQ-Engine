#include "ResourceManager.hpp"

using namespace RQEngine;
//
// A Resource Manager which will help with loading, storing
// and retrieving resources such as textures and sprites
//
std::unordered_map<std::string, sf::Texture> *ResourceManager::textureMap;
std::unordered_map<std::string, sf::Sprite> *ResourceManager::spriteMap;

ResourceManager::ResourceManager() {
	textureMap = new std::unordered_map<std::string, sf::Texture>();
	spriteMap = new std::unordered_map<std::string, sf::Sprite>();
}

ResourceManager::~ResourceManager() {
	textureMap->clear();
	spriteMap->clear();
}

bool ResourceManager::loadTexture(const std::string &filepath, const std::string &textureName, bool smooth) {
	sf::Texture newTexture;
	if (!newTexture.loadFromFile(filepath))
	{
		printf("Unable to load texture from %s!\n", filepath.c_str());
		return false;
	}
	newTexture.setSmooth(smooth);
	textureMap->insert_or_assign(textureName, newTexture);
	return true;
}

bool ResourceManager::createSprite(const std::string &spriteName, const std::string &textureName,
	int originX, int originY, int width, int height) {
	sf::Sprite newSprite;

	auto textureIt = textureMap->find(textureName);
	if (textureIt == textureMap->end()) {
		printf("Unable to load texture %s!\n", textureName.c_str());
		return false;
	}
	newSprite.setTexture(textureIt->second);
	newSprite.setTextureRect(sf::IntRect(originX, originY, width, height));
	spriteMap->insert_or_assign(spriteName, newSprite);
	return true;
}


sf::Sprite* ResourceManager::getSprite(const std::string &spriteName) {
	auto spriteIt = spriteMap->find(spriteName);
	if (spriteIt == spriteMap->end()) {
		printf("Unable to load sprite %s!\n", spriteName.c_str());
		return NULL;
	}
	return &(spriteIt->second);
}