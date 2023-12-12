#include <cstring> // strtok
#include <cstdlib> //atoi / atof
#include "rpn.hpp"

bool is_operator(char c)
{
    return (c == '+' || c == '-' || c == '/' || c == '*');
}

double math_functions(char c, double a, double b)
{
    if (c == '+')
        return (a + b);
    else if (c == '-')
        return (a - b);
    else if (c == '/')
    {
        if (b == 0)
        {
            throw std::runtime_error("Math error: Attempted to divide by zero");
        }
        return (a / b);
    }
    else if (c == '*')
    {
        return (a * b);
    }
    throw std::runtime_error("error");
}


double RPN::func(const std::string& str)
{
    const char *ptr;

    ptr = strtok(const_cast<char *>(str.c_str()), " ");
    while (ptr != NULL)
    {
        if (isdigit(*ptr) && *(ptr + 1) == '\0')
        {
                this->_stack.push(atof(ptr));
        }
        else  if (is_operator(*ptr) && this->_stack.size() >= 2)
        {
            double b = this->_stack.top();
            this->_stack.pop();
            double a = this->_stack.top();
            this->_stack.pop();
            this->_stack.push(math_functions(*ptr, a, b));
        }
        else 
            throw std::runtime_error("bad input");
        ptr = strtok(NULL, " ");
    }
    if (this->_stack.size() == 1)
    {
        return (this->_stack.top());
    }
    throw std::runtime_error("bad input");
}
