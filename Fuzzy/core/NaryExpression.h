#ifndef NARYEXPRESSION_H
#define NARYEXPRESSION_H

#include <vector>
#include "expression.h"

namespace core
{
    template<class T>
    class NaryExpression
    {
    public:
        virtual ~NaryExpression(){}
        virtual T evaluate(std::vector<Expression<T>*>* operands) const = 0;

    };
}

#endif // NARYEXPRESSION_H
