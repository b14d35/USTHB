#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<sys/types.h>
int main(int argc, char *argv[]){
	int fils;
	int tube[2];
	char ch;
	char chaine[] = "Bonjour skd ";
	char chaine1[50];
	if(pipe(tube) != 0){
		perror("Error in creating the pipe\n");
		exit(EXIT_FAILURE);
	}
	fils = fork();
	if(fils == -1) perror("Error in creating the child\n");
	else if(fils == 0){
		close(tube[1]);
		read(tube[0],&chaine1,sizeof(chaine));
		printf("%s\n",chaine1);
	}else{
		close(tube[0]);
		write(tube[1],chaine,sizeof(chaine));
		close(tube[1]);
		wait(NULL);
	}
}
