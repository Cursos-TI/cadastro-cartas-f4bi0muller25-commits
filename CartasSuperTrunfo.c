// Para esse exercicio., utilizei vários conceitos que eu tinha apredindo anteriormente e tambem pesquisei novos, com Structs.

#include <stdio.h>
#include <string.h>

// Definição da struct
struct Cidade
{
    char estado;
    char codigo[6];
    char nome[20];
    int populacao;
    float area;
    float pib;
    int turismo;
    float densidade, PibPerCapita;
};

// Procedimento para o letreiro
void letreiro(void)
{
    printf("----------------------------------------\n");
    printf("         CADASTRO DE CIDADES          \n");
    printf("----------------------------------------\n\n");
}

// Procedimento para ler os dados da cidade
void lerCidade(struct Cidade *c)
{
    char buffer[100];
    
    printf("Estado (sigla A-H): ");
    fgets(buffer, sizeof(buffer), stdin);
    c->estado = buffer[0];

    printf("Codigo da cidade (4 digitos): ");
    fgets(c->codigo, sizeof(c->codigo), stdin);
    c->codigo[strcspn(c->codigo, "\n")] = '\0';

    printf("Nome da cidade: ");
    fgets(c->nome, sizeof(c->nome), stdin);
    c->nome[strcspn(c->nome, "\n")] = '\0';

    printf("Populacao (em milhares): ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &c->populacao);

    printf("Area (em km2): ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%f", &c->area);

    printf("PIB (em milhoes R$): ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%f", &c->pib);

    printf("Indice de turismo (0-100): ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &c->turismo);

    c->densidade = (float) c-> populacao / c->area;
    c->PibPerCapita = (float) (c->pib ) / (c->populacao);

    printf("\n");
}

// Procedimento para imprimir os dados da cidade
void imprimirCidade(struct Cidade c, int numero)
{
    printf("Carta %d:\n", numero);
    printf("Estado: %c\n", c.estado);
    printf("Codigo da cidade: %s\n", c.codigo);
    printf("Nome da cidade: %s\n", c.nome);
    printf("População (em milhares): %d\n", c.populacao);
    printf("Área (em km²): %.2f\n", c.area);
    printf("PIB (em milhões R$): %.2f\n", c.pib);
    printf("Índice de turismo (0-100): %d\n", c.turismo);
    printf("\nDensidade populacional: %.2f habitantes/km²\n", c.densidade);
    printf("PIB per capita: R$ %.2f\n", c.PibPerCapita);
    printf("----------------------------------------\n\n");
}

// Função Principal

int main(void)
{
    struct Cidade cidades[2];

    // Primeira carta
    printf("\033[2J\033[H");
    letreiro();
    printf("Digite os dados da primeira carta:\n\n");
    lerCidade(&cidades[0]);

    // Segunda carta
    printf("\033[2J\033[H");
    letreiro();
    printf("Digite os dados da segunda carta:\n\n");
    lerCidade(&cidades[1]);

    // Exibição dos dados
    printf("\033[2J\033[H");
    printf("----------------------------------------\n");
    printf("         DADOS DAS CIDADES          \n");
    printf("----------------------------------------\n\n");

    imprimirCidade(cidades[0], 1);
    imprimirCidade(cidades[1], 2);

    return 0;
}
