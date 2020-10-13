read -p "Enter num1-" num1
read -p "Enter num2-" num2

echo "****Menu****
1.Add
2.Subtract
3.Multiply
4.Divide
5.Exit"

read -p "Enter choice-" c
case "$c" in
1) expr $num1 + $num2;;
2)expr $num1 - $num2;;
3)expr $num1 * $num2;;
4)expr $num1 / $num2;;
5)exit;;

esac
