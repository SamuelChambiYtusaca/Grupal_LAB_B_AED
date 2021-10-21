#include <iostream>
#include "Binary_Tree.h"
using namespace std;
int main(){
    Binary_Tree<int> B1;
    B1.add(415);
    B1.add(6445);
    B1.add(497);
    B1.add(432);
    B1.add(84);
    B1.add(5241);
    B1.add(31);
    B1.add(4);
    string post = B1.postOrder();
    string pre = B1.preOrder();
    string in = B1.inOrder();
    cout << post << "\n";
    cout << pre << "\n";
    cout << in << "\n";
    cout << B1.erase(5240) << "\n";
    return 1;
}