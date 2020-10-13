
#include<stdio.h>
#include<sys/types.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<ctype.h>
#define MAX 20
int partition(int a[],int l,int h)
{ int temp;
int pivot=a[h];
int i=l-1;
for(int j=l;j<=h-1;j++)
{

if(a[j]<pivot)
{i++;
temp=a[j];
a[j]=a[i];
a[i]=temp;
}
}
temp=a[h];
a[h]=a[i+1];
a[i+1]=temp;

return i+1;

}
void quicksort(int a[MAX],int l,int h)
{


if(l<h)
{
int pi=partition(a,l,h);
quicksort(a,l,pi-1);
quicksort(a,pi+1,h);

}

}

void merge(int a[MAX],int l,int m,int r)
{

int i,j,k;
int n1=m-l+1;
int n2=r-m;

int L[n1],R[n2];

for(i=0;i<n1;i++)
   L[i]=a[l+i];
for(j=0;j<n2;j++)
   R[j]=a[m+1+j];
   i=0;j=0;k=l;

while(i<n1&&j<n2)
{ 

if(L[i]<=R[j])
{a[k]=L[i];
 i++;
}
else
{a[k]=R[j];
j++;
}
k++;
}   
while(i<n1)
{a[k]=L[i];
i++;
k++;
}

while(j<n2)
{a[k]=R[j];
j++;
k++;
}




}

void mergesort(int a[10],int l,int r)
{
if(l<r)
{
int m=l+(r-l)/2;

mergesort(a,l,m);
mergesort(a,m+1,r);

merge(a,l,m,r);
}
}


int main()
{

int i,arr[MAX],arrq[MAX],num,numq,pid;
printf("\nEnter the number Of elements for quick sort : \n");
scanf("%d",&numq);
printf("\nEnter the elements : ");
for(i=0;i<numq;i++)
{scanf("%d",&arrq[i]);}
printf("\nEnter the number Of elements for merge sort : \n");
{scanf("%d",&num);}
printf("\nEnter the elements : ");
for(i=0;i<num;i++)
{scanf("%d",&arr[i]);}
pid=fork();


switch(pid){

case -1:printf("\nError");
break;

case 0:printf("\nI am child process,pid: %d",getpid());
//printf("\nParent id:%d",getppid());
quicksort(arrq,0,numq);
system("ps -aux");
for(i=0;i<numq;i++)
{printf("%d\t",arrq[i]);}

printf("\nDone child process");
break;

default:

printf("\nI am parent process,pid: %d",getpid());
mergesort(arr,0,num);
system("ps -aux");
wait();
for(i=0;i<num;i++)
{printf("%d\t",arr[i]);}

printf("\nDone parent process");

}



return 0;

}
