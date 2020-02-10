/*
	On permute chaque 2 cases qui sont voisines dans le bon ordre, arrivé
		à la fin, si il y'a eu une seule permutation, on refait le parcours
		une fois aucun changement n'a été fait, le tableau est trié.
*/

// Meilleur: O(n) -- Pire : O(n²)
void TriBulle(long T[], long n) {
	int Changement = 1;
	long i;
	while (Changement == 1) {
		Changement = 0;
		for (i = 0; i < n - 1; i++) {
			if (T[i] > T[i + 1]) {
				Permuter(&T[i], &T[i + 1]);
				Changement = 1;
			}
		}
	}
}

/*
	Cette variant est plus optimale, car a chaque parcours, ce qu'on fait c'est
		de prendre le max et le mettre en derniere position, donc il est inutile
		de recomparer avec cette valeur.
*/

// O(n²)
void TriBulleOpt(long T[], long n) {
	long m = n - 1;
	int Changement = 1;
	long i;
	while (Changement == 1) {
		Changement = 0;
		for (i = 0; i < m; i++) {
			if (T[i] > T[i + 1]) {
				Permuter(&T[i], &T[i + 1]);
				Changement = 1;
			}
		}
		m = m - 1;
	}
}