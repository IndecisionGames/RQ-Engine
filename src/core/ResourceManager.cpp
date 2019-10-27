#include "ResourceManager.hpp"

using namespace RQEngine;
//
// A Resource Manager which will help with loading, storing
// and retrieving resources such as textures (soon also sound and fonts)
//
std::unordered_map<std::string, sf::Texture> ResourceManager::textureMap;
std::unordered_map<std::string, sf::SoundBuffer> ResourceManager::soundMap;
std::unordered_map<std::string, sf::Font> ResourceManager::fontMap;

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
    textureMap[textureName] = newTexture;
    return true;
}

bool ResourceManager::loadSound(const std::string& filepath, const std::string& soundName) {
    sf::SoundBuffer newSoundBuffer;
    if (!newSoundBuffer.loadFromFile(filepath))
    {
        printf("Unable to load sound from %s!\n", filepath.c_str());
        return false;
    }
    soundMap[soundName] = newSoundBuffer;
    return true;
}

bool ResourceManager::loadFont(const std::string& filepath, const std::string& fontName) {
    sf::Font newFont;
    if (!newFont.loadFromFile(filepath))
    {
        printf("Unable to load font from %s!\n", filepath.c_str());
        return false;
    }
    fontMap[fontName] = newFont;
    return true;
}

// TODO: Refactor to sprite's wrapper class (entity)
sf::Sprite ResourceManager::createSprite(const std::string &textureName,
    int originX, int originY, int width, int height) {
    sf::Sprite newSprite;

    auto textureIt = textureMap.find(textureName);
    if (textureIt == textureMap.end()) {
        printf("Unable to load texture %s!\n", textureName.c_str());
    }else{
        newSprite.setTexture(textureIt->second);
        newSprite.setTextureRect(sf::IntRect(originX, originY, width, height));
    }
    return newSprite;
}

sf::Font* ResourceManager::getFont(const std::string &fontName){
    auto fontIt = fontMap.find(fontName);
    if (fontIt == fontMap.end()) {
        printf("Unable to load font %s!\n", fontName.c_str());
        return NULL;
    }else{
        return &fontIt->second;
    }
    return NULL;
}

sf::SoundBuffer* ResourceManager::getSound(const std::string &soundName){
    auto soundIt = soundMap.find(soundName);
    if (soundIt == soundMap.end()) {
        printf("Unable to load sound %s!\n", soundName.c_str());
        return NULL;
    }else{
        return &soundIt->second;
    }
}
