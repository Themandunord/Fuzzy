#ifndef NARYSHADOWEXPRESSION_H
#define NARYSHADOWEXPRESSION_H

#include "expression.h"
#include "naryexpression.h"
#include "nullexpressionexception.h"

namespace core {
    template<class T>
    class NaryShadowExpression : public NaryExpression<T>{
      public:
        NaryShadowExpression(const NaryExpression<T>* e = NULL);
        virtual ~NaryShadowExpression(){}
        virtual T evaluate(std::vector<Expression<T>*> ) const;
        virtual void setNaryExpression(const NaryExpression<T>* e);
      private:
        const NaryExpression<T>* m_exp;
    };

    template<class T>
    NaryShadowExpression<T>::NaryShadowExpression(const NaryExpression<T>* e)
        : m_exp(e)
    {

    }

    template<class T>
    T NaryShadowExpression<T>::evaluate(std::vector<Expression<T>*> _operands) const{
        if(m_exp == NULL)
            throw NullExpressionException("Null operand expression !");
        return m_exp->evaluate(_operands);
    }

    template<class T>
    void NaryShadowExpression<T>::setNaryExpression(const NaryExpression<T>* e){
        m_exp=e;
    }


}

#endif // NARYSHADOWEXPRESSION_H
