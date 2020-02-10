import javax.swing.JOptionPane;
import java.util.regex.*;
public class Email {
	private String usager,domaine,suffixe;
	public String saisie(){
		String email;
		email = JOptionPane.showInputDialog("Entrer votre email :");
		return email;
	}
	public boolean isAnEmail(String email){
			if(email.matches("[a-zA-Z][a-zA-Z0-9]{0,20}@[a-z]{1,10}[.][a-z]{1,5}")){
			String ch[] = email.split("[@.]");
			usager=ch[0];
			domaine=ch[1];
			suffixe=ch[2];
			} else return false;
		return true;
	}
	public void showEmail(){
		if(this.isAnEmail(this.saisie())==true){
			System.out.println("Le nom de l'usager est : "+usager);
			System.out.println("Le domaine est : "+domaine);
			System.out.println("Le suffixe est : "+suffixe);
		} else {
			System.out.println("Il y a une erreur dans votre email");
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Email x=new Email();
		x.showEmail();
	}

}
