package Test1;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.ObjectOutputStream;
import java.util.ArrayList;

import ExceptionIL.ExceptionIL;
import ExceptionIL.ExceptionsIL;

public class Test1 {
	private ExceptionsIL exc = new ExceptionsIL();
	private ArrayList<Etudiant> liste = new ArrayList<Etudiant>();
	
	public void dataStudents(String path){
		File f = new File(path);
		try {
			FileReader fr = new FileReader(f);
			BufferedReader br = new BufferedReader(fr);
			String line;
			while((line = br.readLine()) != null){
				try {
					String[] pos = line.split(" ");
					if(pos.length != 5) throw new Exception("Champ non compatible");
					liste.add(new Etudiant(pos[1], pos[0], pos[2], pos[3], pos[4]));
				} catch (Exception e) {
					exc.AjouterException(new ExceptionIL(e));
				}
				
			}
			br.close();
			fr.close();
		} catch (Exception e) {
			exc.AjouterException(new ExceptionIL(e));
		}
	}
	
	public void saveSer(){
		try {
			FileOutputStream fs = new FileOutputStream("Students.ser");
			ObjectOutputStream os = new ObjectOutputStream(fs);
			for (Etudiant etudiant : liste) {
				os.writeObject(etudiant);
				System.out.println(etudiant);
			}
			os.close();
		} catch (Exception e) {
			exc.AjouterException(new ExceptionIL(e));
		}
	}
	
	public static void main(String[] args) {
		Test1 test = new Test1();
		test.dataStudents("stud.txt");
		test.saveSer();
	}
}
