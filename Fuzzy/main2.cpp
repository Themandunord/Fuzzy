#include <iostream>
#include "fuzzy/notminus1.h"
#include "fuzzy/andmin.h"
#include "fuzzy/ormax.h"
#include "fuzzy/thenmin.h"
#include "fuzzy/aggmax.h"
#include "fuzzy/fuzzyfactory.h"
#include "fuzzy/istriangle.h"
#include "fuzzy/cogdefuzz.h"
#include "fuzzy/sugenoconclusion.h"
#include "fuzzy/sugenodefuzz.h"
#include "fuzzy/sugenothen.h"
#include "core/valuemodel.h"
#include "core/expression.h"


using namespace std;

int main(){

    fuzzy::NotMinus1<float> opNot;
    fuzzy::AndMin<float> opAnd;
    fuzzy::OrMax<float> opOr;
    fuzzy::ThenMin<float> opThen;
    fuzzy::AggMax<float> opAgg;
    fuzzy::CogDefuzz<float> opCog(0,25,1);

    std::vector<T> coeff;
    coeff.push_back(1.0f);
    coeff.push_back(1.0f);
    coeff.push_back(1.0f);

    fuzzy::SugenoConclusion<float> sugConcl(coeff);
    fuzzy::SugenoDefuzz<float> sugDefuzz;


    fuzzy::FuzzyFactory<float> f(opAnd,opOr,opThen,opAgg,opNot,opCog,sugDefuzz,sugConcl);

    fuzzy::IsTriangle<float> poor(-5,0,5);
    fuzzy::IsTriangle<float> good(0,5,10);
    fuzzy::IsTriangle<float> excellent(5,10,15);

    fuzzy::IsTriangle<float> cheap(0,5,10);
    fuzzy::IsTriangle<float> average(10,15,20);
    fuzzy::IsTriangle<float> generous(20,25,30);

    core::ValueModel<float> service(0);
    core::ValueModel<float> food(0);
    core::ValueModel<float> tips(0);

    core::Expression<float> *r =
     f.newAgg(
      f.newAgg(
       f.newThen(
        f.newIs(&poor,&service),
        f.newIs(&cheap,&tips)
       ),
       f.newThen(
        f.newIs(&good,&service),
        f.newIs(&average,&tips)
    )
      ),
      f.newThen(
       f.newIs(&excellent,&service),
       f.newIs(&generous,&tips)
    )
     );

    cout << r->evaluate() << endl;
    service.setValue(2);
    core::Expression<float> *system = f.newMamdani(&tips,r);
    //cout << "CogDefuzz via factory : " << f.newMamdani(&tips,r)->evaluate() << endl;

    float s;
    int cpt = 0;
    while(cpt == 2)
    {
      cout << "service : ";cin >> s;
      service.setValue(s);
      cout << "tips -> " << system->evaluate() << endl;
      cpt++;
    }

    fuzzy::SugenoThen<float> sugThen;
    f.changeThen(sugThen);



    core::Expression<float>* expression = null;







    return 0;
}


