#ifndef ISTRAPEZE_H
#define ISTRAPEZE_H

#include "is.h"

namespace fuzzy {
    template<class T>
    class IsTrapeze : public Is<T>{
    public:
        IsTrapeze(const T& min,const T& mid1, const T& mid2, const T& max);
        virtual ~IsTrapeze(){}
        virtual T evaluate(core::Expression<T>* o) const;
    private:
        T m_min, m_mid1, m_mid2, m_max;
    };

    template<class T>
    IsTrapeze<T>::IsTrapeze(const T& min,const T& mid1, const T& mid2,const T& max)
        : m_min(min), m_mid1(mid1), m_mid2(mid2), m_max(max)
    {
    }

    template<class T>
    T IsTrapeze<T>::evaluate(core::Expression<T>* o) const{
        T _value = o->evaluate();
        if(_value > m_min && _value < m_mid1)
            return (_value - m_min) / (m_mid1 - m_min);
        else if(_value >= m_mid1 && _value <= m_mid2)
            return 1;
        else if (_value > m_mid2 && _value < m_max)
            return (_value - m_max) / (m_mid2 - m_max);
        return 0;
    }


}

#endif // ISTRAPEZE_H
