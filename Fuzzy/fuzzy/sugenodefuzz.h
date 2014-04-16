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
        SuganoDefuzz(const T& _min, const T& _max, const T& _step);
        virtual ~SugenoDefuzz(){}
        virtual T evaluate(std::vector<core::Expression<T>*>* operands) const;
    private:
        T m_min, m_max, m_step;
    };

    template<class T>
    SugenoDefuzz<T>::SugenoDefuzz(const T& _min, const T& _max, const T& _step)
        : m_min(_min), m_max(_max), m_step(_step)
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
            core::BinaryExpressionModel<T>* bem = (core::BinaryExpressionModel<T>*)*it;
            core::BinaryShadowExpression<T>* bse = bem->getOperator();
            SugenoThen<T>* st = (SugenoThen<T>*) bse->getBinaryExpression();
            wz += bem->evaluate();
            w += st->premiseValue();
        }
        return wz/w;
    }


}

#endif // SUGENODEFUZZ_H
