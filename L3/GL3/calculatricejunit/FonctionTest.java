package calculatricejunit;

import static org.junit.Assert.*;

import java.util.function.Function;

import org.junit.Test;

public class FonctionTest {

	@Test
	public void testAddition() {
		System.out.println("Test : addition");
		Long a = new Long(4);
		Long b = new Long(6);
		Fonction instance = new Fonction();
		Long expResult = new Long(10);
		Long result = instance.addition(a,b);
		assertEquals(expResult, result);
	}

	@Test
	public void testSoustraction() {
		System.out.println("Test : soustraction");
		Long a = new Long(40);
		Long b = new Long(6);
		Fonction instance = new Fonction();
		Long expResult = new Long(34);
		Long result = instance.soustraction(a,b);
		assertEquals(expResult, result);
	}

	@Test
	public void testMultiplication() {
		System.out.println("Test : multiplication");
		Long a = new Long(3);
		Long b = new Long(9);
		Fonction instance = new Fonction();
		Long expResult = new Long(27);
		Long result = instance.multiplication(a,b);
		assertEquals(expResult, result);
	}

	@Test
	public void testDivision() {
		System.out.println("Test : addition");
		Long a = new Long(9);
		Long b = new Long(3);
		Fonction instance = new Fonction();
		Long expResult = new Long(3);
		Long result = instance.division(a,b);
		assertEquals(expResult, result);
	}

}
