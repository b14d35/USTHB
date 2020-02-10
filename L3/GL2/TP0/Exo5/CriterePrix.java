
public class CriterePrix implements Critere{
	private int pr;
	public CriterePrix(int pr) {
		this.pr=pr;
	}
	@Override
	public boolean correspond(Object o) {
		if(o!=null)
			if (o instanceof Voiture) {
				Voiture x = (Voiture) o;
				if(x.getPrix()<=pr) return true;
			}
		return false;
	}

}
