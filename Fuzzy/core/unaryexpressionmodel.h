#ifndef UNARYEXPRESSIONMODEL_H
#define UNARYEXPRESSIONMODEL_H

#include "unaryexpression.h"

namespace core {
    template<class T>
    class UnaryExpressionModel : UnaryExpression<T>{
    public:
        UnaryExpressionModel(Expression<T>* operand, UnaryExpression<T>* _operator);
        virtual ~UnaryExpressionModel();
        virtual T evaluate() const;
        virtual T evaluate(Expression<T>* o) const;
    private:
        UnaryExpression* m_operator;
        Expression* m_operand;
    };

    template<class T>
    UnaryExpressionModel<T>::UnaryExpressionModel(Expression<T>* operand, UnaryExpression<T>* _operator)
        : m_operator(_operator), m_operand(operand)
    {
    }

    template<class T>
    UnaryExpressionModel<T>::~UnaryExpressionModel(){
        delete m_operand;
        delete m_operator;
    }

    template<class T>
    T UnaryExpressionModel<T>::evaluate() const{
        if(m_operand != null)
           return evaluate(m_operand);
    }

    template<class T>
    T UnaryExpressionModel<T>::evaluate(Expression<T>* o) const{
        if(m_operator)
            return m_operator->evaluate(m_operand);
    }
}

#endif // UNARYEXPRESSIONMODEL_H