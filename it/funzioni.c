#include <windows.h>
#include <conio.h>
#include "strutture.c"

void FullScreenMode()
{
	keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
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
	
	printf("\nTurno di %s: \n\n", att->nome);
	
	
	mano(*att);
	
	
	
	//TOGLI QUESTA PARTE
	att->nc++; dif->nc--; fflush(stdin); getchar(); fflush(stdin);
	// TOGLI QUESTA PARTE
	
}

void start(Giocatore *p1, Giocatore *p2){
	// Ricorda che Player 1 deve partire prima perchè è il più giovane

	while(1){
		
		if(p1->nc == 0){ break; }else{ turno(p1,p2); }
		if(p2->nc == 0){ break; }else{ turno(p2,p1); }
		
	}
	
}


void mano(Giocatore g){
	
	
printf("\n                                ______________________________________");
printf("\n                               |                                      |");
printf("\n                    _.---------|.--.       %5s %5s            |", g.mazzo[0].display[0], g.mazzo[1].display[0]);
printf("\n                 .-'  `       .'/  ``      %5s %5s            |", g.mazzo[0].display[1], g.mazzo[1].display[0]);
printf("\n              .-'           .' |    /|     %5s %5s            |", g.mazzo[0].display[2], g.mazzo[1].display[0]);
printf("\n           .-'         |   /   `.__//      %5s %5s            |", g.mazzo[0].display[3], g.mazzo[1].display[0]);
printf("\n        .-'           _.--/        /                                  |");
printf("\n       |        _  .-'   /        /                                   |");
printf("\n       |     ._  \      /     `  /                                     |");
printf("\n       |        ` .    /     `  /                                     |");
printf("\n       |         \ \ '/        /                                        |");
printf("\n       |        - \  /        /|                                       |");
printf("\n       |        '  .'        / |                                      |");
printf("\n       |          '         |.'|                                      |");
printf("\n       |                    |  |                                      |");
printf("\n       |                    |  |______________________________________|");
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
	
	// Guardo il giocatore più giovane
	if(g1.nascita.anno > g2.nascita.anno){
		// G2 è più giovane
		start(&g2, &g1);
	}
	else if(g1.nascita.anno < g2.nascita.anno){
		// G1 è più giovane
		start(&g1, &g2);
	}
	else{
		// Gli anni sono uguali, devo guardare il mese.
		if(g1.nascita.mese > g2.nascita.mese){
			// G2 è più giovane
			start(&g2, &g1);
		}
		else if(g1.nascita.mese < g2.nascita.mese){
			// G1 è più giovane
			start(&g1, &g2);
		}
		else{
			// Anche i mesi sono uguali, devo guardare il giorno
			if(g1.nascita.giorno > g2.nascita.giorno){
				// G2 è più giovane
				start(&g2, &g1);
			}
			else if(g1.nascita.mese < g2.nascita.mese){
				// G1 è più giovane
				start(&g1, &g2);			
			}
			else{
				// Sono nati lo stesso giorno, fai partire il gioco a caso!
				start(&g2, &g1); // Faccio partire prima il primo che ha inserito i dati
			}
			
		}
	}
	
	
	
	
}
