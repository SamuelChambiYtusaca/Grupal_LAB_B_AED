#ifndef _Nodo_H_
#define _Nodo_H_
#include<iostream>


template<class T>
class Nodo
{
    public:
        int m_Fil;
        int m_Col;
        Nodo<T> * m_Head;
        Nodo<T> * m_SigFil;
        Nodo<T> * m_SigCol; 
        T  m_Dato; 
    public:
        Nodo();
        Nodo(int,int,T);
        Nodo<T>* get_Head() {return m_Head;}
        Nodo<T>* get_SF()   {return m_SigFil;}
        Nodo<T>* get_SC()   {return m_SigCol;}
        int get_Fil() {return m_Fil;}
        int get_Col() {return m_Col;}
        T get_Dato()  {return m_Dato;}
        void set_SF(Nodo<T>* Cl)    {m_SigFil = Cl; return;}
        void set_SC(Nodo<T>* Cl)    {m_SigCol = Cl; return;}
        void set_Head(Nodo<T>* Cl)  {m_Head   = Cl; return;}
        void set_Fil(int n) { m_Fil = n; return;}
        void set_Col(int n) { m_Col = n; return;}
        void set_Dato(T d)  { m_Dato = d; return;};
};

template <class T>
Nodo<T>::Nodo(){
    m_Fil = 0;
    m_Col = 0;
    m_Head = nullptr;
    m_SigCol = nullptr;
    m_SigFil = nullptr;
}

template <class T>
Nodo<T>::Nodo(int f, int c, T dato){
    m_Fil = f;
    m_Col = c;
    m_Head = nullptr;
    m_SigCol = nullptr;
    m_SigFil = nullptr;
    m_Dato = dato;
}

#endif
