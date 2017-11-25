# Operating-Systems-
Homework Codes
#include<stdio.h>
#include<stdlib.h>
#include<time.h>    

 int main(){
  FILE *file; 
  file = fopen("numbers.txt","w");

  int x,y;
  printf("Enter the value of M and N: ");
  scanf("%d",&x);
  scanf("%d",&y);

  int m[x][y];
  int i,j;
    for(i=0; i<x; i++){
      for(j=0; j<y; j++){
        m[i][j]=rand()%100;
      }
    }
    for(i=0; i<x; i++){
       for(j=0; j<y; j++){
         printf("%d ",m[i][j]);
         fprintf(file,"%d ",m[i][j]);
       }
       printf("\n");
       fprintf(file,"\n");
    }
   return 0;
   }
