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
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    else
        std::cout << "Error: could not open file." << std::endl;
}