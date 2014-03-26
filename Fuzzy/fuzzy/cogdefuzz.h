#ifndef COGDEFUZZ_H
#define COGDEFUZZ_H

#include "mamdanidefuzz.h"

namespace fuzzy{
    template<class T>
    class CogDefuzz : public MamdaniDefuzz<T>{
    public:
        CogDefuzz(const T& _min, const T& _max, const T& _step);
        virtual ~CogDefuzz(){}
        virtual T evaluate(core::Expression<T>* l,core::Expression<T>* r) const;
        virtual T defuzz(std::pair<std::vector<T>*,std::vector<T>* >*) const;
    };

    template<class T>
    CogDefuzz<T>::CogDefuzz(const T& _min, const T& _max, const T& _step)
        : MamdaniDefuzz<T>(_min,_max,_step)
    {

    }

    template<class T>
    T evaluate(core::Expression<T>* l, core::Expression<T>* r) const
    {
        MamdaniDefuzz<T>::evaluate(l,r);
    }

    template<class T>
    T Codefuzz<T>::defuzz(std::pair<std::vector<T>*,std::vector<T>* >*) const{

    }
}

#endif // COGDEFUZZ_H
