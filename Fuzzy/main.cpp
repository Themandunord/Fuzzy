#include <iostream>
#include "core/valuemodel.h"
#include "fuzzy/notminus1.h"

using namespace std;

int main()
{

    /* Test de ValueModel */
    core::ValueModel<float>* vm = new core::ValueModel<float>(0.5f);
    cout << vm->evaluate() << endl;
    vm->setValue(1.0f);
    cout << vm->evaluate() << endl;

    /* Test de NotMinus1 */
    fuzzy::NotMinus1<float>* nm1 = new fuzzy::NotMinus1<float>();
    cout << nm1->evaluate(vm) << endl;

    return 0;
}

