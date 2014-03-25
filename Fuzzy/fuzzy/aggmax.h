#ifndef AGGMAX_H
#define AGGMAX_H

#include "agg.h"

namespace fuzzy {
    template<class T>
    class AggMax : public Agg<T>{
    public:
       AggMax();
       virtual ~AggMax(){}
       virtual T evaluate(core::Expression<T>* l, core::Expression<T>* r) const;
    };

    template<class T>
    AggMax<T>::AggMax(){

    }

    template<class T>
    T AggMax<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r) const{
        T _l = l->evaluate();
        T _r = r->evaluate();
        return (_l < _r)?_r:_l;
    }
}

#endif // AGGMAX_H
