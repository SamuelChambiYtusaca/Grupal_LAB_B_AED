#ifndef _D_LINKED_LIST_
#define _D_LINKED_LIST_
#include "NodoD.h"
#include "iostream"
using namespace std;
template<typename T>
class Double_Linked_List{
    private:
        NodoD<T> *head;
        int size;
    public:
        Double_Linked_List();
        Double_Linked_List(const Double_Linked_List<T> &);
        Double_Linked_List(Double_Linked_List<T> &&);
        void push_back(T);
        void print();
        ~Double_Linked_List();
};

template<typename T>
Double_Linked_List<T>::Double_Linked_List(){
    this->head = nullptr;
    this->size = 0;
}

template<typename T>
Double_Linked_List<T>::Double_Linked_List(const Double_Linked_List<T> &p){
    this->head = nullptr;
    this->size = 0;
    NodoD<T> *aux = p.head; 
    while(aux){
        this->push_back(aux->get_dato());
        aux = aux->get_sig();
    }
}

template<typename T>
Double_Linked_List<T>::Double_Linked_List(Double_Linked_List<T> &&p){
    this->head = p.head;
    this->size = p.size;
    p.head = nullptr;
    p.size = 0;
}

template<typename T>
void Double_Linked_List<T>::push_back(T dato){
    NodoD<T> *nuevo = new NodoD<T>(dato);
    if(!this->head){
        this->head = nuevo;
    }else{
        NodoD<T> *aux = this->head;
        while(aux->get_sig()){
            aux = aux->get_sig();
        }
        aux->set_sig(nuevo);
        nuevo->set_ant(aux);
    }
    size++;
    return;
}

template<typename T>
void Double_Linked_List<T>::print(){
    NodoD<T> *ptr = head;
    if(!head){
        cout << "La lista esta vacia.\n";
    }else{
        int i = 1;
        while(i<this->size){
            cout<<"[" << i << ":" << ptr->get_dato() << "]->";
            ptr = ptr->get_sig();
            i++; 
        }
        cout << "[" << i << ":" << ptr->get_dato() << "]\n";
        return;
    }
}

template<typename T>
Double_Linked_List<T>::~Double_Linked_List(){

}
#endif