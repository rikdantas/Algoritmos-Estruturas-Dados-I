#include <stdio.h>
#include <stdlib.h>

void imprimeVetor(int *v, int tamanho){
  for(int i = 0; i < tamanho; i++){
    printf("%d", v[i]);
    printf(" , ");
  }
  printf("\n");
}

void insertionSortIP(int *v, int tamanho){
  for(int i = 1; i < tamanho; i++){
    int valor = v[i];
    int j;
    for(j = i; j > 0 && v[j-1] > valor; j--){
        v[j] = v[j-1];
    }
    v[j] = valor;
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
  insertionSortIP(v,tamanhoVetor);
  imprimeVetor(v,tamanhoVetor);

  return 0;
}
