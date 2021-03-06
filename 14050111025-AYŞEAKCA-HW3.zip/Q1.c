#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
	pid_t child1_pid, child2_pid, child3_pid;
	int i,n,j=0, number, temp;
	char *f;
	char ch;
	FILE *file;
	srand(time(NULL));
	if(argc!=3){
		printf("Not correct number of arguments!\n");
		return 0;
	}
	else{		
		number=atoi(argv[2]);
		f=argv[1];
		child1_pid = fork();
		if(child1_pid == 0){
			file = fopen( f, "w" );
			for(i=0; i<number; i++){
				n=rand()%1000;
				fprintf(file,"%d\n",n);
			}
			printf("[CHILD1] Creating %s with %d integers...\n",f, number);
			fclose( file );
		}
		else{
			printf("[PARENT] Creating first process...\n");
    			wait(NULL);
			child2_pid = fork();
			char sort[number];
			int s[number];
			if(child2_pid == 0){
				printf("[CHILD2] Executing sort command...\n");
				file=fopen(f,"r");
                                   char cmndline[50]="sort";
                                   strcat(cmndline, " -n ");
                                   strcat(cmndline, f);
                                   system(cmndline);
				   fclose( file );
			}
			else{
				printf("[PARENT] Creating second process...\n");
				wait(NULL);

				child3_pid = fork();
				if(child3_pid == 0){
					j=0;
					file=fopen(f,"r");
					while(j<number){
						fscanf(file,"%s",sort);				
						s[j]=atoi(sort);
						j++;
					}
					int max=s[0];
					int min=s[0]; 
					for(i=0;i<number;i++){
						if(s[i]<min)
				        		min=s[i];
						if(s[i]>max)
						    max=s[i];
					}
					printf("[CHILD3] Min: %d",min);
					printf(" Max: %d\n",max);
					fclose( file );	    
				}
				else{
					printf("[PARENT] Executing third process...\n");
					wait(NULL);
					printf("[PARENT] Done.\n");
				}
			}
		}
			
	}
    return 0;
}
/*
centos@localhost:~/Desktop $ gcc -o Desktop Q1.c
centos@localhost:~/Desktop $ ./Desktop  abc.txt 5
[PARENT] Creating first process...
[CHILD1] Creating abc.txt with 5 integers...
[PARENT] Creating second process...
[CHILD2] Executing sort command...
64
431
547
733
956
[PARENT] Executing third process...
[CHILD3] Min: 64 Max: 956
[PARENT] Done.
*/

