#ifndef _D_LINKED_LIST_
#define _D_LINKED_LIST_
#include "NodoD.h"
#include "iostream"
using namespace std;
template<typename T>
class Double_Linked_List{
    private:
        NodoD<T> *head;
        NodoD<T> *actual;
        int size;
    public:
        Double_Linked_List();
        Double_Linked_List(const Double_Linked_List<T> &);
        Double_Linked_List(Double_Linked_List<T> &&);
        void push_back(T);
        void pop_back();
        void print();
        /*Funciones solicitadas*/
        double maximoIterativa();
        double maximoRecursiva(NodoD<T>*,double );
        void maximoRecursiva();
        void printRecursivaInicioFin(NodoD<T>*);
        void printRecursivaInicioFin();
        void printRecursivaFinInicio(NodoD<T>*);
        void printRecursivaFinInicio();
        void printIterativaFinInicio();
        void ordenarAscendente();
        void ordenarDescendente();
        void Begin();
        void Last();
        void Next();
        void Previus();
        T getDato();
        void printBN();
        void printLP();
        int numPares();
        ~Double_Linked_List();
};

template<typename T>
Double_Linked_List<T>::Double_Linked_List(){
    this->head = nullptr;
    this->size = 0;
    this->actual = nullptr; 
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
    this->actual = nullptr;
}

template<typename T>
Double_Linked_List<T>::Double_Linked_List(Double_Linked_List<T> &&p){
    this->head = p.head;
    this->size = p.size;
    this->actual = nullptr;
    p.head = nullptr;
    p.size = 0;
    p.actual = nullptr;
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
void Double_Linked_List<T>::pop_back(){
    if(!this->head){
        return;
    }else if(this->size == 1){
        delete head;
        this->head = nullptr;
    }
    else{
        NodoD<T> *aux = this->head;
        while(aux->get_sig()){
            aux = aux->get_sig();
        }
        aux->get_ant()->set_sig(nullptr);
        delete aux;
    }
    size--;
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
void Double_Linked_List<T>::ordenarAscendente(){
	NodoD<T> *aux1 = this->head, *aux2;
	T temp;
	while(aux1->get_sig()){
		aux2 = aux1->get_sig();
		while(aux2){
			if(aux2->get_dato() < aux1->get_dato()){
				temp = aux1->get_dato();
				aux1->set_dato(aux2->get_dato());
				aux2->set_dato(temp);
			}
			aux2 = aux2->get_sig(); 
		}
		aux1 = aux1->get_sig();
	}
	
}

template<typename T>
void Double_Linked_List<T>::ordenarDescendente(){
	NodoD<T> *aux1 = this->head, *aux2;
	T temp;
	while(aux1->get_sig()){
		aux2 = aux1->get_sig();
		while(aux2){
			if(aux2->get_dato() > aux1->get_dato()){
				temp = aux1->get_dato();
				aux1->set_dato(aux2->get_dato());
				aux2->set_dato(temp);
			}
			aux2 = aux2->get_sig(); 
		}
		aux1 = aux1->get_sig();
	}
	
}

template<typename T>
void Double_Linked_List<T>::Begin(){
    if(this->head)
        this->actual = this->head;
    return;
}
 
template<typename T>
void Double_Linked_List<T>::Last(){
    if(this->head){
        this->actual = this->head;
        while(actual->get_sig()){
            actual = actual->get_sig();
        }
    }
    return;
}

template<typename T>
void Double_Linked_List<T>::Next(){
    if(this->actual){
        this->actual = this->actual->get_sig();
    }else{
        this->Begin();
    }
    return;
}

template<typename T>
void Double_Linked_List<T>::Previus(){
    if(this->actual){
        this->actual = this->actual->get_ant();
    }
    return;
}

template<typename T>
T Double_Linked_List<T>::getDato(){
    if(this->actual)
        return this->actual->get_dato();
    else
        return NULL;
}
template<typename T>
void Double_Linked_List<T>::printBN(){
    this->Begin();
    if(!this->actual){
        cout << "La lista esta vacia.\n";
    }else{
        int i = 1;
        while(i<this->size){
            cout<<"<" << i << ":" << this->getDato() << ">->";
            this->Next();
            i++; 
        }
        cout << "<" << i << ":" << this->getDato() << ">\n";
        return;
    }
}

template<typename T>
void Double_Linked_List<T>::printLP(){
    this->Last();
    if(!this->actual){
        cout << "La lista esta vacia.\n";
    }else{
        int i = this->size;
        while(i>1){
            cout<<"{" << i << ":" << this->getDato() << "}->";
            this->Previus();
            i--; 
        }
        cout << "{" << i << ":" << this->getDato() << "}\n";
        return;
    }
}
template<typename T>
Double_Linked_List<T>::~Double_Linked_List(){
    while(this->size){
        this->pop_back();
    }
    delete head;
    delete actual;
}
#endif
