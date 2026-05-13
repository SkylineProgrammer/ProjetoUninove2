#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Constantes
#define MAX_ESTOQUE 6
#define MAX_AGENDAMENTOS 10
#define DESCONTO_AVISTA 0.10 

int main() {
    setlocale(LC_ALL, "Portuguese");

    // vetores
    char nomesCarros[MAX_ESTOQUE][30] = {"BMW X1", "Jeep Compass", "Honda Civic", "Mercedes GLA", "Audi A3", "Porsche 911"};
    float precosCarros[MAX_ESTOQUE] = {197000.0, 190000.0, 200000.0, 290000.0, 210000.0, 315000.0};
    
    // cadastro e contato
    char clientesAgendados[MAX_AGENDAMENTOS][50];
    int servicosEscolhidos[MAX_AGENDAMENTOS];
    int totalAgendamentos = 0;
    char nomeContato[50], emailContato[50], mensagem[200];

    int opcao, i; 

// pra limpar a tela independente de ser windows ou linux
    do {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        printf("==========================================\n");
        printf("               AUTOPRIME                  \n");
        printf("==========================================\n");
        printf("1 - Ver Catálogo e Preços\n");
        printf("2 - Simular Compra (Ver Opções e Descontos)\n");
        printf("3 - Agendar Serviço\n");
        printf("4 - Listar Agendamentos\n");
        printf("5 - Fale Conosco\n");
        printf("0 - Sair\n");
        printf("------------------------------------------\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("\n--- NOSSO ESTOQUE ATUAL ---\n");
                for(i = 0; i < MAX_ESTOQUE; i++) {
                    printf("%d. %-15s | R$ %.3f\n", i + 1, nomesCarros[i], precosCarros[i]);
                }
                printf("\nPressione Enter para voltar...");
                getchar(); getchar();
                break;

            case 2:
                printf("\n--- SIMULADOR DE VENDA (10%% de Desconto à Vista) ---\n");
                // Mostra o catálogo aqui dentro para facilitar a escolha
                for(i = 0; i < MAX_ESTOQUE; i++) {
                    printf("[%d] %-15s - R$ %.3f\n", i + 1, nomesCarros[i], precosCarros[i]);
                }
                
                printf("\nDigite o número do carro que deseja simular: ");
                int escolha;
                scanf("%d", &escolha);

                if(escolha >= 1 && escolha <= MAX_ESTOQUE) {
                    float precoOriginal = precosCarros[escolha - 1];
                    float vlrDesconto = precoOriginal * DESCONTO_AVISTA;
                    float precoFinal = precoOriginal - vlrDesconto;

                    printf("\n------------------------------------------\n");
                    printf("SIMULAÇÃO:\n");
                    printf("Veículo: %s\n", nomesCarros[escolha - 1]);
                    printf("Preço de Tabela: R$ %.3f\n", precoOriginal);
                    printf("Desconto aplicado: R$ %.3f\n", vlrDesconto);
                    printf("VALOR FINAL À VISTA: R$ %.3f\n", precoFinal);
                    printf("------------------------------------------\n");
                } else {
                    printf("\n Veículo não encontrado no estoque!");
                }
                printf("\nPressione Enter para continuar...");
                getchar(); getchar();
                break;

            case 3:
                if(totalAgendamentos < MAX_AGENDAMENTOS) {
                    printf("\n--- NOVO AGENDAMENTO ---\n");
                    printf("Nome do Cliente: ");
                    scanf("%s", clientesAgendados[totalAgendamentos]);
                    printf("Serviço (1-Financiamento, 2-Garantia, 3-Revisão): ");
                    scanf("%d", &servicosEscolhidos[totalAgendamentos]);
                    
                    totalAgendamentos++;
                    printf("\nAgendamento realizado com sucesso!");
                } else {
                    printf("\nAgenda lotada!");
                }
                printf("\nPressione Enter...");
                getchar(); getchar();
                break;

            case 4:
                printf("\n--- LISTA DE AGENDAMENTOS ---\n");
                if(totalAgendamentos == 0) {
                    printf("Nenhum serviço agendado.\n");
                } else {
                    for(i = 0; i < totalAgendamentos; i++) {
                        printf("Cliente: %-15s | Serviço: %d\n", clientesAgendados[i], servicosEscolhidos[i]);
                    }
                }
                printf("\nPressione Enter...");
                getchar(); getchar();
                break;

            case 5:
                printf("\n--- FALE CONOSCO ---\n");
                printf("Nome: ");
                scanf("%s", nomeContato);
                printf("E-mail: ");
                scanf("%s", emailContato);
                printf("Sua Mensagem: ");
                scanf(" %[^\n]s", mensagem); 

                printf("\nObrigado, %s! Mensagem enviada. Entraremos em Contato em breve \n", nomeContato);
                printf("\nPressione Enter para voltar...");
                getchar(); getchar();
                break;

            case 0:
                printf("\nSaindo do sistema AutoPrime...\n");
                break;

            default:
                printf("\nOpção inválida!\n");
                getchar(); getchar();
        }

    } while(opcao != 0);

    return 0;
}