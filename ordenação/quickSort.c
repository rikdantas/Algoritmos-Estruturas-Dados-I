#include <stdio.h>
#include <stdlib.h>

void imprimeVetor(int *v, int tamanho){
  for(int i = 0; i < tamanho; i++){
    printf("%d", v[i]);
    printf(" , ");
  }
  printf("\n");
}

void troca(int *v, int i, int j){
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

void quickSort(int *v, int ini, int fim){
    if(fim>ini){
        int indexPivo = particiona(v,ini,fim);
        quickSort(v,ini,indexPivo-1);
        quickSort(v,indexPivo+1,fim);
    }
}

int particiona(int *v, int ini, int fim){
    int pIndex = ini;
    int pivo = v[fim-1];
    for(int i = ini; i < fim; i++){
        if(v[i] <= pivo){
            troca(v,i,pIndex);
            pIndex++;
        }
    }
    troca(v,pIndex,fim);
    return pIndex;
}

int main(void) {
  int tamanhoVetor = 10;
  int *v = (int*)calloc(tamanhoVetor, sizeof(int));
  //Preenchendo vetor
  for(int i = 0; i < tamanhoVetor;i++){
    v[i]=rand()%100;
  }



  imprimeVetor(v,tamanhoVetor);
  quickSort(v,0,tamanhoVetor-1);
  imprimeVetor(v,tamanhoVetor);
  return 0;
}

