/*
	Le principe on commence par appeler avec TriRapide(T,taille,0,taille-1);
   (T,n,p,r) On commence par partitionner, avec p,r : pivot = T[p] ; i=p; j=r;
		Tant que i<j:
			on incrémente i jusqu'a trouver un valeur > pivot;
			on décrémente j jusqu'a trouver une valeur < pivot;
			permuter T[i] et T[j];
		fait;
		permuter pivot et T[j];
		retourner j;
	

	Puis on fait des appels avec partitionner(T,taille,p,j-1) et
   partionner(T,taille,j+i,p)
*/

long partitionner(long *T, long n, long d, long f) {
	long eltPivot, i, j;
	eltPivot = T[d];
	i = d;
	j = f;
	while (i < j) {
		while (i < f && T[i] <= eltPivot) i++;
		while (j > d && T[j] > eltPivot) j--;
		if (i < j) Permuter(&T[i], &T[j]);  // afficher(T,n);}
	}
	Permuter(&T[d], &T[j]);
	// afficher(T,n);
	return j;
}

// O(n log n)
void TriRapide(long *T, long n, long p, long r) {
	long q;
	if (p < r) {
		q = partitionner(T, n, p, r);
		TriRapide(T, n, p, q - 1);
		TriRapide(T, n, q + 1, r);
	}
}
