#ifndef COGDEFUZZ_H
#define COGDEFUZZ_H

#include "mamdanidefuzz.h"

namespace core {
    template<class T>
    class CogDefuzz : public MamdaniDefuzz<T>{
        virtual T evaluate(core::Expression<T>* o) const;
    };
}

#endif // COGDEFUZZ_H
