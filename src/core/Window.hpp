
#pragma once

#include "../RQ_include.h"
#include "EventManager.hpp"
#include "Timer.hpp"

namespace RQEngine{

    class Window{

        public:
            //Window() {};
            Window(const std::string& wName, int wWidth=800, int wHeight=600, int maxFPS=60);

            void Update();

            void PrepareFrame();
            void Draw(const sf::Drawable& drawable);
            void DrawFrame();

            bool IsOpen() const;

        private:

            sf::RenderWindow window;
            EventManager EM;
            FpsTimer fps;

    };

}
