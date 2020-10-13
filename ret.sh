#!/bin/bash

Addition(){

result=`expr $1 + $2`

return $result
}

Subtraction(){

result=`expr $1 - $2`

return $result
}

Multi(){

result=`expr $1 * $2`

return $result
}

Div(){
if [ $2 -eq 0 ]
then 
   echo "Denominator is 0"
   result=0
else
   
   result=`expr $1 / $2`
fi
return $result
}

read -p "Enter number1:" a 
read -p "Enter number1:" b

echo "****Menu****
1.ADD
2.SUBTRACT
3.MULTIPLY
4.DIVIDE"

read -p "Enter choice" c

case "$c" in

1) Addition $a $b
  ans=$?

echo "Addition is $ans";;

2) Subtraction $a $b

ans=$?

echo "Subtraction is $ans";;

3) Multi $a $b
ans=$?

echo "Multiplication is $ans";;

4) Div $a $b
ans=$?

echo "Division is $ans";;

esac

