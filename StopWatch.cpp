#include "StopWatch.h"
#include <stdio.h>
#include <time.h>



StopWatch::StopWatch()
{
	this->watch = 0;
	this->time = 0;
}

bool StopWatch::Start()
{
	bool isStarted = false;

	if (!IsTicking())
	{
		this->watch = clock();
		isStarted = true;
	}

	return isStarted;
}

bool StopWatch::Stop()
{
	bool isStopped = false;

	if (IsTicking())
	{
		this->watch = clock() - this->watch;
		time = this->watch;
		isStopped = true;
	}

	return isStopped;
}

bool StopWatch::IsTicking()
{
	bool isTicking = true;

	if (this->watch == 0)
	{
		isTicking = false;

	}

	return isTicking;
}

void StopWatch::DisplayTimerInfo()
{
	printf("%.3f seconds have passed.\n", (float)this->time/CLOCKS_PER_SEC);
}


//Getters/Setters
double StopWatch::getTime()
{
	return time;
}

void StopWatch::setTime(double time)
{
	this->time = time;
}
