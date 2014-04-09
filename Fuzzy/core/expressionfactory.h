#ifndef EXPRESSIONFACTORY_H
#define EXPRESSIONFACTORY_H

#include "expression.h"
#include "unaryexpression.h"
#include "binaryexpression.h"
#include "binaryexpressionmodel.h"
#include "unaryexpressionmodel.h"
#include "naryexpression.h"
#include "naryexpressionmodel.h"
#include <vector>

namespace core {
    template<class T>
    class ExpressionFactory{
    public:
        ExpressionFactory();
        virtual ~ExpressionFactory();
        // à mettre en protected plutôt?
        virtual Expression<T>* hold(Expression<T>*);
        virtual Expression<T>* newUnary(UnaryExpression<T>*, Expression<T>*);
        virtual Expression<T>* newBinary(BinaryExpression<T>*, Expression<T>*, Expression<T>*);
        //virtual Expression<T>* newNary(NaryExpression<T>*, std::vector<Expression<T>* >);
    private:
        std::vector<Expression<T>* >* memory;
    };

    template<class T>
    ExpressionFactory<T>::ExpressionFactory() : memory(new std::vector<Expression<T>* >())
    {

    }

    template<class T>
    ExpressionFactory<T>::~ExpressionFactory(){
        typename std::vector<Expression<T>* >::iterator iterator = memory->begin();
        for(typename std::vector<Expression<T>* >::iterator it = iterator; it != memory->end(); ++it)
            delete *it;
    }

    template<class T>
    Expression<T>* ExpressionFactory<T>::hold(Expression<T>* e){
        memory->push_back(e);
        return e;
    }

    template<class T>
    Expression<T>* ExpressionFactory<T>::newUnary(UnaryExpression<T>* ope, Expression<T>* o){
        return  hold(new UnaryExpressionModel<T>(o,ope));
    }

    template<class T>
    Expression<T>* ExpressionFactory<T>::newBinary(BinaryExpression<T>* ope, Expression<T>* l, Expression<T>* r){
        return hold(new BinaryExpressionModel<T>(l,r,ope));
    }

    /*template<class T>
    Expression<T>* ExpressionFactory<T>::newNary(NaryExpression<T>* ope, std::vector<Expression<T>* > o){
        return hold(new NaryExpressionModel<T>(o,ope));
    }*/
}

#endif // EXPRESSIONFACTORY_H
