#ifndef UNARYEXPRESSION_H
#define UNARYEXPRESSION_H

namespace core {
    template<class T>
    class UnaryExpression{
    public:
        virtual T evaluate() const = 0;
    };
}

#endif // UNARYEXPRESSION_H
