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
        double maximoIterativa();
        double maximoRecursiva(NodoD<T>*,double );
        void maximoRecursiva();
        void printRecursivaInicioFin(NodoD<T>*);
        void printRecursivaInicioFin();
        void printRecursivaFinInicio(NodoD<T>*);
        void printRecursivaFinInicio();
        void printIterativaFinInicio();
        int numPares();
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
double Double_Linked_List<T>::maximoIterativa(){
    NodoD<T> *ptr = head;
    int tam = size;
    double max = 0;
    if(head != nullptr){
        for(int i=0; i<tam; i++){
            if((ptr->get_dato()) > max){
                max = ptr->get_dato();
            }
            ptr = ptr->get_sig();
        }
    }
    return max;
}

template<typename T>
double Double_Linked_List<T>::maximoRecursiva(NodoD<T> *nod,double max){
    if(nod == nullptr){
        return max;
    }
    else{
        if((nod->get_dato())>= max){
            max = nod->get_dato();
        }
        return maximoRecursiva(nod->get_sig(),max);
    }
}

template<typename T>
void Double_Linked_List<T>::maximoRecursiva(){
    NodoD<T> *tmp = head;
    double max=0;
    std::cout<<maximoRecursiva(tmp,max);
}

template<typename T>
void Double_Linked_List<T>::printRecursivaInicioFin(NodoD<T> *nod){
    if(nod->get_sig() == nullptr){
        std::cout<<nod->get_dato();
    }
    else{
        std::cout<<nod->get_dato()<<" -> ";
        printRecursivaInicioFin(nod->get_sig());
    }
}

template<typename T>
void Double_Linked_List<T>::printRecursivaInicioFin(){
    NodoD<T> *tmp = head;
    printRecursivaInicioFin(tmp);
}

template<typename T>
void Double_Linked_List<T>::printRecursivaFinInicio(NodoD<T> *nod){
    if(nod->get_ant() == nullptr){
        printRecursivaFinInicio(nod->get_sig());
        std::cout<<nod->get_dato();
    }
    else{
        if((nod->get_sig()) != nullptr){
            printRecursivaFinInicio(nod->get_sig());
            std::cout<<nod->get_dato()<<" -> ";
        }
        else{
            std::cout<<nod->get_dato()<<" -> ";
        }
    }
}

template<typename T>
void Double_Linked_List<T>::printRecursivaFinInicio(){
    NodoD<T> *tmp = head;
    printRecursivaFinInicio(tmp);
}

template<typename T>
void Double_Linked_List<T>::printIterativaFinInicio(){
    NodoD<T> *ptr = head;
    for(int i=1; i<size; i++){
        ptr = ptr->get_sig();
    }
    for(int i=0; i<size; i++){
        if((ptr->get_ant()) == nullptr){
            std::cout<<ptr->get_dato();
        }
        else{
            std::cout<<ptr->get_dato()<<" -> ";
        }
        ptr = ptr->get_ant();
    }
}

template<typename T>
int Double_Linked_List<T>::numPares(){
    NodoD<T> *tmp = head;
    int cantidad = 0;
    for(int i=0;i<size;i++){
        if((tmp->get_dato())%2 == 0){
            cantidad++;
        }
        tmp = tmp->get_sig();
    }
    return cantidad;
}

template<typename T>
Double_Linked_List<T>::~Double_Linked_List(){

}
#endif