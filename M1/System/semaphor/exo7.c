#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

sem_t A,B;
int ch,N;

void* principal(void* k){
	do{
		printf("Entrer un nombre entre 1 et 50:\t");
		scanf("%d",&N);
	}while(N<1 || N>50);
	do{
		printf("Choisissez :\n\t1-multiples\n\t2-diviseurs\n\t\tVotre choix:\t");
		scanf("%d",&ch);
	}while(ch!=1 && ch!=2);
	if(ch==1)sem_post(&A);
	else sem_post(&B);
}

void* multiples(void* k){
	sem_wait(&A);
	printf("Les multiples de %d:\n",N);
	for(int i=N;i<50;i++) if(i%N==0) printf("%d\n",i);
}

void* diviseurs(void* k){
	sem_wait(&B);
	printf("Les diviseurs de %d:\n",N);
	for(int i=1;i<=N;i++) if(N%i==0) printf("%d\n",i);
}

int main(){
	sem_init(&A,0,0);
	sem_init(&B,0,0);
	pthread_t TH[3];
	pthread_create(&TH[0],0,principal,NULL);
	pthread_create(&TH[1],0,multiples,NULL);
	pthread_create(&TH[2],0,diviseurs,NULL);
	pthread_join(TH[0],NULL);
	pthread_join(TH[ch],NULL);
}
