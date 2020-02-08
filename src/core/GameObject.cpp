#include "GameObject.hpp"
#include "GameObject.hpp"

using namespace RQEngine;

GameObject::GameObject() {};

void GameObject::Init() {
	deltaClock = Timer();
	Start();
	deltaClock.start();
};
void GameObject::Start() {};
void GameObject::Update(uint64_t deltaTime) {};
void GameObject::LateUpdate() {};
void GameObject::Draw() {};
void GameObject::Process() {

	uint64_t deltaTime = deltaClock.getElapsedTime();
	Update(deltaTime);
	deltaClock.start();
	LateUpdate();
	Draw();
}

bool GameObject::IsActive() const
{
	return active;
}

void GameObject::setActive(bool b) {
	active = b;
}