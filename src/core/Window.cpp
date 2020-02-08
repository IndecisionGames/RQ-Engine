
#include "Window.hpp"

using namespace RQEngine;

Window::Window(const std::string& wName, int wWidth, int wHeight, int maxFPS)
    : window(sf::VideoMode(wWidth, wHeight), wName, sf::Style::Titlebar | sf::Style::Close ), EM(&window), fps(maxFPS){}

void Window::Update(){
    fps.start();
    EM.processEvents();
}

void Window::PrepareFrame(){
    window.clear(sf::Color::Black);
}

void Window::Draw(const sf::Drawable& drawable){
    window.draw(drawable);
}

void Window::DrawFrame(){
    window.display();
    fps.limit();
    // std::cout << fps.getCurrentFPS() << std::endl;
}

bool Window::IsOpen() const{
    return window.isOpen();
}
