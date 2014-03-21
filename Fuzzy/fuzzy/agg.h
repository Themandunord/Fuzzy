#ifndef AGG_H
#define AGG_H

#include "core/binaryexpression.h"

namespace fuzzy{
    template<class T>
    class Agg : public core::BinaryExpression<T>{
    public:
        virtual T evaluate(core::Expression<T>* l,core::Expression<T>* r) const = 0;
    };

}

#endif // AGG_H
