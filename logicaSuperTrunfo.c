#include <stdio.h>
#include <string.h>

// Define um comprimento máximo para strings
#define MAX_LENGTH 50

// Define uma estrutura para armazenar informações sobre uma cidade
typedef struct {
    char estado[MAX_LENGTH]; // Estado
    char codigo[MAX_LENGTH]; // Código da carta
    char cidade[MAX_LENGTH]; // Nome da cidade
    int populacao;           // População da cidade
    float area;              // Área da cidade em km²
    float pib;               // PIB da cidade em milhões
    int pontosTuristicos;    // Número de pontos turísticos
} Carta;

// Função para cadastrar uma nova carta com informações sobre uma cidade
void cadastrarCarta(Carta *carta) {
    // Solicita e armazena o estado
    printf("Digite o estado: ");
    fgets(carta->estado, MAX_LENGTH, stdin);
    carta->estado[strcspn(carta->estado, "\n")] = 0;

    // Solicita e armazena o código da carta
    printf("Digite o código da carta: ");
    fgets(carta->codigo, MAX_LENGTH, stdin);
    carta->codigo[strcspn(carta->codigo, "\n")] = 0;

    // Solicita e armazena o nome da cidade
    printf("Digite o nome da cidade: ");
    fgets(carta->cidade, MAX_LENGTH, stdin);
    carta->cidade[strcspn(carta->cidade, "\n")] = 0;

    // Solicita e armazena a população da cidade
    printf("Digite a população: ");
    scanf("%d", &carta->populacao);

    // Solicita e armazena a área da cidade em km²
    printf("Digite a área (km²): ");
    scanf("%f", &carta->area);

    // Solicita e armazena o PIB da cidade em milhões
    printf("Digite o PIB (em milhões): ");
    scanf("%f", &carta->pib);

    // Solicita e armazena o número de pontos turísticos
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);
    getchar(); // Limpa o buffer do teclado
}

// Função que exibe o menu e retorna a escolha do usuário
int menu(char *atributo) {
    int escolha;
    printf("\nEscolha um atributo:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Densidade Populacional\n");
    printf("5. PIB per Capita\n");
    printf("Escolha uma opção: ");
    scanf("%d", &escolha);
    getchar(); // Limpa o buffer do teclado

    // Atribui o nome do atributo escolhido ao parâmetro atributo
    switch (escolha) {
        // strcpy copia uma string para outra
        case 1: strcpy(atributo, "População"); break;
        case 2: strcpy(atributo, "Área"); break;
        case 3: strcpy(atributo, "PIB"); break;
        case 4: strcpy(atributo, "Densidade Populacional"); break;
        case 5: strcpy(atributo, "PIB per Capita"); break;
        default: strcpy(atributo, "Inválido");
    }
    return escolha;
}

// Função para obter o valor de um atributo específico de uma carta
float obterValor(Carta c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.populacao / c.area;
        case 5: return c.pib / c.populacao;
        default: return 0;
    }
}

// Função para comparar duas cartas com base em dois atributos escolhidos pelo usuário
void compararCartas(Carta c1, Carta c2) {
    char atributo1[MAX_LENGTH], atributo2[MAX_LENGTH];
    int escolha1, escolha2;

    // Usuário escolhe o primeiro atributo para comparação
    do {
        escolha1 = menu(atributo1);
    } while (escolha1 < 1 || escolha1 > 5);

    // Usuário escolhe o segundo atributo para comparação (não pode ser o mesmo do primeiro)
    do {
        escolha2 = menu(atributo2);
    } while ((escolha2 < 1 || escolha2 > 5) || escolha1 == escolha2);

    // Obtém os valores dos atributos escolhidos para ambas as cartas
    float valor1_c1 = obterValor(c1, escolha1);
    float valor1_c2 = obterValor(c2, escolha1);
    float valor2_c1 = obterValor(c1, escolha2);
    float valor2_c2 = obterValor(c2, escolha2);

    // Exibe os valores comparados
    printf("\nComparação de cartas:\n");
    printf("%s: %.2f vs %.2f\n", atributo1, valor1_c1, valor1_c2);
    printf("%s: %.2f vs %.2f\n", atributo2, valor2_c1, valor2_c2);

    int pontos_c1 = 0, pontos_c2 = 0;

    // Atribui pontos às cartas com base nos atributos escolhidos
    pontos_c1 += (escolha1 == 4) ? (valor1_c1 < valor1_c2) : (valor1_c1 > valor1_c2);
    pontos_c2 += (escolha1 == 4) ? (valor1_c1 > valor1_c2) : (valor1_c1 < valor1_c2);
    pontos_c1 += (escolha2 == 4) ? (valor2_c1 < valor2_c2) : (valor2_c1 > valor2_c2);
    pontos_c2 += (escolha2 == 4) ? (valor2_c1 > valor2_c2) : (valor2_c1 < valor2_c2);

    // Calcula a soma dos valores dos atributos escolhidos
    float soma_c1 = valor1_c1 + valor2_c1;
    float soma_c2 = valor1_c2 + valor2_c2;

    // Exibe a soma dos atributos
    printf("\nSoma dos atributos:\n%s: %.2f\n%s: %.2f\n", c1.cidade, soma_c1, c2.cidade, soma_c2);

    // Determina o vencedor com base na soma dos atributos
    if (soma_c1 > soma_c2) {
        printf("\nVencedor: %s!\n", c1.cidade);
    } else if (soma_c2 > soma_c1) {
        printf("\nVencedor: %s!\n", c2.cidade);
    } else {
        printf("\nEmpate!\n");
    }
}

// Função principal do programa
int main() {
    Carta carta1, carta2;

    // Cadastro da primeira carta
    printf("Cadastro da Carta 1:\n");
    cadastrarCarta(&carta1);

    // Cadastro da segunda carta
    printf("Cadastro da Carta 2:\n");
    cadastrarCarta(&carta2);

    // Comparação entre as duas cartas
    compararCartas(carta1, carta2);

    return 0;
}

