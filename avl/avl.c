#include "avl.h"
#include <stdlib.h>
#include <stdio.h>

// Função para iniciar uma árvore vazia
arvore inicializar (arvore raiz) {
    raiz = NULL;
}

// Função para calcular a altura de um nó
int altura (arvore no) {
    if (no == NULL) {
        return -1;
    } else {
        return no->altura;
    }
}

// Função para atualizar a altura de um nó
int atualizarAltura (arvore no) {
    if (no != NULL) {
        int alturaEsquerda = altura(no->esquerda);
        int alturaDireita = altura(no->direita);
        // Atualiza a altura do nó como a altura máxima entre a subárvore à esquerda e à direita, mais 1
        if (alturaEsquerda > alturaDireita) {
            no->altura = alturaEsquerda + 1;
        } else {
            no->altura = alturaDireita + 1;
        }
    }
}

// Função para calcular o fator de balanceamento de um nó
int fatorBalanceamento (arvore no) {
    if (no != NULL) {
        return (altura(no->esquerda) - altura(no->direita));
    } else {
        return 0;
    }
}

// Função para realizar a rotação simples à esquerda
arvore rotacaoEsquerda (arvore raiz) {
    arvore aux = raiz->direita;
    arvore temp = aux->esquerda;

    // Realiza a rotação
    aux->esquerda = raiz;
    raiz->direita = temp;

    // Atualiza as alturas dos nós afetados
    atualizarAltura(raiz);
    atualizarAltura(aux);
    return aux;
}

// Função para realizar a rotação simples à direita
arvore rotacaoDireita (arvore raiz) {
    arvore aux = raiz->esquerda;
    arvore temp = aux->direita;

    // Realiza a rotação
    aux->direita = raiz;
    raiz->esquerda = temp;

    // Atualiza as alturas dos nós afetados
    atualizarAltura(raiz);
    atualizarAltura(aux);
    return aux;
}

// Função para realizar uma rotação dupla à esquerda (direita-esquerda)
arvore rotacaoDuplaEsquerda (arvore raiz) {
    raiz->direita = rotacaoDireita(raiz->direita);
    return rotacaoEsquerda(raiz);
}

// Função para realizar uma rotação dupla à direita (esquerda-direita)
arvore rotacaoDuplaDireita (arvore raiz) {
    raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
    return rotacaoDireita(raiz);
}

// Função para balancear a árvore AVL
arvore balancear (arvore raiz) {
    // Atualizar a altura do nó atual
    atualizarAltura(raiz);

    // Calcula o fator de balanceamento deste nó para verificar se é necessário reequilibrar
    int balance = fatorBalanceamento(raiz);

    // Realiza as rotações necessárias para reequilibrar a árvore
    if (balance > 1) {
        if (fatorBalanceamento(raiz->esquerda) >= 0) {
            // Rotação Simples à Direita
            return rotacaoDireita(raiz);
        } else {
            // Rotação Dupla à Direita (Esquerda-Direita)
            return rotacaoDuplaDireita(raiz);
        }
    }

    if (balance < -1) {
        if (fatorBalanceamento(raiz->direita) <= 0) {
            // Rotação Simples à Esquerda
            return rotacaoEsquerda(raiz);
        } else {
            // Rotação Dupla à Esquerda (Direita-Esquerda)
            return rotacaoDuplaEsquerda(raiz);
        }
    }

    // Se o fator de balanceamento estiver fora do intervalo, a árvore já está balanceada
    return raiz;
}

// Função para inserir um valor na árvore AVL
arvore inserir (arvore raiz, int valor) {
    if (raiz == NULL) {
        // Cria um novo nó se a árvore estiver vazia
        arvore novo = (arvore)malloc(sizeof(struct no));

        novo->valor = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        novo->altura = 0;

        return novo;
    } else if (valor < raiz->valor) {
        // Inserção na subárvore esquerda
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        // Inserção na subárvore direita
        raiz->direita = inserir(raiz->direita, valor);
    } else {
        // Valor já existe na árvore, nada a fazer
        return raiz;
    }

    // Atualizar a altura do nó atual
    atualizarAltura(raiz);

    // Balancear a árvore após a inserção
    return balancear(raiz);
}

