#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *Randnum(void *threadid)
{
   long tid;
   tid = (long)threadid;
   int n[5000];
   int i=0,j=0,a=0;
   int count1=0,count2=0;
   
     while(i<5000){
        a = 97+rand()%122;
            n[i]=a; 
            i++;   	    
	 }
      
     for(j=0; j<5000; j++){
		if(n[j]==97 || n[j]==101|| n[j]==105|| n[j]==111|| n[j]==117)
			count1++;
		else count2++;
	}
 
printf(":  Vowels: %d, consonants: %d \n",count1,count2);
   pthread_exit(NULL);
}
int main(int argc, char *argv[])
{
   pthread_t threads[10];
   int trd=0;
   long t;
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
centos@localhost:~/Desktop $ gcc -pthread -o Desktop Q8.c
centos@localhost:~/Desktop $ ./Desktop
Thread 0 - 140729864033472:  Vowels: 199, consonants: 4801 
Thread 1 - 140729864033480:  Vowels: 189, consonants: 4811 
Thread 2 - 140729864033488:  Vowels: 184, consonants: 4816 
Thread 3 - 140729864033496:  Vowels: 202, consonants: 4798 
Thread 4 - 140729864033504:  Vowels: 196, consonants: 4804 
Thread 5 - 140729864033512:  Vowels: 201, consonants: 4799 
Thread 6 - 140729864033520:  Vowels: 199, consonants: 4801 
Thread 7 - 140729864033528:  Vowels: 199, consonants: 4801 
Thread 8 - 140729864033536:  Vowels: 210, consonants: 4790 
Thread 9 - 140729864033544:  Vowels: 206, consonants: 4794
*/
