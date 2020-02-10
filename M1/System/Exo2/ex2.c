#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
	char choix,nom[20];
	do{
		printf("Faites votre choix:\n");
		printf("\t1-Creer un fichier avec touch\n");
		printf("\t2-Afficher un fichier avec cat\n");
		printf("\t3-Supprimer un fichier avec rm\n");
		printf("\t\tVotre choix:  ");
		scanf(" %c",&choix);
	}while(choix != '1' && choix != '2' && choix != '3');
	printf("Donnez le nom du fichier:\t");
	scanf("%s",&nom);
	switch(choix){
		case '1': execlp("touch","touch",nom,NULL);
			break;
		case '2': execlp("cat","cat",nom,NULL);
			break;
		case '3': execlp("rm","rm",nom,NULL);
			break;
	}
}
