## Diario dei vini

Un' applicazione da terminale scritta in C per salvare, valutare e gestire una raccolta personale di vini.

## Funzionalità

- Inserimento di nuovi vini con caratteristiche come nome, tipo, vitigno, anno, voto(1-5) e note
- Visualizzazione della lista completa dei vini salvati
- Ordinamento per voto o anno
- Salvataggio automatico e caricamento da file `.csv`
- Calcolo della media dei voti

## Struttura di un vino

Ogni vino è rappresentato da:

- Nome
- Tipo(es. Rosso, Bianco, Rosé)
- Vitigno (es. Nebbiolo, Merlot)
- Anno di produzione
- Voto (da 1 a 5)
- Note opzionali

## Compilazione

Per compilare il progetto, esegui: 
```bash
make
```
Oppure, manualmente:
```bash
gcc -Wall -o diario-vini src/main.c src/vini.c src/file.c
```

## Utilizzo

Dopo la compilazione esegui il programma con:
```bash
./diario-vini
```
Segui il menu a schermo per inserire, cercare o visualizzare i vini.

## Formato del file CSV

I dati vengono salvati nel file vini.csv con il seguente formato:

Nome,Tipo,Vitigno,Anno,Voto,Note

## Funzionalità da aggiungere (TODO)

- Filtri avanzati per tipo o voto
- Esportazione in formato .txt o .vcf
- Interfaccia più interattiva e user-friendly

## Testato su

- Linux(fedora)
(prossimamente windows e mac)

## Autore

Realizzato da Sabau Valeriu Denis come progetto personale per migliorare la conoscenza del linguaggio C e l'uso di Git. 
Siete liberi di usarlo, modificarlo e distribuirlo liberamente.

