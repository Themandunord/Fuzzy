#ifndef VALUEMODEL_H
#define VALUEMODEL_H

#include "expression.h"

namespace core {
    template<class T>
    class ValueModel : public Expression<T> {
    public :
        ValueModel(T* value);
        virtual ~ValueModel();
        virtual T evaluate() const;
        virtual void setValue(const T* value);
    private :
        T* m_value;
    };

    template<class T>
    ValueModel<T>::ValueModel(T* value) : m_value(value){

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
    void ValueModel<T>::setValue(const T* value){
            *m_value = *value;
    }
}

#endif // VALUEMODEL_H
