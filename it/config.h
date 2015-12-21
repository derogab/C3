/*


88b           d88                     88             
888b         d888                     88             
88`8b       d8'88                     88             
88 `8b     d8' 88 ,adPPYYba,  ,adPPYb,88  ,adPPYba,  
88  `8b   d8'  88 ""     `Y8 a8"    `Y88 a8P_____88  
88   `8b d8'   88 ,adPPPPP88 8b       88 8PP"""""""  
88    `888'    88 88,    ,88 "8a,   ,d88 "8b,   ,aa  
88     `8'     88 `"8bbdP"Y8  `"8bbdP"Y8  `"Ybbd8"'  
                                                     
                                                     
                                           
                   88         88           
                   ""   ,d    88           
                        88    88           
8b      db      d8 88 MM88MMM 88,dPPYba,   
`8b    d88b    d8' 88   88    88P'    "8a  
 `8b  d8'`8b  d8'  88   88    88       88  
  `8bd8'  `8bd8'   88   88,   88       88  
    YP      YP     88   "Y888 88       88  
                                           
                                           
                                                                  
88                                       88                       
88                                       88                       
88                                       88                       
88  ,adPPYba,  8b       d8  ,adPPYba,    88,dPPYba,  8b       d8  
88 a8"     "8a `8b     d8' a8P_____88    88P'    "8a `8b     d8'  
88 8b       d8  `8b   d8'  8PP"""""""    88       d8  `8b   d8'   
88 "8a,   ,a8"   `8b,d8'   "8b,   ,aa    88b,   ,a8"   `8b,d8'    
88  `"YbbdP"'      "8"      `"Ybbd8"'    8Y"Ybbd8"'      Y88'     
                                                         d8'      
                                                        d8'       
                                                                             
  ,ad8888ba,             88                     88            88             
 d8"'    `"8b            88                     ""            88             
d8'                      88                                   88             
88            ,adPPYYba, 88,dPPYba,  8b,dPPYba, 88  ,adPPYba, 88  ,adPPYba,  
88      88888 ""     `Y8 88P'    "8a 88P'   "Y8 88 a8P_____88 88 a8P_____88  
Y8,        88 ,adPPPPP88 88       d8 88         88 8PP""""""" 88 8PP"""""""  
 Y8a.    .a88 88,    ,88 88b,   ,a8" 88         88 "8b,   ,aa 88 "8b,   ,aa  
  `"Y88888P"  `"8bbdP"Y8 8Y"Ybbd8"'  88         88  `"Ybbd8"' 88  `"Ybbd8"'  
                                                                             
                                                                             
                                                                        
88888888ba  88                                                      88  
88      "8b ""                                                      88  
88      ,8P                                                         88  
88aaaaaa8P' 88  ,adPPYba,  ,adPPYba, ,adPPYYba, 8b,dPPYba,  ,adPPYb,88   ,adPPYba,
88""""88'   88 a8"     "" a8"     "" ""     `Y8 88P'   "Y8 a8"    `Y88  a8"     "8a 
88    `8b   88 8b         8b         ,adPPPPP88 88         8b       88  8b       d8 
88     `8b  88 "8a,   ,aa "8a,   ,aa 88,    ,88 88         "8a,   ,d88  "8a,   ,a8" 
88      `8b 88  `"Ybbd8"'  `"Ybbd8"' `"8bbdP"Y8 88          `"8bbdP"Y8   `"YbbdP"'  
                                                                        
                                                                                                              
                           
                                88  
                                88  
                                88  
,adPPYYba, 8b,dPPYba,   ,adPPYb,88  
""     `Y8 88P'   `"8a a8"    `Y88  
,adPPPPP88 88       88 8b       88  
88,    ,88 88       88 "8a,   ,d88  
`"8bbdP"Y8 88       88  `"8bbdP"Y8 
                           
                           
                                                                               
88888888888                 88                       88                        
88                          88                       ""                        
88                          88                                                 
88aaaaa  ,adPPYba,  ,adPPYb,88  ,adPPYba, 8b,dPPYba, 88  ,adPPYba, ,adPPYYba,  
88""""" a8P_____88 a8"    `Y88 a8P_____88 88P'   "Y8 88 a8"     "" ""     `Y8  
88      8PP""""""" 8b       88 8PP""""""" 88         88 8b         ,adPPPPP88  
88      "8b,   ,aa "8a,   ,d88 "8b,   ,aa 88         88 "8a,   ,aa 88,    ,88  
88       `"Ybbd8"'  `"8bbdP"Y8  `"Ybbd8"' 88         88  `"Ybbd8"' `"8bbdP"Y8  




More info: https://github.com/derogab/C3
*/



