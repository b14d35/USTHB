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
	char chaine[100];
	if(pipe(tube) != 0){
		perror("Error in creating the pipe\n");
		exit(EXIT_FAILURE);
	}
	fils = fork();
	if(fils == -1) perror("Error in creating the child\n");
	else if(fils == 0){
		close(tube[1]);
		while(read(tube[0],&ch,1) > 0){
			if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))printf("%c",ch);
		}
		printf("\n");
	}else{
		gets(chaine);
		close(tube[0]);
		write(tube[1],chaine,sizeof(chaine));
		close(tube[1]);
		wait(NULL);
	}
}
