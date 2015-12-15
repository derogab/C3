void turno(Giocatore *att, Giocatore *dif){
	
	int scelta;
	
	clearScreen();
	
	printf("\nTurno di %s: \n\n", att->nome);
	
	mano(*att);
		
	printf("Cosa vuoi fare? \n\t1) Acquisto carte\n\t2) Combattimento\n\nInserisci la tua scelta: ");
	scanf("%d", &scelta);
	
	switch(scelta){
		
		case 1: acquistocarte(att, dif); break;
		case 2: combattimento(att, dif); break;
		default: printf("Scelta non valida. "); turno(att, dif);
		
	}
	
	//TOGLI QUESTA PARTE
	att->nc--; dif->nc--; fflush(stdin); getchar(); fflush(stdin); // Per ora serve solo per terminare il programma dopo un po' di cicli
	// TOGLI QUESTA PARTE
	
	clearScreen();
}

void combattimento(){
	
	
	
	
	
	
}