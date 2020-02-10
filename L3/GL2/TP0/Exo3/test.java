
import java.util.LinkedList;

public class test {
	public static void main(String[] args) {
		LinkedList<Integer> num = new LinkedList<Integer>();
		TestSelection x = new TestSelection();
		for(int i=0;i<=100;i++) num.add(i);
		System.out.println(TestSelection.selection(num, x));
	}
	
}
