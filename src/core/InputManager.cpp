
#include "InputManager.hpp"

using namespace RQEngine;

InputManager::InputManager(){}
InputManager::~InputManager(){}

std::unordered_map<unsigned int, bool> InputManager::currentFrame;
std::unordered_map<unsigned int, bool> InputManager::previousFrame;

std::unordered_map<unsigned int, bool> InputManager::buttonMap;
std::unordered_map<unsigned int, bool> InputManager::previousButtonMap;

sf::Window* InputManager::window;
bool InputManager::isFocused = true;
bool InputManager::mouseState;


void InputManager::setWindow(sf::Window* _window){
    window = _window;
}

// Private
void InputManager::update(){
    // std::cout << "UPDATE" << std::endl;
    for(auto it = currentFrame.begin(); it != currentFrame.end(); it++){
        previousFrame[it->first] = it->second;
    }
    mouseState = false;
}

void InputManager::pressKey(unsigned int keyID){
    currentFrame[keyID] = true;
}

void InputManager::releaseKey(unsigned int keyID){
    currentFrame[keyID] = false;
}

void InputManager::focus(){
    isFocused = true;
}

void InputManager::unFocus(){
    isFocused = false;
}

void InputManager::moveMouse(){
    mouseState = true;
}

KeyCode InputManager::buttonToKey(sf::Mouse::Button buttonID){
    switch(buttonID){
        case sf::Mouse::Button::Left:
            return KeyCode::MouseLeft;

        case sf::Mouse::Button::Right:
            return KeyCode::MouseRight;

        case sf::Mouse::Button::Middle:
            return  KeyCode::MouseMiddle;

        case sf::Mouse::Button::XButton1:
            return KeyCode(MouseX1);

        case sf::Mouse::Button::XButton2:
            return KeyCode(MouseX2);

        case sf::Mouse::Button::ButtonCount:
            return KeyCode(ButtonCount);
        };
}

// Public
bool InputManager::isKeyPressed(KeyCode keyID){
    auto it = currentFrame.find(keyID);
    if(it != currentFrame.end()){
        return it->second;
    }
    return false;
}

bool InputManager::isKeyHeld(KeyCode keyID){
    auto it = previousFrame.find(keyID);
    bool wasDown;
    if(it != previousFrame.end()){
        wasDown = it->second;
    }else{
        wasDown = false;
    }

    if(isKeyPressed(keyID) && wasDown){
        return true;
    }
    return false;
}

bool InputManager::isKeyUp(KeyCode keyID){
    auto it = previousFrame.find(keyID);
    bool wasDown;
    if(it != previousFrame.end()){
        wasDown = it->second;
    }else{
        wasDown = false;
    }

    if(!isKeyPressed(keyID) && wasDown){
        return true;
    }
    return false;
}

bool InputManager::isFocus(){
    return isFocused;
}

bool InputManager::isMouseMoved(){
    return mouseState;
}

sf::Vector2i InputManager::getMousePos(){
    return sf::Mouse::getPosition(*window);
}
