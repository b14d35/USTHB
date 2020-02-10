void afficher(long T[], long n) {
	long i;
	for (i = 0; i < n; i++) {
		printf("%d ", T[i]);
	}
	printf("\n");
}

void initTab(long T[], long n) {
	long i;
	srand();
	for (i = 0; i < n; i++) {
		T[i] = rand();
	}
}

void Permuter(long *x, long *y) {
	long temp = *x;
	*x = *y;
	*y = temp;
}
