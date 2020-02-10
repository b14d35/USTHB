import java.sql.Date;

public class Journal extends Document{
	private Date dateParution;

	public Journal(String titre,Bibliotheque bib,Date dateParution) {
		super(titre,bib);
		this.dateParution = dateParution;
	}
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return super.toString()+" "+dateParution.toString();
	}
	public Date getDateParution() {
		return dateParution;
	}
}
