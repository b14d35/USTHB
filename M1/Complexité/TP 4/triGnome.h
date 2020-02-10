/*
	On parcours de 1 a n:
		Si (mauvais ordre) alors:
			permute;
			si i=0 incremente sinon decremente;
		sinon
			incremente
		fsi;
	fait;
*/

// Meilleur : O(n) -- Pire : O(n²)
void TriGnome(long T[], long n) {
	int i = 0;
	while (i < n) {
		if (T[i] > T[i + 1]) {
			Permuter(&T[i], &T[i + 1]);
			if (i == 0)
				i++;
			else
				i--;
		} else
			i++;
	}
}