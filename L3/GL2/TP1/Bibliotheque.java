import java.util.LinkedList;

public class Bibliotheque {
	LinkedList<Adherent> adherents = new LinkedList<Adherent>();
	LinkedList<Document> documents = new LinkedList<Document>();
	
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return adherents+" "+documents;
	}
	
	public boolean addAdherant(Adherent x){
		if(adherents.contains(x)) return false;
		adherents.add(x);
		return true;
	}
	public boolean addDocument(Document x){
		if(documents.contains(x)) return false;
		documents.add(x);
		return true;
	}
	public void afficherFonds(){
		for(Adherent x : adherents){
			System.out.println(x);
			x.afficherEmprunts();
			System.out.println();
		}
	}
	public LinkedList<Document> rechercheeTitre(String mot){
		LinkedList<Document> docs = new LinkedList<Document>();
		for(Document doc:documents){
			if(doc.getTitre().indexOf(mot)!=-1){
				docs.add(doc);
			}
		}
		return docs;
	}
}
