#include <stdio.h>

void menu(){
    printf("Calculadora de IMC\n");
    printf("------------------\n");
    printf("1. Calcular IMC\n");
    printf("2. Ver médias de IMC\n");
    printf("3. Sair\n");
}

void limpar_tela(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pausar(){
    printf("\nPressione Enter para continuar...");
    while(getchar() != '\n');
    getchar();
}

int main() {
    float peso, altura, imc, media_imc = 0;
    int opc = 0;
    int contador = 0;

    while(opc != 3) {
        limpar_tela();
        menu();

        printf("Escolha uma opção: ");
        scanf(" %d", &opc);

        if (opc == 1) {
            limpar_tela();

            printf("=== CALCULAR IMC ===\n\n");

            printf("Digite seu peso em kg: ");
            scanf(" %f", &peso);

            printf("Digite sua altura em metros: ");
            scanf(" %f", &altura);

            imc = peso / (altura * altura);

            printf("\nSeu IMC é: %.2f\n", imc);

            if (imc < 18.5) {
                printf("Classificação: Abaixo do peso\n");
            } else if (imc >= 18.5 && imc < 24.9) {
                printf("Classificação: Peso normal\n");
            } else if (imc >= 25 && imc < 29.9) {
                printf("Classificação: Sobrepeso\n");
            } else {
                printf("Classificação: Obesidade\n");
            }

            contador++;
            media_imc += imc;

            pausar();

        } else if (opc == 2) {
            limpar_tela();

            printf("=== MÉDIAS DE IMC ===\n\n");

            if (contador == 0) {
                printf("Nenhum IMC foi calculado ainda.\n");

            } else {
                printf("Total de IMCs calculados: %d\n", contador);
                printf("Média dos IMCs calculados: %.2f\n", media_imc / contador);
            }

            pausar();

        } else if (opc == 3) {
            limpar_tela();
            printf("Saindo...\n");
        } else {
            limpar_tela();
            printf("Opção inválida. Tente novamente.\n");
            pausar();
        }
    }
    return 0;
}