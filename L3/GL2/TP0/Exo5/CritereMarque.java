
public class CritereMarque implements Critere{
	private String mar;
	public CritereMarque(String mar) {
		this.mar=mar;
	}
	@Override
	public boolean correspond(Object o) {
		if(o!=null)
			if (o instanceof Voiture) {
				Voiture x = (Voiture) o;
				if(x.getMarque()==mar) return true;
			}
		return false;
	}
	
}
