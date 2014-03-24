#ifndef NULLEXPRESSIONEXCEPTION_H
#define NULLEXPRESSIONEXCEPTION_H

#include <exception>

namespace core{

class NullExpressionException : public std::exception
{
public:
    NullExpressionException(char* str="Null Expression !");
    virtual ~NullExpressionException() throw() {}
    virtual const char* what() const throw();
private:
    char* m_str;
};

}

#endif // NULLEXPRESSIONEXCEPTION_H
