#ifndef _DispersaLista1_H_
#define _DispersaLista1_H_
#include "Nodo.h"
#include <iostream>
using namespace std;
template <class T>
class DispersaLista1{
    private:
        Nodo<T>  *  m_Fil[n_Fil]; 
        Nodo<T>  *  m_Col[n_Col]; 
        Nodo<T> * root;    
    public:
        DispersaLista1(int,int);
        void Insert(T,int,int);
        Nodo<T> buscar(int,int);
        void ligarFila(Nodo<T> * );
        void ligarColumna(Nodo<T> *);
        void desligarFila(Nodo<T>*);
        void desligarColumna(Nodo<T>*);
        void mostrarMayorFila();
        //Tarea
        sumaColumnas();
        mostrarParesFilas();
        eliminarDato(int,int);
        eliminarPares();
        eliminarMayor();
        eliminarMayorFila();
};
template <class T>
DispersaLista1<T>::DispersaLista1(int n, int m){
    Nodo<T> *p,*q,*ant;
    int may;
    if(n > m){
        may = n;
    }
    else{
        may = m;
    }
    root = new Nodo<T>(n,m,may);
    ant = root;
    for(int i=1;i<may;i++){
        q = new Nodo<T>(i,i);
        q->set_SF(q);
        q->set_SC(q);
        ant->set_Head(q);
        ant = q;
    }
    ant->set_Head(root);
}

template <class T> 
void DispersaLista1<T>::Insert(T d, int f, int c){
    Nodo<T> *p,*q;
    int s;
    p = buscar(f,c);
    if(!p){
        q = new Nodo<T>(f,c,d);
        ligarFila(q);
        ligarColumna(q);
    }
    else{
        s= p->get_Dato() + d;
        if(s==0){
            desligarFila(p);
            desligarColumna(p);
            libere(p);
        }
        else{
            p->set_Dato(s);
        }
    }
}

template <class T> 
Nodo<T> DispersaLista1<T>::buscar(int f,int c){
    Nodo<T> *p,*q,*res;
    res= nullptr;
    p = root->get_Head();
    while(p->get_Fil() < f){
        p = p->get_Head();
    }
    q = p->get_SF();
    while(q!=p && q->get_Col()<c){
        q =q->get_SF();
    }
    if(q!=p && (q->get_Fil()==f) && (q->get_Col()==c)){
        res = q;
    }
    return res;
}

template <class T>
void DispersaLista1<T>::ligarFila(Nodo<T> *q){
    Nodo<T> *p,*z,*ant;
    p = root->get_Head();
    while(p->get_Fil() < q->get_Fil()){
        p = p->get_Head();
    }
    z = p->get_SF();
    ant = p;
    while(z!=p && (z->get_Col() < q->get_Col())){
        ant = z;
        z = z->get_SF();
    }
    if(z!=p && (z->get_Col() > q->get_Col())){
        ant->set_SF(q);
        q->set_SF(z);
    }
}

template <class T>
void DispersaLista1<T>::ligarColumna(Nodo<T> *q){
    Nodo<T> *p,*z,*ant;
    p = root->get_Head();
    while(p->get_Col() < q->get_Col()){
        p = p->get_Head();
    }
    z = p->get_SC();
    ant = p;
    while(z!=p && (z->get_Fil() < q->get_Fil())){
        ant =z;
        z = z->get_SF();
    }
    if(z!=p && (z->get_Fil() > q->get_Fil())){
        ant->set_SC(q);
        q->set_SC(z);
    }
}

template <class T>
void DispersaLista1<T>::desligarFila(Nodo<T> *q){
    Nodo<T> *p,*antF;
    p = q->get_SF();
    antF = p;
    while(p!=q){
        antF = p;
        p = p->get_SF();
    }
    antF->set_SF(q->get_SF());
}

template <class T>
void DispersaLista1<T>::desligarColumna(Nodo<T> *q){
    Nodo<T> *p,*antC;
    p = q->get_SC();
    antC = p;
    while(p!=q){
        antC = p;
        p = p->get_SC();
    }
    antC->set_SC(q->get_SC());
}

template <class T>
void DispersaLista1<T>::mostrarMayorFila(){
    Nodo<T> *p,*q;
    p = root->get_Head();
    while(p!=root){
        if(p->get_Fil() <= root->get_Fil()){
            q = p->get_SF();
            if(p == q){
                std::cout<<"la fila: "<< p->get_Fil()<<" esta vacia\n";
            }
            else{
                q = p->get_SF();
                int may = q->get_Dato();
                while(q!=p){
                    if(q->get_Dato() > may){
                        may = q->get_Dato();
                    }
                    q = p->get_SF();
                }
                std::cout<<"el dato mayor de la fila "<<p->get_Fil()<<": "<<may;
            }
        }
        p = p->get_Head();
    }
}



#endif
