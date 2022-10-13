#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

struct arraystack {
    int* elementos;
    int tamanho;    //tam do array
    int qtdade;     //qtdade de elementos no array
};

struct arraystack* inicializar(int tamArray){
    struct arraystack* pilha = (struct arraystack*)malloc(sizeof(struct arraystack));

    pilha -> elementos = (int*)calloc(tamArray, sizeof(int));
    pilha -> tamanho = tamArray;
    pilha -> qtdade = 0;

    return pilha;
}

void duplicarCapacidade(struct arraystack* pilha){
    pilha -> elementos = (int*)realloc(pilha -> elementos, 2 * pilha -> tamanho*sizeof(int));
    pilha -> tamanho = 2 * pilha -> tamanho;
}

//se a pilha estiver nula, instancie a pilha com tamanho 10
//por causa da possibilidade de instanciacao usamos struct arraystack**
//se a pilha encher, duplique a capacidade do array
void empilhar(struct arraystack** pilha, int valor){
    if((*pilha) == NULL){
        (*pilha) = inicializar(10);
    }
    else if((*pilha)->tamanho == (*pilha)->qtdade){
        duplicarCapacidade(*pilha);
    }
    (*pilha)->elementos[(*pilha)->qtdade] = valor;
    (*pilha)->qtdade++;
}

//retornar true se a pilha for nula ou vazia
bool vazia(struct arraystack* pilha) {
    if(pilha == NULL || pilha->qtdade == 0){
        return true;
    }
    else{
        return false;
    }
}

//decrementar qtdade se a pilha não estiver nula ou vazia
void desempilhar(struct arraystack* pilha){
    if(pilha != NULL && pilha->qtdade > 0){
        pilha->qtdade--;
    }
    else{
        return;
    }
}

//retorne a constante INT_MIN se a pilha for nula ou vazia
int topo(struct arraystack* pilha){
    if(pilha == NULL || pilha->qtdade == 0){
        return INT_MIN;
    }
    else{
        int topo = pilha->elementos[pilha->qtdade-1];
        return topo;
    }
}

//retorne a constante INT_MIN se a pilha for nula ou vazia
int desempilharRetornando(struct arraystack* pilha){
    if(pilha == NULL || pilha->qtdade == 0){
        return INT_MIN;
    }
    else{
        int top = topo(pilha);
        pilha -> qtdade--;
        return top;
    }
}

void imprimir(struct arraystack* pilha){
    printf("_\n");
    for(int i = pilha->qtdade - 1; i >= 0; i--){
        printf("%d\n",pilha->elementos[i]);
    }
    printf("_\n\n");
}
