#include<bits/stdc++.h>
#include "Double_Linked_List.h"
using namespace std;
int main(){
    /*Funcionalidad*/
    Double_Linked_List<int> L2;
    L2.push_back(1); 
    L2.push_back(651); 
    L2.push_back(564); 
    L2.push_back(-41); 
    L2.push_back(56);
    L2.push_back(5146);
    L2.ordenarAscendente();
    L2.print();
    L2.ordenarDescendente();
    L2.print();
    L2.Begin();
    cout << "Dato al inicio de la lista: " << L2.getDato() << "\n";
    L2.Next();
    cout << "Dato siguiente: " << L2.getDato() << "\n";
    L2.Last();
    cout << "Dato al final de la lista: " << L2.getDato() << "\n";
    L2.Previus();
    cout << "Dato al anterior: " << L2.getDato() << "\n";
    cout << "Cantidad de #N pares en la lista: " << L2.numPares() << "\n";
    L2.printBN();
    L2.printLP();
    return 1;
}