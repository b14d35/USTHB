import java.io.Serializable;
import java.util.Date;

public class ExceptMIL implements Serializable{
	private static final long serialVersionUID = 1L;
	private Date date ;
	private String pck, name, method, message;
	private int line;
	public ExceptMIL(Exception exc) {
		this.date = new Date();
		this.line = exc.getStackTrace()[0].getLineNumber();
		this.name = exc.getStackTrace()[0].getClassName();
		this.pck = exc.getStackTrace()[0].getClass().getPackage().getName();
		this.method = exc.getStackTrace()[0].getMethodName();
		this.message = exc.toString();
	}
	
	public String toString() {
		return ""+this.date+" | "+pck+" - "+this.name+"."+this.method+"():"+this.line+" "+this.message;	
	}
}
