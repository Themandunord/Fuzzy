#ifndef ISBELL_H
#define ISBELL_H

#include "is.h"
#include "math.h"

namespace fuzzy {
    template<class T>
    class IsBell : public Is<T>{
    public:
        IsBell(const T& a, const T& b, const T& c);
        virtual ~IsBell(){}
        virtual T evaluate(core::Expression<T>* o) const;
    private:
        T m_a, m_b, m_c;
    };

    template<class T>
    IsBell<T>::IsBell(const T& a, const T& b, const T& c)
        : m_a(a), m_b(b), m_c(c)
    {
    }

    template<class T>
    T IsBell<T>::evaluate(core::Expression<T>* o) const{
        T _value = o->evaluate();
        T result = 1 / ( 1 + pow(abs( (_value - m_c ) / m_a), 2 * m_b));
        return result;
    }


}


#endif // ISBELL_H
