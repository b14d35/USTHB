/*
	Ce tri se fait en plusieurs étapes, on commence par trier selon les clés
		des nombres de droites et en incrémente, en arrivant a la fin, on aura
		un tableau trié.
*/

// Retourne le nombre dans la position i -- O(1)
long cle(long x, long i) { return ((long)(x / pow(10, i)) % 10); }

// Tri le tableau selon la position k en utilisant cle O(n)
void TriAux(long *T, long n, int k) {
	long i, j;
	long A[10][n + 1];
	for (i = 0; i < 10; i++) {
		A[i][0] = 0;
	}
	for (i = 0; i < n; i++) {
		int temp = cle(T[i], k);
		A[temp][++A[temp][0]] = T[i];
	}
	i = 0;
	for (j = 0; j < 10; j++) {
		int k = A[j][0];
		for (int l = 1; l <= k; l++) T[i++] = A[j][l];
	}
}

// Tri le tableau en faisant appel a la function TriAux k fois O(kn)
void TriBase(long *T, long n, int k) {
	int i;
	for (i = 0; i < k; i++) TriAux(T, n, i);
}