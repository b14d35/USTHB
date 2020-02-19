
public class Test extends ILException{
	private static final long serialVersionUID = 1L;

	public static void main(String[] args) throws ILException {
		int x = -6;
		try {
			if(x<0) throw new ILException();
		} catch (ILException e) {
			ILException.SaveSer("test.ser", new ExceptMIL(e));
		}
		ILException.ReadSer("test.ser");
	}

}
