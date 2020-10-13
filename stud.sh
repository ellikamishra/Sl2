n=1
echo "****Menu****
1.Accept
2.Display
3.Subject Result
4.Overall Result
5.Exit"
while [ $n -eq 1 ]
do
  read -p "Enter choice-" c

 case "$c" in


 1)read -p "Enter rolno." rn
 read -p "Enter name" name
 read -p "Enter class" class
 read -p "Enter division" div
 read -p "Enter sub1 marks" s1
 read -p "Enter sub2 marks" s2
 read -p "Enter sub12marks" s3;;
 2) echo "Name:`$name`"
   echo "Rollno:`$rn`"
   echo "Class:`$class`"
   echo "Division:`$div`"
   echo "Sub1:`$s1`"
   echo "Sub2:`$s2`"
   echo "Sub3:`$s3`";;
 esac

 echo "1 to continue else to exit"
 read n

done
