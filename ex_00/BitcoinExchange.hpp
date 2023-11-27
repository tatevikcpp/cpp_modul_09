#pragma once

#include <iostream>
#include <fstream>
#include <map>

class BitcoinExchange
{
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& obj);
        ~BitcoinExchange();
        BitcoinExchange& operator=(const BitcoinExchange& obj);
        void read_input(const std::string& file);
        void read_file();
        void print();
        void valid_str(std::string str);
    private:
        std::map<std::string, double, std::greater<std::string> > _map;
};


