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

void selectionSortIP(int *v, int tamanho){
  for(int i = 0; i <(tamanho-1);i++){
    int iMenor = i;
    for(int j = i+1; j<tamanho; j++){
      if(v[j] < v[iMenor]){
        iMenor = j;
      }
    }
    troca(v,i,iMenor);
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
  selectionSortIP(v,tamanhoVetor);
  imprimeVetor(v,tamanhoVetor);
  return 0;
}
