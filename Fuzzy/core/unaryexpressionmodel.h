#ifndef UNARYEXPRESSIONMODEL_H
#define UNARYEXPRESSIONMODEL_H

#include "unaryexpression.h"

namespace core {
    template<class T>
    class UnaryExpressionModel : public UnaryExpression<T>{
    public:
        UnaryExpressionModel(Expression<T>* operand = NULL, UnaryExpression<T>* _operator = NULL);
        virtual ~UnaryExpressionModel();
        virtual T evaluate() const;
        virtual T evaluate(Expression<T>* o) const;

        virtual void setOperand(Expression<T>*);
        virtual void setOperator(UnaryExpression<T>*);

    private:
        UnaryExpression<T>* m_operator;
        Expression<T>* m_operand;
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
        if(m_operand != NULL)
           return evaluate(m_operand);
    }

    template<class T>
    T UnaryExpressionModel<T>::evaluate(Expression<T>* o) const{
        if(m_operator != NULL)
            return m_operator->evaluate(o);
    }

    template<class T>
    void UnaryExpressionModel<T>::setOperand(Expression<T>* op)
    {
        m_operand=op;
    }

    template<class T>
    void UnaryExpressionModel<T>::setOperator(Expression<T>* op)
    {
        m_operator=op;
    }
}

#endif // UNARYEXPRESSIONMODEL_H
