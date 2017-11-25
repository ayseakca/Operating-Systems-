#include<stdio.h>
#include<stdlib.h>
#include<time.h>    

int main(){
  FILE *f; 
  f = fopen("numbers.txt","w");

  int M, N, i, j;
  printf("Enter the value of M and N: ");
  scanf("%d",&M);
  scanf("%d",&N);

  int numbers[M][N];
  
    for(i=0; i<M; i++){
      for(j=0; j<N; j++){
        numbers[i][j]=rand()%100;
      }
    }
    for(i=0; i<M; i++){
       for(j=0; j<N; j++){
         printf("%d ",numbers[i][j]);
         fprintf(f,"%d ",numbers[i][j]);
       }
       printf("\n");
       fprintf(f,"\n");
    }
   return 0;
}

/*
centos@localhost:~ $ cd Desktop
centos@localhost:~/Desktop $ cd Lab1Q1
centos@localhost:~/Desktop/Lab1Q1 $ gcc -o Lab1Q1 14050111028-Lab1Q1.c
centos@localhost:~/Desktop/Lab1Q1 $ ./Lab1Q1
Enter the value of M and N: 2
3
83 86 77 
15 93 35 
centos@localhost:~/Desktop/Lab1Q1 $ cat numbers.txt
83 86 77 
15 93 35 
*/
