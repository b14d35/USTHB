package Matrice;

import java.util.Random;

public class MatriceIL {
	int[][] A;
	int[][] B;
	int[][] C;
	
	public MatriceIL(int n, int m, int p){
		A = new int[n][m];
		B = new int[m][p];
		C = new int[n][p];
		FillRandom(A, n, m);
		FillRandom(B, m, p);
	}
	
	private void FillRandom(int[][] x, int l, int c){
		Random rand = new Random();
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < c; j++) {
				x[i][j] = rand.nextInt(50);
			}
		}
	}
}
