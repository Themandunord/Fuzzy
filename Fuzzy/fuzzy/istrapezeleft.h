#ifndef ISTRAPEZELEFT_H
#define ISTRAPEZELEFT_H

#include "is.h"

namespace fuzzy {
    template<class T>
    class IsTrapezeLeft : public Is<T>{
    public:
        IsTrapezeLeft(const T& mid, const T& max);
        virtual ~IsTrapezeLeft(){}
        virtual T evaluate(core::Expression<T>* o) const;
    private:
        T m_mid, m_max;
    };

    template<class T>
    IsTrapezeLeft<T>::IsTrapezeLeft(const T& mid, const T& max)
        : m_mid(mid), m_max(max)
    {
    }

    template<class T>
    T IsTrapezeLeft<T>::evaluate(core::Expression<T>* o) const{
        T _value = o->evaluate();
        if(_value <= m_mid)
            return 1;
        else if (_value > m_mid && _value < m_max)
            return (_value - m_max) / (m_mid - m_max);
        return 0;
    }


}


#endif // ISTRAPEZELEFT_H
