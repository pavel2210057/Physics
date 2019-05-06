#include "Timer.hpp"

Timer::Timer() {
	timerData.beginTime = time(NULL);
}

Timer::Timer(time_t beginTime) {
	timerData.beginTime = time(NULL) + beginTime;
}

Timer::~Timer() {}

time_t Timer::getSeconds() {
	return *this;
}

time_t Timer::getMilliseconds() {
	return *this / 1000;
}

time_t Timer::getMicroseconds() {
	return *this / 1000000;
}

void Timer::reset(time_t beginTime) {
	timerData.beginTime = time(NULL);
}

Timer::operator time_t() {
	update();
	return timerData.currentTime;
}

void Timer::update() {
	timerData.currentTime = time(NULL) - timerData.beginTime;
}