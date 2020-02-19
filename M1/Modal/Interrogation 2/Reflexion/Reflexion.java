package Reflexion;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.lang.reflect.Parameter;
import java.util.Arrays;

public class Reflexion {
	private Class c;
	private Package pack;
	private String className;
	private Field[] attributs_public, attributs_declaree;
	private Constructor[] constr;
	private Method[] meths, meths_dec;
	public Reflexion(Object obj){
		c = obj.getClass();
		pack = c.getPackage();
		className = c.getSimpleName();
		attributs_public = c.getFields();
		attributs_declaree = c.getDeclaredFields();
		constr = c.getConstructors();
		meths = c.getMethods();
		meths_dec = c.getDeclaredMethods();
	}
	
	public void XML(){
		File f = new File("G.xml");
		try {
			FileWriter fw = new FileWriter(f);
			BufferedWriter wr = new BufferedWriter(fw);
			wr.write("<?xml version='1.0' encoding='ISO-8859-1'?>");
			wr.write("<Class name='"+className+"'>");
			wr.write("<Package name='"+pack.getName()+"'> </Package>");
			wr.write("<Statistics>");
			wr.write("<attributs>"+attributs_declaree.length+"</attributs>");
			wr.write("<Methods>"+meths_dec.length+"</Methods>");
			int nbr = 0;
			for (Method meth : meths_dec) {
				nbr += meth.getParameterCount();
			}
			wr.write("<ParamMethods>"+nbr+"</ParamMethods>");
			wr.write("</Statistics>");
			wr.write("<attributPublic>");
			for (int i=0; i<attributs_public.length; i++) {
				if(i==(attributs_public.length-1)){
					wr.write(attributs_public[i].getName());
				}else{
					wr.write(attributs_public[i].getName()+", ");
				}
			}
			wr.write("</attributPublic>");
			wr.write("<attributType>");
			for (int i=0; i<attributs_public.length; i++) {
				if(i==(attributs_public.length-1)){
					wr.write(attributs_public[i].getType().getSimpleName());
				}else{
					wr.write(attributs_public[i].getType().getSimpleName()+", ");
				}
			}
			wr.write("</attributType>");
			wr.write("<Methods NombreMethode='"+meths_dec.length+"'>");
			for (Method method : meths_dec) {
				wr.write("<Method name='"+method.getName()+"'>");
				int nbr2 = method.getParameterCount();
				wr.write("<Spec>");
				wr.write(method.getName()+":"+nbr2+":");
				Parameter[] params = method.getParameters();
				for (int i=0; i<params.length; i++) {
					if(i==(params.length-1)){
						wr.write(params[i].getType().getSimpleName());
					}else{
						wr.write(params[i].getType().getSimpleName()+",");
					}
				}
				wr.write(":"+method.getReturnType().getSimpleName());
				wr.write("</Spec>");
				wr.write("</Method>");
			}
			wr.write("</Methods>");
			wr.write("</Class>");
			wr.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	public void XML2(){
		File f = new File("H.xml");
		String path = "src\\"+pack.getName()+"\\"+className+".java";
		try {
			int cpt = 0;
			FileWriter fw = new FileWriter(f);
			BufferedWriter wr = new BufferedWriter(fw);
			wr.write("<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?>");
			wr.newLine();
			wr.write("<DeuxInst>");
			File g = new File(path);
			try {
				FileReader fr = new FileReader(g);
				BufferedReader br = new BufferedReader(fr);
				String line;
				while((line = br.readLine()) != null){
					cpt++;
					if(cpt==7 || cpt==9){
						wr.write("<inst nbr='"+cpt+"'>"+line+"</inst>");
						if(cpt == 9){
							break;
						}
					}
				}
				br.close();
				fr.close();
			} catch (Exception e) {
				e.printStackTrace();
			}
			wr.write("</DeuxInst>");
			wr.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
