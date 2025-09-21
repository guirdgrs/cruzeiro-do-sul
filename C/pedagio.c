#include <stdio.h>
#include <string.h>

// Função para apresentar o menu, passa o dia atual como parâmetro 
void menu(char *dia_atual){
    printf("================================\n");
    printf("Bem-vindo ao programa de pedágio!\n");
    printf("\nDia atual: %s\n", dia_atual);
    printf("================================\n");
    printf("\n1. Registrar pedágio\n");
    printf("2. Finalizar dia\n");
    printf("3. Sair\n");
}

void limpar_tela(){
    #ifdef _WIN32 // Verifica se o sistema operacional é Windows
        system("cls");
    #else // Se não for Windows
        system("clear");
    #endif
}

void pausar(){
    printf("Pressione Enter para continuar...");
    // Enquanto o Enter não for pressionado
    while(getchar() != '\n');
    // Limpa o buffer
    getchar();
}

// Função para calcular o pedagio, recebe o tipo de veiculo e a kilometragem percorrida
float calcular_pedagio(char *tipo_veiculo, float km){

    float preco_km;

    if(strcmp(tipo_veiculo, "Leve") == 0){
        preco_km = 0.10;

    } else if (strcmp(tipo_veiculo, "Medio") == 0){
        preco_km = 0.15;

    } else {
        preco_km = 0.20;
    }

    return preco_km * km;
}

int main(){
    int opc = 0, contador_dia = 1;

    // Array com os dias da semana
    char *dia_semana[] = {
         "Segunda-feira", "Terça-feira", "Quarta-feira", 
         "Quinta-feira", "Sexta-feira", "Sábado", "Domingo"
        };
    // Quantos veículos foram registrados em cada dia
    int contador_veiculo_semana[7] = {0}; 

    char tipo_veiculo[20];
    float km = 0;

    while(opc != 3){
        limpar_tela();
        // contador_dia -1, pois o array com os dias da semana começa em 0
        menu(dia_semana[contador_dia - 1]);

        printf("\nDigite uma opção: ");
        scanf(" %d", &opc);

        if(opc == 1){
            limpar_tela();

            printf("Digite o tipo de veiculo (Leve, Medio, Pesado): ");
            scanf("%s", tipo_veiculo);

            printf("Digite a kilometragem percorrida: ");
            scanf("%f", &km);

            float valor = calcular_pedagio(tipo_veiculo, km);
            printf("Valor do pedagio: R$ %.2f\n\n", valor);

            // Incrementa o contador de veiculos
            contador_veiculo_semana[contador_dia - 1]++; 

            pausar();

        } else if (opc == 2){

            printf("\nDia finalizado!\n\n");

            if(contador_dia <= 6){
                printf("Dia atual: %s\n\n", dia_semana[contador_dia]);
            }

            // Incrementa o contador de dia
            contador_dia++;

            pausar();

            if(contador_dia > 7){
                limpar_tela();

                printf("======= RELATÓRIO DA SEMANA =======\n");

                // Variavel para armazenar o maior valor de veiculos
                int max = 0;

                // Percorre o array com os dias da semana
                for(int i = 0; i < 7; i++){
                    if(contador_veiculo_semana[i] > max){
                        max = contador_veiculo_semana[i];
                    }
                }

                // Demonstra o relatório
                for(int i = 0; i < 7; i++){
                    if(contador_veiculo_semana[i] == max && max > 0){
                        // Coloca a cor em vermelho se o dia tiver o maior numero de veiculos
                        printf("\033[1;31m%s: %d veículos\033[0m\n", dia_semana[i], contador_veiculo_semana[i]);

                    } else {
                        // Restante dos dias                        
                        printf("%s: %d veículos\n", dia_semana[i], contador_veiculo_semana[i]);
                    }
                }
                printf("===================================\n\n");

                pausar();

                // Reinicia a semana e o relatório
                contador_dia = 1;
                for(int i = 0; i < 7; i++){
                    contador_veiculo_semana[i] = 0;
                } 
            }
        }
    }

    limpar_tela();
    printf("\nPrograma finalizado!\n");
    return 0;
}