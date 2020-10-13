#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>
#define max 10


sem_t full,empty;
pthread_mutex_t mutex;
int count =0,in=0,out=0,a[max];


void *producer(void *arg)
{
  int n=(int*)arg;

  while(true)
{
  sem_wait(&empty);
  pthread_mutex_lock(&mutex);
  if(count>=5) printf("\nFull");

  else{
  
  a[in]=rand()%100;
  printf("\nProducer %d produced item : %d",n,a[in]);in=(in+1)%5;
  count++;
  }
  
  pthread_mutex_unlock(&mutex);
  sem_post(&full);
}

pthread_exit(0);

}


void *consumer(void *arg)
{
int n=(int*)arg;

  while(true)
  {
  sem_wait(&full);
  pthread_mutex_lock(&mutex);
  
  if(count<=0)printf("\nBuffer is empty...");
  else{
  printf("\nConsumer%d consumed item : %d",n,a[out]);out=(out+1)%5;count--;}
  pthread_mutex_unlock(&mutex);
  sem_post(&empty);
  
  }

pthread_exit(0);
}



int main()
{

 int p,c;
pthread_t pth[max],cth[max];

pthread_mutex_init(&mutex,NULL);
sem_init(&full,0,0);
sem_init(&empty,0,5);

printf("\nenter the num. of producers and consumers: ");
scanf("%d%d",&p,&c);

for(int i=0;i<p;i++) pthread_create(&pth[i],NULL,producer,(void *)i);
for(int i=0;i<c;i++) pthread_create(&cth[i],NULL,consumer,(void *)i);

for(int i=0;i<p;i++) pthread_join(&pth[i],NULL);
for(int i=0;i<c;i++) pthread_join(&cth[i],NULL);


pthread_mutex_destroy(&mutex);
sem_destroy(&full);
sem_destroy(&empty);
return(0);
}

