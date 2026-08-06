#include <stdio.h>

struct Carta {
    char estado[50];
    char codigo[50];
    char cidade[50];
    int populacao;
    double area;
    double pib;
    int pontosTuristicos;
    double densidade;
    double pibPerCapita;
};


void 
    cadastrarCarta(struct Carta *carta, int numero) {
    printf("\nCadastro da Carta %d\n", numero);

    printf("Digite a sigla do Estado: ");
    scanf(" %s", carta->estado);

    printf("Digite o Codigo da Carta (ex: SC01, RJ01, SP04): ");
    scanf(" %s", carta->codigo);

    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", carta->cidade);

    printf("Digite a Populacao: ");
    scanf(" %d", &carta->populacao);

    printf("Digite a Area (em km2): ");
    scanf(" %lf", &carta->area);

    printf("Digite o PIB (em bilhoes de reais): ");
    scanf(" %lf", &carta->pib);

    printf("Digite o Numero de Pontos Turisticos: ");
    scanf(" %d", &carta->pontosTuristicos);

    // cálculos derivados
    carta->densidade = (double)carta->populacao / carta->area;
    carta->pibPerCapita = (double)(carta->pib * 1000000000) / carta->populacao;
}

void exibirCarta(struct Carta carta, int numero) {
    printf("\nCarta %d:\n", numero);
    printf("Estado: %s\n", carta.estado);
    printf("Codigo: %s\n", carta.codigo);
    printf("Cidade: %s\n", carta.cidade);
    printf("Populacao: %d\n", carta.populacao);
    printf("Area: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos Turisticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidade);
    printf("PIB per Capita: %.2f reais\n", carta.pibPerCapita);
}

void compararCartas(struct Carta c1, struct Carta c2, int opcao) {
    printf("\n=================================\n");
    printf("       RESULTADO DA DISPUTA\n");
    printf("=================================\n");

    switch (opcao) {
        case 1:
            printf("População: %s (%d) vs %s (%d)\n", c1.cidade, c1.populacao, c2.cidade, c2.populacao);
            printf("Vencedor: %s\n", (c1.populacao > c2.populacao) ? c1.cidade : c2.cidade);
            break;
        case 2:
            printf("Área: %s (%.2f) vs %s (%.2f)\n", c1.cidade, c1.area, c2.cidade, c2.area);
            printf("Vencedor: %s\n", (c1.area > c2.area) ? c1.cidade : c2.cidade);
            break;
        case 3:
            printf("PIB: %s (%.2f) vs %s (%.2f)\n", c1.cidade, c1.pib, c2.cidade, c2.pib);
            printf("Vencedor: %s\n", (c1.pib > c2.pib) ? c1.cidade : c2.cidade);
            break;
        case 4:
            printf("Pontos Turísticos: %s (%d) vs %s (%d)\n", c1.cidade, c1.pontosTuristicos, c2.cidade, c2.pontosTuristicos);
            printf("Vencedor: %s\n", (c1.pontosTuristicos > c2.pontosTuristicos) ? c1.cidade : c2.cidade);
            break;
        case 5:
            printf("Densidade Populacional: %s (%.2f) vs %s (%.2f)\n", c1.cidade, c1.densidade, c2.cidade, c2.densidade);
            printf("Vencedor: %s\n", (c1.densidade < c2.densidade) ? c1.cidade : c2.cidade);
            break;
        case 6:
            printf("PIB per Capita: %s (%.2f) vs %s (%.2f)\n", c1.cidade, c1.pibPerCapita, c2.cidade, c2.pibPerCapita);
            printf("Vencedor: %s\n", (c1.pibPerCapita > c2.pibPerCapita) ? c1.cidade : c2.cidade);
            break;
        default:
            printf("Opção inválida!\n");
    }
}

int main() {
    struct Carta cartas[32]; // até 32 cartas
    int qtdCartas = 2;       // por enquanto vamos cadastrar só 2 para testar

    for (int i = 0; i < qtdCartas; i++) {
        cadastrarCarta(&cartas[i], i+1);
    }

    for (int i = 0; i < qtdCartas; i++) {
        exibirCarta(cartas[i], i+1);
    }

    int opcao;
    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Populacional\n6 - PIB per Capita\n");
    scanf("%d", &opcao);

    compararCartas(cartas[0], cartas[1], opcao);

    return 0;
}
