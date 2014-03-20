#ifndef THENMIN_H
#define THENMIN_H

#include "then.h"

namespace fuzzy {
    template<class T>
    class ThenMin : public Or<T>{
    public:
        ThenMin();
        virtual ~ThenMin(){}
        virtual T evaluate(core::Expression<T>* l, core::Expression<T>* r) const;
    };

    template<class T>
    ThenMin<T>::ThenMin(){

    }

    template<class T>
    T ThenMin<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r) const{
        T _l = l->evaluate();
        T _r = r->evaluate();
        return (_l < _r)?_l:_r;
    }
}

#endif // THENMIN_H
