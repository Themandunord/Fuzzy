#include <iostream>
#include "core/valuemodel.h"
#include "fuzzy/notminus1.h"
#include "fuzzy/andmin.h"
#include "fuzzy/ormax.h"
#include "fuzzy/orplus.h"
#include "fuzzy/thenmin.h"
#include "fuzzy/thenmult.h"
#include "fuzzy/istriangle.h"
#include "fuzzy/istrapeze.h"
#include "fuzzy/istrapezeleft.h"
#include "fuzzy/istrapezeright.h"
#include "fuzzy/isgaussian.h"
#include "fuzzy/isbell.h"
#include "fuzzy/aggmax.h"
#include "fuzzy/aggplus.h"
#include "fuzzy/fuzzyfactory.h"
#include "core/unaryexpressionmodel.h"
#include "core/binaryexpressionmodel.h"
#include "core/shapeview.h"
#include "core/expressionfactory.h"

using namespace std;

int main()
{

    /* Test de ValueModel */
    core::ValueModel<float> vm (0.5f);
    cout << "ValueModel :" << vm.evaluate() << endl;
    vm.setValue(1.0f);
    cout << "ValueModel : " << vm.evaluate() << endl;

    /* Test UnaryExpression avec NotMinus1 */
    fuzzy::NotMinus1<float> nm1;
    core::UnaryExpressionModel<float> uem1(&vm, &nm1);
    cout << "NotMinus1 : " << uem1.evaluate() << endl;

    /* Test UnaryExpression avec isTriangle */
    vm.setValue(4.0f);
    fuzzy::IsTriangle<float> it (0,5,10);
    core::UnaryExpressionModel<float> uem2(&vm, &it);
    cout << "isTriangle : " << uem2.evaluate() << endl;

    /* Deux valeur pour les tests binaires */
    core::ValueModel<float> vml (0.5f);
    core::ValueModel<float> vmr (0.4f);

    /* Test BinaryExpression avec AndMin */
    fuzzy::AndMin<float> am;
    core::BinaryExpressionModel<float> bem1(&vml,&vmr,&am);
    cout << "AndMin : " << bem1.evaluate() << endl;

    /* Test BinaryExpression avec OrMax */
    fuzzy::OrMax<float> om;
    core::BinaryExpressionModel<float> bem2(&vml,&vmr,&om);
    cout << "OrMax : " << bem2.evaluate() << endl;

    /* Test BinaryExpression avec OrPlus */
    fuzzy::OrPlus<float> op;
    core::BinaryExpressionModel<float> bem3(&vml,&vmr,&op);
    cout << "OrPlus : " << bem3.evaluate() << endl;

    /* Test BinaryExpression avec ThenMin */
    fuzzy::ThenMin<float> tm;
    core::BinaryExpressionModel<float> bem4(&vml,&vmr,&tm);
    cout << "ThenMin : " << bem4.evaluate() << endl;

    /* Test BinaryExpression avec ThenMult */
    fuzzy::ThenMult<float> tml;
    core::BinaryExpressionModel<float> bem5(&vml,&vmr,&tml);
    cout << "ThenMult : " << bem5.evaluate() << endl;

    /* Test BinaryExpression avec AndMult */
    fuzzy::ThenMult<float> aml;
    core::BinaryExpressionModel<float> bem6(&vml,&vmr,&aml);
    cout << "AndMult : " << bem6.evaluate() << endl;

    /* Test BinaryExpression avec AggMax */
    fuzzy::AggMax<float> agm;
    core::BinaryExpressionModel<float> bem7(&vml,&vmr,&agm);
    cout << "AggMax : " << bem7.evaluate() << endl;

    /* Test BinaryExpression avec AggPlus */
    fuzzy::AggPlus<float> agp;
    core::BinaryExpressionModel<float> bem8(&vml,&vmr,&agp);
    cout << "AggPlus : " << bem8.evaluate() << endl;

    /*ShapeView*/
    cout << "ShapeView : Triangle" << endl;
    fuzzy::IsTriangle<float> itView(0,5,10);
    core::ValueModel<float> vmView(1);
    core::ShapeView<float>::getInstance().setParam(&vmView,&itView,0,10,1).run();

    cout << "ShapeView : Trapeze" << endl;
    fuzzy::IsTrapeze<float> itzView(0,3,6,10);
    core::ShapeView<float>::getInstance().setParam(&vmView,&itzView,0,10,1).run();


    cout << "ShapeView : TrapezeLeft" << endl;
    fuzzy::IsTrapezeLeft<float> itzlView(5,10);
    core::ShapeView<float>::getInstance().setParam(&vmView,&itzlView,0,10,1).run();

    cout << "ShapeView : TrapezeRight" << endl;
    fuzzy::IsTrapezeRight<float> itzrView(0,5);
    core::ShapeView<float>::getInstance().setParam(&vmView,&itzrView,0,10,1).run();

    cout << "ShapeView : Gaussian" << endl;
    fuzzy::IsGaussian<float> igView(5,1);
    core::ShapeView<float>::getInstance().setParam(&vmView,&igView,0,10,1).run();

    cout << "ShapeView : Bell" << endl;
    fuzzy::IsBell<float> ibView(2,4,6);
    core::ShapeView<float>::getInstance().setParam(&vmView,&ibView,0,10,1).run();

    /* Text NullExpressionException */
    core::BinaryExpressionModel<float> bem9(NULL,&vmr,&agp);
    try
    {
        cout << "BinaryExpressionModel (Exception) : " << bem9.evaluate() << endl;
    }
    catch(std::exception& e)
    {
        cout << "Exception : " << e.what() << endl;
    }

    core::UnaryExpressionModel<float> uem3(&vm, NULL);
    try
    {
        cout << "UnaryExpressionModel (Exception) : " << uem3.evaluate() << endl;
    }
    catch(std::exception& e)
    {
        cout << "Exception : " << e.what() << endl;
    }

    core::ExpressionFactory<float> efactory;
    cout << efactory.newUnary(&ibView,&vm)->evaluate() << endl;

    fuzzy::FuzzyFactory<float> fFactory(am,om,tm,agm,nm1);
    cout << "AndMin via factory : " << fFactory.newAnd(&vml,&vmr)->evaluate() << endl;
    cout << "OrMax via factory : " << fFactory.newOr(&vml,&vmr)->evaluate() << endl;
    cout << "ThenMin via factory : " << fFactory.newThen(&vml,&vmr)->evaluate() << endl;
    cout << "AggMax via factory : " << fFactory.newAgg(&vml,&vmr)->evaluate() << endl;
    cout << "NotMinus1 via factory : " << fFactory.newNot(&vm)->evaluate() << endl;
    cout << "IsTriangle via factory : " << fFactory.newIs(&it,&vm)->evaluate() << endl;

    return 0;
}

