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
	
	printf("\n\nREGOLAMENTO DI C3:\n");

printf("\nN° GIOCATORI: 2\n");
printf("\nOBIETTIVO: conquistare tutte le carte dell’avversario.\n");
printf("\nAll’inizio della partita il mazzo \130 composto da 26 carte, e viene diviso a metà fra i 2 giocatori.\n");
printf("\nOgni carta, che rappresenta un personaggio di fantasia, è così strutturata:\n");
printf("\n\tnome del personaggio;\n");
printf("\n\tforza del personaggio;\n");
printf("\n\tarma e punti di forza dell’arma;\n");
printf("\n\tcosto in dobloni;\n");
printf("\n\tpunti di potenziamento da aggiungere alla forza dell’arma;\n");
printf("\n\tdurata del potenziamento;\n");
printf("\n\tpunti stanchezza.\n");
printf("\nOgni giocatore riceve inoltre una somma iniziale pari a 50 dobloni.\n");
printf("\nINIZIALIZZAZIONE: inserire nomi e date di nascita dei giocatori.\n");
printf("\nInizia il giocatore piu' giovane.\n");
printf("\nAd ogni turno il programma mostra due opzioni: \n");
printf("\n\t1.acquisto carte\n");
printf("\n\t2.combattimento\n");
printf("\nSi calcolano e si confrontano i punteggi delle due carte estratte, sommando i punti forza del personaggio ai punti dell’arma in dotazione e sottraendo al risultato finale i punti stanchezza.\n");
printf("\nIl personaggio che ha punteggio maggiore vince la sfida e fa guadagnare un doblone al giocatore estraendolo dal forziere comune.\n");
printf("\nIn caso di pareggio non si estraggono dobloni dal forziere ed è necessario rilanciare i dadi.");
printf("\nDopo la sfida è necessario aggiornare i valori di ogni carta:\n");
printf("\n\tchi ha vinto acquisisce comunque un punto stanchezza;\n");
printf("\n\tchi ha perso acquisisce un numero di punti stanchezza pari alla differenza fra le due forze totali che sono state confrontate;\n");
printf("\n\tle carte che stanno a riposo per almeno tre turni consecutivi, si ricaricano fino ad annullare il valore della stanchezza.\n");
printf("\nSe i dobloni del giocatore sono sufficienti, prima di ogni turno è possibile acquistare una sola carta dall'avversario. L'avversario non può rifiutare l'acquisto di una carta.\n");
printf("\nIl gioco termina quando uno dei due giocatori è riuscito a sottrarre tutte le carte avversarie.\n");
	
	printf("\n\nAccetti il regolamento del gioco? (Y/N) ");
	
	fflush(stdin);
	return getchar();
	
}

void preparazione(){
	int i;
	
	system("cls"); // Clears the screen
	printf("Preparazione schermata in corso");
	for(i=0;i<3;i++){ printf("."); sleep(1); }
	system("cls"); // Clears the screen
	fullScreen();
	for(i=0;i<COUNTDOWN;i++){ printf("La partita iniziera' fra %d secondi.", (COUNTDOWN-i)); sleep(1); system("cls"); }
	system("cls"); // Clears the screen
	
}

