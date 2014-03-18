#include <iostream>
#include "core/valuemodel.h"
#include "fuzzy/notminus1.h"
#include "core/unaryexpressionmodel.h"

using namespace std;

int main()
{

    /* Test de ValueModel */
    core::ValueModel<float> vm (0.5f);
    cout << vm.evaluate() << endl;
    vm.setValue(1.0f);
    cout << vm.evaluate() << endl;

    /* Test de NotMinus1 */
    fuzzy::NotMinus1<float> nm1;
    cout << nm1.evaluate(&vm) << endl;

    /* Test UnaryExpression avec NotMinus1 */
    core::UnaryExpressionModel<float> uem(&vm, &nm1);
    cout << uem.evaluate() << endl;

    return 0;
}

