#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void ordenar_produtos(char *produtos[], int n, int ordem) {
    //Ordem -> 1 - crescente | -1 - decrescente
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Se a ordem for crescente e o produto atual for maior que o produto seguinte
            if (ordem * strcmp(produtos[j], produtos[j + 1]) > 0) {

                // Troca os produtos
                char *temp = produtos[j];

                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }
}

void ordenar_precos(float precos[], int n, int ordem) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            // Se a ordem for crescente e o preco atual for maior que o preco seguinte
            if (ordem * (precos[j] - precos[j + 1]) > 0) {

                // Troca os preços
                float temp = precos[j];

                precos[j] = precos[j + 1];
                precos[j + 1] = temp;
            }
        }
    }
}

void limpar_tela(){
    #ifdef _WIN32 // Verifica se o sistema operacional é Windows
        system("cls");
    #else // Se não for Windows
        system("clear");
    #endif
}

void pausar(){
    printf("\nPressione Enter para continuar...");
    // Enquanto o Enter não for pressionado
    while(getchar() != '\n');
    // Limpa o buffer
    getchar();
}

void menu(){
    printf("=================\n");
    printf("Lista de Produtos\n");
    printf("=================\n");
}

int main() {

    // Array com os produtos
    char *produtos[] = {
        "Arroz", "Feijao", "Macarrao", "Cafe", "Leite",
        "Oleo", "Queijo", "Ovos", "Manteiga", "Acucar"
    };

    // Array com os preços
    float precos[] = {
        22.00, 6.00, 3.50, 18.00, 4.50,
        8.00, 15.50, 12.00, 10.50, 4.00
    };

    // Quantidade de produtos
    int n = sizeof(produtos) / sizeof(produtos[0]);

// 1 - Produtos desorganizados
    menu();
    printf("\nDesordenado por Nome\n\n");

    for (int i = 0; i < n; i++) {
        printf("%s \n", produtos[i]);
    }

    pausar();
    limpar_tela();

// 2 - Produtos organizados em ordem crescente
    ordenar_produtos(produtos, n, 1);
    menu();

    printf("\nOrdenado por Nome (Crescente)\n\n");

    for (int i = 0; i < n; i++) {
        printf("%s \n", produtos[i]);
    }

    pausar();
    limpar_tela();

// 3 - Produtos organizados em ordem decrescente
    ordenar_produtos(produtos, n, -1);
    menu();
    printf("\nOrdenado por Nome (Decrescente)\n\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", produtos[i]);
    }

    pausar();
    limpar_tela();

// 4 - Preços desorganizados
    menu();
    printf("\nDesordenado por Preço\n\n");

    for (int i = 0; i < n; i++) {
        printf("R$ %.2f\n", precos[i]);
    }

    pausar();
    limpar_tela();

// 5 - Precos organizados em ordem crescente
    ordenar_precos(precos, n, 1);
    menu();
    printf("\nOrdenado por Preço (Crescente)\n\n");

    for (int i = 0; i < n; i++) {
        printf("R$ %.2f\n", precos[i]);
    }

    pausar();
    limpar_tela();

// 6 - Preços organizados em ordem decrescente
    ordenar_precos(precos, n, -1);
    menu();
    printf("\nOrdenado por Preço (Decrescente)\n\n");

    for (int i = 0; i < n; i++) {
        printf("R$ %.2f\n", precos[i]);
    }

    pausar();

    return 0;
}