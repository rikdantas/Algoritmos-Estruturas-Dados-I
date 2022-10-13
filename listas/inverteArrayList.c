#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct arraylist{
	int* vetor;
	int tamanho;
	int qtdade;
};

struct arraylist* inicializar(int capacidade){

    struct arraylist* lista = (struct arraylist*)malloc(sizeof(struct arraylist));
    lista -> vetor = (int*)calloc(capacidade, sizeof(int));
    lista -> qtdade = 0;
    lista -> tamanho = capacidade;

    return lista;
}

void inverteArray(struct arraylist* lista){
	int aux = 0;
	if((lista -> tamanho % 2) == 0){
		for(int i=0; i<(lista -> tamanho)/2; i++){
			aux = lista -> vetor[i];
			lista -> vetor[i] = lista -> vetor[lista -> tamanho-1-i];
			lista -> vetor[lista -> tamanho-1-i] = aux;
		}
	}else{
		int tamanho = lista -> tamanho - 1;
		for(int i=0; i<tamanho/2; i++){
			aux = lista -> vetor[i];
			lista -> vetor[i] = lista -> vetor[lista -> tamanho-1-i];
			lista -> vetor[lista -> tamanho-1-i] = aux;
		}
	}
}

int main(){

	int capacidade = 100;
	struct arraylist* lista = inicializar(capacidade);

	for(int i=0; i<capacidade; i++){
		lista -> vetor[i] = i;
	}

	for(int i=0; i<capacidade; i++){
		printf("%d", lista -> vetor[i]);
	}

	inverteArray(lista);

	printf("\n");

	for(int i=0; i<capacidade; i++){
		printf("%d", lista -> vetor[i]);
	}

	return 0;
}
