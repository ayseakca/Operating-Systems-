#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
	pid_t child1_pid, child2_pid, child3_pid;
	int i=0,n=0,j=0, number, temp;
	char f[50];
	char ch;
	FILE *file;
	srand(time(NULL));
	if(argc!=3){
		printf("Not correct number of arguments!\n");
		return 0;
	}
	else{		
		number=atoi(argv[2]);
		strcpy(f,argv[1]);
		child1_pid = fork();
		if(child1_pid == 0){
                        strcat(f,".txt"); 
			file = fopen( f, "w" );
			printf("\n[CHILD1] Creating  %d random chars to %s...\n",number,f);
                        int a=0;
                        char c;
                        for(i=0;i<number;i++){
                            while(1==1){
    	                       n = rand()%61;
    	                       c =(char)(n+65);
    	                if(c>=97&&c<=122){
    		           fprintf(file,"%c",c);
                           fprintf(file,"\n");
    		            break;
		            }
		            else
	                        continue;
	                }
                    }
			fclose( file );
		}
		else{
			printf("[PARENT] Creating first process...\n");
    			wait(NULL);
			child2_pid = fork();
			char sort[number];
			int s[number];
                        if(child2_pid == 0){
                                printf("[CHILD2] Executing zip command...\n");
			
				file=fopen(f,"r");
                                strcpy(f,argv[1]);
                                char cmndline[50]="zip ";
                                strcat(cmndline, " -r ");
                                strcat(cmndline, f);
                                strcat(cmndline,".zip");
                                strcat(cmndline," . -i ");
                                strcat(cmndline,f);
                                strcat(cmndline,".txt");
                                system(cmndline);
                                fclose(file);

			}
			else{
				printf("[PARENT] Creating second process...\n");
				wait(NULL);

				child3_pid = fork();
				if(child3_pid == 0){
		                char line[50]="ls";
                                strcat(line," -1");
                                strcat(line, " -sh ");                 
                                strcat(line, f);
                                strcat(line, "*");
                                 system(line);	
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
centos@localhost:~ $ cd Desktop
centos@localhost:~/Desktop $ gcc -o Desktop Q2.c
centos@localhost:~/Desktop $ ./Desktop chars 4000
[PARENT] Creating first process...

[CHILD1] Creating  4000 random chars to chars.txt...
[PARENT] Creating second process...
[CHILD2] Executing zip command...
  adding: chars.txt (deflated 58%)
[PARENT] Executing third process...
8.0K chars.txt
4.0K chars.zip
[PARENT] Done.

*/
