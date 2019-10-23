
#include "Window.hpp"

using namespace RQEngine;

Window::Window(const std::string& wName, int wWidth, int wHeight, int maxFPS)
    : window(sf::VideoMode(wWidth, wHeight), wName), EM(&window), fps(maxFPS){}

void Window::update(){
    fps.start();
    EM.processEvents();
}

void Window::prepareFrame(){
    window.clear(sf::Color::Black);
}

void Window::draw(const sf::Drawable& drawable){
    window.draw(drawable);
}

void Window::drawFrame(){
    window.display();
    fps.limit();
    // std::cout << fps.getCurrentFPS() << std::endl;
}

bool Window::isOpen() const{
    return window.isOpen();
}
