#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
	int a,b,c,s;
	printf("Donnez un nombre a:\t");
	scanf("%d",&a);
	printf("Donnez un nombre b:\t");
        scanf("%d",&b);
	printf("Donnez un nombre c:\t");
        scanf("%d",&c);
	s = a + b + c;
	printf("La somme = %d\n",s);
}
