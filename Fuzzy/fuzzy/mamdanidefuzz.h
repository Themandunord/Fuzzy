#ifndef MAMDANIDEFUZZ_H
#define MAMDANIDEFUZZ_H

#include "../core/binaryexpression.h"
#include <iostream>
#include <vector>

namespace fuzzy {
    template<class T>
    class MamdaniDefuzz : public core::BinaryExpression<T>{
    public:
        virtual T evaluate(core::Expression<T>* l, core::Expession<T>* r) const;
        virtual T defuzz(std::pair<std::vector<T>*,std::vector<T>* >*) const = 0;
    };

}

#endif // MAMDANIDEFUZZ_H
