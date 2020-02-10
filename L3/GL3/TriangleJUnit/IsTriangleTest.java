import static org.junit.Assert.*;

import org.junit.Test;

public class IsTriangleTest {
	@Test
	public void testEstTriangle() {
		System.out.println("Test de Triangle");
		int a=6,b=2,c=3;
		IsTriangle x = new IsTriangle();
		Boolean e = false;
		Boolean r = x.estTriangle(a, b, c);
		assertEquals(e,r);
	}
	@Test
	public void testEstTriangleEqu() {
		System.out.println("Test de Triangle Equilibré");
		int a=4,b=4,c=4;
		IsTriangle x = new IsTriangle();
		Boolean e = true;
		Boolean r = x.estTriangleEqu(a, b, c);
		assertEquals(e,r);
	}

	public void testEstTriangleIso() {
		System.out.println("Test de Triangle Isolé");
		int a=3,b=2,c=3;
		IsTriangle x = new IsTriangle();
		Boolean e = true;
		Boolean r = x.estTriangleIso(a, b, c);
		assertEquals(e,r);
	}
	@Test
	public void testEstTriangleQlq() {
		System.out.println("Test de Triangle Quelconque");
		int a=1,b=2,c=3;
		IsTriangle x = new IsTriangle();
		Boolean e = false;
		Boolean r = x.estTriangleQlq(a, b, c);
		assertEquals(e,r);
	}
}
