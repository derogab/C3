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

void combattimento(Giocatore *att, Giocatore *dif){
	
	srand(time(null));
	Carta carta1 = att->mazzo[rand()%(att->nc)];
	Carta carta2 = dif->mazzo[rand()%(dif->nc)];
	v = combatti(carta1, carta2);
	
	if(v == G1){
		// Ha vinto att
		aggiornaValori(carta1, TRUE, (punteggioCarta(carta1) - puteggioCarta(carta2)));
		aggiornaValori(carta2, FALSE, (punteggioCarta(carta1) - puteggioCarta(carta2)));
		
	}
	else if(v == G2){
		// Ha vinto dif
		aggiornaValori(carta2, TRUE, (punteggioCarta(carta2) - puteggioCarta(carta1)));
		aggiornaValori(carta1, FALSE, (punteggioCarta(carta2) - puteggioCarta(carta1)));
		
	}
	else if(v == PARI){
		// Passo VINTO ad entrambi così aggiorna solo 1 stanchezza
		aggiornaValori(carta1, TRUE, (punteggioCarta(carta1) - puteggioCarta(carta2)));
		aggiornaValori(carta2, TRUE, (punteggioCarta(carta1) - puteggioCarta(carta2)));
	}
	else{
		printf();
	}
	
		
	
}