
package projetgl3;

import java.util.ArrayList;

public class Ascenseur {
    
    private ArrayList<Porte> portes ;
    private int direction ; /*  direction up (oui/nn)*/
    private int etageActu ;
    private ArrayList <Usager> destinations ;

    public Ascenseur() {
        this.portes = new ArrayList<Porte>();
        this.etageActu =1;
        this.direction =1;
        this.destinations =new ArrayList<Usager>();
    }
    public void construirePortes(int nbr){
        this.portes = new ArrayList<Porte>();
        Porte p ;
        for(int i = 0; i < nbr; i++) {
            p=new Porte(portes.size()+1);
            p.setAscenseur(this);
            portes.add(p);
        }
    }
    public Porte getPorte(int i){
        return portes.get(i);
    }
    public int getNbrPortes(){
        return portes.size();
    }

    public int getEtageActu() {
        return etageActu;
    }
    public int getDirection(){
        return direction ;
    }
    private void ajouterdestinationsEtageActu(){ 
    Porte p = portes.get(etageActu-1);
    Usager u ;
        for (int i = 0; i < p.nbrUsagers(); i++) {
            u = p.getUsager(i);
            if(u.getDirection()==direction ||(!dirAppels() && !dirDestinations()) ){
            p.removeUsager(i);
            
            if(u.aDecider()){destinations.add(u);
            System.out.println("# "+u.getNom()+"\t\tEntre dans l'ascenseur");
            System.out.println("# "+u.getNom()+"\t\tEntre la destination "+u.getDestination());
            }
            }
        }
    }
    public boolean dirAppels (){
         // return true si il existe un appel au chemin de l'ascenseur
         int i =etageActu + direction ;
         while(i<portes.size() && i>=0){
             if(portes.get(i).enAppel()){return true;}
             i+=direction;   
         }
    return false ;
    }
    public boolean dirDestinations (){
        // return true si il existe une destination au chemin de l'ascenseur
        for (int i=0; i<destinations.size(); i++) {
            int dest = destinations.get(i).getDestination();
            if(dest*direction>direction*etageActu){ return true ;  }
        }
    return false ;
    }
    public boolean existeAppel (){
        // return true si il existe un appel 
        for (int i = 0; i < portes.size(); i++) {
           if(portes.get(i).enAppel()){
               return true ;
           }
        }
    
    
    return false ;
    }
     public boolean existeDestination (){
    return !destinations.isEmpty() ;
    }


    public void chargerUtilisateurs(Usager [] u ){
        Porte p ;      /*lancer les appels de l'ascenseur*/              

        for (int i =0 ; i <u.length ;i++) {
              p=getPorte(u[i].getEtageCourant()-1);
              p.addUsager(u[i]);   
              String dir ;
              if(u[i].getDirection()==1){dir="-up";}else{ dir="-down";}
              System.out.println("# "+u[i].getNom()+"\t\tEffectue l'appel "+u[i].getEtageCourant()+dir);
        }
    }
    public void miseEnMarche() {
        String [] chaineDirections = {"down","up"};
        Porte p ;
        int klf ;
        Usager u ;
        while(existeDestination() || existeAppel()){
            p= portes.get(etageActu-1); 
            /* si existe Appel ou destination pour l etage actu 
            ouvrir la porte 
            faire sortir les usagers
            attendre la porte 
            charger les usagers qui font un appel
            */
            System.out.println("+ Ascenseur :\t\tEtage "+etageActu);
                if(p.enAppel() || estDestination(etageActu)){
                    System.out.println("+ Ascenseur:\t\tArret à l'étage  "+etageActu);
                    p.ouvrir();
                    if(estDestination(etageActu)){
                        System.out.println("dest.taille"+destinations.size());
                        klf = destinations.size() ;
                         for (int i=0 ;i< destinations.size() ;i++) {
                             
                             u=destinations.get(i);
                               System.out.println(u.getNom()+" --"+i+"->"+u.getDestination());
                                
                                 if(u.getDestination()==etageActu){ destinations.remove(u); i--;
                                     u.sortir();
                                    }
                         }
                    }
                    try {
                        p.attendre();
                    } catch (InterruptedException e) {}
                    if(p.enAppel()){
                    ajouterdestinationsEtageActu();
                    p.fermer();
                    System.out.println("+ Ascenseur:\t\tFin de l'arret ");

                    }
                }
                
                if((!dirAppels() && !dirDestinations())|| (etageActu==5 && direction==1)|| (etageActu==1 && direction==-1) ){
                    direction=-direction ;
                }
                if(existeAppel()||existeDestination()){
                    
                    etageActu+=direction;
                    
                    System.out.println("+ Ascenseur:\t\tDirection:  "+chaineDirections[(direction+1)/2]); 
                }
        }
        
    }
    public boolean estDestination(int etage) {
        for (Usager u : destinations) {
            if(u.getDestination()==etage){return true ;}
        }
        return false ;
    }

    
}

   