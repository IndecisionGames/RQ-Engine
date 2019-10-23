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
            static const int SAMPLE_FRAME = 120;
            static const int MAX_STEPS = 5;

            FpsTimer(int maxFramesPerSecond=60);

            void start();
            void update();
            void limit();

            void setMaxFps(int maxFramesPerSecond);

            float getCurrentFPS();
            float getDeltaTime();
            float getMaxDeltaTime();

        private:
            sf::Clock clock;
            sf::Time startTime;
            sf::Time previousFrameTime;

            int maxFPS;
            float currentFPS = 0.0f;
            sf::Time fpsCounterTime; // Time SAMPLE_RATE frames ago
            int frameCount = 0;

    };

}
