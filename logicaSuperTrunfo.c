#include <stdio.h>
#include <string.h>

// Estrutura para armazenar as informações da carta
typedef struct {
    char estado[50];
    char codigo[5]; // Aumentado o tamanho do buffer para 5
    char nome[50];
    int populacao;
    float area;
    float PIB;
    int pontos_turisticos;
} Carta;

// Função para cadastrar uma carta
void cadastrarCarta(Carta *carta) {
    printf("Digite o estado: ");
    fgets(carta->estado, 50, stdin);
    carta->estado[strcspn(carta->estado, "\n")] = '\0'; // Remove o caractere de nova linha

    printf("Digite o código da carta: ");
    fgets(carta->codigo, 5, stdin); // Tamanho do buffer aumentado para 5
    carta->codigo[strcspn(carta->codigo, "\n")] = '\0'; // Remove o caractere de nova linha

    printf("Digite o nome da cidade: ");
    fgets(carta->nome, 50, stdin);
    carta->nome[strcspn(carta->nome, "\n")] = '\0'; // Remove o caractere de nova linha

    printf("Digite a população: ");
    scanf("%d", &carta->populacao);
    getchar(); // Consome o caractere de nova linha deixado pelo scanf

    printf("Digite a área (km²): ");
    scanf("%f", &carta->area);
    getchar(); // Consome o caractere de nova linha deixado pelo scanf

    printf("Digite o PIB (em milhões): ");
    scanf("%f", &carta->PIB);
    getchar(); // Consome o caractere de nova linha deixado pelo scanf

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);
    getchar(); // Consome o caractere de nova linha deixado pelo scanf
}

// Função para comparar cartas com base em um atributo específico
void compararCartas(Carta carta1, Carta carta2, char *atributo) {
    printf("\nComparação de cartas:\n");
    printf("Carta 1 - Estado: %s, Código: %s, População: %d\n", carta1.estado, carta1.codigo, carta1.populacao);
    printf("Carta 2 - Estado: %s, Código: %s, População: %d\n", carta2.estado, carta2.codigo, carta2.populacao);

    if (strcmp(atributo, "populacao") == 0) {
        if (carta1.populacao > carta2.populacao) {
            printf("Resultado: Carta 1 é a vencedora!\n");
        } else {
            printf("Resultado: Carta 2 é a vencedora!\n");
        }
    } else if (strcmp(atributo, "area") == 0) {
        if (carta1.area > carta2.area) {
            printf("Resultado: Carta 1 é a vencedora!\n");
        } else {
            printf("Resultado: Carta 2 é a vencedora!\n");
        }
    } else if (strcmp(atributo, "PIB") == 0) {
        if (carta1.PIB > carta2.PIB) {
            printf("Resultado: Carta 1 é a vencedora!\n");
        } else {
            printf("Resultado: Carta 2 é a vencedora!\n");
        }
    } else if (strcmp(atributo, "densidade_populacional") == 0) {
        float densidade1 = carta1.populacao / carta1.area;
        float densidade2 = carta2.populacao / carta2.area;
        if (densidade1 < densidade2) {
            printf("Resultado: Carta 1 é a vencedora!\n");
        } else {
            printf("Resultado: Carta 2 é a vencedora!\n");
        }
    } else if (strcmp(atributo, "PIB_per_capita") == 0) {
        float PIB_per_capita1 = carta1.PIB / carta1.populacao;
        float PIB_per_capita2 = carta2.PIB / carta2.populacao;
        if (PIB_per_capita1 > PIB_per_capita2) {
            printf("Resultado: Carta 1 é a vencedora!\n");
        } else {
            printf("Resultado: Carta 2 é a vencedora!\n");
        }
    } else {
        printf("Atributo inválido!\n");
    }
}

int main() {
    Carta carta1, carta2;
    char atributo[50];

    printf("Cadastro da Carta 1:\n");
    cadastrarCarta(&carta1);

    printf("\nCadastro da Carta 2:\n");
    cadastrarCarta(&carta2);

    printf("\nDigite o atributo para comparação (populacao, area, PIB, densidade_populacional, PIB_per_capita): ");
    scanf("%s", atributo);

    compararCartas(carta1, carta2, atributo);

    return 0;
}
