#ifndef MAMDANIDEFUZZ_H
#define MAMDANIDEFUZZ_H

#include "../core/binaryexpression.h"
#include "../core/expression.h"
#include "../core/shapeview.h"
#include <vector>
#include <iostream>

namespace fuzzy {
    template<class T>
    class MamdaniDefuzz : public core::BinaryExpression<T>{
    public:
        MamdaniDefuzz(const T& _min, const T& _max, const T& _step);
        virtual ~MamdaniDefuzz(){}
        virtual T evaluate(core::Expression<T>* l, core::Expression<T>* r) const;
        virtual T defuzz(std::pair<std::vector<T>*,std::vector<T>* >*) const = 0;
    private:
        T m_min, m_max, m_step;
    };

    template<class T>
    MamdaniDefuzz<T>::MamdaniDefuzz(const T& _min, const T& _max, const T& _step)
        : m_min(_min), m_max(_max), m_step(_step)
    {

    }

    template<class T>
    T MamdaniDefuzz<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r) const{
        return defuzz(core::ShapeView<T>::getInstance().setParam((core::ValueModel<T>*)l,r,m_min,m_max,m_step).run().getShape());
    }


}

#endif // MAMDANIDEFUZZ_H
