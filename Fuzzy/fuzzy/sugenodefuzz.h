#ifndef SUGENODEFUZZ_H
#define SUGENODEFUZZ_H

#include "../core/naryexpression.h"

namespace fuzzy {
    template<class T>
    class SugenoDefuzz : public core::NaryExpression<T>{
    public:
        SuganoDefuzz(const T& _min, const T& _max, const T& _step);
        virtual ~SugenoDefuzz(){}
        virtual T evaluate(std::vector<core::Expression<T>*> operands) const;
        virtual T defuzz(std::pair<std::vector<T>*,std::vector<T>* >*) const = 0;
    private:
        T m_min, m_max, m_step;
    };

    template<class T>
    SugenoDefuzz<T>::SugenoDefuzz(const T& _min, const T& _max, const T& _step)
        : m_min(_min), m_max(_max), m_step(_step)
    {

    }

    template<class T>
    T SugenoDefuzz<T>::evaluate(std::vector<core::Expression<T>*> operands) const
    {

    }


}

#endif // SUGENODEFUZZ_H
