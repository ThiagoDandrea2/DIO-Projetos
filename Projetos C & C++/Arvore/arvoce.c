#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int chave;
    struct Node* esquerda;
    struct Node* direita;
    int altura;
} Node;

int altura(Node* n) {
    if (n == NULL) return 0;
    return n->altura;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Node* novoNo(int chave) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->chave = chave;
    node->esquerda = NULL;
    node->direita = NULL;
    node->altura = 1;
    return node;
}

// Rotação à direita
Node* rotacaoDireita(Node* y) {
    Node* x = y->esquerda;
    Node* T2 = x->direita;

    x->direita = y;
    y->esquerda = T2;

    y->altura = max(altura(y->esquerda), altura(y->direita)) + 1;
    x->altura = max(altura(x->esquerda), altura(x->direita)) + 1;

    return x;
}

// Rotação à esquerda
Node* rotacaoEsquerda(Node* x) {
    Node* y = x->direita;
    Node* T2 = y->esquerda;

    y->esquerda = x;
    x->direita = T2;

    x->altura = max(altura(x->esquerda), altura(x->direita)) + 1;
    y->altura = max(altura(y->esquerda), altura(y->direita)) + 1;

    return y;
}

int getBalance(Node* n) {
    if (n == NULL) return 0;
    return altura(n->esquerda) - altura(n->direita);
}

// Inserção balanceada
Node* inserir(Node* node, int chave) {
    if (node == NULL) return novoNo(chave);

    if (chave < node->chave)
        node->esquerda = inserir(node->esquerda, chave);
    else if (chave > node->chave)
        node->direita = inserir(node->direita, chave);
    else
        return node;

    node->altura = 1 + max(altura(node->esquerda), altura(node->direita));
    int balance = getBalance(node);

    // Casos de desbalanceamento
    if (balance > 1 && chave < node->esquerda->chave)
        return rotacaoDireita(node);

    if (balance < -1 && chave > node->direita->chave)
        return rotacaoEsquerda(node);

    if (balance > 1 && chave > node->esquerda->chave) {
        node->esquerda = rotacaoEsquerda(node->esquerda);
        return rotacaoDireita(node);
    }

    if (balance < -1 && chave < node->direita->chave) {
        node->direita = rotacaoDireita(node->direita);
        return rotacaoEsquerda(node);
    }

    return node;
}

// Busca binária
Node* buscar(Node* raiz, int chave) {
    if (raiz == NULL || raiz->chave == chave) return raiz;
    if (chave < raiz->chave)
        return buscar(raiz->esquerda, chave);
    return buscar(raiz->direita, chave);
}

// Em ordem (para mostrar árvore ordenada)
void emOrdem(Node* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);
        printf("%d ", raiz->chave);
        emOrdem(raiz->direita);
    }
}

int main() {
    Node* raiz = NULL;

    int valores[] = {10, 20, 30, 40, 50, 25};
    int n = sizeof(valores) / sizeof(valores[0]);

    for (int i = 0; i < n; i++) {
        raiz = inserir(raiz, valores[i]);
    }

    printf("Em ordem: ");
    emOrdem(raiz);
    printf("\n");

    int chaveBusca = 25;
    Node* resultado = buscar(raiz, chaveBusca);
    if (resultado != NULL)
        printf("Chave %d encontrada.\n", chaveBusca);
    else
        printf("Chave %d não encontrada.\n", chaveBusca);

    return 0;
}
