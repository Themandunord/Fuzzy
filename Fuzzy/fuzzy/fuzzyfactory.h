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
    class FuzzyFactory : public core::ExpressionFactory
    {
    public:
        FuzzyFactory(const And &_and, const Or &_or, const Then &_then, const Agg &_agg, const Not &_not);
        virtual ~FuzzyFactory();

        core::Expression<T>* newAnd(core::Expression<T>* l,core::Expression<T>* r);
        core::Expression<T>* newOr(core::Expression<T>* l,core::Expression<T>* r);
        core::Expression<T>* newThen(core::Expression<T>* l,core::Expression<T>* r);
        core::Expression<T>* newAgg(core::Expression<T>* l,core::Expression<T>* r);
        core::Expression<T>* newNot(core::Expression<T>* o);
        core::Expression<T>* newIs(Is<T>* s,core::Expression<T>* o);

    protected:
        core::BinaryShadowExpression* m_and;
        core::BinaryShadowExpression* m_or;
        core::BinaryShadowExpression* m_then;
        core::BinaryShadowExpression* m_agg;
        //Defuzz m_defuzz;
        core::UnaryShadowExpression* m_not;
    };

    template< class T >
    FuzzyFactory<T>::FuzzyFactory(const And& _and, const Or& _or, const Then& _then, const Agg& _agg, const Not& _not)
        : m_and(new core::BinaryShadowExpression(&_and)),
          m_or(new core::BinaryShadowExpression(&_or)),
          m_then(new core::BinaryShadowExpression(&_then)),
          m_agg(new core::BinaryShadowExpression(&_agg)),
          m_not(new core::UnaryShadowExpression(&_not))
    {

    }

    template< class T >
    FuzzyFactory<T>::~FuzzyFactory()
    {
        delete m_and;
        delete m_or;
        delete m_then;
        delete m_agg;
        delete m_not;
    }

    template< class T >
    core::Expression<T> FuzzyFactory<T>::newAnd(core::Expression* l,core::Expression* r)
    {
        return newBinary(m_and,l,r);
    }

    template< class T >
    core::Expression<T> FuzzyFactory<T>::newOr(core::Expression* l,core::Expression* r)
    {
        return newBinary(m_or,l,r);
    }

    template< class T >
    core::Expression<T> FuzzyFactory<T>::newThen(core::Expression* l,core::Expression* r)
    {
        return newBinary(m_then,l,r);
    }

    template< class T >
    core::Expression<T> FuzzyFactory<T>::newAgg(core::Expression* l,core::Expression* r)
    {
        return newBinary(m_agg,l,r);
    }

    template< class T >
    core::Expression<T> FuzzyFactory<T>::newNot(core::Expression* o)
    {
        return newUnary(m_not,o);
    }

    template< class T >
    core::Expression<T> FuzzyFactory<T>::newIs(Is<T>* is, core::Expression* o)
    {
        return newUnary(is,o);
    }

}



#endif // FUZZYFACTORY_H
