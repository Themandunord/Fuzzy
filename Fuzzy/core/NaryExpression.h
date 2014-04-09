#ifndef NARYEXPRESSION_H
#define NARYEXPRESSION_H

#include <vector>

namespace core
{
    template<class T>
    class NaryExpression : public Expression
    {
    public:
        virtual ~NaryExpression();
        virtual T evaluate(std::vector<Expression<T>*> operands) const = 0;

    };
}

#endif // NARYEXPRESSION_H
