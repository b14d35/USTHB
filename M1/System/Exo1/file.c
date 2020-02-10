#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
// Create a pid : int pid = fork();
// Suspendre execution : sleep(seconds);
// Affiche mon PID : getpid();
// Affiche le père du PID : getppid();
int main(){
	int pid1;
	pid1 = fork();
	if(pid1 == -1) printf("Erreur lors de la cration du processus\n");
	if(pid1 == 0){
		printf("Mon pid=%d, pid parent=%d\n",getpid(),getppid());
		sleep(5);
	}else{
		sleep(2);
		printf("Mon pid=%d, pid parent=%d\n",getpid(),getppid());
	}
}
