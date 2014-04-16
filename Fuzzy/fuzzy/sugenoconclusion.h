#ifndef SUGENOCONCLUSION_H
#define SUGENOCONCLUSION_H

#include "../core/naryexpression.h"

namespace core {

    template<class T>
    class SugenoConclusion : public NaryExpression<T>{
    public:
        SugenoConclusion(const std::vector<T> &coeff);
        virtual T evaluate(std::vector<Expression<core::T> *> *operands) const;
    private:
        std::vector<T> m_coeff;
    };

    template<class T>
    SugenoConclusion<T>::SugenoConclusion(const std::vector<T> &coeff)
        : m_coeff(coeff)
    {

    }

    template<class T>
    T SugenoConclusion<T>::evaluate(std::vector<Expression<core::T> *> *operands) const
    {
        std::vector<Expression<core::T> *>::iterator itOpe = operands->begin();
        std::vector<T>::iterator itCoeff = m_coeff.begin();

        T result = 0;

        while(itOpe != operands->end() && itCoeff != m_coeff.end())
        {
            result += (*itCoeff) * (*itOpe->evaluate());
            itCoeff++;
            itOpe++;
        }

        return result;
    }

}

#endif // SUGENOCONCLUSION_H
