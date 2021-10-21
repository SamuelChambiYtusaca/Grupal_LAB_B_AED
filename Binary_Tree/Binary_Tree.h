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
    //
public:
    Binary_Tree();
    void add(T);
    void add(T, Node<T>*&, Node<T>*);
    bool erase(T);
    bool find(T);
    bool find(T, Node<T>*);
    void preOrder(Node<T>*, stringstream &);
    string preOrder();
    void postOrder(Node<T>*, stringstream &);
    string postOrder();
    void inOrder(Node<T>*, stringstream &);
    string inOrder();
    void clear(Node<T>*);
    void clear();
    ~Binary_Tree();
};

template <typename T>
Binary_Tree<T>::Binary_Tree(){
    this->root = nullptr;
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
            return true;
        }else if(!nodo->sons[0] && !nodo->sons[1]){
            Node<T>* tmp = nodo;
            if(nodo->dato < (nodo->sons[2])->dato){
                nodo->sons[2]->sons[0] = nullptr;
            }else{
                nodo->sons[2]->sons[1] = nullptr;
            }
            delete tmp;
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
void Binary_Tree<T>::clear(Node<T>* nodo){
    if(!nodo) return;
    clear(nodo->sons[0]);
    clear(nodo->sons[1]);
    delete nodo;
}

template <typename T>
void Binary_Tree<T>::clear(){
    clear(root);
}

template <typename T>
Binary_Tree<T>::~Binary_Tree(){
    clear();
}

#endif
