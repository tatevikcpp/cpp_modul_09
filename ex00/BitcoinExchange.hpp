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
    private:
        void valid_str(std::string str);
        std::map<std::string, double, std::greater<std::string> > _map;
};