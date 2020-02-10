#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
	int pid1,pid2;
	printf("Creation du fils 1\n");
	pid1 = fork();
	if(pid1 == -1) printf("Erreur lors de la creation du fils 1\n");
	if(pid1 == 0){
		printf("Fils de PID %d : Bonjour\n",getpid);
		sleep(5);
		printf("Fils de PID %d : Au revoir\n",getpid);
		exit(0);
	}else{
		printf("Creation du fils 2\n");
		pid2 = fork();
		if(pid2 == -1) printf("Erreur lors de la creation du fils 2\n");
		if(pid2 == 0){
			printf("Fils de PID %d : Bonjour\n",getpid);
			sleep(5);
			printf("Fils de PID %d : Au revoir\n",getpid);
			exit(0);
		}else{
			while(wait(NULL) != -1);
			printf("Je suis le pere %d\n",getpid());
		}
	}
}
