#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
int n[10000];
void *Arr(void *threadid){
   long tid;
   tid= (long)threadid;
   int i;
   for(i=0;i<10000;i++){
   n[i]=1000+rand()%9000;
   }
}

void *Randnum(void *threadid)
{
   int ind=0;	
   long tid;
   tid= (long)threadid;
   int i=0,j=0;
   int count=0,state=0;
   //srand(time(NULL));
 for(ind=0;ind<10;ind++){   
   for(i=(ind*1000); i<1000*(ind+1); i++){
     for(j=2;j<n[i];j++){
        if((n[i]%j)==0){
          state=1;
          break;
      }
    }
    if(state==0){
     count++;
   }
  }
 }
 printf("%d primes.\n", count);
   pthread_exit(NULL);
}
int main(int argc, char *argv[])
{
   pthread_t threads[10];
   int trd=0;
   long t;
    trd = pthread_create (&threads[0], NULL, Arr, (void *)t);
    pthread_join(threads[0],NULL);
   for(t=0;t<10;t++){
     printf("Thread %ld - ", t);
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
centos@localhost:~/Desktop $ gcc -pthread -o Desktop Q5.c
centos@localhost:~/Desktop $ ./Desktop
Thread 0 - 0 primes.
Thread 1 - 0 primes.
Thread 2 - 0 primes.
Thread 3 - 0 primes.
Thread 4 - 0 primes.
Thread 5 - 0 primes.
Thread 6 - 0 primes.
Thread 7 - 0 primes.
Thread 8 - 0 primes.
Thread 9 - 0 primes.
*/
