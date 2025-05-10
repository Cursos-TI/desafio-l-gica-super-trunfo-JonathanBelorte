#include <stdio.h>
#include <string.h>

typedef struct {
    char estado[30];
    char codigo[10];
    char cidade[30];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
    float pibPerCapita;
    int ataque;
    int defesa;
    int recuo;
} Carta;

void mostrarAtributo(Carta c1, Carta c2, char atributo[], float val1, float val2) {
    printf("Comparação: %s\n", atributo);
    printf("%s: %.2f\n", c1.cidade, val1);
    printf("%s: %.2f\n", c2.cidade, val2);
}

int main() {
    // Cartas com dados reais e atributos personalizados
    Carta carta1 = {"São Paulo", "BR01", "São Paulo", 12300000, 1521.11, 2300000.0, 15, 0, 0, 90, 85, 60};
    Carta carta2 = {"Rio de Janeiro", "BR02", "Rio de Janeiro", 6710000, 1182.3, 1500000.0, 10, 0, 0, 75, 80, 70};

    // Cálculo de atributos derivados
    carta1.densidade = carta1.populacao / carta1.area;
    carta2.densidade = carta2.populacao / carta2.area;

    carta1.pibPerCapita = carta1.pib / carta1.populacao;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;

    // Atributos numéricos possíveis (índices de seleção)
    float valor1[9] = {
        carta1.populacao, carta1.area, carta1.pib, carta1.densidade,
        carta1.pibPerCapita, carta1.pontosTuristicos,
        carta1.ataque, carta1.defesa, carta1.recuo
    };

    float valor2[9] = {
        carta2.populacao, carta2.area, carta2.pib, carta2.densidade,
        carta2.pibPerCapita, carta2.pontosTuristicos,
        carta2.ataque, carta2.defesa, carta2.recuo
    };

    char *nomesAtributos[9] = {
        "População", "Área", "PIB", "Densidade Populacional",
        "PIB per Capita", "Pontos Turísticos",
        "Ataque", "Defesa", "Recuo"
    };

    int opcao1, opcao2;
    printf("=== Super Trunfo - Países ===\n");
    printf("Atributos disponíveis:\n");
    for (int i = 0; i < 9; i++) {
        printf("%d - %s\n", i + 1, nomesAtributos[i]);
    }

    // Escolha do primeiro atributo
    printf("\nEscolha o primeiro atributo: ");
    scanf("%d", &opcao1);
    if (opcao1 < 1 || opcao1 > 9) {
        printf("Opção inválida!\n");
        return 1;
    }

    // Escolha do segundo atributo (não pode repetir)
    do {
        printf("Escolha o segundo atributo (diferente do primeiro): ");
        scanf("%d", &opcao2);
        if (opcao2 == opcao1)
            printf("Você já escolheu esse. Escolha um atributo diferente.\n");
    } while (opcao2 == opcao1 || opcao2 < 1 || opcao2 > 9);

    opcao1--; opcao2--; // Ajustar para índice

    // Mostrar os atributos e valores
    mostrarAtributo(carta1, carta2, nomesAtributos[opcao1], valor1[opcao1], valor2[opcao1]);
    mostrarAtributo(carta1, carta2, nomesAtributos[opcao2], valor1[opcao2], valor2[opcao2]);

    // Regras: menor densidade vence, os demais: maior vence
    int resultado1 = (opcao1 == 3) ? (valor1[opcao1] < valor2[opcao1]) :
                                     (valor1[opcao1] > valor2[opcao1]);

    int resultado2 = (opcao2 == 3) ? (valor1[opcao2] < valor2[opcao2]) :
                                     (valor1[opcao2] > valor2[opcao2]);

    float soma1 = valor1[opcao1] + valor1[opcao2];
    float soma2 = valor2[opcao1] + valor2[opcao2];

    printf("\nSoma dos dois atributos:\n");
    printf("%s: %.2f\n", carta1.cidade, soma1);
    printf("%s: %.2f\n", carta2.cidade, soma2);

    printf("\nResultado Final:\n");
    if (soma1 > soma2)
        printf("Vencedor: %s\n", carta1.cidade);
    else if (soma2 > soma1)
        printf("Vencedor: %s\n", carta2.cidade);
    else
        printf("Empate!\n");

    return 0;
}
