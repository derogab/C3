#include "config.h"

void clearScreen(){
	
system("cls"); // Clears the screen
fflush(stdin); // Svuto anche il buffer	
	
}

void fullScreen(){
	
	if(isFullScreenEnable == FALSE){
	
	keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
	isFullScreenEnable = TRUE;
	
	}
}

Giocatore getGiocatore(){
	
	// Funzione che chiede i dati del giocatore
	// e restituisce una vatiabile di tipo Giocatore con all'interno tutti i dati relativi richiesti.
	char nome[LS];
	int giorno; int mese; int anno;
	Giocatore new_giocatore;
	printf("Inserisci il nome del giocatore: ");
	gets(nome); fflush(stdin);
	
	printf("Inserisci la data di nascita del giocatore (gg/mm/aaaa): ");
	scanf("%d/%d/%d", &giorno, &mese, &anno);
	fflush(stdin);
		
	strcpy(new_giocatore.nome, nome);
	new_giocatore.nascita.giorno = giorno;
	new_giocatore.nascita.mese = mese;
	new_giocatore.nascita.anno = anno;
	
	return new_giocatore; // Ritorno il giocatore appena creato con le sue varie informazioni
	
}

char continua(){
	// Nuova partita?
	fflush(stdin);
	printf("\nVuoi iniziare un'altra partita? (Y/N) ");
	
	return getchar();	
}

void titolo(){

printf("\n _____ ____");
printf("\n| ____|___ |");
printf("\n||      __)|");
printf("\n||     |__ |");
printf("\n||____ ___)|");
printf("\n|_____|____|");

fflush(stdin);

}

char regolamento(){
	
	printf("\n\nREGOLAMENTO DI C3:\n.....\n.....\n.....\n.....\n.....\n.....\n\n");	
	
	printf("Accetti il regolamento del gioco? (Y/N) ");
	
	fflush(stdin);
	return getchar();
	
}

void preparazione(){
	int i;
	
	system("cls"); // Clears the screen
	printf("Preparazione schermata in corso");
	for(i=0;i<4;i++){ printf("."); sleep(1); }
	system("cls"); // Clears the screen
	fullScreen();
	for(i=0;i<COUNTDOWN;i++){ printf("La partita iniziera' fra %d secondi.", (COUNTDOWN-i)); sleep(1); system("cls"); }
	system("cls"); // Clears the screen
	
}

void mischia(Giocatore *x, Giocatore *y){

	int i;
	x->nc = CARTE; // Inizializza il numero delle carte
	y->nc = CARTE; // Inizializza il numero delle carte
	
	for(i = 0; i < CARTE; i++){
	
	strcpy(x->mazzo[i].display[0], "|Q  ww|");
	strcpy(x->mazzo[i].display[1], "| o {(|");
	strcpy(x->mazzo[i].display[2], "|o o%%|");
	strcpy(x->mazzo[i].display[3], "|_%%%O|");
	
	strcpy(y->mazzo[i].display[0], "|Q  ww|");
	strcpy(y->mazzo[i].display[1], "| o {(|");
	strcpy(y->mazzo[i].display[2], "|o o%%|");
	strcpy(y->mazzo[i].display[3], "|_%%%O|");

	}

}

void turno(Giocatore *att, Giocatore *dif){
	
	clearScreen();
	
	printf("\nTurno di %s: \n\n", att->nome);
	
	
	mano(*att);
	
	
	
	//TOGLI QUESTA PARTE
	att->nc--; dif->nc--; fflush(stdin); getchar(); fflush(stdin); // Per ora serve solo per terminare il programma dopo un po' di cicli
	// TOGLI QUESTA PARTE
	
	clearScreen();
}

void start(Giocatore *p1, Giocatore *p2){
	// Ricorda che Player 1 deve partire prima perche' giovane

	while(1){
		
		if(p1->nc == 0){ break; }else{ system("color 1F"); turno(p1,p2); }
		if(p2->nc == 0){ break; }else{ system("color 5F"); turno(p2,p1); }
		
	}
	
	system("color 0F"); // Torno alla normalita'
	
}


