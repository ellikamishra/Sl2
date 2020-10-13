#!/bin/bash
n=0
while [ $n -le 5 ]
do
  l=$n
  while (( $l >=0 ))
  do
  
    echo -n "$l"
    l=$(( l-1 ))
  done
  echo -e "\n"
  n=$(( n+1 ))
done
