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
        virtual ~ShapeView();

        virtual std::pair<std::vector<T>*,std::vector<T>* >* getShape() const;

        virtual void addFirst(const T);
        virtual void addSecond(const T);

        virtual void process();
        virtual void print();
        virtual void run();

        virtual ShapeView<T>& setParam(ValueModel<T>* v,UnaryExpression<T>* e, const T& _min, const T& _max, const T& _step);

        static ShapeView<T>& getInstance();

    private:
        ShapeView(ValueModel<T>* v = NULL ,UnaryExpression<T>* e = NULL, const T& _min = 0, const T& _max = 0, const T& _step = 0);

        ValueModel<T>* m_value;
        UnaryExpressionModel<T>* m_model;
        std::vector<T> *m_x, *m_y;
        std::pair<std::vector<T>*,std::vector<T>* >* m_content;
        T m_min, m_max, m_step;

        static ShapeView m_instance;


    };
    template<class T>
    ShapeView<T> ShapeView<T>::m_instance;

    template<class T>
    ShapeView<T>& ShapeView<T>::getInstance(){
       return m_instance;
    }

    template<class T>
    ShapeView<T>::ShapeView(ValueModel<T>* v, UnaryExpression<T>* e, const T& _min, const T& _max, const T& _step)
        : m_value(v), m_model(new UnaryExpressionModel<T>(m_value,e)),
          m_x(new std::vector<T>()),m_y(new std::vector<T>()),
          m_content(new std::pair<std::vector<T>*,std::vector<T>* >(m_x,m_y)),
          m_min(_min), m_max(_max), m_step(_step)
    {

    }

    template<class T>
    ShapeView<T>::~ShapeView(){
        delete m_content;
        delete m_x;
        delete m_y;
        delete m_model;

    }

    template<class T>
    std::pair<std::vector<T>*,std::vector<T>* >* ShapeView<T>::getShape() const{
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
        T v = m_value->evaluate();
        for(float i = m_min; i <= m_max; i+=m_step){
            addFirst(i);
            m_value->setValue(i);
            T result = m_model->evaluate();
            addSecond(result);
        }
        m_value->setValue(v);
    }

    template<class T>
    void ShapeView<T>::print(){
        typename std::vector<T>::iterator itSecond = m_content->second->begin();
        for(typename std::vector<T>::iterator itFirst = m_content->first->begin(); itFirst != m_content->first->end(); ++itFirst){
            std::cout << "[ " << *itFirst << ", " << *itSecond << " ]" << std::endl;
            ++itSecond;
        }
    }

    template<class T>
    ShapeView<T>& ShapeView<T>::setParam(ValueModel<T>* v,UnaryExpression<T>* e, const T& _min, const T& _max, const T& _step){
        m_min = _min;
        m_max = _max;
        m_step = _step;

        delete m_model;
        delete m_x;
        delete m_y;
        delete m_content;

        m_value = v;
        m_model = new UnaryExpressionModel<T>(m_value,e);
        m_x = new std::vector<T>();
        m_y = new std::vector<T>();
        m_content = new std::pair<std::vector<T>*,std::vector<T>* >(m_x,m_y);

        return *this;
    }

    template<class T>
    void ShapeView<T>::run(){
        process();
        print();
    }
}

#endif // SHAPEVIEW_H
