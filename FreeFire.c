#include <stdio.h>
#include <string.h>

// Definição da struct para representar cada item
typedef struct {
    char nome[50];
    char tipo[30];
    int quantidade;
} Item;

int main() {
    Item mochila[10]; // Vetor estático para 10 itens
    int totalItens = 0;
    int opcao;

    do {
        printf("\n--- MENU MOCHILA ---\n");
        printf("1. Adicionar item\n");
        printf("2. Remover item (por nome)\n");
        printf("3. Listar itens\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer do teclado

        switch(opcao) {
            case 1:
                if (totalItens < 10) {
                    printf("Nome do item: ");
                    fgets(mochila[totalItens].nome, 50, stdin);
                    strtok(mochila[totalItens].nome, "\n"); // Remove o \n do final

                    printf("Tipo do item: ");
                    fgets(mochila[totalItens].tipo, 30, stdin);
                    strtok(mochila[totalItens].tipo, "\n");

                    printf("Quantidade: ");
                    scanf("%d", &mochila[totalItens].quantidade);
                    
                    totalItens++;
                    printf("Item adicionado com sucesso!\n");
                } else {
                    printf("Erro: Mochila cheia!\n");
                }
                break;

            case 2:
                if (totalItens == 0) {
                    printf("Mochila vazia.\n");
                } else {
                    char busca[50];
                    printf("Digite o nome do item para remover: ");
                    fgets(busca, 50, stdin);
                    strtok(busca, "\n");

                    int encontrado = -1;
                    for(int i = 0; i < totalItens; i++) {
                        if(strcmp(mochila[i].nome, busca) == 0) {
                            encontrado = i;
                            break;
                        }
                    }

                    if(encontrado != -1) {
                        // Move os itens seguintes uma posição para trás
                        for(int i = encontrado; i < totalItens - 1; i++) {
                            mochila[i] = mochila[i + 1];
                        }
                        totalItens--;
                        printf("Item removido!\n");
                    } else {
                        printf("Item nao encontrado.\n");
                    }
                }
                break;

            case 3:
                printf("\n--- ITENS NA MOCHILA ---\n");
                for(int i = 0; i < totalItens; i++) {
                    printf("%d. %s [%s] - Qtd: %d\n", i+1, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
                }
                if(totalItens == 0) printf("Mochila vazia.\n");
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 0);

    return 0;
}