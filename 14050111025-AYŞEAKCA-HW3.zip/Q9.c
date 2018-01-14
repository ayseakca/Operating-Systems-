#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
int n[50000];
void *Arr(void *threadid){
   long tid;
   tid= (long)threadid;
   int i=0;
   int a=0;
     
     while(i<50000){
        a = 97+rand()%122;
            n[i]=a; 
            i++;   	    
	 }
}
void *Randnum(void *threadid)
{
   long tid;
   tid = (long)threadid;
   int j=0;
   int count1=0,count2=0;  
     for(j=0; j<50000; j++){
		if(n[j]==97 || n[j]==101|| n[j]==105|| n[j]==111|| n[j]==117){
			count1++;}
		else{ count2++;}
	}
 
printf(":  Vowels: %d, consonants: %d \n",count1,count2);
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
     printf("Thread %ld - %ld", t,&threads[t]);
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
centos@localhost:~/Desktop $ gcc -pthread -o Desktop Q9.c
centos@localhost:~/Desktop $ ./Desktop
Thread 0 - 140729292209216:  Vowels: 1985, consonants: 48015 
Thread 1 - 140729292209224:  Vowels: 1985, consonants: 48015 
Thread 2 - 140729292209232:  Vowels: 1985, consonants: 48015 
Thread 3 - 140729292209240:  Vowels: 1985, consonants: 48015 
Thread 4 - 140729292209248:  Vowels: 1985, consonants: 48015 
Thread 5 - 140729292209256:  Vowels: 1985, consonants: 48015 
Thread 6 - 140729292209264:  Vowels: 1985, consonants: 48015 
Thread 7 - 140729292209272:  Vowels: 1985, consonants: 48015 
Thread 8 - 140729292209280:  Vowels: 1985, consonants: 48015 
Thread 9 - 140729292209288:  Vowels: 1985, consonants: 48015 
*/
