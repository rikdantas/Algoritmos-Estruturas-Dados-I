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

void bubbleSortIP(int *v, int tamanho){
  //incompleto
  for(int varredura = 1; varredura <= tamanho-1;varredura++){
    bool trocou = false;
    for(int i = 0; j<tamanho; j++){
      if(v[j] < v[iMenor]){
        iMenor = j;
      }
    }
    aux = v[i];
    v[i] = v[iMenor];
    v[iMenor] = aux;
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
