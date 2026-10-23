#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10       
#define NOTAS 3       
#define TAM_NOME 50   

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Lê nomes (não vazios) e notas (entre 0 e 10) de cada estudante
void lerEstudantes(char nomes[][TAM_NOME], double notas[][NOTAS], int n) {
    for (int i = 0; i < n; i++) {
        printf("\n--- Estudante %d ---\n", i + 1);

        do {
            printf("Nome: ");
            if (fgets(nomes[i], TAM_NOME, stdin) == NULL) {
                exit(1);
            }
            nomes[i][strcspn(nomes[i], "\n")] = '\0'; 
        } while (strlen(nomes[i]) == 0);

        for (int j = 0; j < NOTAS; j++) {
            printf("Nota %d (0 a 10): ", j + 1);
            while (scanf("%lf", &notas[i][j]) != 1 || notas[i][j] < 0 || notas[i][j] > 10) {
                limparBuffer();
                printf("Nota invalida. Digite de novo: ");
            }
            limparBuffer();
        }
    }
}

// Recebe um ponteiro e escreve as médias na memória do chamador (a heap)
void calcularMedias(double notas[][NOTAS], int n, double *medias) {
    for (int i = 0; i < n; i++) {
        double soma = 0;
        for (int j = 0; j < NOTAS; j++) {
            soma += notas[i][j];
        }
        medias[i] = soma / NOTAS;
    }
}

void exibirTabela(char nomes[][TAM_NOME], double notas[][NOTAS], double *medias, int n) {
    printf("\n%-15s %6s %6s %6s %7s  %s\n", "Nome", "N1", "N2", "N3", "Media", "Situacao");
    for (int i = 0; i < n; i++) {
        printf("%-15s %6.1f %6.1f %6.1f %7.2f  %s\n",
               nomes[i], notas[i][0], notas[i][1], notas[i][2], medias[i],
               medias[i] >= 6 ? "atingiu a meta" : "abaixo da meta");
    }
}

void exibirResumo(char nomes[][TAM_NOME], double *medias, int n) {
    double soma = 0, maior = medias[0];
    for (int i = 0; i < n; i++) {
        soma += medias[i];
        if (medias[i] > maior) {
            maior = medias[i];
        }
    }
    printf("\nMedia geral da turma: %.2f\n", soma / n);

    printf("Maior media (%.2f): ", maior);
    for (int i = 0; i < n; i++) {
        if (maior - medias[i] < 0.001) {  
            printf("%s  ", nomes[i]);
        }
    }
    printf("\n");
}

int main() {
    char nomes[MAX][TAM_NOME];   
    double notas[MAX][NOTAS];    
    int n;

    printf("Quantidade de estudantes (1 a 10): ");
    while (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        limparBuffer();
        printf("Valor invalido. Digite de 1 a 10: ");
    }
    limparBuffer();

    // Vetor de médias na heap, com a quantidade informada; calloc zera os elementos
    double *medias = calloc(n, sizeof(double));
    if (medias == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    lerEstudantes(nomes, notas, n);
    calcularMedias(notas, n, medias);
    exibirTabela(nomes, notas, medias, n);
    exibirResumo(nomes, medias, n);

    free(medias);   // libera a heap
    return 0;
}