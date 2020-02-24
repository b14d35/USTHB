extern int nbr_temps;
extern modif;

void viderVars();
void usedVars(int x, char* y);
int hasChanged(int x);
int isNumber(int i, int y);
void jump(int num);
void useless();
void mult_reduc();
void copie();
void expression();
int constante(int ind);
void propa();
void propag_exp();
int num_temp(int i, int y);
void temps();
void optimisation();
