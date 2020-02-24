#include "../Headers/pile.h"
#include <stdio.h>
pile * push(pile * tetePile){
  pile * element = malloc(sizeof(pile));
  element->adrCond = QC - 1;
  element->nbrif = nbr_if;
  element->suivant = tetePile;
  tetePile = element;
  return tetePile;
}

pile * pop(pile * tetePile){
  tetePile = tetePile->suivant;
  return tetePile;
}

int peek(pile *tetePile){
	if(tetePile == NULL) return 0;
	return tetePile->nbrif;
}
