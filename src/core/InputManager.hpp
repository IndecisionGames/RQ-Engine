
#pragma once

#include "../RQ_include.h"
#include "Input.hpp"

namespace RQEngine{

    class EventManager;

    class InputManager{

        public:
            InputManager();
            ~InputManager();

            static bool isKeyPressed(KeyCode keyID);
            static bool isKeyHeld(KeyCode keyID);
            static bool isKeyUp(KeyCode keyID);

            static bool isFocus();
            static bool isMouseMoved();

            static sf::Vector2i getMousePos();

        private:

            friend class EventManager;

            static void update();
            static void setWindow(sf::Window* _window);

            static void focus();
            static void unFocus();
            static void moveMouse();

            static void pressKey(unsigned int keyID);
            static void releaseKey(unsigned int keyID);
            static KeyCode buttonToKey(sf::Mouse::Button buttonID);

            static std::unordered_map<unsigned int, bool> currentFrame;
            static std::unordered_map<unsigned int, bool> previousFrame;

            static std::unordered_map<unsigned int, bool> buttonMap;
            static std::unordered_map<unsigned int, bool> previousButtonMap;

            static sf::Window* window;
            static bool isFocused;
            static bool mouseState;

    };

}
