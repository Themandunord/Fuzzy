#ifndef COGDEFUZZ_H
#define COGDEFUZZ_H

#include "../core/binaryexpression.h"

namespace fuzzy{
    template<class T>
    class CogDefuzz : public core::BinaryExpression<T>{
    public:
        CogDefuzz();
        virtual ~CogDefuzz(){}
        virtual T evaluate(core::Expression<T>* l,core::Expression<T>* r) const;
    };

    template<class T>
    CogDefuzz<T>::CogDefuzz()
    {

    }

    template<class T>
    T evaluate(core::Expression<T>* l, core::Expression<T>* r) const
    {

    }

}

#endif // COGDEFUZZ_H
