#include<stdio.h>
#include<pthread.h>



int a[10][10],b[10][10],c[10][10], n, m,p,q,curr=0;
void *mul(void *arg)
{ 
 
int i=curr;
for(int j=0;j<q;j++)
{

for(int k=0;k<p;k++)
{
c[i][j]+=a[i][k]*b[k][j];
}

}

curr++;


pthread_exit(0);


}


int main()
{

printf("Value for row of 1:- ");
 scanf("%d",&n);
 printf("Value for column of 1:-");
 scanf("%d",&m);
 printf("Value for row of 2:- ");
 scanf("%d",&p);
 printf("Value for column of 2:-");
 scanf("%d",&q);
 printf("Value for matrix 1:-");
 
 for(int i=0;i<n;i++)
 {
 
 for(int j=0;j<m;j++)
 {
 
 scanf("%d",&a[i][j]);
 }
 }
 
 printf("Value for matrix 2:-");
 for(int i=0;i<p;i++)
 {
 
 for(int j=0;j<q;j++)
 {
 
 scanf("%d",&b[i][j]);
 }
 }
pthread_t tid[n];

for(int i=0;i<n;i++)
{pthread_create(&tid[i],NULL,mul,NULL);}

for(int i=0;i<n;i++)
{
pthread_join(tid[i],NULL);
}

printf("\nResult is:\n");
for(int i=0;i<n;i++)
  {  for(int j=0;j<q;j++)
	  { printf("%d \t",c[i][j]);}
       printf("\n");
  } 



return 0;

}
