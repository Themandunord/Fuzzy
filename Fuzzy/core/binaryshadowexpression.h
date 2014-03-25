#ifndef BINARYSHADOWEXPRESSION_H
#define BINARYSHADOWEXPRESSION_H

#include "expression.h"
#include "binaryexpression.h"
#include "nullexpressionexception.h"

namespace core {
    template<class T>
    class BinaryShadowExpression : public BinaryExpression<T>{
      public:
        BinaryShadowExpression(BinaryExpression<T>* e = NULL);
        virtual ~BinaryShadowExpression(){}
        virtual T evaluate(Expression<T>* l, Expression<T>* r) const;
      private:
        BinaryExpression<T>* m_exp;
    };

    template<class T>
    BinaryShadowExpression<T>::BinaryShadowExpression(BinaryExpression<T>* e)
        : m_exp(e)
    {

    }

    template<class T>
    T BinaryShadowExpression<T>::evaluate(Expression<T>* l, Expression<T>* r) const{
        if(m_exp == NULL)
            throw NullExpressionException("Null operand expression !");
        return m_exp->evaluate(l,r);
    }


}

#endif // BINARYSHADOWEXPRESSION_H
