
#pragma once

#include "../RQ_include.h"

namespace RQEngine{


    class EventManager{

        public:
            EventManager(sf::Window* window);
            ~EventManager();

            void processEvents();

        private:
            sf::Window* source;
    };

}
