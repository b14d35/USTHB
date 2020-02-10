#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
	int fils[4][2];
	int i=0;
	fils[0][0] = fork();
	if(fils[0][0] == 0){
		srand(getpid());
		fils[0][1] = rand();
		printf("Processus pid %d noeud %d val = %d \n",getpid(),i,fils[0][1]);
	}else{
		i++;
		fils[1][0] = fork();
		if (fils[1][0] == 0){
			srand(getpid());
			fils[1][1] = rand();
			printf("Processus pid %d noeud %d val = %d \n",getpid(),i,fils[1][1]);
		}else{
			i++;
			fils[2][0] = fork();
			if(fils[2][0] == 0){
				srand(getpid());
				fils[2][1] = rand();
				printf("Processus pid %d noeud %d val = %d \n",getpid(),i,fils[2][1]);			
			}else{
				i++;
				fils[3][0] = fork();
				if(fils[3][0] == 0){
					srand(getpid());
					fils[3][1] = rand();
					printf("Processus pid %d noeud %d val = %d \n",getpid(),i,fils[3][1]);
				}else{
					i++;
					wait(NULL);wait(NULL);wait(NULL);wait(NULL);
				}
			}
		}
	}
}
