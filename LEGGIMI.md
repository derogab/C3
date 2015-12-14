# C3
<p align="right"><a href="LEGGIMI.md">Italian Version</a> - <a href="README.md">English Version</a></p>
Gioco di carte. 

<hr>

<h3> Regole di base del gioco </h3>

<p>L’obiettivo del gioco “C3” è conquistare tutte le carte dell’avversario.</p>
<p>All’inizio della partita il mazzo è composto da 26 carte, e viene diviso a metà fra i 2 giocatori;
le carte sono assegnate in modo casuale.</p>
</p>Ogni giocatore riceve inoltre una somma iniziale pari a 50 dobloni.</p>
<p>Ogni carta, che rappresenta un personaggio di fantasia, è così strutturata:
<ul>
<li>nome del personaggio</li>
<li>forza del personaggio</li>
<li>arma e punti di forza dell’arma (da aggiungere, durante un “attacco”, alla forza del
personaggio)</li>
<li>costo in dobloni</li>
<li>potenziamento
<ul>
<li>attivo (vero o falso)</li>
<li>punti di potenziamento da aggiungere alla forza dell’arma (se attivo)</li>
<li>durata del potenziamento (numero di turni prima che svanisca)</li>
</ul>
</li>
<li>punti stanchezza (valore positivo) e quindi riduzione della forza totale (arma + personaggio) su usi consecutivi della medesima carta.</li>
</ul>
</p>
<p>La scelta dei tipi delle variabili è libera. Si consiglia di utilizzare delle costanti definite con la
direttiva #define per indicare le varie dimensioni dei vettori.</p>
<p>Inizia il giocatore più giovane e si alternano i turni dei due giocatori.</p>
<p>L’inserimento del nome dei giocatori fa partire la fase di inizializzazione (distribuzione delle carte e
visualizzazione del tavolo di gioco).</p>
<p>Ad ogni turno il programma mostra due opzioni:
<ol>
<li>acquisto carte</li>
<li>lancio dei dadi</li>
</ol>
</p>
<p>Il lancio dei dadi avviene in modalità casuale e contestuale per entrambi i giocatori e definisce la
posizione all’interno del vettore di ogni giocatore della carta che sarà utilizzata.</p>
<p>N.B.: Il numero di valori di ogni dado è variabile ad ogni turno, a seconda del numero di carte del
giocatore (cioè ogni carta ha la medesima probabilità di estrazione).</p>
</p>Si calcolano e si confrontano i punteggi delle due carte estratte, sommando i punti forza del
personaggio ai punti dell’arma in dotazione e sottraendo al risultato finale i punti stanchezza.</p>
<p>Il personaggio che ha punteggio maggiore vince la sfida e fa guadagnare un doblone al giocatore
estraendolo dal forziere comune.</p>
<p>In caso di pareggio non si estraggono dobloni dal forziere ed è necessario rilanciare i dadi.</p>
<p>Se i dobloni del giocatore sono sufficienti, prima di ogni turno è possibile acquistare una sola carta
dall'avversario. L'avversario non può rifiutare l'acquisto di una carta.</p>
<p>Dopo la sfida è necessario aggiornare i valori di ogni carta, perché i personaggi che hanno appena
disputato il duello devono incrementare il valore della stanchezza:
<ul>
<li>chi ha vinto acquisisce comunque un punto stanchezza</li>
<li>chi ha perso acquisisce un numero di punti stanchezza pari alla differenza fra le due forze
totali che sono state confrontate</li>
</ul>
</p>
<p>Le carte che stanno a riposo per almeno tre turni consecutivi, si ricaricano fino ad annullare il valore
della stanchezza (la quale non può diventare negativa)</p>
<p>Il gioco termina quando uno dei due giocatori è riuscito a sottrarre tutte le carte avversarie.</p>