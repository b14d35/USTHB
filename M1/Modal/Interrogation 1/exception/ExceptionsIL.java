package exception;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.EOFException;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;

public class ExceptionsIL {
	private ArrayList<ExceptionIL> liste;
	
	public ExceptionsIL(){
		liste = new ArrayList<ExceptionIL>();
	}
	
	public void AjouterException(ExceptionIL e){
		liste.add(e);
	}
	
	public void readText(){
		File f = new File("Errors.txt");
		try {
			FileReader fr = new FileReader(f);
			BufferedReader br = new BufferedReader(fr);
			String line;
			while((line = br.readLine()) != null){
				System.out.println(line);
			}
			br.close();
			fr.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	public void saveSer(){
		try {
			FileOutputStream fs = new FileOutputStream("Errors.ser");
			ObjectOutputStream os = new ObjectOutputStream(fs);
			for (ExceptionIL exceptionIL : liste) {
				os.writeObject(exceptionIL);
			}
			os.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	public void restorSer(){
		try {
			FileInputStream fis = new FileInputStream("Errors.ser");
			ObjectInputStream ois = new ObjectInputStream(fis);
			liste.removeAll(liste);
			Object obj;
			while((obj = ois.readObject()) != null){
				if(obj instanceof ExceptionIL){
					liste.add((ExceptionIL) obj);
				}
			}
			ois.close();
		} catch(EOFException e){
			
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	public void saveXML(){
		File f = new File("Errors.xml");
		try {
			FileWriter fw = new FileWriter(f);
			BufferedWriter wr = new BufferedWriter(fw);
			wr.write("<Exceptions>");
			for (ExceptionIL exceptionIL : liste) {
				wr.write("<Exception>");
				wr.write("<Date>"+exceptionIL.getDate()+"</Date>");
				wr.write("<Package>"+exceptionIL.getPack()+"</Package>");
				wr.write("<Class>"+exceptionIL.getClasse()+"</Class>");
				wr.write("<Method>"+exceptionIL.getMethode()+"</Method>");
				wr.write("<Line>"+exceptionIL.getLine()+"</Line>");
				wr.write("<Message>"+exceptionIL.getMessage()+"</Message>");
				wr.write("</Exception>");
			}
			wr.write("</Exceptions>");
			wr.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	public void afficher(){
		for (ExceptionIL exceptionIL : liste) {
			System.out.println(exceptionIL);
		}
	}
	
}