void mano(Giocatore g){

printf("\n                                ______________________________________________________________________________________");
printf("\n                               |                                                                                     |");
printf("\n                               |           %5s %5s %5s %5s %5s %5s %5s %5s %5s   |", g.mazzo[0].display[0], g.mazzo[1].display[0], g.mazzo[2].display[0], g.mazzo[3].display[0], g.mazzo[4].display[0], g.mazzo[5].display[0], g.mazzo[6].display[0], g.mazzo[7].display[0], g.mazzo[8].display[0]);
printf("\n                    _.---------|.--.       %5s %5s %5s %5s %5s %5s %5s %5s %5s   |", g.mazzo[0].display[1], g.mazzo[1].display[1], g.mazzo[2].display[1], g.mazzo[3].display[1], g.mazzo[4].display[1], g.mazzo[5].display[1], g.mazzo[6].display[1], g.mazzo[7].display[1], g.mazzo[8].display[1]);
printf("\n                 .-'  `       .'/  ``      %5s %5s %5s %5s %5s %5s %5s %5s %5s   |", g.mazzo[0].display[2], g.mazzo[1].display[2], g.mazzo[2].display[2], g.mazzo[3].display[2], g.mazzo[4].display[2], g.mazzo[5].display[2], g.mazzo[6].display[2], g.mazzo[7].display[2], g.mazzo[8].display[2]);
printf("\n              .-'           .' |    /|     %5s %5s %5s %5s %5s %5s %5s %5s %5s   |", g.mazzo[0].display[3], g.mazzo[1].display[3], g.mazzo[2].display[3], g.mazzo[3].display[3], g.mazzo[4].display[3], g.mazzo[5].display[3], g.mazzo[6].display[3], g.mazzo[7].display[3], g.mazzo[8].display[3]);
printf("\n           .-'         |   /   `.__//                                                                                |");
printf("\n        .-'           _.--/        /       %5s %5s %5s %5s %5s %5s %5s %5s %5s   |", g.mazzo[9].display[0], g.mazzo[10].display[0], g.mazzo[11].display[0], g.mazzo[12].display[0], g.mazzo[13].display[0], g.mazzo[14].display[0], g.mazzo[15].display[0], g.mazzo[16].display[0], g.mazzo[17].display[0]);
printf("\n       |        _  .-'   /        /        %5s %5s %5s %5s %5s %5s %5s %5s %5s   |", g.mazzo[9].display[1], g.mazzo[10].display[1], g.mazzo[11].display[1], g.mazzo[12].display[1], g.mazzo[13].display[1], g.mazzo[14].display[1], g.mazzo[15].display[1], g.mazzo[16].display[1], g.mazzo[17].display[1]);
printf("\n       |     ._  \      /     `  /          %5s %5s %5s %5s %5s %5s %5s %5s %5s   |", g.mazzo[9].display[2], g.mazzo[10].display[2], g.mazzo[11].display[2], g.mazzo[12].display[2], g.mazzo[13].display[2], g.mazzo[14].display[2], g.mazzo[15].display[2], g.mazzo[16].display[2], g.mazzo[17].display[2]);
printf("\n       |        ` .    /     `  /          %5s %5s %5s %5s %5s %5s %5s %5s %5s   |", g.mazzo[9].display[3], g.mazzo[10].display[3], g.mazzo[11].display[3], g.mazzo[12].display[3], g.mazzo[13].display[3], g.mazzo[14].display[3], g.mazzo[15].display[3], g.mazzo[16].display[3], g.mazzo[17].display[3]);
printf("\n       |         \ \ '/        /                                                                                       |");
printf("\n       |        - \  /        /|            %5s %5s %5s %5s %5s %5s %5s %5s           |", g.mazzo[18].display[0], g.mazzo[19].display[0], g.mazzo[20].display[0], g.mazzo[21].display[0], g.mazzo[22].display[0], g.mazzo[23].display[0], g.mazzo[24].display[0], g.mazzo[25].display[0]);
printf("\n       |        '  .'        / |           %5s %5s %5s %5s %5s %5s %5s %5s           |", g.mazzo[18].display[1], g.mazzo[19].display[1], g.mazzo[20].display[1], g.mazzo[21].display[1], g.mazzo[22].display[1], g.mazzo[23].display[1], g.mazzo[24].display[1], g.mazzo[25].display[1]);
printf("\n       |          '         |.'|           %5s %5s %5s %5s %5s %5s %5s %5s           |", g.mazzo[18].display[2], g.mazzo[19].display[2], g.mazzo[20].display[2], g.mazzo[21].display[2], g.mazzo[22].display[2], g.mazzo[23].display[2], g.mazzo[24].display[2], g.mazzo[25].display[2]);
printf("\n       |                    |  |           %5s %5s %5s %5s %5s %5s %5s %5s           |", g.mazzo[18].display[3], g.mazzo[19].display[3], g.mazzo[20].display[3], g.mazzo[21].display[3], g.mazzo[22].display[3], g.mazzo[23].display[3], g.mazzo[24].display[3], g.mazzo[25].display[3]);
printf("\n       |                    |  |_____________________________________________________________________________________|");
printf("\n       |                    |.'");
printf("\n       |                    /");
printf("\n       |                   /");
printf("\n       |                  /");
printf("\n       )                 /|");
printf("\n    .A/`-.              / |");
printf("\n   AMMMA. `-._         / /");
printf("\n  AMMMMMMMMA. `-.     / /");
printf("\n AMMMMMMMMMMMMA. `.    /");
printf("\nAMMMMMMMMMMMMMMMMA.`. /");
printf("\nMMMMMMMMMMMMMMMMMMMA.`.");
printf("\nMMMMMMMMMMMMMMMMMMMMMA.`.");
printf("\nMMMMMMMMMMMMMMMMMMMMMMMA.");
printf("\nMMMMMMMMMMMMMMMMMMMMMMMMMA.");
printf("\nMMMMMMMMMMMMMMMMMMMMMMMMMMM");
printf("\nMMMMMMMMMMMMMMMMMMMMMMMMMV'");	
}

