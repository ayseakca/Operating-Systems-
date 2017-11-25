#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<time.h>

int count=0;

void sig_handler(int signo){
     count++;
}
void sig_handler1(int signo){
     count++;
}

int main(){
   srand(time(NULL));
   int n=0, num=0;
   char let;
   while(n<15){
	if(count%2==0){
	     num=rand()%20;
	     printf("%d\n",num);
	     n++;
   	     signal(SIGINT, sig_handler1);     
	}
	else if(count%2!=0){
	     int l = rand()%62;
	     let=(char)(l+65);
	     if(let<=90&&let>=65||let>=97&&let<=122)
    	     {
	     printf("%c\n",let);
	     n++;
	     }
   	     signal(SIGINT, sig_handler);	
	}
	sleep(1);
   }

}
