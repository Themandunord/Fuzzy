#include <iostream>
#include "fuzzy/notminus1.h"
#include "fuzzy/andmin.h"
#include "fuzzy/ormax.h"
#include "fuzzy/thenmin.h"
#include "fuzzy/aggmax.h"
#include "fuzzy/fuzzyfactory.h"
#include "fuzzy/istriangle.h"
#include "fuzzy/isgaussian.h"
#include "fuzzy/istrapezeleft.h"
#include "fuzzy/istrapezeright.h"
#include "fuzzy/cogdefuzz.h"
#include "fuzzy/sugenoconclusion.h"
#include "fuzzy/sugenodefuzz.h"
#include "fuzzy/sugenothen.h"
#include "core/valuemodel.h"
#include "core/expression.h"

#include "core/binaryexpressionmodel.h";
#include "core/valuemodel.h"


using namespace std;

void sugenoTest(){
    fuzzy::NotMinus1<float> opNot;
    fuzzy::AndMin<float> opAnd;
    fuzzy::OrMax<float> opOr;
    fuzzy::ThenMin<float> opThen;
    fuzzy::AggMax<float> opAgg;
    fuzzy::CogDefuzz<float> opCog(0,25,0.1);

    std::vector<float> coeff;
    coeff.push_back(1.6f);
    coeff.push_back(2.1f);
    coeff.push_back(1.1f);

    fuzzy::SugenoConclusion<float> sugConcl(coeff);
    fuzzy::SugenoDefuzz<float> sugDefuzz;


    fuzzy::FuzzyFactory<float> f(opAnd,opOr,opThen,opAgg,opNot,opCog,sugDefuzz,sugConcl);

    fuzzy::IsGaussian<float> poor(0,6);
    fuzzy::IsGaussian<float> good(5, 6);
    fuzzy::IsGaussian<float> excellent(10, 6);

    fuzzy::IsTrapezeLeft<float> rancid(1, 4);
    fuzzy::IsTrapezeRight<float> delicious(6, 9);

    fuzzy::IsTriangle<float> cheap(0, 6, 12);
    fuzzy::IsTriangle<float> average(7, 13, 19);
    fuzzy::IsTriangle<float> generous(14, 20, 26);

    core::ValueModel<float> service(0);
    core::ValueModel<float> food(0);
    core::ValueModel<float> tips(0);


    service.setValue(3);
    food.setValue(8);

    core::Expression<float> *r =
        f.newAgg(
            f.newAgg(
                f.newThen(
                    f.newOr(
                        f.newIs(&poor, &service),
                        f.newIs(&rancid, &food)
                    ),
                    f.newIs(&cheap,&tips)
                ),
                f.newThen(
                    f.newIs(&good,&service),
                    f.newIs(&average,&tips)
                )
            ),
            f.newThen(
                f.newOr(
                    f.newIs(&excellent, &service),
                    f.newIs(&delicious, &food)
                ),
                f.newIs(&generous,&tips)
            )
    );

    core::Expression<float> *system = f.newMamdani(&tips,r);

    cout << "Mandani tips -> " << system->evaluate() << endl;

    fuzzy::SugenoThen<float> sugThen;
    f.changeThen(sugThen);


    vector<core::Expression<float>*> sugenoConcServiceFood;
    sugenoConcServiceFood.push_back(&service);
    sugenoConcServiceFood.push_back(&food);

    vector<core::Expression<float>*> sugenoConcService;
    sugenoConcService.push_back(&service);

    vector<core::Expression<float>*> sRules;
    sRules.push_back(
        f.newThen(
            f.newOr(
                f.newIs(&poor,&service),
                f.newIs(&rancid,&food)
            ),
            f.newSugenoConclusion(sugenoConcServiceFood)
        )
    );
    sRules.push_back(
        f.newThen(
            f.newIs(&good,&service),
            f.newSugenoConclusion(sugenoConcService)
        )
    );
    sRules.push_back(
        f.newThen(
            f.newOr(
                f.newIs(&excellent,&service),
                f.newIs(&delicious,&food)
            ),
            f.newSugenoConclusion(sugenoConcServiceFood)
        )
    );


    core::Expression<float>* sugeno =  f.newSugenoDefuzz(sRules);

    cout << "Sugeno tips -> " << sugeno->evaluate() << endl;
}

void mandaniTest(){
    fuzzy::NotMinus1<float> opNot;
    fuzzy::AndMin<float> opAnd;
    fuzzy::OrMax<float> opOr;
    fuzzy::ThenMin<float> opThen;
    fuzzy::AggMax<float> opAgg;
    fuzzy::CogDefuzz<float> opCog(0,25,0.1);

    std::vector<float> coeff;
    coeff.push_back(1.6f);
    coeff.push_back(2.1f);
    coeff.push_back(1.1f);

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

    core::Expression<float> *system = f.newMamdani(&tips,r);

    //cout << "Mandani tips -> " << system->evaluate() << endl;

    float s;
    int cpt = 0;
    while(cpt != 1)
    {
      cout << "service : ";cin >> s;
      service.setValue(s);
      cout << "Mandani tips -> " << system->evaluate() << endl;
      cpt++;
    }
}

int main(){

    sugenoTest();
    //mandaniTest();

    return 0;
}


