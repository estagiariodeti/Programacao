#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para uma carta do Super Trunfo
typedef struct {
    char nome[50];           // Nome da profissão
    int salario;             // Salário (em milhares de reais por ano)
    int nivelEstresse;       // Nível de estresse (1 a 100)
    int anosFormacao;        // Anos de formação necessários
    int impactoSocial;       // Impacto social (1 a 100)
} Carta;

// Função para exibir os atributos de uma carta
void exibirCarta(Carta c) {
    printf("\nProfissão: %s\n", c.nome);
    printf("1. Salário: %d mil/ano\n", c.salario);
    printf("2. Nível de Estresse: %d\n", c.nivelEstresse);
    printf("3. Anos de Formação: %d\n", c.anosFormacao);
    printf("4. Impacto Social: %d\n", c.impactoSocial);
}

// Função para comparar duas cartas com base no atributo escolhido
int compararCartas(Carta c1, Carta c2, int atributo) {
    int valor1, valor2;
    switch (atributo) {
        case 1: // Salário
            valor1 = c1.salario;
            valor2 = c2.salario;
            break;
        case 2: // Nível de Estresse (menor é melhor)
            valor1 = c1.nivelEstresse;
            valor2 = c2.nivelEstresse;
            break;
        case 3: // Anos de Formação (menor é melhor)
            valor1 = c1.anosFormacao;
            valor2 = c2.anosFormacao;
            break;
        case 4: // Impacto Social
            valor1 = c1.impactoSocial;
            valor2 = c2.impactoSocial;
            break;
        default:
            printf("Atributo inválido!\n");
            return 0;
    }
    // Para atributos onde maior é melhor (salário e impacto social)
    if (atributo == 1 || atributo == 4) {
        if (valor1 > valor2) return 1; // Carta 1 vence
        else if (valor2 > valor1) return 2; // Carta 2 vence
        else return 0; // Empate
    }
    // Para atributos onde menor é melhor (estresse e formação)
    else {
        if (valor1 < valor2) return 1; // Carta 1 vence
        else if (valor2 < valor1) return 2; // Carta 2 vence
        else return 0; // Empate
    }
}

int main() {
    // Exemplo de baralho com 4 cartas
    Carta baralho[] = {
        {"Médico", 200, 90, 8, 95},
        {"Engenheiro", 120, 70, 5, 80},
        {"Professor", 60, 60, 4, 90},
        {"Programador", 100, 65, 3, 85}
    };
    int numCartas = 4;

    // Exemplo de jogo simples: comparar duas cartas
    printf("Jogador 1, escolha uma carta (1 a %d): ", numCartas);
    int cartaJ1;
    scanf("%d", &cartaJ1);
    cartaJ1--; // Ajustar para índice do array (0 a 3)

    printf("Jogador 2, escolha uma carta (1 a %d): ", numCartas);
    int cartaJ2;
    scanf("%d", &cartaJ2);
    cartaJ2--; // Ajustar para índice do array

    // Exibir as cartas escolhidas
    printf("\nCarta do Jogador 1:\n");
    exibirCarta(baralho[cartaJ1]);
    printf("\nCarta do Jogador 2:\n");
    exibirCarta(baralho[cartaJ2]);

    // Escolher atributo para comparação
    printf("\nJogador 1, escolha o atributo (1-Salário, 2-Estresse, 3-Formação, 4-Impacto Social): ");
    int atributo;
    scanf("%d", &atributo);

    // Comparar as cartas
    int resultado = compararCartas(baralho[cartaJ1], baralho[cartaJ2], atributo);
    if (resultado == 1) {
        printf("\nJogador 1 vence!\n");
    } else if (resultado == 2) {
        printf("\nJogador 2 vence!\n");
    } else {
        printf("\nEmpate!\n");
    }

    return 0;
}