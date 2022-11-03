#include <stdio.h>
#include <stdlib.h>

void imprimeVetor(int *v, int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("%d", v[i]);
        printf(" , ");
    }
    printf("\n\n");
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
    for(int i = 0; i < tamanho; i++){
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

    for(int i = 0; i < tamanho; i++){
        int valor = v[i];
        contagem[valor - menor]++;
    }

    //Soma cumulativa
    for(int i = 1; i < tamanhoContagem; i++){
        contagem[i] = contagem[i] + contagem[i-1];
    }

    //Posição final dos elementos
    int *ord = (int*)calloc(tamanho, sizeof(int));
    for(int i = tamanho-1; i>=0;i--){
        int iOrd = contagem[v[i]-menor]-1;
        ord[iOrd] = v[i];
        contagem[v[i]-menor]--;
    }

    return ord;
}

int main(void) {
    int tamanhoVetor = 10;
    int *v = (int*)calloc(tamanhoVetor, sizeof(int));
    //Preenchendo vetor
    for(int i = 0; i < tamanhoVetor;i++){
        v[i]=rand()%100;
    }
    v[2]=3;
    v[4]=3;
    v[6]=3;
    v[8]=3;
    v[3] = 5;
    v[5] = 5;

    imprimeVetor(v,tamanhoVetor);
    countingSort(v,tamanhoVetor);
    imprimeVetor(countingSort(v,tamanhoVetor),tamanhoVetor);

    return 0;
}
