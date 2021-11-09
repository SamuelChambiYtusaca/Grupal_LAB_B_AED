#include<iostream>
#include<set>
#include<stdlib.h>
#include<time.h>
using namespace std;
/*Clase celda*/
template<class T>
class Cell{
    public:
        int         m_Fil;
        int         m_Col;
        Cell<T> *   m_SigFil;
        Cell<T> *   m_SigCol; 
        T           m_Dato; 
    public:
        Cell(T d, int f, int c){
            m_Fil=f;
            m_Col=c;
            m_SigFil=0;
            m_SigCol=0;
            m_Dato=d; 
        }  
        
        Cell(){
            m_Fil=0;
            m_Col=0;
            m_SigFil=0;
            m_SigCol=0;
        }
        ~Cell(){
            m_Fil=0;
            m_Col=0;
            m_SigFil=0;
            m_SigCol=0;
        }           	
        
};
 

template<class T, const int n_Fil=10, const int n_Col=10>
class Sparce{
    private:
        Cell<T>  *   m_Fil[n_Fil]; 
        Cell<T>  *   m_Col[n_Col];     
    public:
        Sparce(){
            for(int i=0;i<n_Fil;i++)
                m_Fil[i]=0; 
            for(int i=0;i<n_Col;i++)
                m_Col[i]=0; 
        }
        
        Cell<T>* ant_col(int f, Cell<T>* n){
            Cell<T>* q =  m_Fil[f];
            Cell<T>* ans = m_Fil[f];
            while(q and (q)!=n){
                ans = q;
                (q) = q->m_SigCol;
            }
            return ans;
        }
        Cell<T>* ant_fil(int c, Cell<T>* n){
            Cell<T>* q = m_Col[c];
            Cell<T>* ans = m_Col[c];
            while(q and (q)!= n){
                ans = q;
                q = q->m_SigFil;
            }
            return ans;
        }

        bool find_col(int f, int c, Cell<T> ** & q){
            if(f<0) return false;
            q =  &m_Fil[f];
            while(*q){
                if((*q)->m_Col == c) return true;
                if((*q)->m_Col > c)  return false;
                q = &((*q)->m_SigCol); 
            }
            return false;
        }
        
        bool find_fil(int f, int c, Cell<T> ** & p){
            if(c<0) return false;
            p =  &m_Col[c];
            while(*p){
                if((*p)->m_Fil == f) return true;
                if((*p)->m_Fil > f)  return false;
                p = &((*p)->m_SigFil); 
            }
            return false;
        }
            
        void Insert(T d, int f, int c){
            Cell<T> **p;
            Cell<T> **q;
            bool  a = find_fil(f,c,p);
            bool  b = find_col(f,c,q);
            if(!a && !b){
                Cell<T> * pNuevo = new Cell<T>(d,f,c); 
                pNuevo->m_SigFil= *p;
                pNuevo->m_SigCol= *q;
                *p = *q = pNuevo;
            }    
            
        }

        void Delete(T d,int fil,int col){
            Cell<T> **p;
            Cell<T> **q;
            bool  a = find_fil(fil,col,p);
            bool  b = find_col(fil,col,q);
            if((a && b) && (*p)->m_Dato == d){
                Cell<T> **ant1;
                Cell<T> **ant2;
                bool c = find_fil(fil-1,col,ant1);
                bool d = find_col(fil,col-1,ant2);
                if(c && d){
                    Cell<T>*sigF = (*p)->m_SigFil;
                    Cell<T>*sigC = (*q)->m_SigCol;
                    delete (*p);
                    (*ant1)->m_SigFil = sigF;
                    (*ant2)->m_SigCol = sigC;
                }else if(c && !d){
                    Cell<T>*sigF = (*p)->m_SigFil;
                    Cell<T>*sigC = (*q)->m_SigCol;
                    Cell<T>*aux1 = ant_col(fil,*q);
                    if(aux1 == *q){
                        delete (*q);   
                        m_Fil[fil] = sigC;
                    }else{
                        delete *p;
                        aux1->m_SigCol = sigC;
                    }
                    (*ant1)->m_SigFil = sigF;
                }else if(!c && d ){
                    Cell<T>*sigF = (*p)->m_SigFil;
                    Cell<T>*sigC = (*q)->m_SigCol;
                    Cell<T>*aux1 = ant_fil(col,*p);
                    if(aux1 == *p){
                        delete *p;
                        m_Col[col] = sigF;
                    }else{
                        delete *p;
                        aux1->m_SigFil = sigF;
                    }
                    (*ant2)->m_SigCol = sigC;
                }else{
                    Cell<T>*sigF = (*p)->m_SigFil;
                    Cell<T>*sigC = (*q)->m_SigCol;
                    Cell<T>*aux1 = ant_fil(col,*p);
                    Cell<T>*aux2 = ant_col(fil,*q);   
                    if(aux1 == *p && aux2 == *q){
                        delete *p;
                        m_Fil[fil] = sigC;
                        m_Col[col] = sigF;
                    }else{
                        delete *p;
                        aux1->m_SigCol = sigC;
                        aux2->m_SigFil = sigF;
                    }
                }
            }
            return;
        }
        void Print(){
            Cell<int> ** q, **p;
            for(int i=0;i<n_Fil;i++){
                for(int j=0;j<n_Col;j++){
                    if(find_fil(i,j,p))
                        cout<< (*p)->m_Dato << "\t";
                    else    
                        cout<< "0\t";
                }
                cout<<endl;
            }
        }
};



int main(){
    Sparce<int,3,3> M;
    srand(time(NULL));
    int n = 1;
    /*Intentar con numero aleatorios*/
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++,n++)
            M.Insert(n,i,j);
    M.Print();
    /*
        [1,2,3]
        [4,5,6]
        [7,8,9]
    */
    M.Delete(2,0,1);
    M.Delete(6,1,2);
    M.Delete(4,1,0); 
    M.Delete(9,2,2);
    M.Delete(1,0,0);
    cout << "\n";
    M.Print();
    return 1;
};