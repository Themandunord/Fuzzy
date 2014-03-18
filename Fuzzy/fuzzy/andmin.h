#ifndef ANDMIN_H
#define ANDMIN_H

#include "and.h"

namespace fuzzy{
    template<class T>
    class AndMin : public And<T>{
    public:
        AndMin();
        virtual ~AndMin();
        virtual T evaluate(core::Expression<T>* l,core::Expression<T>* r) const;
    };

    template<class T>
    AndMin<T>::AndMin(){

    }

    template<class T>
    AndMin<T>::~AndMin(){

    }

    template<class T>
    T AndMin<T>::evaluate(core::Expression<T>* l,core::Expression<T>* r)const{
        T vl = l->evaluate();
        T vr = r->evaluate();
        return (vl<vr)?vl:vl;
    }
}

#endif // ANDMIN_H
