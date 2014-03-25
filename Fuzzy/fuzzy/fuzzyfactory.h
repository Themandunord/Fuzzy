#ifndef FUZZYFACTORY_H
#define FUZZYFACTORY_H

#include "../core/expressionfactory.h"
#include "../core/expression.h"
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
        FuzzyFactory();
        FuzzyFactory(And* _and, Or* _or, Then* _then, Agg* _agg, Not* _not);
        virtual ~FuzzyFactory();

        core::Expression<T> newAnd(core::Expression<T> l,core::Expression<T> r);
        core::Expression<T> newOr(core::Expression<T> l,core::Expression<T> r);
        core::Expression<T> newThen(core::Expression<T> l,core::Expression<T> r);
        core::Expression<T> newAgg(core::Expression<T> l,core::Expression<T> r);
        core::Expression<T> newNot(core::Expression<T> o);
        core::Expression<T> newIs(Is s,core::Expression<T> o);

    protected:
        And* m_and;
        Or* m_or;
        Then* m_then;
        Agg* m_agg;
        //Defuzz m_defuzz;
        Not* m_not;
    };

    template< class T >
    FuzzyFactory<T>::FuzzyFactory()
        : m_and(new AndMin()),m_or(new OrMax()),m_then(new ThenMin()),
          m_agg(new AggMax()),m_not(new NotMinus1())
    {

    }

    template< class T >
    FuzzyFactory<T>::FuzzyFactory(And* _and, Or* _or, Then* _then, Agg* _agg, Not* _not)
        : m_and(_and),m_or(_or),m_then(_then),
          m_agg(_agg),m_not(_not)
    {

    }

    template< class T >
    FuzzyFactory<T>::~FuzzyFactory()
    {

    }

    template< class T >
    core::Expression<T> FuzzyFactory<T>::newAnd()
    {

    }

}



#endif // FUZZYFACTORY_H
