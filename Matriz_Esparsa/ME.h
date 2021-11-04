#ifndef _ME_H_
#define _ME_H_
#include "Cell.h"
#include <iostream>
using namespace std;
template<class T, const int n_Fil=10, const int n_Col = 10>
class ME{
    private:
            Cell<T>  *  m_Fil[n_Fil]; 
            Cell<T>  *  m_Col[n_Col];     
    public:
        Sparce(){
            for(int i=0;i<n_Fil;i++)
                m_Fil[i]=0; 
            for(int i=0;i<n_Col;i++)
                m_Col[i]=0; 
        }
        bool find_col(int f, int c, Cell<T> ** & q){
            q =  &m_Fil[f];
            while(*q){
                if( (*q)->m_Col == c) return true;
                if( (*q)->m_Col  > c)  return false;
                q  = &((*q)->m_SigCol); 
            }
            return false;
        }
        
        bool find_fil(int f, int c, Cell<T> ** & p){
            p =  &m_Col[c];
            while(*p){
                if( ((*p)->get_Fil()) == f) return true;
                if( ((*p)->get_Fil()) > f)  return false;
                p  = &((*p)->m_SigFil); 
            }
            return false;
        }
            
        void Insert(T d, int f, int c){
            Cell<T> **p;
            Cell<T> **q;
            bool  a = find_fil(f,c,p);
            bool  b = find_col(f,c,q);
            if(!a && !b){
                    Cell<T> * pNuevo = new Cell<T>(f,c,d); 
                    pNuevo->m_SigFil = *p;
                    pNuevo->m_SigCol = *q;
                    *p = *q = pNuevo;
            }    
            return;
        }
        
        void Print(){
            Cell<T> ** q;
            for(int i=0;i<n_Fil;i++){
                for(int j=0;j<n_Col;j++){
                    if(find_fil(i,j,q))
                        cout<<(*q)->get_Dato()<<" ";
                    else    
                        cout<<"0 ";
                }
                cout<<endl;
            }
        }

};

#endif