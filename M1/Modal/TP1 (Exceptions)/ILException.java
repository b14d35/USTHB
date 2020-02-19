import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.EOFException;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.Date;

public class ILException extends Exception{
	private static final long serialVersionUID = 1L;

	public ILException(){
		super();
	}
	public ILException(String msg){
		super(msg);
	}
	public static void SaveLog(String path, Exception exc) throws IOException{
		int line = exc.getStackTrace()[0].getLineNumber();
		String cName = exc.getStackTrace()[0].getClassName();
		String pck = exc.getStackTrace()[0].getClass().getPackage().getName();
		String method = exc.getStackTrace()[0].getMethodName();
		File f = new File(path);
		if(!f.getAbsoluteFile().getParentFile().exists()){
			System.out.println("Path doesnt exists");
			return;
		}
		FileWriter fw = new FileWriter(f, true);
		String error = ""+new Date()+" | "+pck+" - "+cName+"."+method+"():"+line+" "+exc.toString();
		BufferedWriter wr = new BufferedWriter(fw);
		wr.write(error);
		wr.newLine();
		wr.close();
	}
	public static void ReadLog(String path) throws IOException{
		File f = new File(path);
		if(!f.isFile()){
			System.out.println("File doesn't exist");
			return;
		}
		FileReader fr = new FileReader(f);
		BufferedReader br = new BufferedReader(fr);
		String line = br.readLine();
		while(line != null){
			System.out.println(line);
			line = br.readLine();
		}
		br.close();
	}
	
	public static boolean SaveSer(String path, ExceptMIL obj){
		try {
			FileOutputStream fs = new FileOutputStream(path);
			ObjectOutputStream os = new ObjectOutputStream(fs);
			os.writeObject(obj);
			os.flush();
			os.close();
		} catch (Exception e) {
			return false;
		}
		return true;
	}
	
	public static void ReadSer(String path){
		try {
			FileInputStream fis = new FileInputStream(path);
			ObjectInputStream ois = new ObjectInputStream(fis);
			Object exc = null;
			while ((exc = ois.readObject()) != null) {
				if(exc instanceof ExceptMIL){
					System.out.println(exc);
				}
			}
			ois.close();
		} catch (EOFException e){
			System.out.println("Fin du fichier");
		} catch (Exception e) {
			System.out.println(e.toString());
		}
	}
}