void mischia(Giocatore *x, Giocatore *y){

	int i;
	x->nc = CARTE; // Inizializza il numero delle carte
	y->nc = CARTE; // Inizializza il numero delle carte
	
	// Inizializzazione carte
	
	
//carta 1
strcpy(x->mazzo[0].nome, "Sciamano Goblin");
x->mazzo[0].costo = 20;
strcpy(x->mazzo[0].arma.nome, "Bastone Morghur");
x->mazzo[0].arma.forza = 150;
strcpy(x->mazzo[0].arma.potenziamento.nome, "Funghi allucinogeni");
x->mazzo[0].arma.potenziamento.attivo = FALSE;
x->mazzo[0].arma.potenziamento.punti = 8;
x->mazzo[0].arma.potenziamento.durata = 5;
x->mazzo[0].forza = 100;
x->mazzo[0].stanchezza = 0;
x->mazzo[0].riposo = 0;
// Grafica Carta 1
strcpy(x->mazzo[0].display[0], "|  _  |");
strcpy(x->mazzo[0].display[1], "| / \ |");
strcpy(x->mazzo[0].display[2], "|(___)|");
strcpy(x->mazzo[0].display[3], "| /_\ |");

//carta 2
strcpy(x->mazzo[1].nome, "Troll di caverna");
x->mazzo[1].costo = 18;
strcpy(x->mazzo[1].arma.nome, "Zanna di Gigante");
x->mazzo[1].arma.forza = 120;
strcpy(x->mazzo[1].arma.potenziamento.nome, "Clava");
x->mazzo[1].arma.potenziamento.attivo = FALSE;
x->mazzo[1].arma.potenziamento.punti = 3;
x->mazzo[1].arma.potenziamento.durata = 5;
x->mazzo[1].forza = 100;
x->mazzo[1].stanchezza = 0;
x->mazzo[1].riposo = 0;
// Grafica Carta 2
strcpy(x->mazzo[1].display[0], "| /-|||");
strcpy(x->mazzo[1].display[1], "|(  |||");
strcpy(x->mazzo[1].display[2], "| \-|||");
strcpy(x->mazzo[1].display[3], "|   |||");

//carta 3
strcpy(x->mazzo[2].nome, "Arcimago Elfo");
x->mazzo[2].costo = 21;
strcpy(x->mazzo[2].arma.nome, "Arco della Luna");
x->mazzo[2].arma.forza = 170;
strcpy(x->mazzo[2].arma.potenziamento.nome, "Grifone");
x->mazzo[2].arma.potenziamento.attivo = FALSE;
x->mazzo[2].arma.potenziamento.punti = 10;
x->mazzo[2].arma.potenziamento.durata = 5;
x->mazzo[2].forza = 100;
x->mazzo[2].stanchezza = 0;
x->mazzo[2].riposo = 0;
// Grafica Carta 3
strcpy(x->mazzo[2].display[0], "| \   |");
strcpy(x->mazzo[2].display[1], "|__)_\|");
strcpy(x->mazzo[2].display[2], "|  ) /|");
strcpy(x->mazzo[2].display[3], "| /   |"); 

//carta 4
strcpy(x->mazzo[3].nome, "Banshee");
x->mazzo[3].costo = 25;
strcpy(x->mazzo[3].arma.nome, "Urlo paralizzante");
x->mazzo[3].arma.forza = 200;
strcpy(x->mazzo[3].arma.potenziamento.nome, "Lama spettrale");
x->mazzo[3].arma.potenziamento.attivo = FALSE;
x->mazzo[3].arma.potenziamento.punti = 12;
x->mazzo[3].arma.potenziamento.durata = 5;
x->mazzo[3].forza = 100;
x->mazzo[3].stanchezza = 0;
x->mazzo[3].riposo = 0;
// Grafica Carta 4
strcpy(x->mazzo[3].display[0], "| _}{_|");
strcpy(x->mazzo[3].display[1], "| ‘||’|");
strcpy(x->mazzo[3].display[2], "|  || |");
strcpy(x->mazzo[3].display[3], "|  \/ |"); 

//carta 5
strcpy(x->mazzo[4].nome, "Necromante");
x->mazzo[4].costo = 22;
strcpy(x->mazzo[4].arma.nome, "Tomo dell’evocazione");
x->mazzo[4].arma.forza = 180;
strcpy(x->mazzo[4].arma.potenziamento.nome, "Pegaso Nero");
x->mazzo[4].arma.potenziamento.attivo = FALSE;
x->mazzo[4].arma.potenziamento.punti = 15;
x->mazzo[4].arma.potenziamento.durata = 5;
x->mazzo[4].forza = 100;
x->mazzo[4].stanchezza = 0;
x->mazzo[4].riposo = 0;
// Grafica Carta 5
strcpy(x->mazzo[4].display[0], "| /-/||");
strcpy(x->mazzo[4].display[1], "|/_/ ||");
strcpy(x->mazzo[4].display[2], "|| |M||");
strcpy(x->mazzo[4].display[3], "||_|/ |");
                        
//carta 6
strcpy(x->mazzo[5].nome, "Incantatrice Oscura");
x->mazzo[5].costo = 18;
strcpy(x->mazzo[5].arma.nome, "Pugnale del Sacrificio");
x->mazzo[5].arma.forza = 180;
strcpy(x->mazzo[5].arma.potenziamento.nome, "Altare Sanguinante");
x->mazzo[5].arma.potenziamento.attivo = FALSE;
x->mazzo[5].arma.potenziamento.punti = 7;
x->mazzo[5].arma.potenziamento.durata = 5;
x->mazzo[5].forza = 100;
x->mazzo[5].stanchezza = 0;
x->mazzo[5].riposo = 0;
// Grafica Carta 6
strcpy(x->mazzo[5].display[0], "|  /| |");
strcpy(x->mazzo[5].display[1], "| /:| |");
strcpy(x->mazzo[5].display[2], "|_):|_|");
strcpy(x->mazzo[5].display[3], "| :#| |");
                        
//carta 7
strcpy(x->mazzo[6].nome, "Ingegnere Nano");
x->mazzo[6].costo = 15;
strcpy(x->mazzo[6].arma.nome, "Cannone Lanciafiamme");
x->mazzo[6].arma.forza = 140;
strcpy(x->mazzo[6].arma.potenziamento.nome, "Archibugio dei Nani");
x->mazzo[6].arma.potenziamento.attivo = FALSE;
x->mazzo[6].arma.potenziamento.punti = 18;
x->mazzo[6].arma.potenziamento.durata = 5;
x->mazzo[6].forza = 100;
x->mazzo[6].stanchezza = 0;
x->mazzo[6].riposo = 0;
// Grafica Carta 7
strcpy(x->mazzo[6].display[0], "|Rifle|");
strcpy(x->mazzo[6].display[1], "|'==='|");
strcpy(x->mazzo[6].display[2], "|//'  |");
strcpy(x->mazzo[6].display[3], "|~    |");         

//carta 8
strcpy(x->mazzo[7].nome, "Scheletro");
x->mazzo[7].costo = 12;
strcpy(x->mazzo[7].arma.nome, "Cavallo spettrale");
x->mazzo[7].arma.forza = 130;
strcpy(x->mazzo[7].arma.potenziamento.nome, "Lanciatore di ossa");
x->mazzo[7].arma.potenziamento.attivo = FALSE;
x->mazzo[7].arma.potenziamento.punti = 4;
x->mazzo[7].arma.potenziamento.durata = 5;
x->mazzo[7].forza = 100;
x->mazzo[7].stanchezza = 0;
x->mazzo[7].riposo = 0;
// Grafica Carta 8
strcpy(x->mazzo[7].display[0], "|oo   |");
strcpy(x->mazzo[7].display[1], "| !!  |");
strcpy(x->mazzo[7].display[2], "| !!  |");
strcpy(x->mazzo[7].display[3], "|oo   |");  

//carta 9
strcpy(x->mazzo[8].nome, "Re Spettro");
x->mazzo[8].costo = 19;
strcpy(x->mazzo[8].arma.nome, "Lama Ululante");
x->mazzo[8].arma.forza = 125;
strcpy(x->mazzo[8].arma.potenziamento.nome, "Carro dei cadaveri");
x->mazzo[8].arma.potenziamento.attivo = FALSE;
x->mazzo[8].arma.potenziamento.punti = 5;
x->mazzo[8].arma.potenziamento.durata = 5;
x->mazzo[8].forza = 100;
x->mazzo[8].stanchezza = 0;
x->mazzo[8].riposo = 0;
// Grafica Carta 9
strcpy(x->mazzo[8].display[0], "|_{ }_ |");
strcpy(x->mazzo[8].display[1], "| ):( |");
strcpy(x->mazzo[8].display[2], "| ):( |");
strcpy(x->mazzo[8].display[3], "| \/  |");   

//carta 10
strcpy(x->mazzo[9].nome, "Uomo Bestia");
x->mazzo[9].costo = 9;
strcpy(x->mazzo[9].arma.nome, "Doppia Ascia");
x->mazzo[9].arma.forza = 160;
strcpy(x->mazzo[9].arma.potenziamento.nome, "Cinghiale");
x->mazzo[9].arma.potenziamento.attivo = FALSE;
x->mazzo[9].arma.potenziamento.punti = 6;
x->mazzo[9].arma.potenziamento.durata = 5;
x->mazzo[9].forza = 100;
x->mazzo[9].stanchezza = 0;
x->mazzo[9].riposo = 0;
// Grafica Carta 10
strcpy(x->mazzo[9].display[0], "| /(  |");
strcpy(x->mazzo[9].display[1], "|( -|||");
strcpy(x->mazzo[9].display[2], "| \(|||");
strcpy(x->mazzo[9].display[3], "|   |||");  
             
//carta 11
strcpy(x->mazzo[10].nome, "Guerriero del Caos");
x->mazzo[10].costo = 23;
strcpy(x->mazzo[10].arma.nome, "Lancia Oscura");
x->mazzo[10].arma.forza = 190;
strcpy(x->mazzo[10].arma.potenziamento.nome, "Destriero dell’Apocalisse");
x->mazzo[10].arma.potenziamento.attivo = FALSE;
x->mazzo[10].arma.potenziamento.punti = 10;
x->mazzo[10].arma.potenziamento.durata = 5;
x->mazzo[10].forza = 100;
x->mazzo[10].stanchezza = 0;
x->mazzo[10].riposo = 0;
// Grafica Carta 11
strcpy(x->mazzo[10].display[0], "| /(  |");
strcpy(x->mazzo[10].display[1], "|( -|||");
strcpy(x->mazzo[10].display[2], "| \(|||");
strcpy(x->mazzo[10].display[3], "|   |||"); 
       
//carta 12
strcpy(x->mazzo[11].nome, "Ghoul");
x->mazzo[11].costo = 24;
strcpy(x->mazzo[11].arma.nome, "Spada arrugginita");
x->mazzo[11].arma.forza = 200;
strcpy(x->mazzo[11].arma.potenziamento.nome, "Emerge dal terreno");
x->mazzo[11].arma.potenziamento.attivo = FALSE;
x->mazzo[11].arma.potenziamento.punti = 8;
x->mazzo[11].arma.potenziamento.durata = 5;
x->mazzo[11].forza = 100;
x->mazzo[11].stanchezza = 0;
x->mazzo[11].riposo = 0;
// Grafica Carta 12
strcpy(x->mazzo[11].display[0], "|_{ }_ |");
strcpy(x->mazzo[11].display[1], "| ):( |");
strcpy(x->mazzo[11].display[2], "| ):( |");
strcpy(x->mazzo[11].display[3], "| \/  |");

//carta 13
strcpy(x->mazzo[12].nome, "Demone");
x->mazzo[12].costo = 20;
strcpy(x->mazzo[12].arma.nome, "Lama Eterea");
x->mazzo[12].arma.forza = 150;
strcpy(x->mazzo[12].arma.potenziamento.nome, "Divoratore");
x->mazzo[12].arma.potenziamento.attivo = FALSE;
x->mazzo[12].arma.potenziamento.punti = 3;
x->mazzo[12].arma.potenziamento.durata = 5;
x->mazzo[12].forza = 100;
x->mazzo[12].stanchezza = 0;
x->mazzo[12].riposo = 0;
// Grafica Carta 13
strcpy(x->mazzo[12].display[0], "|_{ }_ |");
strcpy(x->mazzo[12].display[1], "| ):( |");
strcpy(x->mazzo[12].display[2], "| ):( |");
strcpy(x->mazzo[12].display[3], "| \/  |"); 

//carta 14
strcpy(y->mazzo[0].nome, "Nogitsune");
y->mazzo[0].costo = 24;
strcpy(y->mazzo[0].arma.nome, "Possiede e inganna le persone");
y->mazzo[0].arma.forza = 200;
strcpy(y->mazzo[0].arma.potenziamento.nome, "Invisibile agli occhi");
y->mazzo[0].arma.potenziamento.attivo = FALSE;
y->mazzo[0].arma.potenziamento.punti = 12;
y->mazzo[0].arma.potenziamento.durata = 5;
y->mazzo[0].forza = 100;
y->mazzo[0].stanchezza = 0;
y->mazzo[0].riposo = 0;
// Grafica Carta 14
strcpy(y->mazzo[0].display[0], "|^  ^ |");
strcpy(y->mazzo[0].display[1], "| ??  |");
strcpy(y->mazzo[0].display[2], "| —-  |");
strcpy(y->mazzo[0].display[3], "|  ?  |");

//carta 15
strcpy(y->mazzo[1].nome, "Minotauro");
y->mazzo[1].costo = 8;
strcpy(y->mazzo[1].arma.nome, "Ascia di Zanna");
y->mazzo[1].arma.forza = 120;
strcpy(y->mazzo[1].arma.potenziamento.nome, "Corno della grande Caccia ");
y->mazzo[1].arma.potenziamento.attivo = FALSE;
y->mazzo[1].arma.potenziamento.punti = 3;
y->mazzo[1].arma.potenziamento.durata = 5;
y->mazzo[1].forza = 100;
y->mazzo[1].stanchezza = 0;
y->mazzo[1].riposo = 0;
// Grafica Carta 15
strcpy(y->mazzo[1].display[0], "| /-|||");
strcpy(y->mazzo[1].display[1], "|(  |||");
strcpy(y->mazzo[1].display[2], "| \-|||");
strcpy(y->mazzo[1].display[3], "|   |||");

//carta 16
strcpy(y->mazzo[2].nome, "Stegadonte");
y->mazzo[2].costo = 16;
strcpy(y->mazzo[2].arma.nome, "Arco Gigante");
y->mazzo[2].arma.forza = 130;
strcpy(y->mazzo[2].arma.potenziamento.nome, "Pelle a Scaglie");
y->mazzo[2].arma.potenziamento.attivo = FALSE;
y->mazzo[2].arma.potenziamento.punti = 7;
y->mazzo[2].arma.potenziamento.durata = 5;
y->mazzo[2].forza = 100;
y->mazzo[2].stanchezza = 0;
y->mazzo[2].riposo = 0;
// Grafica Carta 16
strcpy(y->mazzo[2].display[0], "| \   |");
strcpy(y->mazzo[2].display[1], "|__)_\|");
strcpy(y->mazzo[2].display[2], "|  ) /|");
strcpy(y->mazzo[2].display[3], "| /   |"); 

//carta 17
strcpy(y->mazzo[3].nome, "Uomo Ratto");
y->mazzo[3].costo = 14;
strcpy(y->mazzo[3].arma.nome, "Pugnali avvelenati");
y->mazzo[3].arma.forza = 145;
strcpy(y->mazzo[3].arma.potenziamento.nome, "Peste Bubbonica");
y->mazzo[3].arma.potenziamento.attivo = FALSE;
y->mazzo[3].arma.potenziamento.punti = 12;
y->mazzo[3].arma.potenziamento.durata = 5;
y->mazzo[3].forza = 100;
y->mazzo[3].stanchezza = 0;
y->mazzo[3].riposo = 0;
// Grafica Carta 17
strcpy(y->mazzo[3].display[0], "| _}{_|");
strcpy(y->mazzo[3].display[1], "| ‘||’|");
strcpy(y->mazzo[3].display[2], "|  || |");
strcpy(y->mazzo[3].display[3], "|  \/ |"); 

//carta 18
strcpy(y->mazzo[4].nome, "Leviatano");
y->mazzo[4].costo = 21;
strcpy(y->mazzo[4].arma.nome, "Lingue di Fuoco");
y->mazzo[4].arma.forza = 200;
strcpy(y->mazzo[4].arma.potenziamento.nome, "Scaglie rotanti");
y->mazzo[4].arma.potenziamento.attivo = FALSE;
y->mazzo[4].arma.potenziamento.punti = 14;
y->mazzo[4].arma.potenziamento.durata = 5;
y->mazzo[4].forza = 100;
y->mazzo[4].stanchezza = 0;
y->mazzo[4].riposo = 0;
// Grafica Carta 18
strcpy(y->mazzo[4].display[0], "| (   |");
strcpy(y->mazzo[4].display[1], "| ((  ||");
strcpy(y->mazzo[4].display[2], "| ) \ |");
strcpy(y->mazzo[4].display[3], "|( # )|");

                          
//carta 19
strcpy(y->mazzo[5].nome, "Sauro Anziano");
y->mazzo[5].costo = 17;
strcpy(y->mazzo[5].arma.nome, "Lama della Realtà");
y->mazzo[5].arma.forza = 160;
strcpy(y->mazzo[5].arma.potenziamento.nome, "Carnasauro");
y->mazzo[5].arma.potenziamento.attivo = FALSE;
y->mazzo[5].arma.potenziamento.punti = 13;
y->mazzo[5].arma.potenziamento.durata = 5;
y->mazzo[5].forza = 100;
y->mazzo[5].stanchezza = 0;
y->mazzo[5].riposo = 0;
// Grafica Carta 19
strcpy(y->mazzo[5].display[0], "|  /| |");
strcpy(y->mazzo[5].display[1], "| /:| |");
strcpy(y->mazzo[5].display[2], "|_):|_|");
strcpy(y->mazzo[5].display[3], "| :#| |");
                        
//carta 20
strcpy(y->mazzo[6].nome, "Kanima");
y->mazzo[6].costo = 24;
strcpy(y->mazzo[6].arma.nome, "veleno paralizzante");
y->mazzo[6].arma.forza = 205;
strcpy(y->mazzo[6].arma.potenziamento.nome, "Squame taglienti");
y->mazzo[6].arma.potenziamento.attivo = FALSE;
y->mazzo[6].arma.potenziamento.punti = 6;
y->mazzo[6].arma.potenziamento.durata = 5;
y->mazzo[6].forza = 100;
y->mazzo[6].stanchezza = 0;
y->mazzo[6].riposo = 0;
// Grafica Carta 20
strcpy(y->mazzo[6].display[0], "|Help |");
strcpy(y->mazzo[6].display[1], "|’ ‘__|");
strcpy(y->mazzo[6].display[2], "|0 0^^|");
strcpy(y->mazzo[6].display[3], "|\_/ |");

//carta 21
strcpy(y->mazzo[7].nome, "Signore della Peste");
y->mazzo[7].costo = 9;
strcpy(y->mazzo[7].arma.nome, "Campana del Destino");
y->mazzo[7].arma.forza = 150;
strcpy(y->mazzo[7].arma.potenziamento.nome, "Globo divinatorio");
y->mazzo[7].arma.potenziamento.attivo = FALSE;
y->mazzo[7].arma.potenziamento.punti = 11;
y->mazzo[7].arma.potenziamento.durata = 5;
y->mazzo[7].forza = 100;
y->mazzo[7].stanchezza = 0;
y->mazzo[7].riposo = 0;
// Grafica Carta 21
strcpy(y->mazzo[7].display[0], "| _|_ |");
strcpy(y->mazzo[7].display[1], "|(   )|");
strcpy(y->mazzo[7].display[2], "|/___\|");
strcpy(y->mazzo[7].display[3], "|  ~  |");   

//carta 22
strcpy(y->mazzo[8].nome, "Berseker");
y->mazzo[8].costo = 21;
strcpy(y->mazzo[8].arma.nome, "Pugnale di Ossa");
y->mazzo[8].arma.forza = 200;
strcpy(y->mazzo[8].arma.potenziamento.nome, "Ricostruzione Ossea");
y->mazzo[8].arma.potenziamento.attivo = FALSE;
y->mazzo[8].arma.potenziamento.punti = 10;
y->mazzo[8].arma.potenziamento.durata = 5;
y->mazzo[8].forza = 100;
y->mazzo[8].stanchezza = 0;
y->mazzo[8].riposo = 0;
// Grafica Carta 22
strcpy(y->mazzo[8].display[0], "|_{ }_ |");
strcpy(y->mazzo[8].display[1], "| |:| |");
strcpy(y->mazzo[8].display[2], "| |:| |");
strcpy(y->mazzo[8].display[3], "| 00  |");   

//carta 23
strcpy(y->mazzo[9].nome, "Kraken");
y->mazzo[9].costo = 24;
strcpy(y->mazzo[9].arma.nome, "Tentacoli Anneganti");
y->mazzo[9].arma.forza = 250;
strcpy(y->mazzo[9].arma.potenziamento.nome, "Inchiostro confusionale");
y->mazzo[9].arma.potenziamento.attivo = FALSE;
y->mazzo[9].arma.potenziamento.punti = 16;
y->mazzo[9].arma.potenziamento.durata = 5;
y->mazzo[9].forza = 100;
y->mazzo[9].stanchezza = 0;
y->mazzo[9].riposo = 0;
// Grafica Carta 23
strcpy(y->mazzo[9].display[0], "|  |> |");
strcpy(y->mazzo[9].display[1], "|__|__|");
strcpy(y->mazzo[9].display[2], "|\___/|");
strcpy(y->mazzo[9].display[3], "|~~~~~|");  

//carta 24
strcpy(y->mazzo[10].nome, "Arpia");
y->mazzo[10].costo = 5;
strcpy(y->mazzo[10].arma.nome, "Artigli");
y->mazzo[10].arma.forza = 140;
strcpy(y->mazzo[10].arma.potenziamento.nome, "Canto ammaliante");
y->mazzo[10].arma.potenziamento.attivo = FALSE;
y->mazzo[10].arma.potenziamento.punti = 15;
y->mazzo[10].arma.potenziamento.durata = 5;
y->mazzo[10].forza = 100;
y->mazzo[10].stanchezza = 0;
y->mazzo[10].riposo = 0;
// Grafica Carta 24
strcpy(y->mazzo[10].display[0], "|‘’ __|");
strcpy(y->mazzo[10].display[1], "|o / (|");
strcpy(y->mazzo[10].display[2], "||/__(|");
strcpy(y->mazzo[10].display[3], "|(\__(|");
       
//carta 25
strcpy(y->mazzo[11].nome, "Coccatrice");
y->mazzo[11].costo = 26;
strcpy(y->mazzo[11].arma.nome, "Sguardo Pietrificante");
y->mazzo[11].arma.forza = 210;
strcpy(y->mazzo[11].arma.potenziamento.nome, "Alito velenoso");
y->mazzo[11].arma.potenziamento.attivo = FALSE;
y->mazzo[11].arma.potenziamento.punti = 10;
y->mazzo[11].arma.potenziamento.durata = 5;
y->mazzo[11].forza = 100;
y->mazzo[11].stanchezza = 0;
y->mazzo[11].riposo = 0;
// Grafica Carta 25
strcpy(y->mazzo[11].display[0], "| _V_ |");
strcpy(y->mazzo[11].display[1], "| @.@ |");
strcpy(y->mazzo[11].display[2], "|(\_/)|");
strcpy(y->mazzo[11].display[3], "| m m |");
            
//carta 26
strcpy(y->mazzo[12].nome, "Lich");
y->mazzo[12].costo = 30;
strcpy(y->mazzo[12].arma.nome, "Incantatore");
y->mazzo[12].arma.forza = 270;
strcpy(y->mazzo[12].arma.potenziamento.nome, "Pugnale dell’immortalità");
y->mazzo[12].arma.potenziamento.attivo = FALSE;
y->mazzo[12].arma.potenziamento.punti = 18;
y->mazzo[12].arma.potenziamento.durata = 5;
y->mazzo[12].forza = 100;
y->mazzo[12].stanchezza = 0;
y->mazzo[12].riposo = 0;
// Grafica Carta 26
strcpy(y->mazzo[12].display[0], "|_{ }_ |");
strcpy(y->mazzo[12].display[1], "| ):( |");
strcpy(y->mazzo[12].display[2], "| ):( |");
strcpy(y->mazzo[12].display[3], "| \/  |");






	
	
	// Fine inizializzazione carte
	
	for(i = CARTE; i < CARTE*2; i++){
	
	strcpy(x->mazzo[i].display[0], "       ");
	strcpy(x->mazzo[i].display[1], "       ");
	strcpy(x->mazzo[i].display[2], "       ");
	strcpy(x->mazzo[i].display[3], "       ");
	
	strcpy(y->mazzo[i].display[0], "       ");
	strcpy(y->mazzo[i].display[1], "       ");
	strcpy(y->mazzo[i].display[2], "       ");
	strcpy(y->mazzo[i].display[3], "       ");

	}

}

