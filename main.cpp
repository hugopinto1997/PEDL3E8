#include <iostream>
using namespace std;

struct nodo{
    int dato;
    nodo *sig;
};

nodo *crearNodo(int dato){
    nodo *nuevo_nodo = new nodo();
    nuevo_nodo->sig=NULL;
    nuevo_nodo->dato = dato;
    return nuevo_nodo;
}

void insertar(nodo *&pInicio, nodo *&nuevo){
    if(pInicio==NULL){
        pInicio=nuevo;
    } else{
        insertar(pInicio->sig,nuevo);
    }
}

void mostrarLista(nodo *pInicio){
    if(pInicio!=NULL){
        cout<<pInicio->dato<<"->";
        mostrarLista(pInicio->sig);
    }
}



void toBinary(int n, nodo *&pInicio){
    nodo *aux;
    if(n<1){
        return;
    }else{
        toBinary(n/2,pInicio);
        if(n%2==0){
            aux = crearNodo(0);
            insertar(pInicio, aux);
        }else{
            aux = crearNodo(1);
            insertar(pInicio, aux);
        }
    }
}


int main() {
    nodo *pInicio=NULL;

    int numero;
    cout<<"Ingrese el numero: ";
    cin>>numero;
    toBinary(numero,pInicio);
    cout<<endl;
    mostrarLista(pInicio);

    return 0;
}