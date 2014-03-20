#ifndef THENMULT_H
#define THENMULT_H

#include "then.h"

namespace fuzzy {
    template<class T>
    class ThenMult : public Or<T>{
    public:
        ThenMult();
        virtual ~ThenMult(){}
        virtual T evaluate(core::Expression<T>* l, core::Expression<T>* r) const;
    };

    template<class T>
    ThenMult<T>::ThenMult(){

    }

    template<class T>
    T ThenMult<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r) const{
        T _l = l->evaluate();
        T _r = r->evaluate();
        T _mult = _l * _r;
        return (_mult < 1)?_mult:1;
    }
}

#endif // THENMULT_H
