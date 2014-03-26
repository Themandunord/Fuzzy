#ifndef FUZZYFACTORY_H
#define FUZZYFACTORY_H

#include "../core/expressionfactory.h"
#include "../core/expression.h"
#include "../core/unaryshadowexpression.h"
#include "../core/binaryshadowexpression.h"
#include "and.h"
#include "andmin.h"
#include "or.h"
#include "ormax.h"
#include "then.h"
#include "thenmin.h"
#include "agg.h"
#include "aggmax.h"
#include "not.h"
#include "notminus1.h"
#include "is.h"
#include "istriangle.h"



namespace fuzzy{
    template< class T >
    class FuzzyFactory : public core::ExpressionFactory<T>
    {
    public:
        FuzzyFactory(const And<T> &_and, const Or<T> &_or, const Then<T> &_then, const Agg<T> &_agg, const Not<T> &_not);
        virtual ~FuzzyFactory();

        core::Expression<T>* newAnd(core::Expression<T>* l,core::Expression<T>* r);
        core::Expression<T>* newOr(core::Expression<T>* l,core::Expression<T>* r);
        core::Expression<T>* newThen(core::Expression<T>* l,core::Expression<T>* r);
        core::Expression<T>* newAgg(core::Expression<T>* l,core::Expression<T>* r);
        core::Expression<T>* newNot(core::Expression<T>* o);
        core::Expression<T>* newIs(Is<T>* s,core::Expression<T>* o);

        void setAnd(const And<T>& _and);
        void setOr(const Or<T>& _or);
        void setThen(const Then<T>& _then);
        void setAgg(const Agg<T>& _agg);
        void setNot(const Not<T>& _not);

    protected:
        core::BinaryShadowExpression<T> m_and;
        core::BinaryShadowExpression<T> m_or;
        core::BinaryShadowExpression<T> m_then;
        core::BinaryShadowExpression<T> m_agg;
        //Defuzz m_defuzz;
        core::UnaryShadowExpression<T> m_not;
    };

    template< class T >
    FuzzyFactory<T>::FuzzyFactory(const And<T>& _and, const Or<T>& _or, const Then<T>& _then, const Agg<T>& _agg, const Not<T>& _not)
        : m_and(&_and),
          m_or(&_or),
          m_then(&_then),
          m_agg(&_agg),
          m_not(&_not)
    {

    }

    template< class T >
    FuzzyFactory<T>::~FuzzyFactory()
    {
    }

    template< class T >
    core::Expression<T>* FuzzyFactory<T>::newAnd(core::Expression<T>* l,core::Expression<T>* r)
    {
        return this->newBinary(&m_and,l,r);
    }

    template< class T >
    core::Expression<T>* FuzzyFactory<T>::newOr(core::Expression<T>* l,core::Expression<T>* r)
    {
        return this->newBinary(&m_or,l,r);
    }

    template< class T >
    core::Expression<T>* FuzzyFactory<T>::newThen(core::Expression<T>* l,core::Expression<T>* r)
    {
        return this->newBinary(&m_then,l,r);
    }

    template< class T >
    core::Expression<T>* FuzzyFactory<T>::newAgg(core::Expression<T>* l,core::Expression<T>* r)
    {
        return this->newBinary(&m_agg,l,r);
    }

    template< class T >
    core::Expression<T>* FuzzyFactory<T>::newNot(core::Expression<T>* o)
    {
        return this->newUnary(&m_not,o);
    }

    template< class T >
    core::Expression<T>* FuzzyFactory<T>::newIs(Is<T>* is, core::Expression<T>* o)
    {
        return this->newUnary(is,o);
    }

    template<class T>
    void FuzzyFactory<T>::setAnd(const And<T> &_and)
    {
        m_and.setBinaryExpression(&_and);
    }

    template<class T>
    void FuzzyFactory<T>::setOr(const Or<T> &_or)
    {
        m_or.setBinaryExpression(&_or);
    }

    template<class T>
    void FuzzyFactory<T>::setThen(const Then<T> &_then)
    {
        m_then.setBinaryExpression(&_then);
    }

    template<class T>
    void FuzzyFactory<T>::setAgg(const Agg<T> &_agg)
    {
        m_agg.setBinaryExpression(&_agg);
    }

    template<class T>
    void FuzzyFactory<T>::setNot(const Not<T> &_not)
    {
        m_not.setUnaryExpression(&_not);
    }

}



#endif // FUZZYFACTORY_H
