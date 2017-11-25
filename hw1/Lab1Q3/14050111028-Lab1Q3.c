#include<stdio.h>

int main() {
 
 int i,j;
 int number[10][10];

 srand(time(NULL));

  for(i=0; i<10; i++){
     for(j=0; j<10; j++){
        number[i][j]=rand()%10000;
    }
  }
  for(i=0; i<10; i++){
    for(j=0; j<10; j++){
        printf("%d ",number[i][j]);
    }
    printf("\n");
  }
  
return 0;
}

/*
centos@localhost:~ $ cd Desktop
centos@localhost:~/Desktop $ cd Lab1Q3
centos@localhost:~/Desktop/Lab1Q3 $ gcc -o Lab1Q3 14050111028-Lab1Q3.c
centos@localhost:~/Desktop/Lab1Q3 $ ./Lab1Q3 | sort -k3 -n -o sorted.txt
*/

