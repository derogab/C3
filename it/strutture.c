#include "config.h"
typedef enum {TRUE, FALSE} boolean;

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
	int costo;
	Arma arma;
	int forza;
	Potenziamento potenziamento;
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

} Giocatore;
