#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include "gpio.h"

int main(int argc, char **argv)
{
	
	int opt, gpio_pin, state, duration;
	pull_type down = PULL_UP; // Pull-up because relais are low-active
	
	gpio_pin = 4;
	duration = 0;
	
	
	if (gpio_init() != 0)
	{
		fprintf(stderr, "Can't init gpio. run programm with \"sudo\"\r\n");
		return -4;
	}
	
	gpio_set_pull(gpio_pin, down);
	gpio_set_output(gpio_pin);
	
	
	while ((opt = getopt(argc, argv, "g:s:d:h")) != -1)
	{
		switch (opt)
		{
			case 'g':
				gpio_pin = atoi(optarg);
				break;
			case 's':
				state = atoi(optarg);
				break;
			case 'd':
				duration = atoi(optarg);
				break;				
			case 'h':
			default:
				fprintf(stderr,
					"Usage: %s [flags]\n"
					"Example: %s -s0 -d3 (set default gpio for 3sec. low)\n"
					"\n"
					"Flags:\n"
					"\t-g <number>  	GPIO number to use (4=default)\n"
					"\t-s <state>   	State for GPIO(0=default 1=high)\n"
					"\t-d <duration>    Duration in seconds (default=0) \n"					
					"\n",
					argv[0]);
				return -1;
		}
	}	
	
	if (duration != 0) {
		// set state
		gpio_write(gpio_pin, state);
		// wait
		for (int i=0; i<duration; i++) 
			sleep(1);
		// reset state 
		if (state == 1) 
			state = 0; 
		else 
			state = 1;
		gpio_write(gpio_pin, state);
	} else 
		gpio_write(gpio_pin, state);
	
	return 0;
}
