package etudiant;

import static org.junit.Assert.*;

import org.junit.Test;

public class FucntionTest {

	@Test
	public void testMoyenne() {
		System.out.println("Test de Moyenne : ");
		float m[] = {10,15,7,12,8};
		int c[] = {2,3,1,2,2};
		Fucntion x = new Fucntion();
		Float e = new Float(11);
		Float r = x.moyenne(m, c);
		assertEquals(e,r);
	}

}
