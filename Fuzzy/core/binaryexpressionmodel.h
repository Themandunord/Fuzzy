#ifndef BINARYEXPRESSIONMODEL_H
#define BINARYEXPRESSIONMODEL_H

#include "binaryexpression.h"
#include "expression.h"
#include <iostream>

namespace core {
    template<class T>
    class BinaryExpressionModel : public Expression<T>, public BinaryExpression<T>{
    public :
        BinaryExpressionModel(Expression<T>* l = NULL, Expression<T>* r = NULL, BinaryExpression<T>* _operator = NULL);
        virtual ~BinaryExpressionModel();
        virtual T evaluate() const;
        virtual T evaluate(Expression<T>* l, Expression<T>* r) const;

        virtual void setOperator(BinaryExpression<T>* _operator);
        virtual void setLeft(Expression<T>* _l);
        virtual void setRight(Expression<T>* _r);

        virtual BinaryExpression<T>* getOperator() const;
        virtual Expression<T>* getLeft() const;
        virtual Expression<T>* getRight() const;

    private:
        Expression<T>* m_r;
        Expression<T>* m_l;
        BinaryExpression<T>* m_operator;
    };

    template<class T>
    BinaryExpressionModel<T>::BinaryExpressionModel(Expression<T>* l, Expression<T>* r, BinaryExpression<T>* _operator)
        : m_r(r), m_l(l), m_operator(_operator)
    {

    }

    template<class T>
    BinaryExpressionModel<T>::~BinaryExpressionModel(){
    }

    template<class T>
    T BinaryExpressionModel<T>::evaluate() const{
        if(m_l != NULL && m_r != NULL)
            return evaluate(m_l, m_r);
    }

    template<class T>
    T BinaryExpressionModel<T>::evaluate(Expression<T>* l, Expression<T>* r) const{
        if(m_operator != NULL)
            return m_operator->evaluate(l, r);
    }

    template<class T>
    void BinaryExpressionModel<T>::setOperator(BinaryExpression<T>* _operator){
        m_operator = _operator;
    }

    template<class T>
    void ExpressionModel<T>::setLeft(Expression<T>* _l){
        m_l = _l;
    }

    template<class T>
    void ExpressionModel<T>::setRight(Expression<T>* _l){
        m_r = _r;
    }

    template<class T>
    BinaryExpression<T>* BinaryExpressionModel<T>::getOperator() const{
        return m_operator;
    }

    template<class T>
    Expression<T>* BinaryExpressionModel<T>::getLeft() const{
        return m_l;
    }

    template<class T>
    Expression<T>* BinaryExpressionModel<T>::getRight() const{
        return m_r;
    }
}

#endif // BINARYEXPRESSIONMODEL_H
