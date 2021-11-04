#ifndef _CELL_H_
#define _CELL_H_
#include<iostream>
template<class T, const int n_Fil, const int n_Col>
class ME;

template<class T>
class Cell
{
    public:
        int m_Fil;
        int m_Col;
        Cell<T> * m_Head;
        Cell<T> * m_SigFil;
        Cell<T> * m_SigCol; 
        T  m_Dato; 
    public:
        Cell();
        Cell(int,int,T);
        Cell<T>* get_Head() {return m_Head;}
        Cell<T>* get_SF()   {return m_SigFil;}
        Cell<T>* get_SC()   {return m_SigCol;}
        int get_Fil() {return m_Fil;}
        int get_Col() {return m_Col;}
        T get_Dato()  {return m_Dato;}
        void set_SF(Cell<T>* Cl)    {m_SigFil = Cl; return;}
        void set_SC(Cell<T>* Cl)    {m_SigCol = Cl; return;}
        void set_Head(Cell<T>* Cl)  {m_Head   = Cl; return;}
        void set_Fil(int n) { m_Fil = n; return;}
        void set_Col(int n) { m_Col = n; return;}
        void set_Dato(T d)  { m_Dato = d; return;};
};

template <class T>
Cell<T>::Cell(){
    m_Fil = 0;
    m_Col = 0;
    m_Head = nullptr;
    m_SigCol = nullptr;
    m_SigFil = nullptr;
}

template <class T>
Cell<T>::Cell(int f, int c, T dato){
    m_Fil = f;
    m_Col = c;
    m_Head = nullptr;
    m_SigCol = nullptr;
    m_SigFil = nullptr;
    m_Dato = dato;
}

#endif