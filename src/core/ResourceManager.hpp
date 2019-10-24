#pragma once

#include "RQ_include.h"

namespace RQEngine {

    class ResourceManager {

    public:
        ResourceManager();
        ~ResourceManager();

        static void cleanUp();

        bool loadTexture(const std::string &filepath, const std::string &textureName, bool smooth = false);

        bool loadSound(const std::string& filepath, const std::string& soundName);

        bool loadFont(const std::string& filepath, const std::string& fontName);

        // TODO: Refactor to sprite's wrapper class
        static sf::Sprite createSprite(const std::string &textureName,
            int originX = 0, int originY = 0, int width = 0, int height = 0);

        static sf::Font* getFont(const std::string &fontName);
        static sf::SoundBuffer* getSound(const std::string &soundName);

    private:
        static std::unordered_map<std::string, sf::Texture> textureMap;
        static std::unordered_map<std::string, sf::SoundBuffer> soundMap;
        static std::unordered_map<std::string, sf::Font> fontMap;

    };

}
