#include <iostream>
#include "ME.h"
#include <ctime>
#include <stdlib.h>
using namespace std;
int main(){
    srand(time(NULL));
    ME<int,5,5> Mt1;
    for(int i = 0;i<5;++i){
        for(int j = 0;j<5;++j){
            Mt1.Insert(1,i,j);
        }
    }/*BUGS CON LA CLASE ME --CHECAR PARA CORREGIR--*/
    Mt1.Print();
    return 1;
}