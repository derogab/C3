// LIBRERIA GENERALE DEL GIOCO
// A cura di Gabriele, Federica, Riccardo
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
	int puntip;
	int duratap;

} Potenziamento;

typedef struct{
	
	char nome[LS];
	int forzarma;
	Potenziamento potenziamento;

} Arma;

typedef struct{
	
	char nome[LS];
	char display[4][LS];
	int costo;
	Arma arma;
	int forza;
//	Potenziamento potenziamento;   -- � gi� presente in Arma
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
	Carta mazzo[MAZZO]; // Inizializzo a mazzo perch� un giocatore pi� comprare anche le carte dell'avversario, ragiungendo l'intero mazzo.
	int nc; // Numero delle carte rimaste

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
Vincitore combatti(Carta *c1, Carta *c2); //Funzione del combattimento tra i due giocatori. c1 = carta giocatore 1,  c2 = carta giocatore 2.  Ritorna vincitore (G1, G2, PARI) 
void aggiornaValori(Carta *c, boolean vinto, int diff); //Funzione che aggiorna i valori della carta. Se ha vinto -> vinto=true, se ha perso -> vinto=false
int punteggioCarta(Carta *c); // Funzione che ritorna il punteggio della carta, calcolandolo in base alle specifiche del gioco
int getForzaArma(Arma arma); // Funzione che ritorna la forza dell'arma (calcolata gi� con il potenziamento)
boolean isGameEnd(Giocatore g1, Giocatore g2); //ritorna vero se un giocatore non ha pi� carte
Giocatore getWinnerGame(Giocatore g1, Giocatore g2); //ritorna il giocatore che ha ancora carte
int lancioDado(); //ritorna numero random