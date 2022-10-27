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

int* countingSort(int *v, int tamanho){
    //Descobrindo menor e maior valor
    int menor = v[0];
    int maior = v[0];
    for(int i = 0; i < tam; i++){
        if(v[i] > maior){
            maior = v[i];
        }
        if(v[i] < menor){
            menor = v[i];
        }
    }

    //Instanciando vetor contagem
    int tamanhoContagem = maior - menor + 1;
    int *contagem = (int*)calloc(tamanhoContagem,sizeof(int));

    for(int i = 0; i < tam; i++){
        int valor = v[i];
        contagem[valor - menor]++;
    }

    //Soma cumulativa
    for(int i = 1; i < tamanhoContagem; i++){
        contagem[i] = contagem[i] + contagem[i-1];
    }


    return ;
}

int main(void) {
  int tamanhoVetor = 10;
  int *v = (int*)calloc(tamanhoVetor, sizeof(int));
  //Preenchendo vetor
  for(int i = 0; i < tamanhoVetor;i++){
    v[i]=rand()%100;
  }



  imprimeVetor(v,tamanhoVetor);
  //countingSort(v,tamanhoVetor);
  imprimeVetor(v,tamanhoVetor);
  return 0;
}
