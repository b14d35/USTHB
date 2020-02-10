import java.util.ArrayList;

public class test {
	public static void main(String[] args) {
		ArrayList<Personne> x = new ArrayList<Personne>();
		Féminin p1= new Féminin("p1","p1","Rube4","Alger",new Date(9,11,1996),null,null,null);
		Masculin f2= new Masculin("f2","f1","Rube4","Alger",new Date(9,11,1996),null,null,null);
		x.add(p1);
		x.add(f2);
		Féminin f1= new Féminin("f1","f1","Rube4","Alger",new Date(9,11,1996),null,null,x);
		x.removeAll(x);
		x.add(p1);
		Masculin p2= new Masculin("p2","p1","Rube4","Alger",new Date(9,11,1996),null,null,x);
		for(Personne t:f1.descendants()){
			t.afficher();
		}
	}
}
