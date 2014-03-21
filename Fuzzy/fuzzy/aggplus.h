#ifndef AGGPLUS_H
#define AGGPLUS_H

#include "agg.h"

namespace fuzzy {
    template<class T>
    class AggPlus : public Or<T>{
    public:
       AggPlus();
       virtual ~AggPlus(){}
       virtual T evaluate(core::Expression<T>* l, core::Expression<T>* r) const;
    };

    template<class T>
    AggPlus<T>::AggPlus(){

    }

    template<class T>
    T AggPlus<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r) const{
        T _l = l->evaluate();
        T _r = r->evaluate();
        T _sum = _l + _r;
        return (_sum < 1)?_sum:1;
    }
}

#endif // AGGPLUS_H
