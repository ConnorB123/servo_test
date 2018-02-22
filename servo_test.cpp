#include "PCA9685.h"
#include <iostream>
#include <stdio.h>
//#include <ncurses.h>
//#include <thread>
#include <unistd.h>

using namespace std;
int main () {

	PCA9685 pwm1;
	pwm1.init(1,0x40);

  PCA9685 pwm2;
	pwm2.init(1,0x40);

	pwm1.setPWMFreq(61);
  pwm2.setPWMFreq(150);
	usleep(1000 * 1000);

	int count = 0;
	while (count++<10) {

		pwm1.setPWM(0,0,150);
    pwm2.setPWM(1,0,600);
		usleep(1000 * 1000);

    pwm1.setPWM(0,0,600);
    pwm2.setPWM(0,0,150);

		usleep(1000 * 1000);

	}

	pwm1.setPWM(0,0,0);
	pwm2.setPWM(1,0,0);
	printf ("\n");

	return 0;
}
