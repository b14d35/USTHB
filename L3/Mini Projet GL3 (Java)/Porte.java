
package projetgl3;

import java.util.ArrayList;

public class Porte {
    
    private int numero ;
    private Ascenseur a ;
    private ArrayList <Usager>  appels ;
    

    public Porte(int numero) {
        this.numero =numero;
        appels = new ArrayList<Usager> ();
    }
   

    public void setAscenseur(Ascenseur a) {
        this.a = a;
    }

    public Ascenseur getAscenseur() {
        return a;
    }
    

    public void ouvrir() {
        System.out.println("* Porte étage "+numero+":\tOuverture");
    }

    public void attendre() throws InterruptedException{
       Thread th =new Thread();
       th.sleep((long)3000);
       
    }

    public void fermer() {
    System.out.println("* Porte étage "+numero+":\tFermeture");
    }
    public void appelerAscenseur(Usager u){
        appels.add(u);
    
    }
    public Usager getUsager(int indice){
        return appels.get(indice);
    }
     public void removeUsager(int indice){
        appels.remove(indice);
    }
      public int nbrUsagers(){
        return appels.size();
    }
      public void addUsager(Usager u){
        appels.add(u);
    }
    public boolean enAppel(){
    return !appels.isEmpty();
    } 
    public boolean existeAppelsDirectioAscenseur() {
        for(int i=0;i<appels.size();i++){
            if(appels.get(i).getDirection()==a.getDirection()){
            return true ;}
        }
        return false;
    }
   
    
}