// LIBRERIA GENERALE DEL GIOCO
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Dichiarazioni delle costanti del gioco
#define LS 100
#define COUNTDOWN 2
#define MAZZO 26
#define CARTE 13

boolean isFullScreenEnable = FALSE;

// Dichiarazione delle strutture e dei tipi del gioco
typedef enum {G1, G2, PARI} Vincitore;

typedef struct{
	
	char nome[LS];
	boolean attivo;
	int punti;
	int durata;

} Potenziamento;

typedef struct{
	
	char nome[LS];
	int forza;
	Potenziamento potenziamento;

} Arma;

typedef struct{
	char nome[LS];
	char display[4][LS];
	int costo;
	Arma arma;
	int forza;
	int stanchezza;
	int riposo;
	
} Carta;

typedef struct{
	
	int giorno;
	int mese;
	int anno;
	
} Nascita;

typedef struct{

	char nome[LS];
	char cognome[LS];
	Nascita nascita;
	Carta mazzo[MAZZO]; // Inizializzo a mazzo perche' un giocatore piu' comprare anche le carte dell'avversario, ragiungendo l'intero mazzo.
	int nc; // Numero delle carte rimaste
	int dobloni;

} Giocatore;






// Dichiarazione delle funzioni definite nel gioco, commentate con la loro funzionalit�
void clearScreen(); // Funzione per pulire completamente lo schermo.
void fullScreen(); // Funzione per ingrandire al massimo lo schermo.
Giocatore getGiocatore(); // Funzione per prendere i dati di un giocatore e restituire una variabile di tipo Giocatore
void titolo(); // Funzione per stampare il titolo del gioco
char regolamento(); // Funzione per stampare il regolamento del gioco
void gioca(Giocatore g1, Giocatore g2); // Funzione principale del gioco.
void preparazione(); // Funzione che prepara la schermata di gioco.
void mischia(Giocatore *x, Giocatore *y); // Funzione che assegna carte cauali ai giocatori
void start(Giocatore *p1, Giocatore *p2); // Funzione che fa partire il vero gioco con i turni
void turno(Giocatore *att, Giocatore *dif); // Funzione di un turno della partita
char continua(); // Funzione per chiedere di iniziare una nuova partita
void mano(Giocatore g); // Funzione che stampa a video le carte che il giocatore ha in mano
void combattimento(Giocatore *att, Giocatore *dif); // Funzione che fa partire il combattimento in un turno dopo la relativa scelta.
Vincitore combatti(Carta *c1, Carta *c2); //Funzione del combattimento tra i due giocatori. c1 = carta giocatore 1,  c2 = carta giocatore 2.  Ritorna vincitore (G1, G2, PARI) 
void aggiornaValori(Carta *c, boolean vinto, int diff); //Funzione che aggiorna i valori della carta. Se ha vinto -> vinto=true, se ha perso -> vinto=false
int punteggioCarta(Carta *c); // Funzione che ritorna il punteggio della carta, calcolandolo in base alle specifiche del gioco
int getForzaArma(Arma arma); // Funzione che ritorna la forza dell'arma (calcolata gi� con il potenziamento)
boolean isGameEnd(Giocatore g1, Giocatore g2); // Funzione che ritorna vero se un giocatore non ha pi� carte
Giocatore getWinnerGame(Giocatore g1, Giocatore g2); // Funzione che ritorna il giocatore che ha ancora carte
void updateDobloniWinner(Giocatore *g); // Funzione che aggiorna dobloni giocatore
boolean compraCartaAvversario(Giocatore *cliente, Giocatore *venditore); // Cliente compra carta da avversario - ritona true se vendita ok, altrimenti false
void distruggiCarta(Carta *carta); //distrugge la carta (svuota tutto)
void aumentaRiposo(int indiceCartaNonRiposo, Giocatore *giocatore); //aumenta riposo a tutti tranne a carta con indice passato
void ordinaMazzo(Giocatore *giocatore); //mette tutte le carte nelle prima nc posizioni, eliminando i buchi 
void invertiCarte(Giocatore *giocatore, int indiceVuoto, int indiceCarta); //inverte le posizioni delle carte passate
/*

printf("\77\97\100\101\32\119\105\116\106\32\60\51\32\98\121\32\71\97\98\114\105\101\108\101\44\32\82\105\99\99\97\114\100\111\32\97\110\100\32\70\101\100\101\114\105\99\97");

*/
