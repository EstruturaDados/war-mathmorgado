// Inclusão das bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Constantes Globais ---
#define MAX_TAM_STRING 50
#define MAX_TERRITORIOS 5


// --- Estrutura de Dados ---
typedef struct
{
    char nome[MAX_TAM_STRING];
    char cor[MAX_TAM_STRING];
    int tropas;
} war_game;


// declarando as funções
void exibir_mapa(war_game territorios[]);
void limparBufferEntrada();

// --- Função Principal (main) ---
int main() {
    war_game *territorios;
    territorios = calloc(MAX_TERRITORIOS, sizeof(war_game));
    
    printf("COMECE DEFININDO %d TERRITÓRIOS\n\n", MAX_TERRITORIOS);

    for (int t = 0; t < MAX_TERRITORIOS; t++)
    {
        printf("--- Cadastrando Territorio %d ---\n", t + 1);
        printf("Qual é o nome do território? ");
        fgets(territorios[t].nome, MAX_TAM_STRING, stdin);
        territorios[t].nome[strcspn(territorios[t].nome, "\n")] = '\0'; // Retira o \n no final da string

        printf("Qual é a cor do território? ");
        fgets(territorios[t].cor, MAX_TAM_STRING, stdin);
        territorios[t].cor[strcspn(territorios[t].cor, "\n")] = '\0';

        printf("Qual é a quantidade de tropas do território? ");
        scanf("%d", &territorios[t].tropas);
        limparBufferEntrada();

        printf("\n\n");
    }

    exibir_mapa(territorios);
    
    return 0;
}

void exibir_mapa(war_game territorios[]) 
{
    printf("========================================\n");
    printf("      MAPA DO MUNDO - ESTADO ATUAL      \n");
    printf("========================================\n");

    for(int i = 0; i < MAX_TERRITORIOS; i++) 
    {
        printf("%d. %s (Exercito %s, Tropas: %d)\n", 
            i + 1, 
            territorios[i].nome, 
            territorios[i].cor, 
            territorios[i].tropas
        );
    }

    printf("\n");
}

// Função utilitária para limpar o buffer de entrada do teclado (stdin), evitando problemas com leituras consecutivas de scanf e getchar.
void limparBufferEntrada() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}
