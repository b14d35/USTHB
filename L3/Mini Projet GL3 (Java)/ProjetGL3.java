
package projetgl3;


public class ProjetGL3 {

    public static  void main(String[] args) {
        Ascenseur a =new Ascenseur();
        a.construirePortes(5);
        Usager u [] = {
           new Usager("Usager[1]",2,1), new Usager("Usager[2]",3,-1),new Usager("Usager[3]", 2,-1)
        };
        u[0].setDestination(3);
        u[1].setDestination(1);  
        u[2].setDestination(1);
        a.chargerUtilisateurs(u);
        a.miseEnMarche();
    }
    
}
