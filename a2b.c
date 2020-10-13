#include<stdio.h>
#include<sys/types.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<ctype.h>
#define MAX 20


void bsort(int arr[],int n)
{



   int i, j,temp,swapped; 
   for (i = 0; i < n-1; i++) 
   { 
     swapped = 0; 
     for (j = 0; j < n-i-1; j++) 
     { 
        if (arr[j] > arr[j+1]) 
        { 
           temp=arr[j];
           arr[j]=arr[j+1];
           arr[j+1]=temp; 
           swapped = 1; 
        } 
     } 
  
     
     if (swapped == 0) 
        break; 
   
} 


}


int main(int argc, char *argv[])
{
int i,arr[MAX],num;
pid_t pid=1;
char *str=NULL;
char *arg[MAX];
printf("\nEnter the number Of elements for sorting : \n");
{scanf("%d",&num);}
printf("\nEnter the elements : ");
for(i=0;i<num;i++)
{scanf("%d",&arr[i]);}
bsort(arr,num);
pid=fork();



if (pid==-1){printf("\nError");}


if(pid==0){
printf("\nI am child process,pid: %d",getpid());
for(i=0;i<num;i++)
{printf("%d\t",arr[i]);}
for(i=0;i<num;i++)
{sprintf(str,"%d\t",arr[i]);
arg[i]=malloc(sizeof(str));


strcpy(arg[i],str);
}

arg[i]=NULL;
execv(argv[1],arg);
printf("\nDone child process");
}

if(pid>0){
wait();
printf("\nI am parent process,pid: %d",getpid());


printf("\n");
for(i=0;i<num;i++)
{printf("%d\t",arr[i]);}

printf("\nDone parent process");


}

return 0;
}


