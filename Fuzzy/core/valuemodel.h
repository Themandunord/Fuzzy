#ifndef VALUEMODEL_H
#define VALUEMODEL_H

#include "expression.h"

namespace core {
    template<class T>
    class ValueModel : public Expression<T> {
    public :
        ValueModel(T* _value);
        virtual ~ValueModel();
        virtual T evaluate() const;
        virtual void setValue(const T* _value);
    private :
        T* m_value;
    };

    template<class T>
    ValueModel<T>::ValueModel(T* _value) : m_value(_value){

    }

    template<class T>
    ValueModel<T>::~ValueModel(){
        delete m_value;
    }

    template<class T>
    T ValueModel<T>::evaluate() const{
        return *m_value;
    }

    template<class T>
    void ValueModel<T>::setValue(const T* _value){
            *m_value = *_value;
    }
}

#endif // VALUEMODEL_H
