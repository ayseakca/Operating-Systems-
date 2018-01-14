#include<stdio.h>
#include<stdlib.h>
#include<time.h>
  void main(){
	int p[10], dt[10],total,order[10],arr[10],i=0,j=0,k=0,m=0,turn,temp,tq,t,flag,wt=0,rt[10],n;
	float awt;
	int process;
    	srand(time(NULL));
    	process=2+rand()%3;
        n=process;
	for( i=0;i<process;i++){
	    dt[i]=1+rand()%9;
            arr[i]=rand()%3;
            rt[i]=dt[i]; 
	}
        tq=rand()%10; 
        for(j=0;j<process;j++){
	    printf("Process[%d] -> During Time:%d -> Order:%d -> Arrival Time:%d\n",j,dt[j],j+1,arr[j]);
	}
       tq=1+rand()%9;
       printf("Time Quantum:%d\t",tq); 
  for(t=0,k=0;n!=0;) { 
    if(rt[k]<=tq && rt[k]>0) { 
      t+=rt[k]; 
      rt[k]=0; 
      flag=1; 
    } 
    else if(rt[k]>0) { 
      rt[k]-=tq; 
      t+=tq; 
    } 
    if(rt[k]==0 && flag==1) { 
      n--;  
      wt+=t-arr[k]-rt[k]; 
      flag=0; 
    } 
    if(k==process-1) 
      k=0; 
    else if(arr[k+1]<=t) 
      k++; 
    else 
      k=0;  
  } 
       awt=(float)((wt*1.0)/process);      //average waiting time
      printf("\nAverage Waiting Time= %f\n",awt); 
   }
/*
centos@localhost:~/Desktop $ gcc -o Desktop rr.c
centos@localhost:~/Desktop $ ./Desktop
Process[0] -> During Time:1 -> Order:1 -> Arrival Time:0
Process[1] -> During Time:1 -> Order:2 -> Arrival Time:0
Process[2] -> During Time:7 -> Order:3 -> Arrival Time:0
Process[3] -> During Time:3 -> Order:4 -> Arrival Time:0
Time Quantum:3	
Average Waiting Time= 5.750000
*/
