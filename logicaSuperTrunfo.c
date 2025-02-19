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
// strcmp compara duas strings
void compararCartas(Carta carta1, Carta carta2, char *atributo) {
    printf("\nComparação de cartas:\n");
    printf("Carta 1 - Estado: %s, Código: %s, Nome: %s, População: %d, Área: %.2f, PIB: %.2f, Pontos Turísticos: %d\n",
           carta1.estado, carta1.codigo, carta1.nome, carta1.populacao, carta1.area, carta1.PIB, carta1.pontos_turisticos);
    printf("Carta 2 - Estado: %s, Código: %s, Nome: %s, População: %d, Área: %.2f, PIB: %.2f, Pontos Turísticos: %d\n",
           carta2.estado, carta2.codigo, carta2.nome, carta2.populacao, carta2.area, carta2.PIB, carta2.pontos_turisticos);

    if (strcmp(atributo, "populacao") == 0) {
        printf("\nAtributo usado na comparação: População\n");
        if (carta1.populacao > carta2.populacao) {
            printf("Resultado: Carta 1 é a vencedora!\n");
        } else if (carta1.populacao < carta2.populacao) {
            printf("Resultado: Carta 2 é a vencedora!\n");
        } else {
            printf("Empate!\n");
        }
    } else if (strcmp(atributo, "area") == 0) {
        printf("\nAtributo usado na comparação: Área\n");
        if (carta1.area > carta2.area) {
            printf("Resultado: Carta 1 é a vencedora!\n");
        } else if (carta1.area < carta2.area) {
            printf("Resultado: Carta 2 é a vencedora!\n");
        } else {
            printf("Empate!\n");
        }
    } else if (strcmp(atributo, "PIB") == 0) {
        printf("\nAtributo usado na comparação: PIB\n");
        if (carta1.PIB > carta2.PIB) {
            printf("Resultado: Carta 1 é a vencedora!\n");
        } else if (carta1.PIB < carta2.PIB) {
            printf("Resultado: Carta 2 é a vencedora!\n");
        } else {
            printf("Empate!\n");
        }
    } else if (strcmp(atributo, "densidade_populacional") == 0) {
        printf("\nAtributo usado na comparação: Densidade Populacional\n");
        float densidade1 = carta1.populacao / carta1.area;
        float densidade2 = carta2.populacao / carta2.area;
        if (densidade1 < densidade2) {
            printf("Resultado: Carta 1 é a vencedora!\n");
        } else if (densidade1 > densidade2) {
            printf("Resultado: Carta 2 é a vencedora!\n");
        } else {
            printf("Empate!\n");
        }
    } else if (strcmp(atributo, "PIB_per_capita") == 0) {
        printf("\nAtributo usado na comparação: PIB per Capita\n");
        float PIB_per_capita1 = carta1.PIB / carta1.populacao;
        float PIB_per_capita2 = carta2.PIB / carta2.populacao;
        if (PIB_per_capita1 > PIB_per_capita2) {
            printf("Resultado: Carta 1 é a vencedora!\n");
        } else if (PIB_per_capita1 < PIB_per_capita2) {
            printf("Resultado: Carta 2 é a vencedora!\n");
        } else {
            printf("Empate!\n");
        }
    } else {
        printf("Atributo inválido!\n");
    }
}

// Função para exibir o menu e obter a escolha do usuário
int menu() {
    int opcao;
    printf("\nMenu de Comparação de Cartas:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Densidade Populacional\n");
    printf("5. PIB per Capita\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    getchar(); // Consome o caractere de nova linha deixado pelo scanf
    return opcao;
}

int main() {
    Carta carta1, carta2;
    int opcao;
    char atributo[50];

    printf("Cadastro da Carta 1:\n");
    cadastrarCarta(&carta1);

    printf("\nCadastro da Carta 2:\n");
    cadastrarCarta(&carta2);

    opcao = menu();

    // Define o atributo de comparação com base na opção do menu
    switch (opcao) {
        case 1:
        // strcpy copia uma string para outra
            strcpy(atributo, "populacao");
            break;
        case 2:
            strcpy(atributo, "area");
            break;
        case 3:
            strcpy(atributo, "PIB");
            break;
        case 4:
            strcpy(atributo, "densidade_populacional");
            break;
        case 5:
            strcpy(atributo, "PIB_per_capita");
            break;
        default:
            printf("Opção inválida!\n");
            return 1;
    }

    compararCartas(carta1, carta2, atributo);

    return 0;
}
