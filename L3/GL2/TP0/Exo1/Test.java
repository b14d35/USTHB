
public class Test {

	public static void main(String[] args) {
		Eleve e1= new Eleve("Amine",5);
		System.out.print(e1.toString()+"\n");
		Eleve e2,e3=e1;
		e1= new Eleve();
		e2= new Eleve("Samia",2);
		System.out.println(e1.toString()+"\n"+e2.toString()+"\n"+e3);
	}

}
