#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include "stack.h"

void Hanoi(int n, struct Stack* A, struct Stack* B, struct Stack* C, char a,
		   char b, char c) {
	if (n > 0) {
		Hanoi(n - 1, A, C, B, a, c, b);
		printf("Moving %c to %c\n", a, c);
		push(C, pop(A));
		Hanoi(n - 1, B, A, C, b, a, c);
	}
}

void shift_disks(struct Stack* src, struct Stack* dest, char a, char b) {
	int pole1 = pop(src);
	int pole2 = pop(dest);
	if (pole1 == INT_MIN) {
		printf("Moving %c to %c\n", b, a);
		push(src, pole2);
	} else if (pole2 == INT_MIN) {
		printf("Moving %c to %c\n", a, b);
		push(dest, pole1);
	} else if (pole1 > pole2) {
		printf("Moving %c to %c\n", b, a);
		push(src, pole1);
		push(src, pole2);
	} else {
		printf("Moving %c to %c\n", a, b);
		push(dest, pole2);
		push(dest, pole1);
	}
}

void HanoiIterative(int n, struct Stack* A, struct Stack* B, struct Stack* C) {
	int i, nbr;
	char D = 'A', M = 'B', F = 'C';
	if (n % 2 == 0) {
		M = 'C';
		F = 'B';
	}
	nbr = pow(2, n) - 1;
	for (i = 1; i <= nbr; i++) {
		if (i % 3 == 1) shift_disks(A, C, D, F);
		if (i % 3 == 2) shift_disks(A, B, D, M);
		if (i % 3 == 0) shift_disks(B, C, M, F);
	}
}

int main() {
	int i, N = 5;
	double T[15];
	while (N < 20) {
		struct Stack* A;
		struct Stack* B;
		struct Stack* C;
		A = createStack(N);
		B = createStack(N);
		C = createStack(N);
		for (i = N; i > 0; i--) push(A, i);
		clock_t t1, t2;
		// Hanoi(N,A,B,C,'A','B','C');
		t1 = clock();
		HanoiIterative(N, A, B, C);
		t2 = clock();
		T[N - 5] = (double)(t2 - t1) / CLOCKS_PER_SEC;
		N++;
	}
	for (i = 0; i < 15; i++) {
		printf("For %d time : %f\n", i + 5, T[i]);
	}
	return 0;
}
