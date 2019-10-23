
#pragma once

#include "../RQ_include.h"
#include "EventManager.hpp"
#include "Timer.hpp"

namespace RQEngine{

    class Window{

        public:
            Window(const std::string& wName, int wWidth=800, int wHeight=600, int maxFPS=60);

            void update();

            void prepareFrame();
            void draw(const sf::Drawable& drawable);
            void drawFrame();

            bool isOpen() const;

        private:

            sf::RenderWindow window;
            EventManager EM;
            FpsTimer fps;

    };

}
