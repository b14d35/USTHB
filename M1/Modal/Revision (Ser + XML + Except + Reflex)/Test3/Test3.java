package Test3;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Map;
import java.util.TreeMap;

import ExceptionIL.ExceptionIL;
import ExceptionIL.ExceptionsIL;

public class Test3 {
	ExceptionsIL exc = new ExceptionsIL();
	TreeMap<Integer, Entreprise> liste = new TreeMap<Integer, Entreprise>();
	
	public void dataEntreprise(String path){
		File f = new File(path);
		try {
			FileReader fr = new FileReader(f);
			BufferedReader br = new BufferedReader(fr);
			String line;
			while((line = br.readLine()) != null){
				try {
					String[] pos = line.split(" ");
					if(pos.length != 3) throw new Exception("Champ non compatible");
					Entreprise temp = new Entreprise(pos[0], Integer.parseInt(pos[1]), pos[2]);
					liste.put(temp.getCode(), temp);
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
	
	public void sortEntreprise(String path){
		File f = new File(path);
		try {
			BufferedWriter bw = new BufferedWriter(new FileWriter(f));
			for(Map.Entry<Integer, Entreprise> ent: liste.entrySet()){
				bw.write(ent.getValue().toString());
				bw.newLine();
			}
			bw.close();
		} catch (Exception e) {
			exc.AjouterException(new ExceptionIL(e));
		}
	}
	
	public void Afficher(){
		for(Map.Entry<Integer, Entreprise> ent: liste.entrySet()){
			System.out.println(ent.getValue());
		}
	}
	
	public static void main(String[] args) {
		Test3 test = new Test3();
		test.dataEntreprise("entr.txt");
		test.sortEntreprise("entrSorted.txt");
	}
}
