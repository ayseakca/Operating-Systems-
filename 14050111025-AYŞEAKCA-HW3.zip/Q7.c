#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
int n[10000];
void *Arr(void *threadid){
   long tid;
   tid= (long)threadid;
   int i;
   for(i=0;i<10000;i++){
   n[i]=0+rand()%50000;
   }
}
void *Randnum(void *threadid)
{
   long tid;
   tid= (long)threadid;
   int ind=0;
   int c1=0,c5=0,c2=0,c3=0,c4=0,i=0;
   for(ind=0;ind<5;ind++)
      for(i=(ind*1000); i<1000*(ind+1); i++){
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
    trd = pthread_create (&threads[0], NULL, Arr, (void *)t);
    pthread_join(threads[0],NULL);
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
centos@localhost:~/Desktop $ gcc -pthread -o Desktop Q7.c
centos@localhost:~/Desktop $ ./Desktop
Thread 0: 1-9: 1, 10-99: 11, 100-999: 82, 1000-9999: 896, 10000-99999: 4010
Thread 1: 1-9: 1, 10-99: 11, 100-999: 82, 1000-9999: 896, 10000-99999: 4010
Thread 2: 1-9: 1, 10-99: 11, 100-999: 82, 1000-9999: 896, 10000-99999: 4010
Thread 3: 1-9: 1, 10-99: 11, 100-999: 82, 1000-9999: 896, 10000-99999: 4010
Thread 4: 1-9: 1, 10-99: 11, 100-999: 82, 1000-9999: 896, 10000-99999: 4010

*/
