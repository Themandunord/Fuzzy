#ifndef OR_H
#define OR_H

#include "core/binaryexpression.h"

namespace fuzzy {
    template<class T>
    class Or : public core::BinaryExpression<T>{
    public:
        virtual T evaluate(core::Expression<T>* l, core::Expression<T>* r) const = 0;
    };
}

#endif // OR_H
