package asc;

import static org.junit.Assert.*;

import org.junit.Test;

public class AscenseurTest {
	@Test
	public void testAscenseur() {
	}

	@Test
	public void testVers() {
		Ascenseur ac = new Ascenseur(3);
		ac.ajoutUs(new Usager(2, "UP", 3, 0));
		String exp = "UP";
		Ascenseur instance = new Ascenseur(3);
		String act = instance.vers();
		assertEquals(exp, act);
	}

	@Test
	public void testAjoutUs() {
		fail("Not yet implemented"); // TODO
	}

	@Test
	public void testVasortir() {
		fail("Not yet implemented"); // TODO
	}

	@Test
	public void testAtteint() {
		fail("Not yet implemented"); // TODO
	}

	@Test
	public void testComportement() {
		fail("Not yet implemented"); // TODO
	}

}
