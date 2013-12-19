#!/bin/bash
#ping 192.168.0.*~192.168.5.*网段，如果主机是通的，记录主机IP
LOG_FILE=/home/active_ip.txt

date >>"$LOG_FILE"
for j in {0,1,2,3,4,5}
do
    echo "$j"
    i=1
    while [ "$i" -le 255 ]
    do
        ping -c1 192.168."$j"."$i"|grep ttl|cut -d: -f1|cut -d' ' -f4 >>"$LOG_FILE"
        i=$((i+1))
    done
done
