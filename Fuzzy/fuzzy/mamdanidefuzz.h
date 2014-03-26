#ifndef MAMDANIDEFUZZ_H
#define MAMDANIDEFUZZ_H

#include "../core/binaryexpression.h"
#include "../core/shapeview.h"
#include <iostream>
#include <vector>

namespace fuzzy {
    template<class T>
    class MamdaniDefuzz : public core::BinaryExpression<T>{
    public:
<<<<<<< HEAD
        virtual T evaluate(core::Expression<T>* l, core::Expression<T>* r) const;
=======
        MamdaniDefuzz(const T& _min, const T& _max, const T& _step);
        virtual ~MamdaniDefuzz(){}
        virtual T evaluate(core::Expression<T>* l, core::Expession<T>* r) const;
>>>>>>> de92fe64f3e4f5cd6dda141888f2d99db54c9a60
        virtual T defuzz(std::pair<std::vector<T>*,std::vector<T>* >*) const = 0;
    private:
        T m_min, m_max, m_step;
    };

<<<<<<< HEAD
=======
    template<class T>
    MamdaniDefuzz<T>::MamdaniDefuzz(const T& _min, const T& _max, const T& _step)
        : m_min(_min), m_max(_max), m_step(_step)
    {

    }

    template<class T>
    MamdaniDefuzz<T>::evaluate(core::Expression<T>* l, core::Expession<T>* r){
        return defuzz(core::ShapeView<T>::getInstance().setParam(l,r,m_min,m_max,m_step));
    }
>>>>>>> de92fe64f3e4f5cd6dda141888f2d99db54c9a60


}

#endif // MAMDANIDEFUZZ_H
