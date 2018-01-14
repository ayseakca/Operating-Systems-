#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
	pid_t child1_pid, child2_pid, child3_pid;
	int i,n1,n2,j=0, number1,number2, temp;
	char *f1,*f2;
	char ch;
	FILE *file1,*file2;
	srand(time(NULL));
	if(argc!=5){
		printf("Not correct number of arguments!\n");
		return 0;
	}
	else{		
		number1=atoi(argv[3]);
                number2=atoi(argv[4]);
		f1=argv[1];
                f2=argv[2];
		child1_pid = fork();
		if(child1_pid == 0){
			file1 = fopen( f1, "w" );
			for(i=0; i<number1; i++){
				n1=rand()%1000;
				fprintf(file1,"%d\n",n1);
			}
			printf("[CHILD1] Creating %s with %d integers...\n",f1, number1);
			fclose( file1 );
		}
		else{
			printf("[PARENT] Creating first process...\n");
    			wait(NULL);
			child2_pid = fork();
			if(child2_pid == 0){
                           file2 = fopen( f2, "w" );
			   for(j=0; j<number2; j++){
				n2=rand()%1000;
				fprintf(file2,"%d\n",n2);
			}
			printf("[CHILD1] Creating %s with %d integers...\n",f2, number2);
			fclose( file2 );
			}
			else{
				printf("[PARENT] Creating second process...\n");
				wait(NULL);

				child3_pid = fork();
				if(child3_pid == 0){
                                   char cmndline[50]="sort";
                                   strcat(cmndline, " -n ");
                                   strcat(cmndline,f1);
                                   strcat(cmndline, " ");
                                   strcat(cmndline, f2);
                                   system(cmndline);
				  // fclose( file1 );
                                  //fclose( file2 );
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
centos@localhost:~/Desktop $ gcc -o Desktop Q3.c
centos@localhost:~/Desktop $ ./Desktop  cde.txt def.txt 3 4
[PARENT] Creating first process...
[CHILD1] Creating cde.txt with 3 integers...
[PARENT] Creating second process...
[CHILD1] Creating def.txt with 4 integers...
[PARENT] Executing third process...
42
42
106
713
713
974
974
[PARENT] Done.
*/
