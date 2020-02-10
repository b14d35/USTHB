import static org.junit.Assert.*;

import org.junit.Test;

public class examen2Test {

	@Test
	public void testSomme() {
		int[][] mat = new int[3][3];
		mat[0][0] = 1;
		mat[0][1] = 2;
		mat[0][2] = 5;
		mat[1][0] = 1;
		mat[1][1] = 2;
		mat[1][2] = 3;
		mat[2][0] = 1;
		mat[2][1] = 2;
		mat[2][2] = 3;
		int exp = new Integer(14);
		examen2 instance = new examen2();
		int resu = instance.somme(mat);
		assertEquals(exp, resu);
	}

	@Test
	public void testColonne() {
		int[][] mat = new int[2][3];
		mat[0][0] = 1;
		mat[0][1] = 2;
		mat[0][2] = 3;
		mat[1][0] = 1;
		mat[1][1] = 2;
		mat[1][2] = 3;
		int[][] exp = new int[2][3];
		exp[0][0] = 3;
		exp[0][1] = 2;
		exp[0][2] = 1;
		exp[1][0] = 3;
		exp[1][1] = 2;
		exp[1][2] = 1;
		examen2 instance = new examen2();
		int[][] resu = instance.colonne(mat);
		assertArrayEquals(exp, resu);
	}

}
