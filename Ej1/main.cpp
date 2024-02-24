
#include "ABB.h"

using std::cout;
using std::endl;

int main(void){
    //
    ABB a;
    //
    a.insertar("U");
    a.insertar("D");
    a.insertar("M");
    a.insertar("F");
    a.insertar("Y");
    a.insertar("Z");
    a.insertar("A");
    a.insertar("B");
    a.insertar("N");
    //
    if ( a.buscar("D") ){
        cout << "Se encontro el nodo D" << "\n";
    }
    // a.eliminar("F");
    //
    cout << "La altura de U es: " << a.altura("D") << endl;
    //
    return 0;
}