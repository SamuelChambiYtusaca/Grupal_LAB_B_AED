#ifndef _NODE_H_
#define _NODE_H_
template <typename T>
class Binary_Tree;

template <typename T>
class Node
{
private:
    Node<T>* sons[3];
    T dato;
    friend class Binary_Tree<T>;
public:
    Node(T);
    ~Node();
};

template <typename T>
Node<T>::Node(T dato){
    this->dato = dato;
    this->sons[0] = nullptr;
    this->sons[1] = nullptr;
    this->sons[2] = nullptr;
}

template <typename T>
Node<T>::~Node()
{
}

#endif