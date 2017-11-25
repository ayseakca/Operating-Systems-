#include<stdio.h>
#include <unistd.h>
#include<time.h>
#include<stdlib.h>



int main(){
    int num,n;
    char letter,l; 
    
  FILE *f,*file;
   
    
  f=fopen("data1.txt","w");
    file=fopen("data2.txt","w");
    srand(time(NULL));
    int x;
   pid_t pid=fork();
    for(x=0; x<10; x++){   
     num=rand()%10;
    fprintf(f,"%d \n",num);
       int n = 97+rand()%25;
      letter=(char)(n);
      
      fprintf(file,"%c",letter);   
  }
   fclose(f);
   fclose(file);
 

FILE *readfiledata1, *readfiledata2;

   readfiledata1=fopen("data1.txt","r");
    readfiledata2=fopen("data2.txt","r");



 if(pid>0){
        printf("[PARENT] Child process ID: %d\n",getpid());
  	n=getc(readfiledata1);
        printf("[CHILD1] Wrote:");
  	while(n != EOF){
        n=getc(readfiledata1);
	fscanf(readfiledata1,"%d ",n);   
      	}
        printf("to file. "); 
  
	fclose(readfiledata1);
  }
  
if(pid==0){
  	printf("[PARENT] Child process ID: %d\n",getpid());
  	l=getc(readfiledata2);
        printf("[CHILD2] Wrote: ");
  	while(l != EOF){
       l=getc(readfiledata2); 	  	
       fscanf(readfiledata2,"%c ",l); 
	   }     

        printf("to file. ");
        fclose(readfiledata2);
}

        sleep(2);   
return 0 ;
}



