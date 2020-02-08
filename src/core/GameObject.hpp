#pragma once

#include "../RQ_include.h"
#include "Timer.hpp"

class GameObject {
private:
    bool active = true;
    class RQEngine::Timer deltaClock;

public:
    GameObject();
    void Init();
    virtual void Start();
    virtual void Update(uint64_t deltaTime);
    virtual void LateUpdate();
    virtual void Draw();
    void Process();
    void setActive(bool b);
    bool IsActive() const;
};