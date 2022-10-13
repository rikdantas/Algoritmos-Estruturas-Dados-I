#include <iostream>

using namespace std;

bool busca(int v[], int val, int ini, int fim){
    if(ini < fim){
        return false;
    }

    int meio = (ini+fim)/2;

    if(v[meio] == val){
        return true;
    }
    else if(v[meio]>val){
        return busca(v, val, meio+1, fim);
    }
    else{
        return busca(v, val, ini, meio-1);
    }
}

int main(){
    int i, aux = 100;
    int array[100];

    for(i = 0; i < 100; i++){
        array[i] = aux;
        aux++;
    }

    if(busca(array, 51, 100, 1)){
        cout << "1" << endl;
    }
    else{
        cout << "0" << endl;
    }

    return 0;
}
