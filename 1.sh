#!/bin/bash
n=1
while [ $n -le 5 ]
do
  echo "$n"
  n=$(( n+1 ))
done

while (( $n <=10 ))
do
  echo "$n"
  (( ++n ))
done



n=0
while [ $n -le 5 ]
do
  l=n
  while [ $l -le 0 ]
  do 
    echo "$l"
    l=$(( l-1 ))
  done
  n=$(( n+1 ))
done
    
   
  
  
