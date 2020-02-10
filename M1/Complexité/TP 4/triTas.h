#define GAUCHE(i) (2 * (i) + 1)
#define DROITE(i) (2 * (i) + 2)

long domine(long *T, long n, long j) {
	long max = j;
	if (GAUCHE(j) < n && T[GAUCHE(j)] > T[j]) max = GAUCHE(j);
	if (DROITE(j) < n && T[DROITE(j)] > T[max]) max = DROITE(j);
	return max;
}

void retablirTas(long *T, long j, long n) {
	long max = domine(T, n, j);
	while (max != j) {
		Permuter(&T[j], &T[max]);
		j = max;
		max = domine(T, n, j);
	}
}

void faireTas(long *T, long n) {
	long i;
	for (i = n / 2 - 1; i >= 0; i--) retablirTas(T, i, n);
}

void TriTas(long *T, long n) {
	long i;
	for (i = n - 1; i > 0; i--) {
		faireTas(T, n);
		Permuter(&T[0], &T[n - 1]);
		n--;
	}
}