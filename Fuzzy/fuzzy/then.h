#ifndef THEN_H
#define THEN_H

#include "core/binaryexpression.h"

namespace fuzzy {
    template<class T>
    class Then : public core::BinaryExpression<T>{
    public:
        virtual ~Then(){}
        virtual T evaluate(core::Expression<T>* l, core::Expression<T>* r) const = 0;
    };
}

#endif // THEN_H
