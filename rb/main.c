#include "rb.h"
#include <stdlib.h>
#include <stdio.h>

int main (int argc, char* argv[]) {
    // Inicializa uma árvore vazia
    arvore tree = NULL;

    // Variáveis para opções do usuário
    int escolha, opcao, valor, numero;

    // Preenche a árvore inicialmente
    printf("Preencha a arvore: \n");
    printf("Primeiro valor: ");
    scanf("%d", &valor);
    tree = inserir(&tree, valor); // Corrigido

    // Pergunta se o usuário deseja inserir mais números na árvore
    printf("Deseja inserir outro numero na arvore?\n");
    printf("1. Sim\n");
    printf("2. Nao\n");
    scanf("%d", &escolha);
    if (escolha > 2 || escolha < 1) {
        printf("Opcao inválida, tente novamente\n");
    }

    // Loop para continuar inserindo valores na árvore
    while (escolha != 2) {
        printf("Insira um numero na arvore: ");
        scanf("%d", &valor);
        tree = inserir(&tree, valor); // Corrigido
        
        printf("Deseja inserir outro numero na arvore?\n");
        printf("1. Sim\n");
        printf("2. Nao\n");
        scanf("%d", &escolha);

        if (escolha > 2 || escolha < 1) { 
            printf("Opcao invalida, tente novamente\n");
            printf("Deseja inserir outro numero na arvore?\n");
            printf("1. Sim\n");
            printf("2. Nao\n");
            scanf("%d", &escolha);
        }
    }
    
    // Exibe o menu de opções
    printf("\n================= MENU =================\n");
    printf("1. INSERIR \n");
    printf("2. PREORDER \n");
    printf("3. INORDER \n");
    printf("4. POSORDER \n");
    printf("5. REMOVER \n");
    printf("6. BUSCA \n");
    printf("99. SAIR \n");
    printf("=======================================\n");

    // Leitura da opção escolhida pelo usuário
    scanf("%d", &opcao); 

    // Loop principal para processar as opções do usuário
    while (opcao) {
        switch (opcao) {

        case 1:
            // Opção para inserir um novo elemento na árvore
            printf("Digite o numero para ser inserido: ");
            scanf("%d", &numero);
            tree = inserir(&tree, numero); // Corrigido
            printf("\nEscolha outra opcao: ");
            scanf("%d", &opcao);
            break;

        case 2:
            // Opção para exibir a árvore em pré-ordem
            preOrder(tree);
            printf("\nEscolha outra opcao: ");
            scanf("%d", &opcao);
            break;
        
        case 3:
            // Opção para exibir a árvore em ordem
            inOrder(tree);
            printf("\nEscolha outra opcao: ");
            scanf("%d", &opcao);
            break;
        
        case 4:
            // Opção para exibir a árvore em pós-ordem
            posOrder(tree);
            printf("\nEscolha outra opcao: ");
            scanf("%d", &opcao);
            break;

        case 5:
            // Opção para remover um elemento da árvore
            printf("Qual elemento que deseja remover? ");
            scanf("%d", &numero);
            remover(numero, &tree); // Corrigido
            printf("Escolha outra opcao: ");
            scanf("%d", &opcao);
            break;

        case 6:
            // Opção de buscar um determinado valor na árvore
            printf("Qual valor deseja buscar? ");
            scanf("%d", &numero);
            printf("%d\n", busca(numero, tree)); // Corrigido
            printf("Escolha outra opcao: ");
            scanf("%d", &opcao);
            break;

        case 99:
            // Opção de sair
            free(tree);
            exit(0);
            break;

        default:
            // Opção inválida
            printf("opcao invalida, tente novamente: ");
            scanf("%d", &opcao);
            break;
        }
    }
}