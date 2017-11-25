#include<signal.h>
#include<stdio.h>
int i,a=0,sum=0,avarage=0;

void sig_handler(int signo)
{
  if (signo == SIGINT)
      avarage=sum/a;
	printf("input is %d ",a);
	printf("The average is %d ",avarage);
  
}

int main(){
	
        signal(SIGINT, sig_handler);
	while(a!=-1){
		printf("Enter an integer(-1 for exit):");
		scanf("%d",&i);
		if(i==-1){
		break;	
		}
		sum=sum+i;
		
		++a;
	}
       
	return 0;
}

}
