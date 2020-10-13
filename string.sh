#!/bin/bash

read -p "enter string-" str

if [ -n str ]
then
echo "****Menu****
1.Length
2.Substring start position
3.Exit"

read -p "Enter choice-" c

case "$c" in

1) expr "$str" : ."*";;
2) read -p "enter substring-" s1
 if [[ "$str" == *"$s1"* ]]; then
  expr index "$s1" "$str" 
  fi
  ;;

3)exit;;
esac
fi


