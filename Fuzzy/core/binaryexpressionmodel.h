#ifndef BINARYEXPRESSIONMODEL_H
#define BINARYEXPRESSIONMODEL_H

#include "binaryexpression.h"

namespace core {
    template<class T>
    class BinaryExpressionModel : BinaryExpression<T>{
    public :
        BinaryExpressionModel(Expression<T>* l, Expression<T>* r, BinaryExpression<T> _operator);
        virtual ~BinaryExpressionModel();
    private:
        Expression<T>* m_r;
        Expression<T>* m_l;
        BinaryExpression<T> m_operator;
    };

}

#endif // BINARYEXPRESSIONMODEL_H