void gioca(Giocatore g1, Giocatore g2){
	
	preparazione();
	mischia(&g1, &g2);
	
	// Guardo il giocatore piu' giovane
	if(g1.nascita.anno > g2.nascita.anno){
		// G2 giovane
		start(&g2, &g1);
	}
	else if(g1.nascita.anno < g2.nascita.anno){
		// G1 giovane
		start(&g1, &g2);
	}
	else{
		// Gli anni sono uguali, devo guardare il mese.
		if(g1.nascita.mese > g2.nascita.mese){
			// G2 giovane
			start(&g2, &g1);
		}
		else if(g1.nascita.mese < g2.nascita.mese){
			// G1 giovane
			start(&g1, &g2);
		}
		else{
			// Anche i mesi sono uguali, devo guardare il giorno
			if(g1.nascita.giorno > g2.nascita.giorno){
				// G2 giovane
				start(&g2, &g1);
			}
			else if(g1.nascita.mese < g2.nascita.mese){
				// G1 giovane
				start(&g1, &g2);			
			}
			else{
				// Sono nati lo stesso giorno, fai partire il gioco a caso!
				start(&g2, &g1); // Faccio partire prima il primo che ha inserito i dati
			}
			
		}
	}
}

Vincitore combatti(Carta *c1, Carta *c2){
	int p_c1 = punteggioCarta(c1);
	int p_c2 = punteggioCarta(c2);
	if(p_c1 > p_c2){
		aggiornaValori(c1, TRUE, 0);
		aggiornaValori(c2, FALSE, (p_c1 - p_c2));
		return G1;
	}else if(p_c1 < p_c2){
		aggiornaValori(c2, TRUE, 0);
		aggiornaValori(c1, FALSE, (p_c2 - p_c1));
		return G2;
	}
	aggiornaValori(c1, TRUE, 0);
	aggiornaValori(c2, TRUE, 0);
		
	return PARI;
}

void aggiornaValori(Carta *c, boolean vinto, int diff){
	if(vinto == TRUE){
		c->stanchezza += 1;
	}else{
		c->stanchezza += diff;
	}
}

int punteggioCarta(Carta *c){
	int p = (c->forza) + getForzaArma(c->arma);
	p -= c->stanchezza; // Sottrai stanchezza
	return p;
}

int getForzaArma(Arma arma){
	int forza = arma.forza;
	if(arma.potenziamento.attivo == TRUE){
		forza += arma.potenziamento.punti;
	}
	return forza;
}
boolean isGameEnd(Giocatore g1, Giocatore g2){
	if(g1.nc == 0 || g2.nc == 0){
		return TRUE;
	}
	return FALSE;
}
Giocatore getWinnerGame(Giocatore g1, Giocatore g2){  //prima richiama isGameEnd
	if(g1.nc == 0){
		return g2;
	}
	return g1;	
}
int lancioDado(){
	printf("%d", rand()%6 +1);
}
void updateDobloniWinner(Giocatore *g){
	(g->dobloni)++;
}
