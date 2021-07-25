typedef struct pile2{
  int nbrQuad;
  struct pile2 * suivant;
}pile2;

pile2 * push2(pile2 * tetePile, int x);
pile2 * pop2(pile2 * tetePile);
int peek2(pile2 *tetePile);
int empty2(pile2 *tetePile);
