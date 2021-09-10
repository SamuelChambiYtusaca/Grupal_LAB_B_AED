#ifndef _NODE_D_
#define _NODE_D_
template<typename T>
class NodoD{
    private:
        T dato;
        NodoD<T> *anterior;
        NodoD<T> *siguiente;
    public:
        NodoD();
        NodoD(T dato);
        NodoD<T>* get_sig();
        NodoD<T>* get_ant();
        void set_sig(NodoD<T>*);
        void set_ant(NodoD<T>*);
        T get_dato();
        void set_dato(T);
        ~NodoD();
};
template <typename T>
NodoD<T>::NodoD(){
    this->dato = NULL;
    this->anterior = nullptr;
    this->siguiente = nullptr;
}

template <typename T>
NodoD<T>::NodoD(T dato){
    this->dato = dato;
    this->anterior = nullptr;
    this->siguiente = nullptr;
}

template <typename T>
NodoD<T>* NodoD<T>::get_sig(){
    return this->siguiente;
}

template <typename T>
NodoD<T>* NodoD<T>::get_ant(){
    return this->anterior;
}

template <typename T>
void NodoD<T>::set_sig(NodoD<T>* nuevo){
    this->siguiente = nuevo;
    return;
}

template <typename T>
void NodoD<T>::set_ant(NodoD<T>* nuevo){
    this->anterior = nuevo;
    return;
}

template<typename T>
T NodoD<T>::get_dato(){
    return this->dato;   
}

template<typename T>
void NodoD<T>::set_dato(T dato){
    this->dato = dato;
    return;
}

template <typename T>
NodoD<T>::~NodoD(){
}




#endif