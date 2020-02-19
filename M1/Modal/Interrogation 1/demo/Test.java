package demo;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;

import exception.ExceptionIL;
import exception.ExceptionsIL;

public class Test {
	private ExceptionsIL exc = new ExceptionsIL();
	
	public void saveXml(String path){
		File f = new File(path);
		File g = new File("G.xml");
		try {
			FileReader fr = new FileReader(f);
			BufferedReader br = new BufferedReader(fr);
			FileWriter fw = new FileWriter(g);
			BufferedWriter wr = new BufferedWriter(fw);
			String line = br.readLine();
			if(line.compareTo("Begin") != 0){
				br.close();
				fr.close();
				wr.close();
				throw new Exception("Erreur de structuration");
			}
			fw.write("<file>");
			line = br.readLine();
			do {
				if(line == null){
					br.close();
					fr.close();
					wr.close();
					throw new Exception("Erreur de Structuration");
				}
				fw.write("<method name=\""+line+"\">");
				
				while((line = br.readLine()) != null && !line.equals("#") && !line.contains(" ")){
					fw.write("<param>"+line+"</param>");
				}
				fw.write("</method>");
				if(line.equals("#")) line = br.readLine();
			} while (!line.contains(" "));
			String[] test = line.split(" ");
			if(test.length != 4){
				br.close();
				fr.close();
				wr.close();
				throw new Exception("Champ incomplet");
			}
			fw.write("<niveau>"+test[0]+"</niveau>");
			fw.write("<Spec>"+test[1]+"</Spec>");
			fw.write("<Univ>"+test[2]+"</Univ>");
			fw.write("<Year>"+test[3].substring(0, test[3].length()-1)+"</Year>");
			while(!(line = br.readLine()).equals("End")){
				br.close();
				fr.close();
				wr.close();
				throw new Exception("Champ End non trouve");
			}
			fw.write("</file>");
			br.close();
			fr.close();
			wr.close();
		} catch (Exception e) {
			exc.AjouterException(new ExceptionIL(e));
		}
	}
	
	public static void main(String[] args) {
		Test test = new Test();
		test.saveXml("G.txt");
		test.exc.afficher();
		test.exc.saveXML();
	}

}
