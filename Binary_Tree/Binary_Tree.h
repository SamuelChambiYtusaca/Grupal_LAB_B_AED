#ifndef _BT_H_
#define _BT_H_
#include "Node.h"
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;
template <typename T>
class Binary_Tree
{
private:
    Node<T> * root;
    int contPeso;
public:
    Binary_Tree();
    void add(T);
    void add(T, Node<T>*&, Node<T>*);
    bool erase(T);
    bool find(T);
    bool find(T, Node<T>*);
    T get_Padre(T,Node<T>*,Node<T>*);
    T get_Padre(T);
    T get_abuelo(T);
    T get_hermano(T);
    void preOrder(Node<T>*, stringstream &);
    string preOrder();
    void postOrder(Node<T>*, stringstream &);
    string postOrder();
    void inOrder(Node<T>*, stringstream &);
    string inOrder();
    int altura(T);
    int altura(Node<T>*);
    int peso();
    Node<T>* buscar(T);
    Node<T>* buscar(T,Node<T>*);
    void sucesores(T );
    void sucesores(Node<T>*);
    void antecesores(T);
    void antecesores(Node<T>*);
    ~Binary_Tree();
};

template <typename T>
Binary_Tree<T>::Binary_Tree(){
    this->root = nullptr;
    this->contPeso = 0;
}

template <typename T>
void Binary_Tree<T>::add(T dato, Node<T>*&nodo, Node<T>*padre){
        if(!nodo){
            nodo = new Node<T>(dato); 
            if(nodo != root)
                nodo->sons[2] = padre;
            return;
        }
        else if(nodo->dato == dato) return;
        add(dato,nodo->sons[nodo->dato < dato],nodo);
}

template <typename T>
void Binary_Tree<T>::add(T dato){
    add(dato,root,root);
    this->contPeso++;
    return;
}

template <typename T>
bool Binary_Tree<T>::erase(T dato){
    if(!root)
        return false;
    else if(root->dato == dato && !root->sons[0] && !root->sons[0]){
        Node<T>* tmp = root;
        root = nullptr;
        delete tmp;
        this->contPeso--;
        return true;
    }
    Node<T>*nodo = root;
    while(nodo && nodo->dato != dato){
        nodo = nodo->sons[nodo->dato < dato];
    }
    if(!nodo)
        return false;
    else if(nodo->dato == dato){
        if(nodo->sons[0] && nodo->sons[1]){
            Node<T>*aux = nodo->sons[1];
            while(aux && aux->sons[0]){
                aux = aux->sons[0];
            }
            nodo->dato = aux->dato;
            if(aux->sons[1]){
                aux->sons[1]->sons[2] = aux->sons[2];
                Node<T>* tmp = aux->sons[1];
                aux = aux->sons[1];
                aux->sons[2]->sons[0] = aux;
                delete tmp;
            }else{
                aux->sons[2]->sons[1] = nullptr;
                delete aux;
            }
            this->contPeso--;
            return true;
        }else if(!nodo->sons[0] && !nodo->sons[1]){
            Node<T>* tmp = nodo;
            if(nodo->dato < (nodo->sons[2])->dato){
                nodo->sons[2]->sons[0] = nullptr;
            }else{
                nodo->sons[2]->sons[1] = nullptr;
            }
            delete tmp;
            this->contPeso--;
            return true;
        }else{
            if(nodo->sons[0]){
                Node<T>* tmp = nodo;
                nodo = nodo->sons[0];
                nodo->sons[2] = tmp->sons[2];
                if(tmp->sons[2]->sons[0]==tmp)
                    tmp->sons[2]->sons[0] = nodo;
                else
                    tmp->sons[2]->sons[1] = nodo;
                delete tmp;
            }else{
                Node<T>* tmp = nodo;
                nodo = nodo->sons[1];
                nodo->sons[2] = tmp->sons[2];
                if(tmp->sons[2]->sons[0]==tmp)
                    tmp->sons[2]->sons[0] = nodo;
                else
                    tmp->sons[2]->sons[1] = nodo;
                delete tmp;
            }
            this->contPeso--;
            return true;
        }
    }
}

template <typename T>
bool Binary_Tree<T>::find(T dato, Node<T>* nodo){
    if(!nodo)return false;
    if(nodo->dato == dato) return true;
    find(dato,nodo->sons[nodo->dato<dato]);
}

template <typename T>
bool Binary_Tree<T>::find(T dato){
    return find(dato,root);
}

