#ifndef IS_H
#define IS_H

#include "core/unaryexpression.h"

namespace fuzzy {
    template<class T>
    class Is : public core::UnaryExpression<T>{
    public:
        virtual ~Is(){}
        virtual T evaluate(core::Expression<T>* o) const = 0;
    };
}

#endif // IS_H
