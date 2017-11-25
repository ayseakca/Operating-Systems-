#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
 
 int x,y;
 int matrix[10][10];

 srand(time(NULL));

  for(x=0; x<10; x++){
     for(y=0; y<10; y++){
        matrix[x][y]=rand()%10000;
    }
  }
  for(x=0; x<10; x++){
    for(y=0; y<10; y++){
        printf("%d ",matrix[x][y]);
    }
    printf("\n");
  }
  }
return 0;
}
/* ./Desktop | sort -n -k3 -o sorted.txt */

