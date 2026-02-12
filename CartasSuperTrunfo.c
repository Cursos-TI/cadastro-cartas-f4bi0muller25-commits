// Para esse exercicio, utilizei vários conceitos que eu tinha apredindo anteriormente e tambem pesquisei novos, com Structs.

#include <stdio.h>
#include <string.h>

// Definição da struct
struct Cidade
{
    char estado;
    char codigo[6];
    char nome[20];
    unsigned int populacao;
    float area;
    float pib;
    int turismo;
    int PontosTuristicos;
    float densidade, PibPerCapita;
    float SuperPoder;
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
    
    c-> SuperPoder = 0.0;

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
    sscanf(buffer, "%u", &c->populacao);

    printf("Area (em km2): ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%f", &c->area);

    printf("PIB (em milhoes R$): ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%f", &c->pib);

    printf("Indice de turismo (0-100): ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &c->turismo);

    printf("Numero de pontos turisticos: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &c->PontosTuristicos);

    c->densidade = (float) c-> populacao / c->area;
    c->PibPerCapita = (float) (c->pib ) / (c->populacao);
    c->SuperPoder = (float) (c->populacao) + (c-> pib) + (c-> area) + (c->PibPerCapita) + (c->turismo) + (c->PontosTuristicos) +  (1 / c->densidade);
    printf("\n");
}

// Procedimento para imprimir os dados da cidade
void imprimirCidade(struct Cidade c, int numero)
{
    printf("Carta %d:\n", numero);
    printf("Estado: %c\n", c.estado);
    printf("Codigo da cidade: %s\n", c.codigo);
    printf("Nome da cidade: %s\n", c.nome);
    printf("População (em milhares): %u\n", c.populacao);
    printf("Área (em km²): %.2f\n", c.area);
    printf("PIB (em milhões R$): %.2f\n", c.pib);
    printf("Índice de turismo (0-100): %d\n", c.turismo);
    printf("Numero de pontos turisticos: %d\n", c.PontosTuristicos);
    printf("\nDensidade populacional: %.2f habitantes/km²\n", c.densidade);
    printf("PIB per capita: R$ %.2f\n", c.PibPerCapita);
    printf("Super Poder: %.2f\n", c.SuperPoder);
    printf("----------------------------------------\n\n");
}

// Função Principal

int main(void)
{
    
    //Variaveis para comparação

    unsigned int Comp_populacao = 0;
    float Comp_area = 0.0;
    float Comp_pib = 0.0;
    int Comp_turismo = 0.0;
    int Comp_PontosTuristicos = 0;
    float Comp_densidade = 0.0, Comp_PibPerCapita = 0.0;
    float Comp_SuperPoder = 0.0;

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

   printf("----------------------------------------\n");
    printf("         COMPARAÇAO DE CARTAS          \n");
    printf("----------------------------------------\n\n"); 

    // Comparação das cartas
    printf("Se resultado for 1, a carta 1 é maior. Se for 0, a carta 2 é maior.\n\n");

    Comp_populacao = cidades[0].populacao > cidades[1].populacao;
    printf("Populaçao: %d\n", Comp_populacao);
    Comp_area = cidades[0].area > cidades[1].area;
    printf("Area: %d\n", Comp_area);
    Comp_pib = cidades[0].pib > cidades[1].pib;
    printf("PIB: %d\n", Comp_pib);
    Comp_turismo = cidades[0].turismo > cidades[1].turismo;
    printf("Turismo: %d\n", Comp_turismo);
    Comp_PontosTuristicos = cidades[0].PontosTuristicos > cidades[1].PontosTuristicos;
    printf("Pontos Turisticos: %d\n", Comp_PontosTuristicos);
    Comp_densidade = cidades[0].densidade > cidades[1].densidade;
    printf("Densidade: %d\n", Comp_densidade);
    Comp_PibPerCapita = cidades[0].PibPerCapita > cidades[1].PibPerCapita;
    printf("PIB per Capita: %d\n", Comp_PibPerCapita);
    Comp_SuperPoder = cidades[0].SuperPoder > cidades[1].SuperPoder;
    printf("Super Poder: %d\n", Comp_SuperPoder);

    return 0;
}
