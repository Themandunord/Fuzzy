#include "nullexpressionexception.h"

namespace core{

NullExpressionException::NullExpressionException(char* str)
    : m_str(str)
{}

const char* NullExpressionException::what() const throw()
{
    return m_str;
}

}
