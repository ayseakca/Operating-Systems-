#include<stdio.h>
#include<stdlib.h>
#include<time.h>    

 int main(){
  FILE *file; 
  file = fopen("numbers2.txt","w");

  int x,y;
  for(x=0; x<1000; x++){   
     y=100+rand()%900;
    fprintf(file,"%d \n",y);
  }
   return 0;
   }
/* cat numbers2.txt | grep -o '[2][0-9][0-9]'*/
