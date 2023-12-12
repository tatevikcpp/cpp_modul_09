#include <iostream>
#include <stack>

class RPN
{
    public:
        RPN() {};
        ~RPN() {};

        RPN(const RPN& obj)
        {
            this->_stack = obj._stack;
        }

        RPN& operator=(const RPN& obj)
        {
            if (this != &obj)
                this->_stack = obj._stack;
            return (*this);
        }
        
        double func(const std::string& str);
    private:
        std::stack<double> _stack;
};
