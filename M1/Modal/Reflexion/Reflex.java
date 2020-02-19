package reflex;

import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.lang.reflect.Parameter;
import java.util.Arrays;

public class Reflex {
	private String pack, classe;
	private Field[] public_fields, declared_fields;
	private Method[] declared_methods;
	private Constructor[] constructors;
	public Reflex(Object x){
		Class c = x.getClass();
		this.pack = c.getPackage().getName();
		this.classe = c.getSimpleName();
		this.public_fields = c.getFields();
		this.declared_fields = c.getDeclaredFields();
		this.declared_methods = c.getDeclaredMethods();
		this.constructors = c.getConstructors();
	}
	
	public void show(){
		System.out.println("Package: "+pack);
		System.out.println("Classe: "+classe);
		System.out.println("Start Public Fields:");
		for (Field field : public_fields) {
			System.out.println("\t"+field.getType().getSimpleName()+" "+field.getName()+";");
		}
		System.out.println("End Public Fields.");
		System.out.println("Start Declared Fields:");
		for (Field field : declared_fields) {
			System.out.println("\t"+field.getType().getSimpleName()+" "+field.getName()+";");
		}
		System.out.println("End Declared Fields.");
		System.out.println("Start Constructors:");
		for (Constructor constructor : constructors) {
			Parameter[] temp = constructor.getParameters();
			for (Parameter parameter : temp) {
				System.out.print("\t"+parameter.getType().getSimpleName()+" "+parameter.getName());
			}
			System.out.println();
		}
		System.out.println("End Constructors.");
		System.out.println("Start Declared Methods:");
		for (Method method : declared_methods) {
			System.out.println("\t"+method.getReturnType().getSimpleName()+" "+method.getName());
			Parameter[] temp = method.getParameters();
			for (Parameter parameter : temp) {
				System.out.println("\t\t"+parameter.getType().getSimpleName()+" "+parameter.getName());
			}
		}
		System.out.println("End Declared Methods.");
	}
}
