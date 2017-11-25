#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<time.h>

int count=1;

void sig_handler(int signo){
   printf("[Decreasing]");
        
   count++;
}
void sig_handler1(int signo){
   printf("[Increasing]");
     count--;
}

int main(){
   srand(time(NULL));
   int num=100+rand()%100;

   while(num<200 && num>100){
	if(count%2==0){
	     num=num+10;
             
	     printf("Variable: %d\n",num);
   	     signal(SIGINT, sig_handler);
   	     if(num>200 || num<100){
	         break;}
	}
	else if(count%2!=0){
	     num=num-10;
       
	     printf("Variable: %d\n",num);
   	     signal(SIGINT, sig_handler1);	
	}
	sleep(1);
   }

}
