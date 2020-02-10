#include <math.h>
#include <stdio.h>
#include <time.h>
#define MILLI_S 1000.0
#include <windows.h>
int main() {
	long j, n[12] = {1000003,   2000003,   4000037,	8000009,
					 16000057,  32000011,  64000031,   128000003,
					 256000001, 512000009, 1024000009, 2048000011};
	LARGE_INTEGER deb, fin, freq;
	double tempExec[12], tempExecEnSeconds[12];
	int i, cpt;
	for (i = 0; i < 12; i++) n[i] += 1;
	for (i = 0; i < 12; i++) {
		QueryPerformanceFrequency(&freq);
		QueryPerformanceCounter(&deb);
		cpt = 0;
		j = 1;
		long x = (long)sqrt(n[i]);
		while (j <= x) {
			if (n[i] % j == 0) cpt++;
			j++;
		}
		if (cpt == 1)
			printf("%ld est Premier\n", n[i]);
		else
			printf("%ld n'est pas Premier\n", n[i]);
		QueryPerformanceCounter(&fin);
		tempExec[i] = MILLI_S * (fin.QuadPart - deb.QuadPart) / freq.QuadPart;
		tempExecEnSeconds[i] = (fin.QuadPart - deb.QuadPart) / freq.QuadPart;
	}
	for (i = 0; i < 12; i++) {
		printf("%ld : %f ms : %f s\n", n[i], tempExec[i], tempExecEnSeconds[i]);
	}
	return 0;
}
