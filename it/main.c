#include "funzioni.c"

void main(){
	srand ( time(NULL) );
	
	Giocatore g1;
	Giocatore g2;
	titolo();	
	if(regolamento() == 'Y'){
		
		do{
			fflush(stdin);
			// Gioca
			g1 = getGiocatore();
			g2 = getGiocatore();
			g1.dobloni = 30;
			g2.dobloni = 30;
			// Fai partire il gioco!
			gioca(g1,g2);
							
		}while(continua() == 'Y');
	
	}
	else{
		printf("\nPurtroppo non accettando il regolamento non puoi giocare.\n");
	}

	
}
