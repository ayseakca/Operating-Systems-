#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *Randnum(void *threadid)
{
   long tid;
   tid= (long)threadid;
   int n[2000];
   int c1=0,c5=0,c2=0,c3=0,c4=0,i=0;
   //srand(time(NULL));
   for(i=0;i<2000;i++)
   n[i]=0+rand()%50000;
      for(i=0; i<2000; i++){
		if(n[i]>=0 && n[i]<10)
			c1++;
		if(n[i]>=10 && n[i]<100)
			c2++;
		if(n[i]>=100 && n[i]<1000)
			c3++;
		if(n[i]>=1000 && n[i]<10000)
			c4++;
		if(n[i]>=10000 && n[i]<100000)
			c5++;
	}
   
  printf("1-9: %d, 10-99: %d, 100-999: %d, 1000-9999: %d, 10000-99999: %d\n",c1,c2,c3,c4,c5);
       
   pthread_exit(NULL);

}
int main(int argc, char *argv[])
{
   pthread_t threads[5];
   int trd=0;
   long t;
   for(t=0;t<5;t++){
     printf("Thread %ld: ", t);
     trd = pthread_create (&threads[t], NULL, Randnum, (void *)t);
     pthread_join(threads[t],NULL);
     if (trd){
       printf("ERROR; return code from pthread_create() is %d\n", trd);
       exit(0);
       }
     }
   pthread_exit(NULL);
}
/*
centos@localhost:~/Desktop $ gcc -pthread -o Desktop Q6.c
centos@localhost:~/Desktop $ ./Desktop
Thread 0: 1-9: 0, 10-99: 5, 100-999: 37, 1000-9999: 372, 10000-99999: 1586
Thread 1: 1-9: 1, 10-99: 2, 100-999: 27, 1000-9999: 357, 10000-99999: 1613
Thread 2: 1-9: 0, 10-99: 6, 100-999: 44, 1000-9999: 346, 10000-99999: 1604
Thread 3: 1-9: 0, 10-99: 5, 100-999: 36, 1000-9999: 356, 10000-99999: 1603
Thread 4: 1-9: 3, 10-99: 4, 100-999: 43, 1000-9999: 347, 10000-99999: 1603
*/
