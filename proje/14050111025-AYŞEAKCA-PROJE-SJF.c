#include<stdio.h>
#include<stdlib.h>
#include<time.h>
  void main(){
	int p[10], dt[10],wt[10],total,order[10],arr[10],i=0,j=0,k=0,m=0,turn,temp;
	float awt;
	int process;
    	srand(time(NULL));
    	process=2+rand()%8;
	for( i=0;i<process;i++){
	    dt[i]=1+rand()%9;
            arr[i]=rand()%3;
	}
        for(j=0;j<process;j++){
	    printf("Process[%d] -> During Time:%d -> Order:%d -> Arrival Time:%d\n",j,dt[j],j+1,arr[j]);
	}
        for(k=0;k<process;k++){
            turn=k;
           for(m=k+1;m<process;m++){
               if(dt[m]<dt[k]){
               turn=m;
               }
	   }
           temp=dt[k];
           dt[k]=dt[turn];
           dt[turn]=temp;
 
           temp=p[k];
           p[k]=p[turn];
           p[turn]=temp;	
	}
          for(i=1;i<process;i++){
             wt[i]=0;
             for(j=0;j<i;j++)
             wt[i]+=dt[j];
 
             total+=wt[i];
    }
        printf("\n");
        awt=(float)total/process;      //average waiting time
          wt[0]=0;
          for(j=0;j<process;j++){
	    printf("Execution %d -> Wating Time:%d\n",j+1,wt[j]);
	}
    printf("\nNon-Preemetive Average Waiting Time=%f\n",awt);
    
   }
/*
centos@localhost:~/Desktop $ gcc -o Desktop s.c
centos@localhost:~/Desktop $ ./Desktop
Process[0] -> During Time:8 -> Order:1 -> Arrival Time:2
Process[1] -> During Time:9 -> Order:2 -> Arrival Time:2
Process[2] -> During Time:6 -> Order:3 -> Arrival Time:0
Process[3] -> During Time:1 -> Order:4 -> Arrival Time:2

Execution 1 -> Wating Time:0
Execution 2 -> Wating Time:1
Execution 3 -> Wating Time:9
Execution 4 -> Wating Time:15

Non-Preemetive Average Waiting Time=6.250000

*/
