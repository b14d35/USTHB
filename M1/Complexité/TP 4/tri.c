#include <math.h>
#include <stdio.h>
#include "tableau.h"
#include "triBase.h"
#include "triBulle.h"
#include "triGnome.h"
#include "triRapide.h"
#include "triTas.h"

int main() {
	long N = 20;
	long *T;
	T = (long *)malloc(N * sizeof(long));
	initTab(T, N);
	afficher(T, N);
	TriTas(T, N);
	afficher(T, N);
	printf("\n");
	return 0;
}
