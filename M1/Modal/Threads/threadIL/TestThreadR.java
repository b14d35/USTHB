package threadIL;

public class TestThreadR {

	public static void main(String[] args) {
		Thread t = new Thread(new MyThreadR());
		t.start();
	}

}
