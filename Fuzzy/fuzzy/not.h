#ifndef NOT_H
#define NOT_H

#include "core/unaryexpression.h"

namespace fuzzy {
    template<class T>
    class Not : public core::UnaryExpression<T>{
    public:
        virtual T evaluate(core::Expression<T>* o) const = 0;
    };
}

#endif // NOT_H
