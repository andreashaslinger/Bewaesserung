# Bewaesserung
Bewässerungssteuerung per Raspberry Pi 


pi@raspberrypi:~ $ crontab -e

Add Lines to crontab

\# switch on water pump for 40 seconds at 8am and 8pm
00 8,20  * * *  sudo /home/pi/water/water -s0 -d40

\# switch on water pump
\#1 8,20 * * *  sudo /home/pi/water/water -s0pi@raspberrypi:~ $ crontab -e

\# switch off water pump
\#1 8,20  * * *  sudo /home/pi/water/water -s1

# How to start the program
pi@raspberrypi:~/water $ sudo ./water -h

Usage: ./water [flags]
Example: ./water -s0 -d3 (set default gpio for 3sec. low)

Flags:
	-g <number>  	GPIO number to use (4=default)
	-s <state>   	State for GPIO(0=default 1=high)
	-d <duration>    Duration in seconds (default=0)
