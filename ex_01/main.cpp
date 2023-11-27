// #include "RPN.hpp"
#include <iostream>
#include <stack>
#include <utility>
#include <string>
#include <cstring>
#include <cstdlib>

int main()
{
    std::string str = "8 9 * 9 - 9 - 9 - 4 - 1 +";
    std::stack<int> stack;
    char *ptr = strtok (const_cast<char *>(str.c_str())," ");
    while(ptr != NULL)
    {
        std::cout << atoi(ptr);
        // stack.push(atoi(ptr));
        std::cout << ptr << " ";
        std::cout << isdigit(ptr) << std::endl;
        if (isdigit(atoi(ptr)))
        {
            std::cout << "lalala\n";
            std::cout << "push " << atoi(ptr) << std::endl;
            stack.push(atoi(ptr));
        }
        ptr = strtok (NULL, " "); // veranayel STRTOK funkcian
    }
}