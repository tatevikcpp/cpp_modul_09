#include "BitcoinExchange.hpp"

int main(int c, char **v)
{
    if (c == 2)
    {
        try
        {
            BitcoinExchange obj;
            obj.read_file();
            obj.read_input(v[1]);
            // obj.print();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    else
        std::cout << "could not open file\n";
}