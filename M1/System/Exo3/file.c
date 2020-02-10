#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
	int f1,f2,f3;
	f1 = fork();
	if(f1 == 0) exit(5);
	else{
		f2 = fork();
		if(f2 == 0) exit(10);
		else{
			f3 = fork();
			if(f3 == 0) exit(3);
			else{
				int status;
				waitpid(f1,&status,0);
				int v1 = WEXITSTATUS(status);
				waitpid(f2,&status,0);
				int v2 = WEXITSTATUS(status);
				waitpid(f3,&status,0);
				int v3 = WEXITSTATUS(status);
				printf("%d\n",v3*v2+v1);
			}
		}
	}
}
