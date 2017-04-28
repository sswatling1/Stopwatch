#include <time.h>

class StopWatch
{
private:
	clock_t time;
	clock_t watch;

public:



	StopWatch();

	bool Start();

	bool Stop();

	bool IsTicking();

	void DisplayTimerInfo();


	//Getters/Setters
	double getTime();

	void setTime(double time);

};