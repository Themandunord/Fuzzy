#ifndef BINARYSHADOWEXPRESSION_H
#define BINARYSHADOWEXPRESSION_H

#include "expression.h"
#include "binaryexpression.h"
#include "nullexpressionexception.h"

namespace core {
    template<class T>
    class BinaryShadowExpression : public BinaryExpression<T>{
      public:
        BinaryShadowExpression(const BinaryExpression<T>* e = NULL);
        virtual ~BinaryShadowExpression(){}
        virtual T evaluate(Expression<T>* l, Expression<T>* r) const;
        virtual void setBinaryExpression(const BinaryExpression<T>* e);
        virtual const BinaryExpression<T>* getBinaryExpression() const;
      private:
        const BinaryExpression<T>* m_exp;
    };

    template<class T>
    BinaryShadowExpression<T>::BinaryShadowExpression(const BinaryExpression<T>* e)
        : m_exp(e)
    {

    }

    template<class T>
    T BinaryShadowExpression<T>::evaluate(Expression<T>* l, Expression<T>* r) const{
        if(m_exp == NULL)
            throw NullExpressionException("Null operand expression !");
        return m_exp->evaluate(l,r);
    }

    template<class T>
    void BinaryShadowExpression<T>::setBinaryExpression(const BinaryExpression<T>* e){
        m_exp=e;
    }

    template<class T>
    const BinaryExpression<T>* BinaryShadowExpression<T>::getBinaryExpression() const{
        return m_exp;
    }


}

#endif // BINARYSHADOWEXPRESSION_H
