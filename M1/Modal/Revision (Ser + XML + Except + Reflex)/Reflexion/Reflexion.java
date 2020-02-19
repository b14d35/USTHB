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
		File f = new File("classe.xml");
		try {
			FileWriter fw = new FileWriter(f);
			BufferedWriter wr = new BufferedWriter(fw);
			wr.write("<?xml version='1.0' encoding='ISO-8859-1'?>");
			wr.write("<Class>");
			wr.write("<Package>"+pack.getName()+"</Package>");
			wr.write("<Name>"+className+"</Name>");
			wr.write("<Attributes nbr='"+attributs_declaree.length+"'>");
			for (Field field : attributs_declaree) {
				wr.write("<Attribute>");
				wr.write("<Type>"+field.getType().getSimpleName()+"</Type>");
				wr.write("<Name>"+field.getName()+"</Name>");
				wr.write("</Attribute>");
			}
			wr.write("</Attributes>");
			wr.write("<Constructors nbr='"+constr.length+"'>");
			for (Constructor constructor : constr) {
				wr.write("<Constructor nbrParam='"+constructor.getParameterCount()+"'>");
				Parameter[] params = constructor.getParameters();
				for (Parameter parameter : params) {
					wr.write("<Parameter>");
					wr.write("<Type>"+parameter.getType().getSimpleName()+"</Type>");
					wr.write("<Name>"+parameter.getName()+"</Name>");
					wr.write("</Parameter>");
				}
				wr.write("</Constructor>");
			}
			wr.write("</Constructors>");
			wr.write("<Methods>");
			for (Method method : meths_dec) {
				wr.write("<Method name='"+method.getName()+"'>");
				wr.write("<Parameters nbr='"+method.getParameterCount()+"'>");
				Parameter[] params = method.getParameters();
				for (Parameter parameter : params) {
					wr.write("<Parameter>");
					wr.write("<Type>"+parameter.getType().getSimpleName()+"</Type>");
					wr.write("<Name>"+parameter.getName()+"</Name>");
					wr.write("</Parameter>");
				}
				wr.write("</Parameters>");
				wr.write("<ReturnType>"+method.getReturnType().getSimpleName()+"</ReturnType>");
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
		File f = new File("classe2.xml");
		String path = "src\\"+pack.getName()+"\\"+className+".java";
		try {
			int cpt = 0;
			FileWriter fw = new FileWriter(f);
			BufferedWriter wr = new BufferedWriter(fw);
			wr.write("<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?>");
			wr.newLine();
			wr.write("<Info>");
			File g = new File(path);
			try {
				wr.write("<Impair>");
				FileReader fr = new FileReader(g);
				BufferedReader br = new BufferedReader(fr);
				String line;
				while((line = br.readLine()) != null){
					cpt++;
					wr.write("<Line>"+ line +"</Line>");
					line = br.readLine();
					if(line != null){
						cpt++;
					}
				}
				br.close();
				fr.close();
				wr.write("</Impair>");
			} catch (Exception e) {
				e.printStackTrace();
			}
			try {
				wr.write("<Pair>");
				FileReader fr = new FileReader(g);
				BufferedReader br = new BufferedReader(fr);
				String line = br.readLine();
				while((line = br.readLine()) != null){
					wr.write("<Line>"+ line +"</Line>");
					line = br.readLine();
				}
				br.close();
				fr.close();
				wr.write("</Pair>");
			} catch (Exception e) {
				e.printStackTrace();
			}
			try {
				wr.write("<Comments>");
				FileReader fr = new FileReader(g);
				BufferedReader br = new BufferedReader(fr);
				String line;
				while((line = br.readLine()) != null){
					if(line.contains("//")){
						wr.write("<Comment>"+line+"</Comment>");
					}
				}
				br.close();
				fr.close();
				wr.write("</Comments>");
			} catch (Exception e) {
				e.printStackTrace();
			}
			wr.write("<Nbr_Lines>"+cpt+"</Nbr_Lines>");
			wr.write("</Info>");
			wr.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
