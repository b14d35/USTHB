
public enum SpécialitéM {
	ACAD("Informatique Académique",10,"Akli",12),
	ISIL("Informatique Système Information et Logiciels",9,"Hamel",12.5),
	GTR("Transmission et Réseaux",8,"Doukha",11),
	Stat("Probabilité et Statistique",13,"Merad",10),
	RO("Recherche opérationnelle",10,"Azi",10.5);
	private String intitule,responsable;
	private int module;
	private double moyenne;
	private SpécialitéM(String intitule, int module, String responsable, double moyenne) {
		this.intitule = intitule;
		this.responsable = responsable;
		this.module = module;
		this.moyenne = moyenne;
	}
	
	public String getResponsable() {
		return responsable;
	}
	
	public double getMoyenne() {
		return moyenne;
	}
	
	public String getIntitule() {
		return intitule;
	}
	public static void afficheResponsable(String m){
		for(SpécialitéM x:SpécialitéM.values()){
			if(x.name().equalsIgnoreCase(m)){
				System.out.println("Affichage des responsables :");
				System.out.println(x.getResponsable());
			}
		}
	}

	public static void afficheMoyenne(){
		for(SpécialitéM x:SpécialitéM.values()){
			System.out.print(x+" ");
			System.out.println(x.getMoyenne());
		}
	}

	public static void choixPossible(double m){
		if(m>=0 && m<=20){
			if(m<10)System.out.println("vous êtes ajournée");
			else{
				System.out.println("\nChoix possible d'une moyenne donnée :");
				for(SpécialitéM x:SpécialitéM.values()){
					if(x.getMoyenne()<=m) System.out.println(x);
				}
			}
		}
		else
		{
			System.out.println("Erreur dans la moyenne");
		}
	}
}
