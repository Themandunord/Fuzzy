#ifndef AND_H
#define AND_H

#include "core/binaryexpression.h"

namespace fuzzy{
    template<class T>
    class And : public core::BinaryExpression<T>{
    public:
        virtual ~And(){}
        virtual T evaluate(core::Expression<T>* l,core::Expression<T>* r) const = 0;
    };

}

#endif // AND_H
