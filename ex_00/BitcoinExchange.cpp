#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <cstring>
#include <string>

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj)
{
    
}

BitcoinExchange::~BitcoinExchange()
{

}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange& obj)
{
    return (*this);
}

void BitcoinExchange::read_file()
{
    std::ifstream fin;

    fin.open("data.csv");

    if (fin.is_open())
    {
        std::string str;
        std::string day;

        if (getline(fin, str))
        {
            while (!fin.eof())
            {
                getline(fin, str);
                size_t pos = 0;

                if ((pos = str.find(",")) != std::string::npos)
                {
                    day = str.substr(0, pos);
                    // val = strtod(str.erase(0,pos+del.length()).c_str(), NULL);
                    this->_map[day] = strtod(str.substr(pos+1).c_str(), NULL);
                }
            }
        }
        else
            throw std::runtime_error("empty file");
    }
    else
        throw std::runtime_error("can not open file");

    fin.close();
}

// static bool isSpace(int c) {
//     return (!std::isspace(c));
// }

inline std::string &strTrim(std::string &str) {
    str.erase(0, str.find_first_not_of(" "));
    int pos = str.find_last_not_of(" ") + 1;
    str.erase(pos, str.size() - pos);
    return (str);
}

void BitcoinExchange::read_input(const std::string& file)
{
    std::ifstream fin;
    std::string str;
    std::string day;
    double  val;
    size_t pos = 0;

    fin.open(file.c_str());

    if (fin.is_open())
    {
        if (getline(fin, str))
        {
            while (!fin.eof())
            {
                getline(fin, str);
                if ((pos = str.find("|")) != std::string::npos)
                {
                    day = str.substr(0, pos);
                    char *ptr;
                    // strTrim(0,pos + 1);
                    std::string tmp = str.substr(pos + 1);
                    val = strtod(tmp.c_str(), &ptr);
                    try
                    {
                        std::cout << "-ptr " << (int)*ptr  << std::endl;
                        if (!std::isspace(*ptr))
                        {
                        printf("ptr = %d\n", *ptr);
                            throw std::runtime_error("invalid val");
                        }
                        if (val < 1 || val > 1000)
                        {
                            throw std::runtime_error("out of range");
                        }
                        strTrim(day);
                        // std::cout << "day = " << day << "$" << std::endl;                        // remove space
                        valid_str(day);
                    }
                    catch(const std::exception& e)
                    {
                        std::cerr << day << " -> " << e.what() << '\n';
                        continue;
                    }
                    std::map<std::string, double>::iterator it = this->_map.lower_bound(day);

                    if (it != this->_map.end())
                    {
                        double money = it->second * val;
                        std::cout << day << " => " << val << " = " << money << std::endl;
                    }
                    else
                        std::cout << day << " not found\n";
                }
                else
                {
                    std::cout << "Error bad input => " << str << std::endl;
                }
            }
        }
        else
            throw std::runtime_error("empty file");
    }
    else
        throw std::runtime_error("can not open file");
    // print();
    fin.close();
}



void BitcoinExchange::print()
{
    for(std::map<std::string, double>::iterator it = _map.begin();
        it != _map.end(); ++it)
    {
        std::cout << "|"<< it->first << "|" << " " << it->second<< "\n";
    }
}

/* char *ft_strtok(char *str, char c)
{
    static char *bufer = str;

    if (str == NULL && bufer == NULL) 
    {
        return(NULL);
    }

    int i = 0;

    while (bufer[i])
    {
        if (bufer[i] == c)
        {
            while (bufer[i] == c)
            {
                bufer[i++] = '/0';
            }
            break ;
        }
        ++i;
    }
    if (bufer[i] == '/0')
    {
        bufer = NULL;
    }
    bufer += i;
    return (bufer - i);
} */



bool is_digit(const std::string &str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

bool is_leap_year(int year)
{
    return ((year % 400 == 0 || year % 100 != 0) && (year % 4 == 0));
}

// bool is_leap_year(int year) 
// {
//   if (year % 4 != 0) {
//     return false;
//   } else if (year % 400 == 0) {
//     return true;
//   } else if (year % 100 == 0) {
//     return false;
//   } else {
//     return true;
//   }
// }

bool func(int year, int month, int day)
{
    // std::cout << "func\n";
    if (day > 31)
    {
        return (0);
    }

    if (!is_leap_year(year) && (month == 2) && (day > 28))
    {
        // std::cout << "petrvar\n";
        return (0);
    }

    if (is_leap_year(year) && month == 2 && day > 29)
    {
        // std::cout << "petrvar_28\n";
        return (0);
    }

    if (((month % 2 == 0) && (month != 8)) && day > 30)
    {
        return (0);
    }

    return (1);
}


void BitcoinExchange::valid_str(std::string str)
{
    str += "-";
    int count = 0;
    size_t pos = 0;
    char *c_str = (char *)str.c_str();
    std::string year;
    std::string month;
    std::string day;

    char *ptr = strtok(c_str, "-");

    if (ptr == NULL)
        throw std::runtime_error("bad input tari");
    
    year = ptr;

    if (!is_digit(year))
    {
        throw std::runtime_error("bad input year");
    }

    ptr = strtok(NULL, "-");

    if (ptr == NULL)
        throw std::runtime_error("bad input year");
    
    month = ptr;

    if (month.size() != 2 || !is_digit(month) || (atoi(month.c_str()) > 12))
        throw std::runtime_error("bad input month");
    
    ptr = strtok(NULL, "-");

    if (ptr == NULL)
        throw std::runtime_error("bad input month");
    
    day = ptr;

    if ((day.size() != 2 || !is_digit(day)) || !func(atoi(year.c_str()), atoi(month.c_str()), atoi(day.c_str())))
        throw std::runtime_error("bad input day");

    ptr = strtok(NULL, "-");

    if (ptr != NULL)
        throw std::runtime_error("bad input ayl");
}