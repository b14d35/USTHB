#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<math.h>
int main(){
	int a,b,c,delta,fils1,fils2,fils3;
	double x1,x2;
	while(1){
		printf("Donnez a:\t");
		scanf("%d",&a);
		printf("Donnez b:\t");
                scanf("%d",&b);
		printf("Donnez c:\t");
                scanf("%d",&c);
		delta = b*b - 4*a*c;
		printf("Delta = %d\n",delta);
		if(delta >= 0){
			fils1 = fork();
			if(fils1 == 0){
				x1 = (-b-sqrt(delta))/(2*a);
				printf("x1 = %f\n",x1);
				exit(x1);
			}else{
				fils2 = fork();
				if(fils2 == 0){
					x2 = (-b+sqrt(delta))/(2*a);
	                                printf("x2 = %f\n",x2);
        	                        exit(x2);

				}else{
					int status;
					waitpid(fils1,&status,0);
					x1 = WEXITSTATUS(status);
					waitpid(fils2,&status,0);
					x2 = WEXITSTATUS(status);
				}
			}
		}else{
			fils3 = fork();
			if(fils3 == 0){
				execlp("./stop",NULL);
				break;
			}
			else{
				wait(NULL);
				break;
			}
		}
	}
}
