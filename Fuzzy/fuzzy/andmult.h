#ifndef ANDMULT_H
#define ANDMULT_H

#include "and.h"

namespace fuzzy{
    template<class T>
    class AndMult : public And<T>{
    public:
        AndMult();
        virtual ~AndMult();
        virtual T evaluate(core::Expression<T>* l,core::Expression<T>* r) const;
    };

    template<class T>
    AndMult<T>::AndMult(){

    }

    template<class T>
    AndMult<T>::~AndMult(){

    }

    template<class T>
    T AndMult<T>::evaluate(core::Expression<T>* l,core::Expression<T>* r) const{
        T vl = l->evaluate();
        T vr = r->evaluate();
        return vl*vr;
    }
}

#endif // ANDMULT_H
