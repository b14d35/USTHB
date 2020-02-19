package Tests;

import ExceptionIL.ExceptionIL;
import ExceptionIL.ExceptionsIL;

public class Test {
	
	public static void main(String[] args) {
		ExceptionsIL exceptions = new ExceptionsIL();
		try {
			System.out.println(5/0);
		} catch (Exception e) {
			exceptions.AjouterException(new ExceptionIL(e));
			exceptions.AjouterException(new ExceptionIL(e));
			exceptions.AjouterException(new ExceptionIL(e));
			exceptions.AjouterException(new ExceptionIL(e));
			exceptions.AjouterException(new ExceptionIL(e));
			exceptions.AjouterException(new ExceptionIL(e));
			exceptions.AjouterException(new ExceptionIL(e));
			exceptions.AjouterException(new ExceptionIL(e));
			exceptions.AjouterException(new ExceptionIL(e));
			exceptions.AjouterException(new ExceptionIL(e));
			exceptions.saveSer();
			exceptions.afficher();
		}
	}
	
}