void turno(Giocatore *att, Giocatore *dif){
	
	int scelta;
	
	clearScreen();
	
	printf("\nTurno di %s: \n\n", att->nome);
	
	mano(*att);
		
	printf("\n\nCosa vuoi fare? \n\t1) Acquisto carte\n\t2) Combattimento\n\nInserisci la tua scelta: ");
	scanf("%d", &scelta);
	
	switch(scelta){
		
		case 1: acquistoCarte(att, dif); break;
		case 2: combattimento(att, dif); break;
		default: printf("Scelta non valida. "); turno(att, dif);
		
	}
	printf("\nFine turno\n\n");
/*	//TOGLI QUESTA PARTE
	att->nc--; dif->nc--; fflush(stdin); getchar(); fflush(stdin); // Per ora serve solo per terminare il programma dopo un po' di cicli
	// TOGLI QUESTA PARTE
*/	
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

void combattimento(Giocatore *att, Giocatore *dif){
	
	int i = 0;
	Carta *carta1;
	Carta *carta2;
	
	srand(time(NULL));
	
	carta1 = &(att->mazzo[rand()%((att->nc)-1)]);
	carta2 = &(dif->mazzo[rand()%((dif->nc)-1)]);
	
	clearScreen();
	
	printf("                 __");
	printf("\n                /  >");
	printf("\n  *            /  /________________________________________________");
	printf("\n (O)77777777777)  7                                                `~~--__");
	printf("\n8OO>>>>>>>>>>>>] <===   Combattimento            __-");
	printf("\n (O)LLLLLLLLLLL)  L________________________________________________.--~~");
	printf("\n  *            \  \ ");
	printf("\n                \__>");	
	
	printf("\n\n%s sta attaccando con:\n\n",att->nome);	
	printf("%s", carta1->display[0]); printf("\t\tNome: %s\n", carta1->nome);
	printf("%s", carta1->display[1]); printf("\t\tPotenza: %d\n", punteggioCarta(carta1));
	printf("%s", carta1->display[2]); if(strcmp(carta1->arma.nome, "")==0){ printf("\t\tArma : /\n"); }else{printf("\t\tArma : %s\n", carta1->arma.nome);}
	printf("%s", carta1->display[3]); printf("\t\tStanchezza: %d\n", carta1->stanchezza);		
	
	printf("\n\n");for(i=0;i<2;i++){printf(".");sleep(1);}
	
	printf("%s sta attaccando con:\n\n", dif->nome);	
	printf("%s", carta2->display[0]); printf("\t\tNome: %s\n", carta2->nome);
	printf("%s", carta2->display[1]); printf("\t\tPotenza: %d\n", punteggioCarta(carta2));
	printf("%s", carta2->display[2]); if(strcmp(carta1->arma.nome, "")==0){ printf("\t\tArma : /\n"); }else{printf("\t\tArma : %s\n", carta2->arma.nome);}
	printf("%s", carta2->display[3]); printf("\t\tStanchezza: %d\n", carta2->stanchezza);
	
	Vincitore v = combatti(carta1, carta2);
	
	if(v == G1){
		// Ha vinto att
		//aggiornaValori(carta1, TRUE, (punteggioCarta(carta1) - puteggioCarta(carta2)));
		//aggiornaValori(carta2, FALSE, (punteggioCarta(carta1) - puteggioCarta(carta2)));
		printf("\n\nHa vinto la carta di G1\n\n");
		
	}
	else if(v == G2){
		// Ha vinto dif
		//aggiornaValori(carta2, TRUE, (punteggioCarta(carta2) - puteggioCarta(carta1)));
		//aggiornaValori(carta1, FALSE, (punteggioCarta(carta2) - puteggioCarta(carta1)));
		printf("\n\nHa vinto la carta di G2\n");
	}
	else if(v == PARI){
		// Passo VINTO ad entrambi in modo da aggiornare solo 1 stanchezza
		//aggiornaValori(carta1, TRUE, (punteggioCarta(carta1) - puteggioCarta(carta2)));
		//aggiornaValori(carta2, TRUE, (punteggioCarta(carta1) - puteggioCarta(carta2)));
		
		printf("\n\nPareggio.\n");
	}
	else{
		printf("\n\nSi e' verificato un errore.\n'");
	}
	printf("\n\n");for(i=0;i<2;i++){sleep(1);}
		
	
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

void updateDobloniWinner(Giocatore *g){
	(g->dobloni)++;
}

void distruggiCarta(Carta *carta){
	strcpy(carta->nome, "");
	int k = 0;
	int i = 0;
	for(i = 0; i < 4; i++){
		strcpy(carta->display[i],"");
	}
	carta->costo = 0;
	carta->forza = 0;
	carta->stanchezza = 0;
	carta->riposo = 0;
}

boolean compraCartaAvversario(Giocatore *cliente, Giocatore *venditore){
	int r;
	Carta cartaVenduta;
	if(cliente->dobloni <= 0){
		return FALSE;
	}
	do{
		r = rand()%MAZZO;
		cartaVenduta = venditore->mazzo[r];
	} while(isCarta(&(cartaVenduta)) == FALSE);
	if(cliente->dobloni < cartaVenduta.costo){
		return FALSE;
	}
	cliente->mazzo[cliente->nc] = cartaVenduta;
	cliente->dobloni -= cartaVenduta.costo;
	venditore->dobloni += cartaVenduta.costo;
	(venditore->nc)--;
	(cliente->nc)++;
	distruggiCarta(&(venditore->mazzo[r]));
	return TRUE;
}
boolean isCarta(Carta *carta){
	if(strcmp(carta->nome,"")){
		return FALSE;
	}
	return TRUE;
}

void aumentaRiposo(int indiceCartaNonRiposo, Giocatore *giocatore){
	int n = giocatore->nc;
	int x = 0;
	for(x = 0; x < n; x++){
		if(x != indiceCartaNonRiposo){
			(giocatore->mazzo[x].riposo)++;
			if(giocatore->mazzo[x].riposo >= 3 && giocatore->mazzo[x].stanchezza > 0){
				(giocatore->mazzo[x].stanchezza)--;
			}
		}
	}
}

void ordinaMazzo(Giocatore *giocatore){
	int x = 0;
	int y = giocatore->nc;
	for(x = 0; x < giocatore->nc; x++){
		if(isCarta(&(giocatore->mazzo[x])) == FALSE){
			for(y = giocatore->nc; y < MAZZO; y++){
				if(isCarta(&(giocatore->mazzo[y]))== TRUE){
					invertiCarte(giocatore, x, y);
					break;
				}
			}
		}
	}
}

void invertiCarte(Giocatore *giocatore, int indiceVuoto, int indiceCarta){
	Carta carta = giocatore->mazzo[indiceCarta];
	giocatore->mazzo[indiceVuoto] = carta;
	distruggiCarta(&(giocatore->mazzo[indiceCarta]));
}

void acquistoCarte(Giocatore *x, Giocatore *g){
    
    int i = 0;
    int r;
    Carta c;
    
    clearScreen();
    printf("ACQUISTO CARTA AVVERSARIO: \n");
    printf("Tuoi dobloni: %d    Avversario: %d \n\n",x->dobloni, g->dobloni);
    if(x->dobloni == 0){
        
        printf("Non possiedi abbastanza dobloni per acquistare carte dell'avversario.\n\n");
        return;
    }
    
        
    printf("Scegli la carta che vuoi acquistare dall'avversario.");
     
    printf("\n%5d %5d %5d %5d %5d %5d %5d %5d %5d", g->mazzo[0].display[0], g->mazzo[1].display[0], g->mazzo[2].display[0], g->mazzo[3].display[0], g->mazzo[4].display[0], g->mazzo[5].display[0], g->mazzo[6].display[0], g->mazzo[7].display[0], g->mazzo[8].display[0]);
    printf("\n%5d %5d %5d %5d %5d %5d %5d %5d %5d", g->mazzo[0].display[1], g->mazzo[1].display[1], g->mazzo[2].display[1], g->mazzo[3].display[1], g->mazzo[4].display[1], g->mazzo[5].display[1], g->mazzo[6].display[1], g->mazzo[7].display[1], g->mazzo[8].display[1]);
    printf("\n%5d %5d %5d %5d %5d %5d %5d %5d %5d", g->mazzo[0].display[2], g->mazzo[1].display[2], g->mazzo[2].display[2], g->mazzo[3].display[2], g->mazzo[4].display[2], g->mazzo[5].display[2], g->mazzo[6].display[2], g->mazzo[7].display[2], g->mazzo[8].display[2]);
    printf("\n%5d %5d %5d %5d %5d %5d %5d %5d %5d", g->mazzo[0].display[3], g->mazzo[1].display[3], g->mazzo[2].display[3], g->mazzo[3].display[3], g->mazzo[4].display[3], g->mazzo[5].display[3], g->mazzo[6].display[3], g->mazzo[7].display[3], g->mazzo[8].display[3]);
                
    printf("\n%5d %5d %5d %5d %5d %5d %5d %5d %5d", g->mazzo[9].display[0], g->mazzo[10].display[0], g->mazzo[11].display[0], g->mazzo[12].display[0], g->mazzo[13].display[0], g->mazzo[14].display[0], g->mazzo[15].display[0], g->mazzo[16].display[0], g->mazzo[17].display[0]);
    printf("\n%5d %5d %5d %5d %5d %5d %5d %5d %5d", g->mazzo[9].display[1], g->mazzo[10].display[1], g->mazzo[11].display[1], g->mazzo[12].display[1], g->mazzo[13].display[1], g->mazzo[14].display[1], g->mazzo[15].display[1], g->mazzo[16].display[1], g->mazzo[17].display[1]);
    printf("\n%5d %5d %5d %5d %5d %5d %5d %5d %5d", g->mazzo[9].display[2], g->mazzo[10].display[2], g->mazzo[11].display[2], g->mazzo[12].display[2], g->mazzo[13].display[2], g->mazzo[14].display[2], g->mazzo[15].display[2], g->mazzo[16].display[2], g->mazzo[17].display[2]);
    printf("\n%5d %5d %5d %5d %5d %5d %5d %5d %5d", g->mazzo[9].display[3], g->mazzo[10].display[3], g->mazzo[11].display[3], g->mazzo[12].display[3], g->mazzo[13].display[3], g->mazzo[14].display[3], g->mazzo[15].display[3], g->mazzo[16].display[3], g->mazzo[17].display[3]);
    
    printf("\n%5d %5d %5d %5d %5d %5d %5d %5d", g->mazzo[18].display[0], g->mazzo[19].display[0], g->mazzo[20].display[0], g->mazzo[21].display[0], g->mazzo[22].display[0], g->mazzo[23].display[0], g->mazzo[24].display[0], g->mazzo[25].display[0]);
    printf("\n%5d %5d %5d %5d %5d %5d %5d %5d", g->mazzo[18].display[1], g->mazzo[19].display[1], g->mazzo[20].display[1], g->mazzo[21].display[1], g->mazzo[22].display[1], g->mazzo[23].display[1], g->mazzo[24].display[1], g->mazzo[25].display[1]);
    printf("\n%5d %5d %5d %5d %5d %5d %5d %5d", g->mazzo[18].display[2], g->mazzo[19].display[2], g->mazzo[20].display[2], g->mazzo[21].display[2], g->mazzo[22].display[2], g->mazzo[23].display[2], g->mazzo[24].display[2], g->mazzo[25].display[2]);
    printf("\n%5d %5d %5d %5d %5d %5d %5d %5d", g->mazzo[18].display[3], g->mazzo[19].display[3], g->mazzo[20].display[3], g->mazzo[21].display[3], g->mazzo[22].display[3], g->mazzo[23].display[3], g->mazzo[24].display[3], g->mazzo[25].display[3]);
    
    
 /*   printf("\n");for(i = 0; i < 30; i++){sleep(0.15);printf(".");}printf("\n\n");*/
    
   if(compraCartaAvversario(x, g) == TRUE){
       
     printf("\n Carta acquistata con successo.");
       
   }
   else{
       
       printf("Non possiedi abbastanza dobloni per acquistare questa carta dell'avversario..\n\n");
       
   }
   
   printf("\n");
   /*for(i = 0; i < 3; i++){
   		sleep(0.15);
   		printf(".");
   }*/
   printf("\n\n");for(i=0;i<2;i++){sleep(1);}
   printf("fine\n\n");
   
      

 
}
