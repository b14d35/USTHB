package ExceptionIL;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.Serializable;
import java.util.Date;

public class ExceptionIL implements Serializable{
	private static final long serialVersionUID = -4206019701917450480L;
	private Date date;
	private String classe, methode, pack, message;
	private int line;
	
	public ExceptionIL(Exception e){
		date = new Date();
		String[] test = e.getStackTrace()[0].getClassName().split("\\.");
		classe = test[1];
		methode = e.getStackTrace()[0].getMethodName();
		pack = test[0];
		message = e.toString();
		line = e.getStackTrace()[0].getLineNumber();
		this.saveText();
	}

	public Date getDate() {
		return date;
	}

	public String getClasse() {
		return classe;
	}

	public String getMethode() {
		return methode;
	}

	public String getPack() {
		return pack;
	}

	public String getMessage() {
		return message;
	}

	public int getLine() {
		return line;
	}

	public String toString() {
		return date + " " + pack + ":" + classe + "." + methode + "():" + line + " - " + message;
	}
	
	private void saveText(){
		File f = new File("Errors.txt");
		try {
			BufferedWriter bw = new BufferedWriter(new FileWriter(f, true));
			bw.write(this.toString());
			bw.newLine();
			bw.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
