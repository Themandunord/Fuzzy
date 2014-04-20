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
        virtual T premiseValue();
    private:
        mutable T m_premiseValue;
    };

    template<class T>
    SugenoThen<T>::SugenoThen()
    {
    }

    template<class T>
    T SugenoThen<T>::evaluate(core::Expression<T> *l, core::Expression<T> *r) const
    {
        T _l = l->evaluate();
        T _r = r->evaluate();
        T _mult = _l * _r;
        m_premiseValue = _l;
        return _mult;
    }

    template<class T>
    T SugenoThen<T>::premiseValue()
    {
        return m_premiseValue;
    }



}
#endif // SUGENOTHEN_H
