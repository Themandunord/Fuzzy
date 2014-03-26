#ifndef COGDEFUZZ_H
#define COGDEFUZZ_H

#include "mamdanidefuzz.h"

namespace fuzzy{
    template<class T>
    class CogDefuzz : public MamdaniDefuzz<T>{
    public:
        CogDefuzz(const T& _min, const T& _max, const T& _step);
        virtual ~CogDefuzz(){}
        virtual T defuzz(std::pair<std::vector<T>*,std::vector<T>* >*) const;
    };

    template<class T>
    CogDefuzz<T>::CogDefuzz(const T& _min, const T& _max, const T& _step)
        : MamdaniDefuzz<T>(_min,_max,_step)
    {

    }

    template<class T>
    T CogDefuzz<T>::defuzz(std::pair<std::vector<T>*,std::vector<T>* >* shape) const{
        T _num;
        T _den;

        typename std::vector<T>::const_iterator it_first = shape->first->begin();
        typename std::vector<T>::const_iterator it_second = shape->second->begin();

        for(int i = 0; it_first != shape->first->end(); i++){
            _num += *it_first + *it_second;
            _den += *it_second;
            it_first++;
            it_second++;
        }

        return _num / _den;
    }
}

#endif // COGDEFUZZ_H
