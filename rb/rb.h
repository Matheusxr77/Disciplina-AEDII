#ifndef RB_H
#define RB_H

enum Cor {
    VERMELHO,
    PRETO,
    DUPLO_PRETO,
};

typedef int tipoDado;

typedef struct no {
    tipoDado dado;
    struct no *esquerda;
    struct no *direita;
    struct no *pai;
    enum Cor cor;
} no;

typedef no* arvore;

int ehRaiz (arvore elemento);
int ehFilhoEsquerdo (arvore elemento);
int ehFilhoDireito (arvore elemento);
arvore irmao (arvore elemento);
arvore tio (arvore elemento);
enum Cor cor (arvore elemento);
void inicializar (arvore *raiz);
arvore inserir (arvore *raiz, int valor);
void ajustar (arvore *raiz, arvore elemento);   
void rotacaoDireita (arvore *raiz, arvore pivo);
void rotacaoEsquerda (arvore *raiz, arvore pivo);
void rotacaoDuplaDireita (arvore *raiz, arvore elemento);
void rotacaoDuplaEsquerda (arvore *raiz, arvore elemento);
void preOrder (arvore raiz);
void inOrder (arvore raiz);
void posOrder (arvore raiz);
void retiraDuploPreto (arvore *raiz, arvore elemento);
void reajustar (arvore *raiz, arvore elemento);
int maiorElemento (arvore raiz);
arvore busca (int valor, arvore raiz);
void remover (int valor, arvore *raiz);

#endif