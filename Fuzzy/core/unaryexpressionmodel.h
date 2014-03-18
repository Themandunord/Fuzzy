#ifndef UNARYEXPRESSIONMODEL_H
#define UNARYEXPRESSIONMODEL_H

#include "unaryexpression.h"
#include "expression.h"

namespace core {
    template<class T>
    class UnaryExpressionModel : UnaryExpression<T>{
    public:
        UnaryExpressionModel(Expression<T>* _operand, UnaryExpression<T>* _operator);
        virtual ~UnaryExpressionModel();
        virtual T evaluate() const;
        virtual T evaluate(Expression<T>* o) const;
    private:
        UnaryExpression* operator;
        Expression* operand;
    };

    template<class T>
    UnaryExpressionModel<T>::UnaryExpressionModel(Expression<T>* _operand, UnaryExpression<T>* _operator)
    {

    }

    template<class T>
    UnaryExpressionModel<T>::~UnaryExpressionModel(){

    }

    template<class T>
    T UnaryExpressionModel<T>::evaluate() const{

    }

    template<class T>
    T UnaryExpressionModel<T>::evaluate(Expression<T>* o) const{

    }
}

#endif // UNARYEXPRESSIONMODEL_H
