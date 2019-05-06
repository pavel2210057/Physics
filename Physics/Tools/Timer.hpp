#ifndef TIMER_HPP
#define TIMER_HPP

#include <ctime>

class Timer {
	struct TimerData {
		time_t beginTime, currentTime;
	} timerData;
public:
	Timer();

	Timer(time_t beginTime);

	~Timer();

	time_t getSeconds();

	time_t getMilliseconds();

	time_t getMicroseconds();

	void reset(time_t beginTime);

	operator time_t();
protected:
	void update();
};

#endif //!TIMER_HPP