Monitoring.sh
architecture + kernel :					uname -a
CPU :									lscpu | grep "CPU(s)" | head -n 1
virtual CPU :							nproc
current available RAM :					free | awk '{print ($4 / $2) * 100'
current avalable storage:				df --total | awk 'END {print 100 - ($5 + 0) "%"}'
current utilization rate of processor :	top | awk 'NR=3 {print $2 + $4 "%"}'
date and time of the last reboot :		whp -b | awk '{print $3 " " $4'
LVM is active or not :					if [lsblk -eq 0]; then echo "active"; echo "inactive"; fi
The number of active connections :		ss | wc -l
The number of users using the server :	users | wc -w
server IPv4 address and MAC address :	hostname -I && ip link show | grep "link/ether" | awk '{print $2}'

number of commands executed with sudo :	cat /va/log/sudo/sudo.log | wc -l | awk '{print $1 / 2}'

