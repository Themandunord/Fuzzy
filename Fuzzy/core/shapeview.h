#ifndef SHAPEVIEW_H
#define SHAPEVIEW_H

#include <iostream>
#include <vector>
#include "unaryexpressionmodel.h"
#include "valuemodel.h"

namespace core {
    template<class T>
    class ShapeView{
    public:
        ShapeView(ValueModel<T>* v,UnaryExpression<T>* e);
        virtual ~ShapeView();
    private:
        std::pair<std::vector<T>*,std::vector<T>* >* m_content;
        ValueModel<T>* m_value;
        UnaryExpressionModel<T>* m_model;

    };

    template<class T>
    ShapeView<T>::ShapeView(ValueModel<T>* v, UnaryExpression<T>* e)
        : m_value(v), m_model(new UnaryExpressionModel<T>(v,e))
    {
        m_content = new std::pair<std::vector<T>*,std::vector<T>* >(new std::vector<T>(), new std::vector<T>());
    }

    template<class T>
    ShapeView<T>::~ShapeView(){
        delete m_model;
    }
}

#endif // SHAPEVIEW_H
