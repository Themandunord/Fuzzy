#ifndef SHAPEBUILDER_H
#define SHAPEBUILDER_H

#include <vector>
#include "expression.h"
#include "valuemodel.h"

namespace core
{
    template<class T>
    class ShapeBuilder
    {

    public:
        virtual ~ShapeBuilder(){}
        static ShapeBuilder<T> &getInstance();
        std::pair<std::vector<T>, std::vector<T> > const& buildShape(ValueModel<T>* vm, Expression<T>* e,T min, T max, T step) const;


    private:
        std::pair<std::vector<T>,std::vector<T> > shape;

        ShapeBuilder(){}
        ShapeBuilder(const ShapeBuilder&);
        void operator=(const ShapeBuilder&);

        typedef std::pair<std::vector<T>, std::vector<T> > Shape;
    };

    template<class T>
    ShapeBuilder<T>& ShapeBuilder<T>::getInstance()
    {
        static ShapeBuilder instance;
        return instance;
    }

    template<class T>
    Shape const& ShapeBuilder::buildShape(ValueModel<T>* vm,Expression<T> *e, const T& min, const T& max, const T& step) const
    {
        std::vector<T> x;
        std::vector<T> y;

        for (T i=min;i<max;i+=step)
        {
            x.push_back(i);
            vm->setValue(i);
            y.push_back(e->evaluate());
        }

        Shape pair(x,y);
        return pair;
    }



}

#endif // SHAPEBUILDER_H
