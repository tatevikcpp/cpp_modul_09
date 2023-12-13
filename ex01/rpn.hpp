#include <iostream>
#include <stack>

class RPN
{
    public:
        RPN();
        ~RPN();
        RPN(const RPN& obj);
        RPN& operator=(const RPN& obj);
        double func(const std::string& str);
    private:
        std::stack<double> _stack;
};