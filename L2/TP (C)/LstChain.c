#include <stdio.h>
#include <stdlib.h>
/*
typedef struct noeud *tete;
typedef struct {
	int info;
	tete suiv;
} noeud;
*/
typedef struct list {
	int x;
	struct list *suiv;
} list;
list noeud() {
	list *l;
	l = malloc(sizeof(list));
	l->suiv = NULL;
	return *l;
}
list ajoutete(list *T, int y) {
	list *l;
	*l = noeud();
	l->x = y;
	l->suiv = T;
	T = l;
	return *T;
}
list ajoutapres(list *T, int y, int p) {
	list *temp, *q;
	int i = 0;
	temp = T;
	while (i < p && temp->suiv != NULL) {
		temp = temp->suiv;
		i++;
	}
	if (i == p) {
		*q = noeud();
		q->x = y;
		q->suiv = temp->suiv;
		temp->suiv = q;
	}
	return *T;
}
list FIFO(int n) {
	int i, y;
	list *T, *temp;
	T = NULL;
	if (n > 0) {
		for (i = 1; i <= n; i++) {
			scanf("%d", &y);
			ajoutapres(T, y, i);
		}
	}
	return *T;
}
list supprimetete(list *T) {
	list *temp;
	temp = T;
	T->suiv = T;
	free(temp);
	return *T;
}
list supprimeapres(list *T, int p) {}
main() {}
