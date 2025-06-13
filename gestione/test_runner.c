#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RIGA 1024

bool confronta_file(const char* percorso1, const char* percorso2) {
    FILE* f1 = fopen(percorso1, "r");
    FILE* f2 = fopen(percorso2, "r");
    if (!f1 || !f2) return false;

    char riga1[MAX_RIGA];
    char riga2[MAX_RIGA];
    bool uguali = true;

    while (true) {
        char* r1 = fgets(riga1, MAX_RIGA, f1);
        char* r2 = fgets(riga2, MAX_RIGA, f2);

        if (r1 == NULL || r2 == NULL) {
            if (r1 != r2) uguali = false;
            break;
        }

        if (strcmp(riga1, riga2) != 0) {
            uguali = false;
            break;
        }
    }

    fclose(f1);
    fclose(f2);
    return uguali;
}

// Funzione per eseguire un test dato un file di input e un file atteso
void esegui_test(const char* file_input, const char* file_atteso) {
    //Compila il programma se non esiste
    if (system("gcc -o gestione_studio main.c attivita.c") != 0) {
        fprintf(stderr, "Compilazione fallita\n");
        exit(1);
    }

    // Esegui il test
    char comando[256];
    sprintf(comando, "gestione_studio < %s > output.txt", file_input);
    system(comando);

    // Valuta il risultato
    if (confronta_file("output.txt", file_atteso)) {
        printf("TEST SUPERATO\n");
    } else {
        printf("TEST FALLITO\n");
        printf("=== Differenze ===\n");
        system("diff -u output.txt oracolo.txt");
    }
}

int main() {
    printf("=== Avvio dei test ===\n");
    esegui_test("input.txt", "oracolo.txt");
    return 0;
}