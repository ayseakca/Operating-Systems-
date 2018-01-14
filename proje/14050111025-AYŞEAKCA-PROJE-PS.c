#include<stdio.h>
#include<stdlib.h>
#include<time.h>
  void main(){
	int p[10], dt[10],wt[10],total,order[10],arr[10],pr[10],i=0,j=0,k=0,m=0,turn,temp;
	float awt;
	int process;
    	srand(time(NULL));
    	process=2+rand()%8;
	for( i=0;i<process;i++){
	    dt[i]=1+rand()%9;
            arr[i]=rand()%3;
            pr[i]=rand()%5;
	}
        for(j=0;j<process;j++){
	    printf("Process[%d] -> During Time:%d -> Order:%d -> Priority: %d -> Arrival Time:%d\n",j,dt[j],j+1,pr[j],arr[j]);
	}
         for(i=0;i<process;i++)
    {
        turn=i;
        for(j=i+1;j<process;j++)
        {
            if(pr[j]>pr[turn])
                turn=j;
        }
 
        temp=pr[i];
        pr[i]=pr[turn];
        pr[turn]=temp;
 
        temp=dt[i];
        dt[i]=dt[turn];
        dt[turn]=temp;
 
        temp=p[i];
        p[i]=p[turn];
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

    printf("\nPriority Shceduling Average Waiting Time=%f\n",awt);
    
   }
/*
centos@localhost:~/Desktop $ gcc -o Desktop p.c
centos@localhost:~/Desktop $ ./Desktop
Process[0] -> During Time:1 -> Order:1 -> Priority: 0 -> Arrival Time:1
Process[1] -> During Time:6 -> Order:2 -> Priority: 4 -> Arrival Time:1
Process[2] -> During Time:6 -> Order:3 -> Priority: 4 -> Arrival Time:2
Process[3] -> During Time:3 -> Order:4 -> Priority: 1 -> Arrival Time:0
Process[4] -> During Time:9 -> Order:5 -> Priority: 0 -> Arrival Time:1

Execution 1 -> Wating Time:0
Execution 2 -> Wating Time:6
Execution 3 -> Wating Time:12
Execution 4 -> Wating Time:15
Execution 5 -> Wating Time:16

Priority Shceduling Average Waiting Time=9.800000

*/
