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


// Função utilitária para limpar o buffer de entrada do teclado (stdin), evitando problemas com leituras consecutivas de scanf e getchar.
void limparBufferEntrada() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}


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

        printf("Qual é a cor do território? ");
        fgets(territorios[t].cor, MAX_TAM_STRING, stdin);

        printf("Qual é a quantidade de tropas do território? ");
        scanf("%d", &territorios[t].tropas);
        limparBufferEntrada();

        printf("\n\n");
    }

    for (int t = 0; t < MAX_TERRITORIOS; t++) 
    {
        int p = t + 1;
        printf("TERRITÓRIO %d:\n", p);
        printf("\t- Nome: %s", territorios[t].nome);
        printf("\t- Cor: %s", territorios[t].cor);
        printf("\t- Quantidade de tropas: %d", territorios[t].tropas);

        printf("\n\n");
    }
    
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
