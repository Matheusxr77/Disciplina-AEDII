#ifndef BST_H
#define BST_H

typedef struct no {
    int valor;
    struct no *esquerda;
    struct no *direita;
} no;

typedef no* arvore;

arvore inserir (arvore raiz, int valor);
void preorder (arvore raiz);
void inorder (arvore raiz);
void posorder (arvore raiz);
void reverso (arvore raiz);
int quantidadePar (arvore raiz);
int antecessor (arvore raiz, int n);
void pai (arvore raiz, int n);
arvore remover (arvore raiz, int n);
int somaPar (arvore raiz);
arvore podar (arvore raiz, int n);
void dobro (arvore raiz);
int busca (arvore raiz, int chave);
void descendentes (arvore raiz, int n);
int altura (arvore raiz);

#endif