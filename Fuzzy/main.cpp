#include <iostream>
#include "core/valuemodel.h"
#include "fuzzy/notminus1.h"

using namespace std;

int main()
{
    int nb = 1;

    /* Test de ValueModel */
    core::ValueModel<int>* vm = new core::ValueModel<int>(&nb);
    cout << vm->evaluate() << endl;
    nb = 2;
    vm->setValue(&nb);
    cout << vm->evaluate() << endl;

    /* Test de NotMinus1 */
    nb = 1;
    fuzzy::NotMinus1<int>* nm1 = new fuzzy::NotMinus1<int>();
    cout << nm1->evaluate(vm) << endl;

    return 0;
}

