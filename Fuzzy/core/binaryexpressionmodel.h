#ifndef BINARYEXPRESSIONMODEL_H
#define BINARYEXPRESSIONMODEL_H

#include "binaryexpression.h"

namespace core {
    template<class T>
    class BinaryExpressionModel : BinaryExpression<T>{
    public :
        BinaryExpressionModel(Expression<T>* l, Expression<T>* r, BinaryExpression<T> _operator);
        virtual ~BinaryExpressionModel();
        virtual T evaluate() const;
        virtual T evaluate(Expression<T>* l, Expression<T>* r) const;
    private:
        Expression<T>* m_r;
        Expression<T>* m_l;
        BinaryExpression<T> m_operator;
    };

    template<class T>
    BinaryExpressionModel<T>::BinaryExpressionModel(Expression<T>* l, Expression<T>* r, BinaryExpression<T> _operator)
        : m_r(r), m_l(l), m_operator(_operator)
    {
    }

    template<class T>
    BinaryExpressionModel<T>::~BinaryExpressionModel(){
        delete m_r;
        delete m_l;
        delete m_operator;
    }

    template<class T>
    T BinaryExpressionModel<T>::evaluate() const{
        if(m_l != null && m_r != null)
            return evaluate(m_l, m_r);
    }

    template<class T>
    BinaryExpressionModel<T>::evaluate(Expression<T>* l, Expression<T>* r) const{
        if(m_operator != null)
            return m_operator->evaluate(m_l, m_r);
    }

}

#endif // BINARYEXPRESSIONMODEL_H
