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

// Função para cadastrar manualmente uma carta
void cadastrarCarta(struct Carta *carta, int numero) {
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

// Exibir carta
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

// Comparar duas cartas
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

// Nova função para mostrar todas as cartas
void mostrarCartas(struct Carta cartas[], int qtd) {
    for (int i = 0; i < qtd; i++) {
        exibirCarta(cartas[i], i+1);
    }
}

int main() {
    // Baralho pronto com 32 cartas
    struct Carta cartas[32] = {


        {"SP","SP01","São Paulo",12300000,1521.0,700.0,50,12300000/1521.0,(700.0*1000000000)/12300000},
        {"RJ","RJ01","Rio de Janeiro",6748000,1200.0,400.0,45,6748000/1200.0,(400.0*1000000000)/6748000},
        {"MG","MG01","Belo Horizonte",2500000,331.0,120.0,20,2500000/331.0,(120.0*1000000000)/2500000},
        {"RS","RS01","Porto Alegre",1500000,496.0,90.0,18,1500000/496.0,(90.0*1000000000)/1500000},
        {"PR","PR01","Curitiba",1900000,435.0,110.0,22,1900000/435.0,(110.0*1000000000)/1900000},
        {"SC","SC01","Florianópolis",500000,675.0,30.0,15,500000/675.0,(30.0*1000000000)/500000},
        {"PE","PE01","Recife",1600000,218.0,85.0,25,1600000/218.0,(85.0*1000000000)/1600000},
        {"CE","CE01","Fortaleza",2700000,314.0,95.0,28,2700000/314.0,(95.0*1000000000)/2700000},
        {"BA","BA01","Salvador",2900000,693.0,100.0,30,2900000/693.0,(100.0*1000000000)/2900000},
        {"GO","GO01","Goiânia",1500000,739.0,70.0,12,1500000/739.0,(70.0*1000000000)/1500000},
        {"DF","DF01","Brasília",3100000,5802.0,200.0,40,3100000/5802.0,(200.0*1000000000)/3100000},
        {"AM","AM01","Manaus",2200000,11401.0,60.0,10,2200000/11401.0,(60.0*1000000000)/2200000},
        {"PA","PA01","Belém",1500000,1059.0,50.0,14,1500000/1059.0,(50.0*1000000000)/1500000},
        {"MA","MA01","São Luís",1100000,834.0,40.0,9,1100000/834.0,(40.0*1000000000)/1100000},
        {"PB","PB01","João Pessoa",820000,211.0,25.0,8,820000/211.0,(25.0*1000000000)/820000},
        {"RN","RN01","Natal",900000,170.0,28.0,10,900000/170.0,(28.0*1000000000)/900000},
        {"AL","AL01","Maceió",1000000,510.0,35.0,12,1000000/510.0,(35.0*1000000000)/1000000},
        {"SE","SE01","Aracaju",650000,181.0,20.0,7,650000/181.0,(20.0*1000000000)/650000},
        {"TO","TO01","Palmas",300000,2218.0,15.0,5,300000/2218.0,(15.0*1000000000)/300000},
        {"RO","RO01","Porto Velho",500000,3401.0,18.0,6,500000/3401.0,(18.0*1000000000)/500000},
        {"AC","AC01","Rio Branco",400000,883.0,12.0,4,400000/883.0,(12.0*1000000000)/400000},
        {"MS","MS01","Campo Grande",900000,8096.0,40.0,10,900000/8096.0,(40.0*1000000000)/900000},
        {"MT","MT01","Cuiabá",600000,3546.0,30.0,8,600000/3546.0,(30.0*1000000000)/600000},
        {"ES","ES01","Vitória",365000,93.0,22.0,6,365000/93.0,(22.0*1000000000)/365000},
        {"PI","PI01","Teresina",870000,1391.0,27.0,9,870000/1391.0,(27.0*1000000000)/870000},
        {"AP","AP01","Macapá",510000,6407.0,14.0,5,510000/6407.0,(14.0*1000000000)/510000},
        {"RR","RR01","Boa Vista",420000,5120.0,13.0,4,420000/5120.0,(13.0*1000000000)/420000},
        {"RS","RS02","Caxias do Sul",520000,1648.0,25.0,7,520000/1648.0,(25.0*1000000000)/520000},
        {"PR","PR02","Londrina",580000,1650.0,28.0,8,580000/1650.0,(28.0*1000000000)/580000},
        {"SC","SC02","Joinville",600000,1134.0,25.0,10,600000/1134.0,(25.0*1000000000)/600000},
        {"SP","SP02","Campinas",1200000,795.0,60.0,15,1200000/795.0,(60.0*1000000000)/1200000},
        {"RJ","RJ02","Niterói",520000,133.0,22.0,6,520000/133.0,(22.0*1000000000)/520000}
    };

    int escolha = 0;
    while (escolha != 4) {
    printf("\nMenu:\n");
    printf("1 - Exibir todas as cartas\n");
    printf("2 - Cadastrar nova carta\n");
    printf("3 - Comparar duas cartas\n");
    printf("4 - Sair\n");
    printf("Escolha: ");
    scanf("%d", &escolha);

    if (escolha == 1) {
        mostrarCartas(cartas, 32);
    } else if (escolha == 2) {
        struct Carta nova;
        cadastrarCarta(&nova, 33);
        exibirCarta(nova, 33);
    } else if (escolha == 3) {
        int c1, c2, opcao;
        printf("Digite o número da primeira carta (1-32): ");
        scanf("%d", &c1);
        printf("Digite o número da segunda carta (1-32): ");
        scanf("%d", &c2);
        printf("Escolha o atributo para comparar:\n");
        printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Populacional\n6 - PIB per Capita\n");
        scanf("%d", &opcao);
        compararCartas(cartas[c1-1], cartas[c2-1], opcao);
    } else if (escolha == 4) {
        printf("Encerrando o programa...\n");
    } else {
        printf("Opção inválida! Tente novamente.\n");
    }
}

    return 0;
}
