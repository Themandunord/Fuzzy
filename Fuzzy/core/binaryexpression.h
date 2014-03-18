#ifndef BINARYEXPRESSION_H
#define BINARYEXPRESSION_H

#include "expression.h"

namespace core {
    template<class T>
    class BinaryExpression{
    public:
         virtual ~BinaryExpression(){}
         virtual T evaluate(Expression<T>* l, Expression<T>* r) const = 0;
    };

}

#endif // BINARYEXPRESSION_H
