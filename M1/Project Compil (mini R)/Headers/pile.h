extern int QC, num_quad;

typedef struct pile{
  int adrCond;
  int nbrif;
  struct pile * suivant;
}pile;

pile * push(pile * tetePile);
pile * pop(pile * tetePile);
int peek(pile *tetePile);
