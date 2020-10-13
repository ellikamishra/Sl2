#!/bin/bash

read -p "Enter no." num

for i in 1 2 3 4 5 6 7 8 9 10
do
   echo "$((i * num))"
done

read -p "Enter num1" num1
read -p "Enter num2" num2

expr $num1 + $num2
expr $num1 - $num2
expr $num1 * $num2
if [ $num2 -eq 0 ]
then 
   echo "Denominator is 0"
else
   expr $num1 / $num2
fi
