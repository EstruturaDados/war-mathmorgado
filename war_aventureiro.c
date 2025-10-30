// Inclusão das bibliotecas
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Constantes Globais ---
#define MAX_TAM_STRING 50
#define MAX_TERRITORIOS 3


// --- Estrutura de Dados ---
typedef struct
{
    char nome[MAX_TAM_STRING];
    char cor[MAX_TAM_STRING];
    int tropas;
} war_game;


// declarando as funções
void limparBufferEntrada();
void exibir_mapa(war_game territorios[]);
void fase_ataque(war_game territorios[]);
void simular_ataque(war_game territorios[], int atacante, int defensor);

// --- Função Principal (main) ---
int main() 
{
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
    fase_ataque(territorios);
    
    free(territorios);
    printf("\nJogo encerrado e memoria liberada. Até a proxima!\n");
    
    return 0;
}


void exibir_mapa(war_game territorios[]) 
{
    printf("\n========================================\n");
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


void fase_ataque(war_game territorios[]) 
{
    int opcao_atacante;
    int opcao_defesa;

    while (1)
    {
        printf("\n--- FASE DE ATAQUE --\n");
        
        printf("Escolha o territorio atacante (1 a %d, ou 0 para sair): ", MAX_TERRITORIOS);
        scanf("%d", &opcao_atacante);
        limparBufferEntrada();

        if (opcao_atacante == 0)
        {
            break;
        }

        printf("Escolha o territorio defensor (1 a %d): ", MAX_TERRITORIOS);
        scanf("%d", &opcao_defesa);
        limparBufferEntrada();

        simular_ataque(territorios, opcao_atacante - 1, opcao_defesa - 1);        
    }

}


void simular_ataque(war_game territorios[], int atacante, int defensor) 
{
    int dado_atacante = rand() % 6 + 1;  // Gera número de 1 a 6
    int dado_defensor = rand() % 6 + 1;  // Gera número de 1 a 6

    printf("\n--- RESULTADO DA BATALHA ---\n");
    printf("O atacante %s rolou um dado e tirou: %d\n", territorios[atacante].nome, dado_atacante);
    printf("O defensor %s rolou um dado e tirou: %d\n", territorios[defensor].nome, dado_defensor);

    if (dado_atacante > dado_defensor)
    {
        printf("VITÓRIA DO ATAQUE! O defensor perdeu 1 tropa.\n");
        territorios[defensor].tropas--;

        if (territorios[defensor].tropas == 0)
        {
            printf("CONQUISTA! O territorio %s foi dominado pelo Exercito %s!\n", territorios[defensor].nome, territorios[atacante].cor);
            strcpy(territorios[defensor].cor, territorios[atacante].cor);
            territorios[defensor].tropas = 1;
        }
        
    }
    else if (dado_atacante < dado_defensor)
    {
        printf("VITÓRIA DA DEFESA! O atacante perdeu 1 tropa.\n");
        territorios[atacante].tropas--;

        if (territorios[atacante].tropas == 0)
        {
            printf("CONQUISTA! O territorio %s foi dominado pelo Exercito %s!\n", territorios[atacante].nome, territorios[defensor].cor);
            strcpy(territorios[atacante].cor, territorios[defensor].cor);
            territorios[atacante].tropas = 1;
        }
    }
    else 
    {
        printf("EMPATE! Ninguém perdeu tropas.\n");
    }

    printf("\nPressione 'Enter' para continuar...");
    limparBufferEntrada();
    getchar();  // Aguarda o Enter

    exibir_mapa(territorios);
}



// Função utilitária para limpar o buffer de entrada do teclado (stdin), evitando problemas com leituras consecutivas de scanf e getchar.
void limparBufferEntrada()
{
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}
