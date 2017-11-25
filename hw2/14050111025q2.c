#include<stdio.h>
#include <unistd.h>

int main(){
  
  FILE *f;
  f=fopen("data.txt","r");
  pid_t pid=fork();
  int count=0, num=0;
  char in;
    if(pid==0){
  	printf("[PARENT] Child process ID: %d\n",getpid());
  	in=getc(f);
  	while(in != EOF){
	  if(in=='0'||in=='1'||in=='2'||in=='3'||in=='4'||in=='5'||in=='6'||in=='7'||in=='8'||in=='9'){
            
	      num++;
	   }     
     	   in=getc(f); 
               
  	}
        fclose(f);
        printf("[CHILD2] Number of numbers: %d\n",num); 
        sleep(2);   
}

  f=fopen("data.txt","r");
  if(pid>0){
        printf("[PARENT] Child process ID: %d\n",getpid());
  	in=getc(f);
  	while(in != EOF){
	   if(in!='0' && in!='1' && in!='2' && in!='3' && in!='4' && in!='5' && in!= '6' && in!= '7' && in!='8' && in!='9' && in!=' '){
	     count++;
	   }     
        in=getc(f);    
      	}
  	printf("[CHILD1] Number of letters: %d\n",count);
	fclose(f);
  }
  

  return 0;
}
