#ifndef UNARYEXPRESSIONMODEL_H
#define UNARYEXPRESSIONMODEL_H

#include "unaryexpression.h"
#include "expression.h"
#include "nullexpressionexception.h"

namespace core {
    template<class T>
    class UnaryExpressionModel : public Expression<T>, public UnaryExpression<T>{
    public:
        UnaryExpressionModel(Expression<T>* operand = NULL, UnaryExpression<T>* _operator = NULL);
        virtual ~UnaryExpressionModel();
        virtual T evaluate() const;
        virtual T evaluate(Expression<T>* o) const;

        virtual void setOperand(Expression<T>*);
        virtual void setOperator(UnaryExpression<T>*);

        virtual Expression<T>* getOperand() const;
        virtual UnaryExpression<T>* getOperator() const;

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
    }

    template<class T>
    T UnaryExpressionModel<T>::evaluate() const{
        if(m_operand == NULL) throw NullExpressionException("Null operand exception !");
        return evaluate(m_operand);
    }

    template<class T>
    T UnaryExpressionModel<T>::evaluate(Expression<T>* o) const{
        if(m_operator == NULL) throw NullExpressionException("Null operator expression !");
        return m_operator->evaluate(o);
    }

    template<class T>
    void UnaryExpressionModel<T>::setOperand(Expression<T>* op)
    {
        m_operand=op;
    }

    template<class T>
    void UnaryExpressionModel<T>::setOperator(UnaryExpression<T>* op)
    {
        m_operator=op;
    }

    template<class T>
    Expression<T> *UnaryExpressionModel<T>::getOperand() const
    {
        return m_operand;
    }

    template<class T>
    UnaryExpression<T> *UnaryExpressionModel<T>::getOperator() const
    {
        return m_operator;
    }
}

#endif // UNARYEXPRESSIONMODEL_H
