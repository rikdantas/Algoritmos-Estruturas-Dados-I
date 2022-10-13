#include <iostream>

using namespace std;

void inverteArray(int v[], int tamanho){
    int aux = 0;
    int j;

    for(j = 0; j < tamanho/2; j++){
        aux = v[j];
        v[j] = v[tamanho-1-j];
        v[tamanho-1-j] = aux;
    }
}

int main(){
    int i, aux = 1, tamArray;
    int array[25];

    for(i = 0; i < 25; i++){
        array[i] = aux;
        aux++;
    }
    tamArray = sizeof(array)/4;

    for(i = 0; i < 25; i++){
        cout<<array[i]<<" ";
    }
    cout << endl;
    inverteArray(array,tamArray);
    for(i = 0; i < 25; i++){
        cout<<array[i]<<" ";
    }
    return 0;
}

