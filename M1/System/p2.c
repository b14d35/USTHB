#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
	int fils[4][3];
	int i=0;
	int tube[4][2];
	int j;
	int send,temp;
	int max;
	for(j=0;j<4;j++){
		if(pipe(tube[j]) == -1){
			perror("erreur fatal\n");
			exit(-1);
		}
	}
	fils[0][0] = fork();
	if(fils[0][0] == 0){
		srand(getpid());
		fils[0][1] = rand();
		fils[0][2] = i;
		printf("Processus pid %d noeud %d val = %d \n",getpid(),fils[0][2],fils[0][1]);
		if(i != 0){
			close(tube[(i-1)%4][1]);
			read(tube[(i-1)%4][0],&temp,sizeof(int));
			close(tube[(i-1)%4][0]);
			send = (temp<fils[0][1])?fils[0][1]:temp;
			max = (temp<fils[0][1])?fils[0][2]:(fils[0][2]+3)%4;
		}else{
			send = fils[0][1];
		}
		close(tube[i][0]);
		write(tube[i][1],&send,sizeof(int));
		close(tube[i][1]);
	}else{
		//wait(NULL);
		i++;
		fils[1][0] = fork();
		if (fils[1][0] == 0){
			srand(getpid());
			fils[1][1] = rand();
			fils[1][2] = i;
			printf("Processus pid %d noeud %d val = %d \n",getpid(),fils[1][2],fils[1][1]);
			if(i != 0){
				close(tube[(i-1)%4][1]);
				read(tube[(i-1)%4][0],&temp,sizeof(int));
				close(tube[(i-1)%4][0]);
				send = (temp<fils[1][1])?fils[1][1]:temp;
				max = (temp<fils[0][1])?fils[0][2]:(fils[1][2]+3)%4;
			}else{
				send = fils[1][1];
			}
			close(tube[i][0]);
			write(tube[i][1],&send,sizeof(int));
			close(tube[i][1]);
		}else{
			//wait(NULL);
			i++;
			fils[2][0] = fork();
			if(fils[2][0] == 0){
				srand(getpid());
				fils[2][1] = rand();
				fils[2][2] = i;
				printf("Processus pid %d noeud %d val = %d \n",getpid(),fils[2][2],fils[2][1]);
				if(i != 0){
					close(tube[(i-1)%4][1]);
					read(tube[(i-1)%4][0],&temp,sizeof(int));
					close(tube[(i-1)%4][0]);
					send = (temp<fils[2][1])?fils[2][1]:temp;
					max = (temp<fils[0][1])?fils[0][2]:(fils[2][2]+3)%4;
				}else{
					send = fils[2][1];		
				}
				close(tube[i][0]);
				write(tube[i][1],&send,sizeof(int));
				close(tube[i][1]);
			}else{
				//wait(NULL);
				i++;
				fils[3][0] = fork();
				if(fils[3][0] == 0){
					srand(getpid());
					fils[3][1] = rand();
					fils[3][2] = i;
					printf("Processus pid %d noeud %d val = %d \n",getpid(),fils[3][2],fils[3][1]);
					if(i != 0){
						close(tube[(i-1)%4][1]);
						read(tube[(i-1)%4][0],&temp,sizeof(int));
						close(tube[(i-1)%4][0]);
						send = (temp<fils[3][1])?fils[3][1]:temp;
						max = (temp<fils[0][1])?fils[0][2]:(fils[3][2]+3)%4;
					}else{
						send = fils[3][1];		
					}
					close(tube[i][0]);
					write(tube[i][1],&send,sizeof(int));
					close(tube[i][1]);
				}else{
					wait(NULL);wait(NULL);wait(NULL);wait(NULL);
					close(tube[3][1]);
					read(tube[3][0],&temp,sizeof(int));
					close(tube[3][0]);
					send = (temp<fils[0][1])?fils[0][1]:temp;
					printf("Max = %d\n",send);
				}
			}
		}
	}
}
