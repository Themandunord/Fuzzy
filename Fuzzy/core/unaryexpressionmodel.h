#ifndef UNARYEXPRESSIONMODEL_H
#define UNARYEXPRESSIONMODEL_H

#include "unaryexpression.h"
#include "expression.h"

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
        return evaluate(m_operand);
    }

    template<class T>
    T UnaryExpressionModel<T>::evaluate(Expression<T>* o) const{
       return m_operator->evaluate(m_operand);
    }
}

#endif // UNARYEXPRESSIONMODEL_H
