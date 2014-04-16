#ifndef SUGENOTHEN_H
#define SUGENOTHEN_H

#include "then.h"

namespace fuzzy
{
    template<class T>
    class SugenoThen : public Then<T>
    {
    public:
        SugenoThen();
        virtual ~SugenoThen(){}
        virtual T evaluate(core::Expression<T> *l, core::Expression<T> *r) const;
    private:
        virtual fuzzy::T premiseValue();
        T premiseValue;
    };

    template<class T>
    SugenoThen<T>::SugenoThen()
    {
    }

    template<class T>
    T SugenoThen<T>::evaluate(core::Expression<T> *l, core::Expression<T> *r)
    {
        T _l = l->evaluate();
        T _r = r->evaluate();
        T _mult = _l * _r;
        premiseValue = _l;
        return (_mult < 1)?_mult:1;
    }

    template<class T>
    T SugenoThen<T>::premiseValue()
    {
        return premiseValue;
    }



}
#endif // SUGENOTHEN_H
