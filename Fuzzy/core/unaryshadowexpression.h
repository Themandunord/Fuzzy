#ifndef UNARYSHADOWEXPRESSION_H
#define UNARYSHADOWEXPRESSION_H

#include "expression.h"
#include "unaryexpression.h"
#include "nullexpressionexception.h"

namespace core {
    template<class T>
    class UnaryShadowExpression : public UnaryExpression<T>{
      public:
        UnaryShadowExpression(const UnaryExpression<T>* e = NULL);
        virtual ~UnaryShadowExpression(){}
        virtual T evaluate(Expression<T>* o) const;
      private:
        const UnaryExpression<T>* m_exp;
    };

    template<class T>
    UnaryShadowExpression<T>::UnaryShadowExpression(const UnaryExpression<T> *e)
        : m_exp(e)
    {

    }

    template<class T>
    T UnaryShadowExpression<T>::evaluate(Expression<T>* o) const{
        if(m_exp == NULL)
            throw NullExpressionException("Null operand expression !");
        return m_exp->evaluate(o);
    }


}

#endif // UNARYSHADOWEXPRESSION_H
