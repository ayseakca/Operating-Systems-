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

    printf("\nFCFS Average Waiting Time=%f\n",awt);
    
   }
/*
centos@localhost:~/Desktop $ gcc -o Desktop f.c
centos@localhost:~/Desktop $ ./Desktop
Process[0] -> During Time:9 -> Order:1 -> Arrival Time:0
Process[1] -> During Time:1 -> Order:2 -> Arrival Time:2
Process[2] -> During Time:5 -> Order:3 -> Arrival Time:1
Process[3] -> During Time:3 -> Order:4 -> Arrival Time:2
Process[4] -> During Time:7 -> Order:5 -> Arrival Time:1
Process[5] -> During Time:2 -> Order:6 -> Arrival Time:2
Process[6] -> During Time:8 -> Order:7 -> Arrival Time:2
Process[7] -> During Time:3 -> Order:8 -> Arrival Time:2
Process[8] -> During Time:1 -> Order:9 -> Arrival Time:1

Execution 1 -> Wating Time:0
Execution 2 -> Wating Time:9
Execution 3 -> Wating Time:10
Execution 4 -> Wating Time:15
Execution 5 -> Wating Time:18
Execution 6 -> Wating Time:25
Execution 7 -> Wating Time:27
Execution 8 -> Wating Time:35
Execution 9 -> Wating Time:38

FCFS Average Waiting Time=19.666666

*/
