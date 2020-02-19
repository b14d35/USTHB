package Test2;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.text.DateFormat;
import java.text.SimpleDateFormat;

import ExceptionIL.ExceptionIL;
import ExceptionIL.ExceptionsIL;

public class Test2 {
	private ExceptionsIL exc = new ExceptionsIL();
	private ArrayList<Produit> liste = new ArrayList<Produit>();
	public void dataProduits(String path){
		File f = new File(path);
		try {
			FileReader fr = new FileReader(f);
			BufferedReader br = new BufferedReader(fr);
			String line;
			while((line = br.readLine()) != null){
				try {
					String[] pos = line.split(" ");
					if(pos.length != 4) throw new Exception("Champ non compatible");
					liste.add(new Produit(Integer.parseInt(pos[0]), Integer.parseInt(pos[2]), pos[1], new SimpleDateFormat("dd/MM/yyyy").parse(pos[3])));
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
	
	public void splitXML(){
		File f = new File("Prod0.xml");
		File g = new File("Prod1.xml");
		try {
			FileWriter fw0 = new FileWriter(f);
			BufferedWriter wr0 = new BufferedWriter(fw0);
			FileWriter fw1 = new FileWriter(g);
			BufferedWriter wr1 = new BufferedWriter(fw1);
			wr0.write("<Produits>");
			wr1.write("<Produits>");
			for (Produit produit : liste) {
				if(produit.getCode()%2 == 0){
					wr0.write("<Produit>");
					wr0.write("<Code>"+produit.getCode()+"</Code>");
					wr0.write("<Nom>"+produit.getNom()+"</Nom>");
					wr0.write("<Quantite>"+produit.getQte()+"</Quantite>");
					DateFormat formatter = new SimpleDateFormat("dd/MM/yyyy");
					wr0.write("<Date>"+formatter.format(produit.getFab())+"</Date>");
					wr0.write("</Produit>");
				}else{
					wr1.write("<Produit>");
					wr1.write("<Code>"+produit.getCode()+"</Code>");
					wr1.write("<Nom>"+produit.getNom()+"</Nom>");
					wr1.write("<Quantite>"+produit.getQte()+"</Quantite>");
					DateFormat formatter = new SimpleDateFormat("dd/MM/yyyy");
					wr1.write("<Date>"+formatter.format(produit.getFab())+"</Date>");
					wr1.write("</Produit>");
				}
			}
			wr0.write("</Produits>");
			wr1.write("</Produits>");
			wr0.close();
			wr1.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	public static void main(String[] args) {
		Test2 test = new Test2();
		test.dataProduits("prod.txt");
		test.splitXML();
	}
}
