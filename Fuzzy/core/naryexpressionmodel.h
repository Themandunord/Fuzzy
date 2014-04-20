#ifndef NARYEXPRESSIONMODEL_H
#define NARYEXPRESSIONMODEL_H

#include "naryexpression.h"
#include "nullexpressionexception.h"
#include <iostream>


namespace core {

    template<class T>
    class NaryExpressionModel : public NaryExpression<T>, public Expression<T>
    {
    public:
        NaryExpressionModel(std::vector<Expression<T>*>* operands = NULL, NaryExpression<T>* _operator = NULL);
        virtual ~NaryExpressionModel();
        virtual T evaluate(std::vector<Expression<T>*>* operands) const;
        virtual T evaluate() const;

        virtual void setOperator(NaryExpression<T>* _operator);
        virtual void setOperands(std::vector<Expression<T>* >* _operands);

        virtual NaryExpression<T>* getOperator() const;
        virtual std::vector<Expression<T>* >* getOperands() const;
    private:
        std::vector<Expression<T>* >* m_operands;
        NaryExpression<T>* m_operator;
    };

    template<class T>
    NaryExpressionModel<T>::NaryExpressionModel(std::vector<Expression<T>*>* operands, NaryExpression<T>* _operator)
        : m_operands(operands), m_operator(_operator)
    {

    }

    template<class T>
    NaryExpressionModel<T>::~NaryExpressionModel(){

    }

    template<class T>
    T NaryExpressionModel<T>::evaluate(std::vector<Expression<T>*>* operands) const{
        if(m_operator == NULL) throw NullExpressionException("Null operator expression !");

        return m_operator->evaluate(operands);
    }

    template<class T>
    T NaryExpressionModel<T>::evaluate() const{
        if(m_operands == NULL) throw NullExpressionException("Null operator expression !");

        return evaluate(m_operands);
    }
    template<class T>
    void NaryExpressionModel<T>::setOperator(NaryExpression<T>* _operator){
        m_operator = _operator;
    }

    template<class T>
    void NaryExpressionModel<T>::setOperands(std::vector<Expression<T>* >* _operands){
        m_operands = _operands;
    }

    template<class T>
    NaryExpression<T>* NaryExpressionModel<T>::getOperator() const{
        return m_operator;
    }
    template<class T>
    std::vector<Expression<T>* >* NaryExpressionModel<T>::getOperands() const{
        return m_operands;
    }

}

#endif // NARYEXPRESSIONMODEL_H
