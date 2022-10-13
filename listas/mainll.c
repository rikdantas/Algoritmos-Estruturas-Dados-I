#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

int main(){
    struct linkedlist* lista = inicializar();
    inserirElementoNoFim(lista,5);
    inserirElementoNoFim(lista,4);
    inserirElementoNoFim(lista,3);
    inserirElementoNoInicio(lista,1);
    inserirElementoEmPosicao(lista,20,2);
    return 0;
}
