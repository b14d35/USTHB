#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

char car;
int att = 0;
int cpt = 0;
void* lecteur(){
	while(att == 1);
	scanf(" %c",&car);
	att = 1;
}

void* afficheur(){
	while(att == 0);
	printf("%d - %c\n",++cpt,car);
	att = 0;
}

int main(){
	pthread_t th[2];
	while(car != 'F'){
		pthread_create(&th[0],0,lecteur,NULL);
		pthread_create(&th[1],0,afficheur,NULL);
		pthread_join(th[0],NULL);
		pthread_join(th[1],NULL);
	}
	return 0;
}
