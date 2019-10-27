
#include "EventManager.hpp"
#include "InputManager.hpp"
#include "Input.hpp"

using namespace RQEngine;

// TODO: Add missing events
// https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Event.php

EventManager::EventManager(sf::Window* window){
    source = window;
    InputManager::setWindow(window);
}
EventManager::~EventManager(){}

void EventManager::processEvents(){

    InputManager::update();
    sf::Event event;
    while (source->pollEvent(event)){

        switch (event.type){

            case sf::Event::Closed:
                source->close();
                break;

            case sf::Event::LostFocus:
                InputManager::unFocus();
                break;

            case sf::Event::GainedFocus:
                InputManager::focus();
                break;

            case sf::Event::KeyPressed:
                InputManager::pressKey(event.key.code);
                break;

            case sf::Event::KeyReleased:
                InputManager::releaseKey(event.key.code);
                break;

            case sf::Event::MouseMoved:
                InputManager::moveMouse();
                break;

            case sf::Event::MouseButtonPressed:
                InputManager::pressKey(InputManager::buttonToKey(event.mouseButton.button));
                break;

            case sf::Event::MouseButtonReleased:
                InputManager::releaseKey(InputManager::buttonToKey(event.mouseButton.button));
                break;

            case sf::Event::MouseWheelScrolled:
                break;

            default:
                break;
        }
    }
}
