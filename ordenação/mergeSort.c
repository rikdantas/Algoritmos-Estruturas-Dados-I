#include <stdio.h>
#include <stdlib.h>

void imprimeVetor(int *v, int tamanho){
  for(int i = 0; i < tamanho; i++){
    printf("%d", v[i]);
    printf(" , ");
  }
  printf("\n");
}

void merge(int *v, int tamV, int *e, int tamE, int *d, int tamD){
    int indexV=0;
    int indexE=0;
    int indexD=0;
    while(indexE < tamE && indexD < tamD){
        if(e[indexE] <= d[indexD]){
            v[indexV] = e[indexE];
            indexE++;
        }
        else{
            v[indexV] = d[indexD];
            indexD++;
        }
        indexV++;
    }
    while(indexE < tamE){
        v[indexV] = e[indexE];
        indexV++;
        indexE++;
    }
    while(indexD < tamD){
        v[indexV] = d[indexD];
        indexV++;
        indexD++;
    }
}

void mergeSort(int *v, int tamanho){
  if(tamanho > 1){
    int meio = tamanho/2;
    int tamV1 = meio;
    int *V1 = (int*)malloc(tamV1*sizeof(int));
    //Preenchendo V1
    for(int i = 0; i < meio;i++){
        V1[i] = v[i];
    }

    int tamV2 = tamanho - tamV1;
    int *V2 = (int*)malloc(tamV2*sizeof(int));
    //PreenchendoV2
    for(int i = meio; i<tamanho;i++){
        V2[i-meio] = v[i];
    }

    mergeSort(V1, tamV1);
    mergeSort(V2, tamV2);
    merge(v,tamanho,V1,tamV1,V2,tamV2);

    free(V1);
    free(V2);
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
  mergeSort(v,tamanhoVetor);
  imprimeVetor(v,tamanhoVetor);
  return 0;
}
