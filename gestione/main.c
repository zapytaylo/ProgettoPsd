#include <stdio.h>
#include "attivita.h"
// Include le definizioni e dichiarazioni delle funzioni per la gestione attività

/*
 * Funzione principale del programma.
 * Permette all'utente di gestire una lista di attività tramite un menu.
 * Supporta input/output da file passati come argomenti o da stdin/stdout.
 *
 * Parametri:
 *   - argc: numero di argomenti da linea di comando
 *   - argv: array di argomenti 
 */
 int main(int argc, char *argv[]) {
    Nodo* lista = NULL; // Inizializza la lista di attività vuota
    int scelta;
    FILE *input = stdin;
    FILE *output = stdout;

    // Se viene passato un argomento, usalo come file di input
    if (argc > 1) {
        input = fopen(argv[1], "r");
        if (!input) {
            fprintf(stderr, "Errore nell'apertura del file di input\n");
            return 1;
        }
    }

     // Se viene specificato un file di output, prova ad aprirlo.
    // Permette di salvare l'output su file anziché su terminale.
    if (argc > 2) {
        output = fopen(argv[2], "w");
        if (!output) {
            fprintf(stderr, "Errore nell'apertura del file di output\n");
            fclose(input);  // Chiude il file di input se già aperto
            return 1;
        }
    }

    // Loop principale del menu: continua finché l'utente non sceglie di uscire
    do {
        mostraMenu(output); // Stampa il menu all'utente
        fscanf(input, "%d", &scelta); // Legge la scelta dell'utente
        fgetc(input); // consuma il newline

        // Esegue l'azione corrispondente alla scelta effettuata
        switch (scelta) {
            case 1:
                lista = aggiungiAttivitaFile(lista, input, output);
                break;
            case 2:
                mostraAttivitaFile(lista, input, output);
                break;
            case 3:
                aggiornaProgressoFile(lista, input, output);
                break;
            case 4:
                generaReportFile(lista, input, output);
                break;
            case 0:
                fprintf(output, "Uscita dal programma.\n");
                break;
            default:
                fprintf(output, "Scelta non valida.\n");
        }
    } while (scelta != 0);  // Ripete finché non si sceglie l'opzione 0 (uscita)

    liberaLista(lista); // Libera la memoria occupata dalla lista di attività

    
    // Chiude i file solo se sono stati effettivamente aperti
    if (input != stdin) fclose(input);
    if (output != stdout) fclose(output);
    
    return 0;
}