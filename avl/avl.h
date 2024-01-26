#ifndef AVL_H
#define AVL_H

typedef struct no {
    int valor;
    struct no* esquerda;
    struct no* direita;
    int altura;
} no;

typedef no* arvore;

int altura (arvore no);
int atualizarAltura (arvore no);
int fatorBalanceamento (arvore no);
arvore rotacaoEsquerda (arvore raiz);
arvore rotacaoDireita (arvore raiz);
arvore rotacaoDuplaEsquerda (arvore raiz);
arvore rotacaoDuplaDireita (arvore raiz);
arvore balancear (arvore raiz);
arvore inserir (arvore raiz, int valor);
arvore remover (arvore raiz, int valor);
void preorder (arvore raiz);
void inorder (arvore raiz);
void posorder (arvore raiz);
void reverso (arvore raiz);
int quantidadePar (arvore raiz);
int antecessor (arvore raiz, int n);
int busca (arvore raiz, int chave);
void pai (arvore raiz, int n);
int somaPar (arvore raiz);
arvore podar (arvore raiz, int n);
void dobro (arvore raiz);
void descendentes (arvore raiz, int n);

#endif