#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Binary_Tree.h"
using namespace std;
int main(){
    srand(time(NULL));
    Binary_Tree<int> B1;
    for(int i=0;i<100;++i)
        B1.add(1+rand()%(100));
    string post = B1.postOrder();
    string pre = B1.preOrder();
    string in = B1.inOrder();
    cout << post << "\n";
    cout << pre << "\n";
    cout << in << "\n";
    cout << B1.erase(5241) << "\n";
    B1.graficar();
    return 1;
}