#ifndef ISTRIANGLE_H
#define ISTRIANGLE_H

namespace fuzzy {
    template<class T>
    class Istriangle : public Is<T>{
    public:
        IsTriangle(T min, T mid, T max);
        virtual T evaluate(core::Expression<T>* o) const;
    private:
        T m_min, m_mid, m_max;
    };

    template<class T>
    IsTriangle<T>::IsTriangle(T min, T mid, T max)
        : m_min(min), m_mid(mid), m_max(max)
    {
    }

    template<class T>
    T IsTriangle<T>::evaluate(core::Expression<T>* o) const{
        return 1;
    }


}

#endif // ISTRIANGLE_H
