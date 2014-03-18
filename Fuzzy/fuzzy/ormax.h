#ifndef ORMAX_H
#define ORMAX_H

namespace fuzzy {
    template<class T>
    class OrMax : public Or<T>{
    public:
       OrMax();
       virtual T evaluate(Expression<T>* l, Expression<T>* r) const;
    };

    template<class T>
    OrMax<T>::OrMax(){

    }

    template<class T>
    T OrMax<T>::evaluate(Expression<T>* l, Expression<T>* r) const{
        return 1;
    }
}

#endif // ORMAX_H
