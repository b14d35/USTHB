extern int nbligne;
extern int nbcolone;
void ErrorDoubleDeclaration(char *idf){
	textattr(14);
	printf("Erreur Symantique Ligne:%d Colone:%d Double Declaration de %s\n",nbligne,nbcolone,idf);
	textattr(15);
}
void ErrorDivisionParZero(){
	textattr(13);
	printf("Erreur Symantique Ligne:%d Colonne:%d Devision par zero impossible\n",nbligne,nbcolone);
	textattr(15);
}
void ErrorNonCompatibilite(){
	textattr(4);
	printf("Erreur Symantique Ligne:%d Colone:%d Non Compatibilite\n",nbligne,nbcolone);
	textattr(15);
}
void ErrorNonDeclaree(char *idf){
	textattr(2);
	printf("Erreur Symantique Ligne:%d Colone:%d Non Declaration de %s\n",nbligne,nbcolone,idf);
	textattr(15);
}
void ErrorTailleDepassee(){
	textattr(6);
	printf("Erreur Symantique Ligne:%d Colonne:%d Taille Tableau Depasse\n",nbligne,nbcolone);
	textattr(15);
}
void ErrorLongueurIdf(char *idf){
	textattr(12);
	printf("Erreur Lexical Ligne:%d Ligne:%d  IDF (%s )trop long \n",nbligne,nbcolone,idf);
	textattr(15);
}
void ErrorDepassementTaille(){
	textattr(9);
	printf("Erreur Lexical Ligne:%d Ligne:%d Capacite Depassee \n",nbligne,nbcolone);
	textattr(15);
}
