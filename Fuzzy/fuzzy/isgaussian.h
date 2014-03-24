#ifndef ISGAUSSIAN_H
#define ISGAUSSIAN_H

#include "is.h"
#include "math.h"

namespace fuzzy {
    template<class T>
    class IsGaussian : public Is<T>{
    public:
        IsGaussian(const T& center,const T& sigma);
        virtual ~IsGaussian(){}
        virtual T evaluate(core::Expression<T>* o) const;
    private:
        T m_center, m_sigma;
    };

    template<class T>
    IsGaussian<T>::IsGaussian(const T& center,const T& sigma)
        : m_center(center), m_sigma(sigma)
    {
    }

    template<class T>
    T IsGaussian<T>::evaluate(core::Expression<T>* o) const{
        T _value = o->evaluate();
        T result = exp(-(pow(_value - m_center, 2)) / (2 * pow(m_sigma, 2)));
        return result;
    }


}

#endif // ISGAUSSIAN_H
