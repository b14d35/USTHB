
import java.util.Scanner;
import java.util.TreeSet;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		TreeSet<Integer> list = new TreeSet<Integer>();
		int n = sc.nextInt();
		for(int i=0;i<n;i++)
			list.add((int)(1000*Math.random()));
		System.out.println(list);
	}

}
