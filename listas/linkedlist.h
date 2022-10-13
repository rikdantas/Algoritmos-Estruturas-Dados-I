#include <stdlib.h>
#include <stdio.h>

struct no {
    int val;
    struct no* prox;
};

struct linkedlist {
    struct no* cabeca;
    int qtdade;
};

struct linkedlist* inicializar() {
    struct linkedlist* lista = (struct linkedlist*)malloc(sizeof(struct linkedlist));

    lista -> cabeca = NULL;
    lista -> qtdade = 0;

    return lista;
}

struct no* alocarNovoNo(int valor) {
    struct no* novoNo = (struct no*)malloc(sizeof(struct no));
    novoNo -> val = valor;
    novoNo -> prox = NULL;

    return novoNo;
}

void inserirElementoNoFim(struct linkedlist* lista, int valor) {
    struct no* novoNo = alocarNovoNo(valor);

    //Dois casos principais: array com elementos e array sem elementos;
    //Primeiro: array com pelo menos um elemento

    if (lista->cabeca != NULL) {
        struct no* aux = lista->cabeca;

        while(aux->prox != NULL){
            aux = aux->prox;
        }

        aux->prox = novoNo;

    }

    //Segundo: array sem nenhum elemento

    else{
        lista -> cabeca = novoNo;
    }

    lista -> qtdade++;
}

void inserirElementoNoInicio(struct linkedlist* lista, int valor) {
    struct no* novoNo = alocarNovoNo(valor);

    if(lista -> cabeca == NULL){
        lista -> cabeca = novoNo;
    }
    else {
        novoNo -> prox = lista -> cabeca;
        lista -> cabeca = novoNo;
    }
    lista -> qtdade++;
}


void inserirElementoEmPosicao(struct linkedlist* lista, int valor, int posicao) {
    if(posicao >= 0 && posicao <= lista->qtdade){

        if(posicao == lista->qtdade){
            inserirElementoNoFim(lista,valor);
        }
        else if(posicao == 0){
            inserirElementoNoInicio(lista,valor);
        }
        else{
            struct no* novoNo = alocarNovoNo(valor);
            struct no* aux = lista -> cabeca;

            for(int i = 0; i < posicao - 1;i++){
                aux = aux->prox;
            }
            novoNo->prox = aux->prox;
            aux->prox = novoNo;

            lista->qtdade++;
        }

    }
}

int obterElementoEmPosicao(struct linkedlist* lista, int posicao) {
    //verificando se posicao eh valida
    if(posicao >= 0 && posicao < lista->qtdade){
        struct no* aux = lista->cabeca;

        for(int i = 0; i < posicao; i++){
            aux = aux->prox;
        }
        return aux->val;
    }
}

void removerElementoEmPosicao(struct linkedlist* lista, int posicao) {
    //verificando se posicao eh valida
    if(posicao >= 0 && posicao < lista->qtdade){
        struct no* aux = lista->cabeca;

        if(posicao == 0){
            lista->cabeca = aux->prox;
            free(aux);
            lista->qtdade--;
        }
        else{
            for(int i = 0; i < posicao; i++){
                aux = aux->prox;
            }
            struct no* aux2 = aux -> prox;
            aux -> prox = aux2 -> prox;
            free(aux2);
            lista->qtdade--;
        }
    }
}

void imprimirLista(struct linkedlist* lista) {
    //usamos o aux para percorrer a lista
    if (lista->cabeca != NULL) {
        struct no* aux = lista->cabeca;
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
