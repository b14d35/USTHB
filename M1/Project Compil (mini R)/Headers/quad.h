#define TailleQuad 200

typedef struct {
	char* opr;
	char* op1;
	char* op2;
	char* res;
	int col[4];
}quadruplet;

quadruplet q[TailleQuad];

extern QC;

void getColor(int i);
void Quad(char* opr, char* op1, char* op2, char* res);
void afficherQuad(int x);
void Maj(int nQc, int jmp);
