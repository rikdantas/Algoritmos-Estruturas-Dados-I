#include <stdlib.h>
#include <stdio.h>

struct no{
    struct no *ant;
    int val;
    struct no *prox;
};

struct doublylinkedlist {
    struct no* cabeca;
    struct no* cauda;
    int qtdade;
};

struct doublylinkedlist* inicializar() {
    struct linkedlist* lista = (struct linkedlist*)malloc(sizeof(struct linkedlist));
    lista -> cabeca = NULL;
    lista -> cauda = NULL;
    lista -> qtdade = 0;

    return lista;
}

struct no* alocarNovoNo(int valor){
    struct no* novoNo = (struct no*)malloc(sizeof(struct no));
    novoNo -> val = valor;
    novoNo -> prox = NULL;
    novoNo -> ant = NULL;

    return novoNo;
}

void inserirElementoNoInicio(struct doublylinkedlist* lista, int valor){
    struct no* novoNo = alocarNovoNo(valor);

    if(lista -> cabeca == NULL){
        lista -> cabeca = novoNo;
    }
    else{
        novoNo->prox = lista->cabeca;
        lista->cabeca->ant = novoNo;
        lista->cabeca = novoNo;
    }
    lista->qtdade++;
}

void inserirElementoNoFim(struct doublylinkedlist* lista, int valor){
    struct no* novoNo = alocarNovoNo(valor);

    if(lista->qtdade == 0){
        inserirElementoNoInicio(lista,valor);
    }
    else{
        struct no* aux = lista -> cauda;
        aux->prox = novoNo;
        novoNo->ant = lista->cauda;
        lista->cauda = novoNo;
        lista->qtdade++;
    }
}

void inserirElementoEmPosicao(struct doublylinkedlist* lista, int valor, int posicao){
    //TODO
}

int obterElementoEmPosicao(struct doublylinkedlist* lista, int posicao){
    //TODO
}

void removerElementoEmPosicao(struct doublylinkedlist* lista, int posicao){
    //TODO
}

void imprimirLista(struct no** cabeca) {
    //usamos o aux para percorrer a lista
    if ((*cabeca) != NULL) {
        struct no* aux = (*cabeca);
        //navega partindo da cabeça até chegar NULL
        printf("[");
        do {
            printf("%d", aux->val);
            aux = aux->prox;
            if (aux != NULL) {
                printf(", ");
            }
        } while (aux != NULL);
        printf("]");
    }
    else {
        printf("A lista está vazia!");
    }
}
