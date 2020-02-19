package threadIL;

public class TestThread {

	public static void main(String[] args) {
		MyThread first = new MyThread();
		MyThread second = new MyThread();
		first.start();
		second.start();
	}

}
