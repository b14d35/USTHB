
package projetgl3;
public class Usager {
    private String nom ;
    private int etageCourant ,destination; 
    private int direction ;/* up: 1 / down: -1*/
    public Usager(String nom ,int etageCourant, int direction) {
        this.nom=nom;
        this.etageCourant = etageCourant;
        this.direction = direction;
        destination=-1;
        
    }
    public int getDestination() {
        return destination;
    }
    public void setDestination(int destination) {
        this.destination = destination;
    }
    public String getNom() {
        return nom;
    }
    
    public int getEtageCourant() {
        return etageCourant;
    }
    public int getDirection() {
        return direction;
    }
    public boolean aDecider() {
        return destination!=-1;
    }
    
    public void sortir(){
        System.out.println("# "+nom+":\t\tdestination atteinte");
    }
  
    
}
