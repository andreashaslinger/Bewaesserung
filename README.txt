Bewässerungssteuerung per Raspberry Pi 

Edit crontab:
pi@raspberrypi:~ $ crontab -e

Add Lines to crontab:
\# switch on water pump for 40 seconds at 8am and 8pm
00 8,20  * * *  sudo /home/pi/water/water -s0 -d40

# switch on water pump
#1 8,20 * * *  sudo /home/pi/water/water -s0pi@raspberrypi:~ $ crontab -e

# switch off water pump
#1 8,20  * * *  sudo /home/pi/water/water -s1

How to start the program:
pi@raspberrypi:~/water $ sudo ./water -h
Usage: ./water [flags]
Example: ./water -g2 -s0 -d3 (set gpio 2 for 3sec. low level)

Flags:
	-g <number>  	GPIO number to use (4=default)
	-s <state>   	State for GPIO(0=default 1=high)
	-d <duration>    Duration in seconds (default=0)


The relais cards work on active low level. So when gpio pin is low the relais is switching.
