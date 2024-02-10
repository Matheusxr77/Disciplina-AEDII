#include "bst.h"
#include <stdlib.h>
#include <stdio.h>

void main (int argc, char * argv[]) {
    // Inicializa uma árvore vazia 
    arvore tree = NULL;

    // Variáveis para opções do usuário
    int escolha, opcao, valor, numero;
    
    // Preenche a árvore inicialmente
    printf("Preencha a arvore: \n");
    printf("Primeiro valor: ");
    scanf("%d", &valor);
    tree = inserir(tree, valor);

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
        tree = inserir(tree, valor); 
        
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
    printf("5. REVERSO \n");
    printf("6. QUANTIDADE DE NUMEROS PARES \n");
    printf("7. ANTECESSOR \n");
    printf("8. PAI \n");
    printf("9. REMOVER \n");
    printf("10. SOMA DOS NUMEROS PARES \n");
    printf("11. PODAS \n");
    printf("12. DOBRO \n");
    printf("13. BUSCA \n");
    printf("14. DESCENDENTES \n");
    printf("15. ALTURA \n");
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
            inserir(tree, numero);
            printf("\nEscolha outra opcao: ");
            scanf("%d", &opcao);
            break;

        case 2:
            // Opção para exibir a árvore em pré-ordem
            preorder(tree);
            printf("\nEscolha outra opcao: ");
            scanf("%d", &opcao);
            break;
        
        case 3:
            // Opção para exibir a árvore em ordem
            inorder(tree);
            printf("\nEscolha outra opcao: ");
            scanf("%d", &opcao);
            break;
        
        case 4:
            // Opção para exibir a árvore em pós-ordem
            posorder(tree);
            printf("\nEscolha outra opcao: ");
            scanf("%d", &opcao);
            break;

        case 5:
            // Opção para exibir a árvore em ordem reversa
            reverso(tree);
            printf("\nEscolha outra opcao: ");
            scanf("%d", &opcao);
            break;
        
        case 6:
            // Opção para exibir a quantidade de números pares
            printf("Quantidade de numeros pares: %d\n", quantidadePar(tree));
            printf("Escolha outra opcao: ");
            scanf("%d", &opcao);
            break;

        case 7:
            // Opção para descobrir o antecessor de algum número
            printf("De qual valor deseja descobrir o antecessor? ");
            scanf("%d", &numero);
            printf("Antecessor: %d\n", antecessor(tree, numero));
            printf("Escolha outra opcao: ");
            scanf("%d", &opcao);
            break;

        case 8:
            // Opção para descober o pai de algum número
            printf("De qual valor deseja descobrir o pai? ");
            scanf("%d", &numero);
            pai(tree, numero);
            printf("\nEscolha outra opcao: ");
            scanf("%d", &opcao);
            break;

        case 9:
            // Opção para remover um elemento da árvore
            printf("Qual elemento que deseja remover? ");
            scanf("%d", &numero);
            remover(tree, numero);
            printf("Escolha outra opcao: ");
            scanf("%d", &opcao);
            break;

        case 10:
            // Opção para realizar a soma dos números pares
            printf("Soma de todos os numeros pares: %d\n", somaPar(tree));
            printf("Escolha outra opcao: ");
            scanf("%d", &opcao);
            break;

        case 11:
            // Opção para podar elementos
            printf("Qual elemento deseja podar? ");
            scanf("%d", &numero);
            podar(tree, numero);
            printf("Escolha outra opcao: ");
            scanf("%d", &opcao);
            break;

        case 12:
            // Opção para dobrar os elementos da árvore
            dobro(tree);
            printf("Escolha outra opcao: ");
            scanf("%d", &opcao);
            break;

        case 13:
            // Opção de buscar um determinado valor na árvore
            printf("Qual valor deseja buscar? ");
            scanf("%d", &numero);
            printf("%d\n", busca(tree, numero));
            printf("Escolha outra opcao: ");
            scanf("%d", &opcao);
            break;

        case 14:
            // Opção para descobrir o descendente de um número
            printf("De qual elemento deseja descobrir os descendentes? ");
            scanf("%d", &numero);
            descendentes(tree, numero);
            printf("\nEscolha outra opcao: ");
            scanf("%d", &opcao);
            break;

        case 15:
            // Opção para calcular a altura da árvore
            printf("%d\n", altura(tree));
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