#ifndef ISTRIANGLE_H
#define ISTRIANGLE_H

#include "is.h"

namespace fuzzy {
    template<class T>
    class IsTriangle : public Is<T>{
    public:
        IsTriangle(const T& min,const T& mid,const T& max);
        virtual ~IsTriangle(){}
        virtual T evaluate(core::Expression<T>* o) const;
    private:
        T m_min, m_mid, m_max;
    };

    template<class T>
    IsTriangle<T>::IsTriangle(const T& min,const T& mid,const T& max)
        : m_min(min), m_mid(mid), m_max(max)
    {
    }

    template<class T>
    T IsTriangle<T>::evaluate(core::Expression<T>* o) const{
        T _value = o->evaluate();
        if(_value > m_min && _value <= m_mid)
            return (_value - m_min) / (m_mid - m_min);
        else if (_value >= m_mid && _value < m_max)
            return (_value - m_max) / (m_mid - m_max);
        return 0;
    }


}

#endif // ISTRIANGLE_H
