#include "ResourceManager.hpp"

using namespace RQEngine;
//
// A Resource Manager which will help with loading, storing
// and retrieving resources such as textures (soon also sound and fonts)
//
std::unordered_map<std::string, std::unique_ptr<sf::Texture>> ResourceManager::textureMap;
std::unordered_map<std::string, std::unique_ptr<sf::SoundBuffer>> ResourceManager::soundMap;
std::unordered_map<std::string, std::unique_ptr<sf::Font>> ResourceManager::fontMap;

ResourceManager::ResourceManager() {}
ResourceManager::~ResourceManager() {}

void ResourceManager::cleanUp() {
    textureMap.clear();
    soundMap.clear();
    fontMap.clear();
}

bool ResourceManager::loadTexture(const std::string &filepath, const std::string &textureName, bool smooth) {
    std::unique_ptr<sf::Texture> newTexture(new sf::Texture());
    if (!newTexture->loadFromFile(filepath))
    {
        printf("Unable to load texture from %s!\n", filepath.c_str());
        return false;
    }
    newTexture->setSmooth(smooth);
    textureMap.insert(std::make_pair(textureName, std::move(newTexture)));
    return true;
}

bool ResourceManager::loadSound(const std::string& filepath, const std::string& soundName) {
    std::unique_ptr<sf::SoundBuffer> newSoundBuffer(new sf::SoundBuffer());
    if (!newSoundBuffer->loadFromFile(filepath))
    {
        printf("Unable to load sound from %s!\n", filepath.c_str());
        return false;
    }
    soundMap.insert(std::make_pair(soundName, std::move(newSoundBuffer)));
    return true;
}

bool ResourceManager::loadFont(const std::string& filepath, const std::string& fontName) {
    std::unique_ptr<sf::Font> newFont(new sf::Font());
    if (!newFont->loadFromFile(filepath))
    {
        printf("Unable to load font from %s!\n", filepath.c_str());
        return false;
    }
    fontMap.insert(std::make_pair(fontName, std::move(newFont)));
    return true;
}

// TODO: Refactor to sprite's wrapper class (entity)
sf::Sprite ResourceManager::createSprite(const std::string& textureName,
    int originX, int originY, int width, int height) {
    sf::Sprite newSprite;

    auto textureIt = textureMap.find(textureName);
    if (textureIt == textureMap.end()) {
        printf("Unable to load texture %s!\n", textureName.c_str());
    }
    else {
        newSprite.setTexture(*textureIt->second);
        if (originX != -1 && originY != -1 && width != -1 && height != -1) {
            newSprite.setTextureRect(sf::IntRect(originX, originY, width, height));
        }
    }
    return newSprite;
}

sf::Font* ResourceManager::getFont(const std::string& fontName) {
    auto fontIt = fontMap.find(fontName);
    if (fontIt == fontMap.end()) {
        printf("Unable to load font %s!\n", fontName.c_str());
        return NULL;
    }
    return &(*fontIt->second);
}

sf::SoundBuffer* ResourceManager::getSound(const std::string& soundName) {
    auto soundIt = soundMap.find(soundName);
    if (soundIt == soundMap.end()) {
        printf("Unable to load sound %s!\n", soundName.c_str());
        return NULL;
    }
    return &(*soundIt->second);
}
