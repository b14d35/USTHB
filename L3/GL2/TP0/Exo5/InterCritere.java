import java.util.LinkedList;

public class InterCritere implements Critere{
	LinkedList<Critere> x = new LinkedList<Critere>();
	public void ajouter(Critere c){
		x.add(c);
	}
	@Override
	public boolean correspond(Object o) {
		for(Critere y : x){
			if(y.correspond(o)==false)
				return false;
		}
		return true;
	}

}
