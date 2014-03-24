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
        ShapeView(UnaryExpression<T>* e, T _min, T _max, T _delta);
        virtual ~ShapeView();

        virtual std::pair<std::vector<T>*,std::vector<T>* >* getPair() const;

        virtual void addFirst(const T);
        virtual void addSecond(const T);

        virtual void process();
        virtual void print();
    private:
        std::pair<std::vector<T>*,std::vector<T>* >* m_content;
        ValueModel<T>* m_value;
        UnaryExpressionModel<T>* m_model;
        float m_delta;
        T m_min, m_max;

    };

    template<class T>
    ShapeView<T>::ShapeView(UnaryExpression<T>* e, T _min, T _max, T _delta)
        : m_value(new ValueModel<T>(_min)), m_model(new UnaryExpressionModel<T>(m_value,e)),
          m_content(new std::pair<std::vector<T>*,std::vector<T>* >(new std::vector<T>(), new std::vector<T>())),
          m_min(_min), m_max(_max), m_delta(_delta)
    {

    }

    template<class T>
    ShapeView<T>::~ShapeView(){
        delete m_model;
    }

    template<class T>
    std::pair<std::vector<T>*,std::vector<T>* >* ShapeView<T>::getPair() const{
        return m_content;
    }

    template<class T>
    void ShapeView<T>::addFirst(const T _value){
        m_content->first->push_back(_value);
    }

    template<class T>
    void ShapeView<T>::addSecond(const T _value){
        m_content->second->push_back(_value);
    }

    template<class T>
    void ShapeView<T>::process(){
        for(float i = m_min; i < m_max; i+=m_delta){
            addFirst(i);
            m_value->setValue(i);
            T result = m_model->evaluate();
            addSecond(result);
        }
    }

    template<class T>
    void ShapeView<T>::print(){
        typename std::vector<T>::iterator itSecond = m_content->second->begin();
        for(typename std::vector<T>::iterator itFirst = m_content->first->begin(); itFirst != m_content->first->end(); ++itFirst){
            std::cout << "[ " << *itFirst << ", " << *itSecond << " ]" << std::endl;
            ++itSecond;
        }
    }
}

#endif // SHAPEVIEW_H