// Função para remover um valor da árvore AVL
arvore remover (arvore raiz, int valor) {
    // Verifica se a árvore está vazia
    if (raiz == NULL) {
        return raiz;
    }

    if (valor < raiz->valor) {
        // Remoção na subárvore esquerda
        raiz->esquerda = remover(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        // Remoção na subárvore direita
        raiz->direita = remover(raiz->direita, valor);
    } else {
        // Valor encontrado, realizar a remoção
        if (raiz->esquerda == NULL) {
            // Caso 1: Nó com no máximo um filho à direita
            arvore aux = raiz->direita;

            // Liberar memória
            free(raiz);

            return aux;
        } else if (raiz->direita == NULL) {
            // Caso 2: Nó com no máximo um filho à esquerda
            arvore aux = raiz->esquerda;

            // Liberar memória
            free(raiz);

            return aux;
        } else {
            // Caso 3: Nó com dois filhos
            arvore auxPai = raiz;
            arvore aux = raiz->direita;
            while (aux->esquerda != NULL) {
                auxPai = aux;
                aux = aux->esquerda;
            }
            if (auxPai != raiz) {
                auxPai->esquerda = aux->direita;
            } else {
                raiz->direita = aux->direita;
            }
            raiz->valor = aux->valor;
            free(aux);
        }
    }

    // Caso a árvore fique vazia pós-remoção
    if (raiz == NULL) {
        return raiz;
    }

    // Atualizar a altura do nó atual
    atualizarAltura(raiz);

    // Balancear a árvore após a remoção
    return balancear(raiz);
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
    
    // Verifica se a árvore está vazia
    if (raiz == NULL) {
        return 0;
    }
    contador = 0;
    
    // Verifica se o valor do nó atual é par
    if (raiz->valor % 2 == 0) {
        contador = 1;
    }

    // Calcula a soma total de nós pares nas subárvores esquerda e direita
    somaTotal = contador + quantidadePar(raiz->esquerda) + quantidadePar(raiz->direita);
    return somaTotal;
}

// Função para encontrar o antecessor de um nó
int antecessor (arvore raiz, int n) {
    // Valor inicial do antecessor, caso não seja encontrado
    int antecessorValor = -1;

    while (raiz != NULL) {
        // Se o valor do nó atual for menor que o valor desejado
        if (raiz->valor < n) {
            antecessorValor = raiz->valor;
            raiz = raiz->direita;
        } else {
            raiz = raiz->esquerda;
        }
    }

    // Retorna o valor do antecessor encontrado
    return antecessorValor;
}

// Função para realizar a busca de uma chave na árvore AVL
int busca (arvore raiz, int chave) {
    // Verifica se a árvore está vazia
    if (raiz == NULL) {
        return 0;
    }

    // Caso base: a chave foi encontrada no nó atual
    if (raiz->valor == chave) {
        return 1;
    } else if (chave < raiz->valor) {
        // Se a chave é menor que o valor do nó atual, busca na subárvore esquerda
        return busca(raiz->esquerda, chave);
    } else {
        // Se a chave é maior que o valor do nó atual, busca na subárvore direita
        return busca(raiz->direita, chave);
    }
}

// Função para encontrar e imprimir o pai de um nó com uma chave específica na árvore AVL
void pai (arvore raiz, int chave) {
    arvore pai = NULL;

    // Verifica se a árvore está vazia
    if (raiz == NULL) {
        printf("-1\n"); 
        return;
    }

    // Percorre a árvore AVL
    while (raiz != NULL) {
        if (raiz->valor == chave) {
            // Se a chave é encontrada, imprime o valor do pai
            if (pai == NULL) {
                printf("-1\n");
            } else {
                printf("%d\n", pai->valor);
            }
            return;
        } else if (chave > raiz->valor) {
            // Se a chave é maior que o valor do nó atual, move para a subárvore direita
            pai = raiz;
            raiz = raiz->direita;
        } else {
            // Se a chave é menor que o valor do nó atual, move para a subárvore esquerda
            pai = raiz;
            raiz = raiz->esquerda;
        }
    }
    
    // Se a chave não foi encontrada, imprime -1
    printf("-1\n");
}

// Função para calcular a soma dos valores pares na árvore AVL
int somaPar (arvore raiz) {
    int soma = 0;

    // Verifica se a árvore está vazia
    if (raiz == NULL) {
        return 0;
    }

    // Se o valor do nó atual é par, adiciona à soma
    if (raiz->valor % 2 == 0) {
        soma += raiz->valor;
    }

    // Soma os valores pares nas subárvores esquerda e direita
    soma += somaPar(raiz->esquerda);
    soma += somaPar(raiz->direita);
    return soma;
}

// Função para podar um nó e seus descendentes da árvore AVL
arvore podar (arvore raiz, int n) {
    // Verifica se a árvore está vazia
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

// Função para dobrar os valores dos nós na árvore AVL
void dobro (arvore raiz) {
    // Verifica se a árvore está vazia
    if (raiz != NULL) {
        raiz->valor *= 2;
        dobro(raiz->esquerda);
        dobro(raiz->direita);
    }
}

// Função para imprimir os descendentes de um nó em ordem crescente na árvore AVL
void descendentes (arvore raiz, int n) {
    // Verifica se a árvore está vazia
    if (raiz == NULL) {
        return;
    }

    if (raiz->valor == n) {
        // Se encontrou o nó desejado, imprime os descendentes
        if (raiz->esquerda != NULL) {
            descendentes(raiz->esquerda, n);
        }
        if (raiz->direita != NULL) {
            printf("%d ", raiz->direita->valor);
            descendentes(raiz->direita, n);
        }
    }
    if (raiz->valor > n) {
        // Se o valor do nó atual é maior que n, busca na subárvore esquerda
        descendentes(raiz->esquerda, n);
    } else {
        // Se o valor do nó atual é menor que n, busca na subárvore direita
        descendentes(raiz->direita, n);
    }
}