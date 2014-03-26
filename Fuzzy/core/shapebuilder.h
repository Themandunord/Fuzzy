#ifndef SHAPEBUILDER_H
#define SHAPEBUILDER_H

#include <vector>
#include <iostream>
#include "expression.h"
#include "valuemodel.h"

namespace core
{
    template<class T>
    class ShapeBuilder
    {

    public:
        typedef std::pair<std::vector<T>, std::vector<T> > Shape;

        virtual ~ShapeBuilder(){}
        static ShapeBuilder<T> &getInstance();
        Shape& buildShape(ValueModel<T>* vm, Expression<T>* e,const T& min, const T& max, const T& step);
        Shape& getShape() const;

    private:
        Shape* m_shape;

        ShapeBuilder():m_shape(NULL){}
        ShapeBuilder(const ShapeBuilder&);
        void operator=(const ShapeBuilder&);
    };

    template<class T>
    ShapeBuilder<T>& ShapeBuilder<T>::getInstance()
    {
        static ShapeBuilder instance;
        return instance;
    }

    template<class T>
    typename ShapeBuilder<T>::Shape& ShapeBuilder<T>::buildShape(ValueModel<T>* vm,Expression<T> *e, const T& min, const T& max, const T& step)
    {
        std::vector<T> x;
        std::vector<T> y;

        for (T i=min;i<max;i+=step)
        {
            x.push_back(i);
            vm->setValue(i);
            y.push_back(e->evaluate());
        }

        ShapeBuilder<T>::Shape pair(x,y);
        m_shape=&pair;
        return *m_shape;
    }

    template<class T>
    typename ShapeBuilder<T>::Shape& ShapeBuilder<T>::getShape() const
    {
        if(m_shape == NULL) throw "Null Shape !";
        return *m_shape;
    }



}

template<typename U>
std::ostream& operator<<(std::ostream& os,const typename core::ShapeBuilder<U>::Shape& s)
{
    os << "[";
    for(typename std::vector<U>::const_iterator itx=s.first.begin();itx!=s.first.end();itx++)
        os << *itx << ", ";
    os << "]" << std::endl << "[";
    for(typename std::vector<U>::const_iterator ity=s.second.begin();ity!=s.second.end();ity++)
        os << *ity << ", ";
    os << "]";

    return os;
}

#endif // SHAPEBUILDER_H
