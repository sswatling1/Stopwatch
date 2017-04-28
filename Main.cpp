#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "StopWatch.h"

using namespace std;

void sleep(clock_t delayInMS);

int main()
{
	int progressCounter = 0;
	int progressStriker = 0;

	// make the timer
	StopWatch myTimer;

	// start the timer
	cout << "Press any key to start the stopwatch..." << endl;

	_getch();

	myTimer.Start();

	// display progress bar flicker
	cout << "The stopwatch has been started, press any key to stop it..." << endl;

	progressCounter = 1;

	progressStriker = 0;

	while (!_kbhit()) {

		// display the appropriate timing symbol
		if (progressStriker % 2 == 0)
			cout << ".";
		else
			cout << " ";
		// if the progress bar reaches the end of the line
		// goto a new line and change the timing symbol
		progressCounter++;

		if (progressCounter == 80) {
			progressCounter = 1;
			progressStriker++;
			_putch(13); // carriage return
		}
		sleep(10);
	}

	cout << endl;
	myTimer.Stop();
	myTimer.DisplayTimerInfo();
	_getch();

	return 0;
}

void sleep(clock_t delayInMS) {

	clock_t targetTime = clock() + delayInMS;

	while (clock() < targetTime);

}