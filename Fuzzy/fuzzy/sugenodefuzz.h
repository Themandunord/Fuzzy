#ifndef SUGENODEFUZZ_H
#define SUGENODEFUZZ_H

#include "../core/naryexpression.h"
#include "../core/binaryexpressionmodel.h"
#include "../core/binaryshadowexpression.h"
#include "sugenothen.h"


namespace fuzzy {
    template<class T>
    class SugenoDefuzz : public core::NaryExpression<T>{
    public:
        SugenoDefuzz();
        virtual ~SugenoDefuzz(){}
        virtual T evaluate(std::vector<core::Expression<T>*>* operands) const;
    };

    template<class T>
    SugenoDefuzz<T>::SugenoDefuzz()
    {

    }

    template<class T>
    T SugenoDefuzz<T>::evaluate(std::vector<core::Expression<T>*>* operands) const
    {
        T w=0;
        T wz=0;
        typename std::vector<core::Expression<T>*>::iterator it;
        for(it=operands->begin();it!=operands->end();it++)
        {
            core::BinaryExpressionModel<T>* bem = (core::BinaryExpressionModel<T>*) (*it);
            core::BinaryShadowExpression<T>* bse = (core::BinaryShadowExpression<T>*) bem->getOperator();
            SugenoThen<T>* st = (SugenoThen<T>*) bse->getBinaryExpression();
            wz += bem->evaluate();
            w += st->premiseValue();
        }
        return wz/w;
    }


}

#endif // SUGENODEFUZZ_H
