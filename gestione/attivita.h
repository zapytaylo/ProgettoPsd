#ifndef ATTIVITA_H
#define ATTIVITA_H

// Costanti di lunghezza per le stringhe
#define DESC_LEN 100
#define CORSO_LEN 50
#define DATA_LEN 11 // Data nel formato "AAAA-MM-GG" + terminatore

// Enumerazioni per la priorità e lo stato di un'attività
typedef enum { BASSA = 1, MEDIA, ALTA } Priorita;
typedef enum { IN_CORSO, COMPLETATA, RITARDO } Stato;

// Struttura che rappresenta un'attività
typedef struct {
    char descrizione[DESC_LEN];
    char corso[CORSO_LEN];
    char scadenza[DATA_LEN];
    int tempoStimato;
    int tempoTrascorso;
    Priorita priorita;
    Stato stato;
} Attivita;

/* Struttura nodo per realizzare una lista collegata di attività.
* Ogni nodo contiene un'attività e il puntatore al nodo successivo.*/
typedef struct Nodo {
    Attivita attivita;
    struct Nodo* next;
} Nodo;

// Funzioni del programma
Nodo* aggiungiAttivita(Nodo* testa);
void mostraAttivita(Nodo* testa);
void aggiornaProgresso(Nodo* testa);
void generaReport(Nodo* testa);
void liberaLista(Nodo* testa);
void mostraMenu();


// Nuove funzioni con supporto file
Nodo* aggiungiAttivitaFile(Nodo* testa, FILE* input, FILE* output);
void mostraAttivitaFile(Nodo* testa, FILE* input, FILE* output);
void aggiornaProgressoFile(Nodo* testa, FILE* input, FILE* output);
void generaReportFile(Nodo* testa, FILE* input, FILE* output);
void mostraMenuFile(FILE* output);

#endif