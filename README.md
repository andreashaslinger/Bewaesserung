# Bewaesserung
Bewässerungssteuerung per Raspberry Pi 


pi@raspberrypi:~ $ crontab -e

# Edit this file to introduce tasks to be run by cron.
#
# Each task to run has to be defined through a single line
# indicating with different fields when the task will be run
# and what command to run for the task
#
# To define the time you can provide concrete values for
# minute (m), hour (h), day of month (dom), month (mon),
# and day of week (dow) or use '*' in these fields (for 'any').#
# Notice that tasks will be started based on the cron's system
# daemon's notion of time and timezones.
#
# Output of the crontab jobs (including errors) is sent through
# email to the user the crontab file belongs to (unless redirected).
#
# For example, you can run a backup of all your user accounts
# at 5 a.m every week with:
# 0 5 * * 1 tar -zcf /var/backups/home.tgz /home/
#
# For more information see the manual pages of crontab(5) and cron(8)
#
# m h  dom mon dow   command

# switch on water pump for 40 seconds at 8am and 8pm
00 8,20  * * *  sudo /home/pi/water/water -s0 -d40

# switch on water pump
#1 8,20 * * *  sudo /home/pi/water/water -s0pi@raspberrypi:~ $ crontab -e


# switch off water pump
#1 8,20  * * *  sudo /home/pi/water/water -s1


pi@raspberrypi:~/water $ sudo ./water -h
Usage: ./water [flags]
Example: ./water -s0 -d3 (set default gpio for 3sec. low)

Flags:
	-g <number>  	GPIO number to use (4=default)
	-s <state>   	State for GPIO(0=default 1=high)
	-d <duration>    Duration in seconds (default=0)
