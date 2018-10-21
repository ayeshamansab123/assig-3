#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

int  t[1000];
int totalSum = 0;

void * sumofthreads(void *arg)
{
   int *ind=(int*)arg;
   int sum=0;
   int i  = 0;	
   for(i=*ind;i<*ind+100;i++)
   {
      sum=sum+t[i];
   }
   totalSum = totalSum + sum;
}


int main()
{
    int i = 0;
    int ind[10]={0,100,200,300,400,500,600,700,800,900};
    pthread_t c[10];
    for(i; i<1000; i++ )
    {
      t[i] = i;
    }
	
    for(i=0;i<10;i++)
     {
     	pthread_create(&c[i],NULL,sumofthreads,(void*)&ind[i]);
     }
    for(i=0;i<10;i++)
     {
     	pthread_join(c[i],NULL); 
     }

 	printf("%d\n", totalSum);
}

