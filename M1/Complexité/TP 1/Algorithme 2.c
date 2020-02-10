#include <math.h>
#include <stdio.h>
#include <time.h>

int main() {
	long j, n[12] = {1000003,   2000003,   4000037,	8000009,
					 16000057,  32000011,  64000031,   128000003,
					 256000001, 512000009, 1024000009, 2048000011};
	double t[12];
	clock_t t1, t2;
	int i, cpt;
	for (i = 0; i < 12; i++) {
		t1 = clock();
		cpt = 0;
		j = 1;
		long x = n[i] / 2;
		while (j <= x) {
			if (n[i] % j == 0) cpt++;
			j++;
		}
		if (cpt == 1)
			printf("%ld est Premier\n", n[i]);
		else
			printf("%ld n'est pas Premier\n", n[i]);
		t2 = clock();
		t[i] = (double)(t2 - t1) / CLOCKS_PER_SEC;
	}
	for (i = 0; i < 12; i++) {
		printf("%ld : %f\n", n[i], t[i]);
	}
	return 0;
}
