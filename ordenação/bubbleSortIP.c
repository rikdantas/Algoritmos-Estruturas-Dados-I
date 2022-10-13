#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void bubbleSortIP(int *v, int tamanho){
  for(int varredura = 0; varredura < tamanho-1;varredura++){
    bool trocou = false;
    for(int i = 0; i<tamanho-varredura-1; i++){
      if(v[i] > v[i+1]){
        troca(v,i,(i+1));
        trocou = true;
      }
    }
    if(trocou==false){
        return;
    }
  }
}

int main(void) {
  int tamanhoVetor = 10;
  int *v = (int*)calloc(tamanhoVetor, sizeof(int));
  //Preenchendo vetor
  for(int i = 0; i < tamanhoVetor;i++){
    v[i]=rand()%100;
  }



  imprimeVetor(v,tamanhoVetor);
  bubbleSortIP(v,tamanhoVetor);
  imprimeVetor(v,tamanhoVetor);
  return 0;
}
