#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"

int main(){
    struct arraylist* lista = inicializar(1);
    inserirElementoNoFim(lista,2);
    inserirElementoNoFim(lista,2);
    inserirElementoNoFim(lista,4);
    inserirElementoNoFim(lista,5);
    inserirElementoEmPosicao(lista,10,4);
    exibirLista(lista);
    return 0;
}
