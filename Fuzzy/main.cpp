#include <iostream>
#include "core/valuemodel.h"
using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    int nb = 5;
    core::ValueModel<int>* vm = new core::ValueModel<int>(&nb);
    cout << vm->evaluate() << endl;
    return 0;
}

