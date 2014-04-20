#ifndef SUGENOCONCLUSION_H
#define SUGENOCONCLUSION_H

#include "../core/naryexpression.h"
#include "../core/binaryexpressionmodel.h"
#include "../core/nullexpressionexception.h"

namespace fuzzy {

    template<class T>
    class SugenoConclusion : public core::NaryExpression<T>{
    public:
        SugenoConclusion(const std::vector<T> &coeff);
        virtual T evaluate(std::vector<core::Expression<T> *> *operands) const;
    private:
        std::vector<T> m_coeff;
    };

    template<class T>
    SugenoConclusion<T>::SugenoConclusion(const std::vector<T> &coeff)
        : m_coeff(coeff)
    {

    }

    template<class T>
    T SugenoConclusion<T>::evaluate(std::vector<core::Expression<T> *> *operands) const
    {
        typename std::vector<core::Expression<T> *>::iterator itOpe = operands->begin();
        typename std::vector<T>::const_iterator itCoeff = m_coeff.begin();

        T result = 0;

        if(operands->size() + 1 != m_coeff.size())
            throw new core::NullExpressionException("Operands and Coeff Size Error");

        while(itOpe != operands->end() && itCoeff != m_coeff.end())
        {
            result += (*itCoeff) * (*itOpe)->evaluate();
            itCoeff++;
            itOpe++;
        }

        result += m_coeff[m_coeff.size() - 1];

        return result;
    }

}

#endif // SUGENOCONCLUSION_H
