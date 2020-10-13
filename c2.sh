#!/bin/bash

n=1
while [ $n -eq 1 ]
printf "****Menu****\n1.List\n2.Process\n3.Date\n4.User\n5.Exit\n"

do
  read -p "Enter choice-" c

 case "$c" in
 1)ls -l;;
 2)ps -f;;
 3)date;;
 4)who;;
 5)exit;;
 
 esac
 
 echo "1 to continue else to exit"
 read n

done
