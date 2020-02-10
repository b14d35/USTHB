package moyenne;

import static org.junit.Assert.*;

import org.junit.Test;


public class FunctionTest {

	@Test
	public void testMoyenne() {
		System.out.println("Test : moeyenne");
		float a[] = new float[5];
		int b = 5;
		a[0]=7;
		a[1]=10;
		a[2]=18;
		a[3]=3;
		a[4]=12;
		Function instance = new Function();
		Float expResult = new Float(15);
		Float result = instance.moyenne(a,b);
		assertEquals(expResult, result);
	}

}
