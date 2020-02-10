#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(int argc, char* argv[]){
	if(argc == 2)execlp("ls","ls",argv[1],NULL);
	else printf("Utilisez: %s PATH\n",argv[0]);
}
