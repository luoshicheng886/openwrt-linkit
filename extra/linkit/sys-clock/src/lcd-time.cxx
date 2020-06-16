/*
 * Author: Thomas Ingleby <thomas.c.ingleby@intel.com>
 * Copyright (c) 2014 Intel Corporation.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <upm/lcm1602.h>
#include <unistd.h>
#include <signal.h>
#include <ctime>
#include <string>
#include <iostream>

using namespace std;

int shouldRun = true;

void sig_handler(int signo)
{
	if (signo == SIGINT)
		shouldRun = false;
}

int main(int argc, char **argv)
{
	signal(SIGINT, sig_handler);

	upm::Lcm1602* lcd = new upm::Lcm1602(0, 0x27);
	char date[20], dtime[12];
	string last_date, last_time;

	lcd->clear();
	while (shouldRun) {
		time_t curr_time = time(0);
		tm* datetime = localtime(&curr_time);

		strftime(date, sizeof(date), "%Y-%m-%d", datetime);
		strftime(dtime, sizeof(dtime), "%X", datetime);
		if (last_date.compare(date)) {
			lcd->setCursor(0, 3);
			last_date = date;
			lcd->write(date);
		}
		if (last_time.compare(dtime)) {
			lcd->setCursor(1, 4);
			last_time = dtime;
			lcd->write(dtime);
		}
		usleep(100000);
	}
	delete lcd;
	cout << "Exitting. Bye!" << endl;
	return 0;
}
