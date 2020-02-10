#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

int R;
int n;
sem_t S;

void* puissance(void *k){
	long x = (long) k;
	sem_wait(&S);
	printf("Le %ld calcule %d*%d=",x,R,n);
	R*=n;
	printf("%d\n",R);
	sem_post(&S);
}

int main(){
	int p;
	printf("Donnez le nombre :\t");
	scanf("%d",&n);
	R = n;
	do{
		printf("Donnez la puissance :\t");
		scanf("%d",&p);
	}while(p<2);
	sem_init(&S,0,1);
	pthread_t TH[p-1];
	printf("Le pere va creer %d threads\n",p-1);
	for(long i=0;i<p-1;i++) pthread_create(&TH[i],0,puissance,(void *)i+1);
	for(int i=0;i<p-1;i++) pthread_join(TH[i],NULL);
}
