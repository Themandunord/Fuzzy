#ifndef ORMAX_H
#define ORMAX_H

#include "or.h"

namespace fuzzy {
    template<class T>
    class OrMax : public Or<T>{
    public:
       OrMax();
       virtual ~OrMax(){}
       virtual T evaluate(core::Expression<T>* l, core::Expression<T>* r) const;
    };

    template<class T>
    OrMax<T>::OrMax(){

    }

    template<class T>
    T OrMax<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r) const{
        T _l = l->evaluate();
        T _r = r->evaluate();
        return (_l < _r)?_r:_l;
    }
}

#endif // ORMAX_H
