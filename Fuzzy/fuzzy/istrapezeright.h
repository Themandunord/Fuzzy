#ifndef ISTRAPEZERIGHT_H
#define ISTRAPEZERIGHT_H

#include "is.h"

namespace fuzzy {
    template<class T>
    class IsTrapezeRight : public Is<T>{
    public:
        IsTrapezeRight(const T& min, const T& mid);
        virtual ~IsTrapezeRight(){}
        virtual T evaluate(core::Expression<T>* o) const;
    private:
        T m_min, m_mid;
    };

    template<class T>
    IsTrapezeRight<T>::IsTrapezeRight(const T& min, const T& mid)
        : m_min(min), m_mid(mid)
    {
    }

    template<class T>
    T IsTrapezeRight<T>::evaluate(core::Expression<T>* o) const{
        T _value = o->evaluate();
        if(_value >= m_min && _value < m_mid)
            return (_value - m_min) / (m_mid - m_min);
        else if (_value >= m_mid)
            return 1;
        return 0;
    }
}

#endif // ISTRAPEZERIGHT_H
