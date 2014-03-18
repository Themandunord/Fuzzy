#ifndef UNARYEXPRESSION_H
#define UNARYEXPRESSION_H

#include "expression.h"

namespace core {
    template<class T>
    class UnaryExpression{
    public:
        virtual ~UnaryExpression(){}
        virtual T evaluate(Expression<T>* o) const = 0;
    };
}

#endif // UNARYEXPRESSION_H
