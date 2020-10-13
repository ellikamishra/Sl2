#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 

void odd_even(int a)
{

if(a%2==0)
{printf("\nEven");}
else
{printf("\nOdd");}

}


void table(int a)
{
for(int i=1;i<=10;i++)
{printf("\n%d",a*i);}

}
void prime(int a)
{int i;
for(i=2;i<a;i++)
{
  if(a%i==0)
  {printf("\nComposite");break;}
  
}
if(i==a)
{printf("\nPrime");}
}
int main(){

int a,pid;
printf("\nenter no.");
scanf("%d",&a);
pid=1;
//printf("%d\n",pid);
pid=fork();

switch(pid){

case -1:printf("\nError");
break;

case 0:printf("\nI am child process,pid: %d",getpid());
//c=a+b;
odd_even(a);
prime(a);
break;

default:

printf("\nI am parent process,pid: %d",getpid());
sleep(50);
table(a);

}

return 0;
}
