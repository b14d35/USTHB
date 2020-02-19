package threadIL;

public class MyThread extends Thread{
	public void run(){
		for (int count = 0; count < 4; count++) {
			System.out.println(count + " From: "+ getName());
		}
	}
}
