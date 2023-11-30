#include "bst.h"
#include <stdlib.h>
#include <stdio.h>

// Função para iniciar uma árvore vazia
arvore inicializar (arvore raiz) {
    raiz = NULL;
}

// Função para inserir um valor na árvore
arvore inserir (arvore raiz, int valor) {
    if (raiz == NULL) {
        // Cria um novo nó se a árvore estiver vazia
        arvore nova = (arvore)malloc(sizeof(struct no));
        nova->valor = valor;
        nova->esquerda = NULL;
        nova->direita = NULL;
        return nova;
    } else {
        // Insere o valor na subárvore esquerda ou direita, conforme necessário
        if (valor > raiz->valor) {
            raiz->direita = inserir(raiz->direita, valor);
        } else {
            raiz->esquerda = inserir(raiz->esquerda, valor);
        }
        return raiz;
    }
}

// Função para percorrer a árvore em pré-ordem
void preorder (arvore raiz) {
    if (raiz != NULL) {
        printf("[%d]", raiz->valor);
        preorder(raiz->esquerda);
        preorder(raiz->direita);
    }
}

// Função para percorrer a árvore em ordem
void inorder (arvore raiz) {
    if (raiz != NULL) {
        inorder(raiz->esquerda);
        printf("[%d]", raiz->valor);
        inorder(raiz->direita);
    }
}

// Função para percorrer a árvore em pós-ordem
void posorder (arvore raiz) {
    if (raiz != NULL) {
        posorder(raiz->esquerda);
        posorder(raiz->direita);
        printf("[%d]", raiz->valor);
    }
}

// Função para imprimir a árvore em ordem reversa
void reverso (arvore raiz) {
    if (raiz != NULL) {
        reverso(raiz->direita);
        printf("[%d]", raiz->valor);
        reverso(raiz->esquerda);
    }
    printf("\n");
}

// Função para contar a quantidade de nós com valores pares
int quantidadePar (arvore raiz) {
    int contador, somaTotal;
    if (raiz == NULL) {
        return 0;
    }
    contador = 0;
    if (raiz->valor % 2 == 0) {
        contador = 1;
    }
    somaTotal = contador + quantidadePar(raiz->esquerda) + quantidadePar(raiz->direita);
    return somaTotal;
}

// Função para encontrar o antecessor de um nó
int antecessor (arvore raiz, int n) {
    int antecessorValor = -1;
    while (raiz != NULL) {
        if (raiz->valor < n) {
            antecessorValor = raiz->valor;
            raiz = raiz->direita;
        } else {
            raiz = raiz->esquerda;
        }
    }
    return antecessorValor;
}

// Função para encontrar o pai de um nó
void pai (arvore raiz, int n) {
    arvore pai = NULL;
    if (raiz == NULL) {
        printf("-1");
    }
    while (raiz != NULL) {
        if (raiz->valor == n) {
            if (pai == NULL) {
                printf("-1\n");
            } else {
                printf("%d\n", pai->valor);
            }
            return;
        } else if (n > raiz->valor) {
            pai = raiz;
            raiz = raiz->direita;
        } else {
            pai = raiz;
            raiz = raiz->esquerda;
        }
    }
    printf("-1");
    printf("\n");
}

// Função para remover um nó da árvore
arvore remover (arvore raiz, int n) {
    if (raiz == NULL) {
        return raiz;
    }
    if (raiz->valor > n) {
        raiz->esquerda = remover(raiz->esquerda, n);
    } else if (n > raiz->valor) {
        raiz->direita = remover(raiz->direita, n);
    } else {
        if (raiz->esquerda == NULL) {
            // Caso 1: Nó com no máximo um filho à direita
            arvore aux = raiz->direita;
            free(raiz);
            return aux;
        } else if (raiz->direita == NULL) {
            // Caso 2: Nó com no máximo um filho à esquerda
            arvore aux = raiz->esquerda;
            free(raiz);
            return aux;
        }
        // Caso 3: Nó com dois filhos
        arvore atual = raiz->direita;
        arvore pai = NULL;
        while (atual->esquerda != NULL) {
            pai = atual;
            atual = atual->esquerda;
        }
        if (pai != NULL) {
            pai->esquerda = atual->direita;
        } else {
            raiz->direita = atual->direita;
        }
        raiz->valor = atual->valor;
        free(atual);
    }
    return raiz;
}

// Função para calcular a soma dos valores pares na árvore
int somaPar (arvore raiz) {
    int soma;
    if (raiz == NULL) {
        return 0;
    }
    soma = 0;
    if (raiz->valor % 2 == 0) {
        soma = soma + raiz->valor;
    }
    soma = soma + somaPar(raiz->esquerda);
    soma = soma + somaPar(raiz->direita);
    return soma;
}

// Função para remover um nó e seus descendentes da árvore
arvore podar (arvore raiz, int n) {
    if (raiz == NULL) {
        return raiz;
    }
    if (raiz->valor > n) {
        raiz->esquerda = podar(raiz->esquerda, n);
    } else if (n > raiz->valor) {
        raiz->direita = podar(raiz->direita, n);
    } else {
        if (raiz->esquerda != NULL) {
            // Caso 1: Nó com filho à esquerda
            arvore aux = raiz->esquerda;
            raiz->esquerda = NULL;
            free(aux);
            free(raiz);
            return NULL;
        } else if (raiz->direita != NULL) {
            // Caso 2: Nó com filho à direita
            arvore aux = raiz->direita;
            raiz->direita = NULL;
            free(aux);
            free(raiz);
            return NULL;
        } else {
            // Caso 3: Nó folha
            free(raiz);
            return NULL;
        }
    }
    return raiz;
}

// Função para dobrar os valores dos nós na árvore
void dobro (arvore raiz) {
    if (raiz != NULL) {
        raiz->valor *= 2;
        dobro(raiz->esquerda);
        dobro(raiz->direita);
    }
}

// Função para realizar a busca de uma chave na árvore
int busca (arvore raiz, int chave) {
    if (raiz == NULL) {
        return 0;
    }
    if (chave == raiz->valor) {
        return 1;
    } else if (chave < raiz->valor) {
        return busca(raiz->esquerda, chave);
    } else {
        return busca(raiz->direita, chave);
    }
}

// Função para imprimir os descendentes de um nó em ordem crescente
void descendentes (arvore raiz, int n) {
    if (raiz == NULL) {
        return;
    }
    if (raiz->valor == n) {
        if (raiz->esquerda != NULL) {
            descendentes(raiz->esquerda, n);
        }
        if (raiz->direita != NULL) {
            printf("%d ", raiz->direita->valor);
            descendentes(raiz->direita, n);
        }
    }
    if (raiz->valor > n) {
        descendentes(raiz->esquerda, n);
    } else {
        descendentes(raiz->direita, n);
    }
}

// Função para calcular a altura de uma árvore
int altura (arvore raiz) {
    if (raiz == NULL) {
        return -1;
    } else {
        int alturaEsquerda = altura(raiz->esquerda);
        int alturaDireita = altura(raiz->direita);

        if (alturaEsquerda > alturaDireita) {
            return alturaEsquerda + 1;
        } else {
            return alturaDireita + 1;
        }
    }
}