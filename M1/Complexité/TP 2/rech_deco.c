#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define MILLI_S 1000.0
#include <windows.h>

long rechElets_TabNonTries(long T[], long N, long val) {
	long i = 0;
	while (i < N) {
		if (T[i] == val) return i;
		i++;
	}
	return -1;
}

long rechElets_TabTries(long T[], long N, long val) {
	long i = 0;
	if (val < T[0] && val > T[N - 1]) return -1;
	while (val > T[i]) i++;
	return i;
}

long rechElets_Dicho(long T[], long N, long val) {
	long start, end, half;
	start = 0;
	end = N - 1;
	while (start < end) {
		half = (start + end) / 2;
		if (T[half] == val)
			return half;
		else if (T[half] < val)
			start = half + 1;
		else
			end = half - 1;
	}
	if (T[start] == val) return start;
	if (T[end] == val) return end;
	printf("n existe pas\n");
	return -1;
}

int main() {
	long taille[10] = {100000,  200000,  400000,  600000,  800000,
					   1000000, 1200000, 1400000, 1600000, 1800000},
		 i;
	double wtms[10], wtmss[10], btms[10], btmss[10];
	LARGE_INTEGER deb, fin, freq;
	double tempExec, tempExecEnSeconds;
	int j;
	long *T, *F;
	F = (long *)malloc(taille[9] * sizeof(taille[9]));
	i = 0;
	while (i < taille[9]) {
		F[i] = taille[9] - i - 1;
		i++;
	}
	T = (long *)malloc(taille[9] * sizeof(taille[9]));
	i = 0;
	while (i < taille[9]) T[i] = i++;

	for (j = 0; j < 10; j++) {
		QueryPerformanceFrequency(&freq);
		QueryPerformanceCounter(&deb);
		// Calcul the best scenario
		printf("%ld\n", rechElets_TabNonTries(F, taille[j], taille[9] - 1));
		QueryPerformanceCounter(&fin);
		tempExec = MILLI_S * (fin.QuadPart - deb.QuadPart) / freq.QuadPart;
		tempExecEnSeconds = (fin.QuadPart - deb.QuadPart) / freq.QuadPart;
		btms[j] = tempExecEnSeconds;
		btmss[j] = tempExec;
		// Calcul the worst scenario
		QueryPerformanceFrequency(&freq);
		QueryPerformanceCounter(&deb);
		printf("%ld\n", rechElets_TabNonTries(F, taille[j], taille[9]));
		QueryPerformanceCounter(&fin);
		tempExec = MILLI_S * (fin.QuadPart - deb.QuadPart) / freq.QuadPart;
		tempExecEnSeconds = (fin.QuadPart - deb.QuadPart) / freq.QuadPart;
		wtms[j] = tempExecEnSeconds;
		wtmss[j] = tempExec;
	}
	printf("Recherche Tableau non trie\n\nBest case:\n");
	for (j = 0; j < 10; j++)
		printf("%ld : %lf ms %lf s\n", taille[j], btmss[j], btms[j]);
	printf("\n\nWOrst case:\n");
	for (j = 0; j < 10; j++)
		printf("%ld : %lf ms %lf s\n", taille[j], wtmss[j], wtms[j]);

	for (j = 0; j < 10; j++) {
		QueryPerformanceFrequency(&freq);
		QueryPerformanceCounter(&deb);
		// Calcul the best scenario
		printf("%ld\n", rechElets_TabTries(T, taille[j], 0));
		QueryPerformanceCounter(&fin);
		tempExec = MILLI_S * (fin.QuadPart - deb.QuadPart) / freq.QuadPart;
		tempExecEnSeconds = (fin.QuadPart - deb.QuadPart) / freq.QuadPart;
		btms[j] = tempExecEnSeconds;
		btmss[j] = tempExec;
		// Calcul the worst scenario
		int temp = taille[j] - 1;
		QueryPerformanceFrequency(&freq);
		QueryPerformanceCounter(&deb);
		printf("%ld\n", rechElets_TabTries(T, taille[j], temp));
		QueryPerformanceCounter(&fin);
		tempExec = MILLI_S * (fin.QuadPart - deb.QuadPart) / freq.QuadPart;
		tempExecEnSeconds = (fin.QuadPart - deb.QuadPart) / freq.QuadPart;
		wtms[j] = tempExecEnSeconds;
		wtmss[j] = tempExec;
	}
	printf("Recherche Tableau trie\n\nBest case:\n");
	for (j = 0; j < 10; j++)
		printf("%ld : %lf ms %lf s\n", taille[j], btmss[j], btms[j]);
	printf("\n\nWOrst case:\n");
	for (j = 0; j < 10; j++)
		printf("%ld : %lf ms %lf s\n", taille[j], wtmss[j], wtms[j]);

	for (j = 0; j < 10; j++) {
		QueryPerformanceFrequency(&freq);
		QueryPerformanceCounter(&deb);
		// Calcul the best scenario
		printf("%ld\n", rechElets_Dicho(T, taille[j], ((taille[j] - 1) / 2)));
		QueryPerformanceCounter(&fin);
		tempExec = MILLI_S * (fin.QuadPart - deb.QuadPart) / freq.QuadPart;
		tempExecEnSeconds = (fin.QuadPart - deb.QuadPart) / freq.QuadPart;
		btms[j] = tempExecEnSeconds;
		btmss[j] = tempExec;
		// Calcul the worst scenario
		QueryPerformanceFrequency(&freq);
		QueryPerformanceCounter(&deb);
		printf("%ld\n", rechElets_Dicho(T, taille[j], taille[9]));
		QueryPerformanceCounter(&fin);
		tempExec = MILLI_S * (fin.QuadPart - deb.QuadPart) / freq.QuadPart;
		tempExecEnSeconds = (fin.QuadPart - deb.QuadPart) / freq.QuadPart;
		wtms[j] = tempExecEnSeconds;
		wtmss[j] = tempExec;
	}
	printf("Recherche Tableau Decho\n\nBest case:\n");
	for (j = 0; j < 10; j++)
		printf("%ld : %lf ms %lf s\n", taille[j], btmss[j], btms[j]);
	printf("\n\nWOrst case:\n");
	for (j = 0; j < 10; j++)
		printf("%ld : %lf ms %lf s\n", taille[j], wtmss[j], wtms[j]);
}