template <typename T>
void Binary_Tree<T>::preOrder(Node<T>* nodo, stringstream &content){
    if(!nodo) return ;
    content << "[" << nodo->dato << "] ";
    preOrder(nodo->sons[0],content);
    preOrder(nodo->sons[1],content);
}

template <typename T>
string Binary_Tree<T>::preOrder(){
    stringstream content;
    preOrder(root, content);
    return content.str();
}

template <typename T>
void Binary_Tree<T>::inOrder(Node<T>* nodo, stringstream &content){
    if(!nodo) return ;
    inOrder(nodo->sons[0],content);
    content << "[" << nodo->dato << "] ";
    inOrder(nodo->sons[1],content);
}

template <typename T>
string Binary_Tree<T>::inOrder(){
    stringstream content;
    inOrder(root,content);
    return content.str();
}
template <typename T>
void Binary_Tree<T>::postOrder(Node<T>* nodo, stringstream &content){
    if(!nodo) return ;
    postOrder(nodo->sons[0],content);
    postOrder(nodo->sons[1],content);
    content << "[" << nodo->dato << "] ";
}

template <typename T>
string Binary_Tree<T>::postOrder(){
    stringstream content;
    postOrder(root,content);
    return content.str();
}

template <typename T>
T Binary_Tree<T>::get_Padre(T dato,Node<T>* nodo, Node<T>*padre){
    if(!nodo) return 0;
    if(nodo->dato == dato) return padre->dato;
    padre = nodo;
    get_Padre(dato,nodo->sons[nodo->dato<dato],padre);
}

template <typename T>
T Binary_Tree<T>::get_Padre(T dato){
    return get_Padre(dato,root,root);
}

template <typename T>
T Binary_Tree<T>::get_abuelo(T dato){
    return get_Padre(get_Padre(dato,root,root),root,root);
}

template<typename T>
T Binary_Tree<T>::get_hermano(T d){   
    Node<T>*p = new Node<T>(0);
    if(!root) return 0;                            
    if(root->dato==d) return 0;                   
    Node<T>* padre = root;                           
    Node<T>* hijo = root;                           
    while(hijo && hijo->dato!=d){
        padre = hijo;                                  
        hijo = hijo->sons[ hijo->dato < d ];          
    }
    if(hijo){
        if( padre->sons[ !( padre->dato < d ) ] )      
            p = padre->sons[ !( padre->dato < d ) ];   
        else p = nullptr;                         
    }
    if(p) return p->dato; else return 0;                                                         
}

template <typename T>
int Binary_Tree<T>::altura(Node<T>*nodo){
    if(!nodo)
        return 0;
    if(!nodo->sons[0] && !nodo->sons[1]) // Es una hoja
        return 1;
    return max(altura(nodo->sons[0]),altura(nodo->sons[1]))+1;
}

template <typename T>
int Binary_Tree<T>::altura(T dato){
    Node<T>* nodo = buscar(dato);
    if(!nodo) return 0;
    return altura(nodo);
}

template <typename T>
int Binary_Tree<T>::peso(){
    return this->contPeso;
}

template <typename T>
Node<T>* Binary_Tree<T>::buscar(T dato){
    return buscar(dato,root);
}

template <typename T>
Node<T>* Binary_Tree<T>::buscar(T dato, Node<T>* nodo){
    if(!nodo)return nullptr;
    if(nodo->dato == dato) return nodo;
    buscar(dato,nodo->sons[nodo->dato<dato]);
}

template <typename T>
void Binary_Tree<T>::sucesores(T dato){
    Node<T> *aux = buscar(dato);
    if(!aux){
        return;
    }
    std::cout << "Sucesores de "<< aux->dato << ": \n";
    sucesores(aux);
}

template <typename T>
void Binary_Tree<T>::sucesores(Node<T> *nodo){
    if(nodo->sons[0]){
        std::cout<< "[" << nodo->sons[0]->dato << "]\n";
        sucesores(nodo->sons[0]);
    }
    if(nodo->sons[1]){
        std::cout<< "[" << nodo->sons[1]->dato << "]\n";
        sucesores(nodo->sons[1]);
    }
}

template <typename T>
void Binary_Tree<T>::antecesores(Node<T>*nodo){
    if(!nodo)
        return;
    std::cout << "[" << nodo->dato << "]\n";
    antecesores(nodo->sons[2]);
}

template<typename T>
void Binary_Tree<T>::antecesores(T dato){
    Node<T>* nodo = buscar(dato);
    if(!nodo)
        return;
    std::cout << "Antecesores de " << nodo->dato << ": \n";
    antecesores(nodo->sons[2]);
}

template <typename T>
Binary_Tree<T>::~Binary_Tree()
{
}

#endif