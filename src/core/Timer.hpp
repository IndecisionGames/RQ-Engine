#pragma once

#include "../RQ_include.h"

namespace RQEngine{

    class Timer{

        public:
            Timer();

            void start();
            void stop();
            void pause();
            void unpause();

            uint64_t getElapsedTime();

            bool isStarted();
            bool isPaused();

        private:
            sf::Clock clock;
            sf::Time runTime;

            bool paused;
            bool started;
        };

    class FpsTimer{

        public:
            static const int SAMPLE_RATE = 30;
            static const int MAX_STEPS = 5;

            FpsTimer();
            void init(float _maxFPS);

            void start();
            void update();
            void limit();

            void setMaxFps(float _maxFPS);

            float getCurrentFPS();
            float getDeltaTime();
            float getMaxDeltaTime();

        private:
            sf::Clock clock;
            sf::Time startTime;
            sf::Time previousFrameTime;

            float maxFPS;
            float currentFPS = 0.0f;
            sf::Time fpsCounterTime; // Time SAMPLE_RATE frames ago
            int frameCount = 0;

    };

}
