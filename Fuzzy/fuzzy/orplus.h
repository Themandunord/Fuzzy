#ifndef ORPLUS_H
#define ORPLUS_H

#include "or.h"

namespace fuzzy {
    template<class T>
    class OrPlus : public Or<T>{
    public:
        OrPlus();
        virtual ~OrPlus(){}
        virtual T evaluate(core::Expression<T>* l, core::Expression<T>* r) const;
    };

    template<class T>
    OrPlus<T>::OrPlus(){

    }

    template<class T>
    T OrPlus<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r) const{
        T _l = l->evaluate();
        T _r = r->evaluate();
        T _sum = _l + _r;
        return (_sum < 1)?_sum:1;
    }
}

#endif // ORPLUS_H
