package threadIL;

public class MyThreadR implements Runnable{
	public void run(){
		for (int i = 0; i < 10; i++) {
			System.out.println("Test "+ i);
		}
	}
}
