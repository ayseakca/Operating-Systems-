#include<stdio.h>
#include<stdlib.h>
#include<time.h>    

int main(){
  FILE *f; 
  f = fopen("numbers2.txt","w");

  int i,number;
  for(i=0; i<1000; i++){   
     number=100+rand()%900;
     fprintf(f,"%d",number);
     fprintf(f,"\n");
  }
  return 0;
}

/*centos@localhost:~/Desktop/Lab1Q2 $ cat numbers2.txt | grep -o '[2][0-9][0-9]' */

