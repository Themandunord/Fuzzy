#ifndef NOTMINUS1_H
#define NOTMINUS1_H

#include "not.h"

namespace fuzzy {
    template<class T>
    class NotMinus1 : Not<T>{
    public:
        NotMinus1();
        virtual ~NotMinus1();
        virtual T evaluate(core::Expression<T>* o) const;
    };
    template<class T>
    NotMinus1<T>::NotMinus1(){

    }

    template<class T>
    NotMinus1<T>::~NotMinus1(){

    }

    template<class T>
    T NotMinus1<T>::evaluate(core::Expression<T>* o) const{
        return 1 - o->evaluate();
    }
}

#endif // NOTMINUS1_H
