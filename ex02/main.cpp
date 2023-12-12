#include "PmergeMe.hpp"
#include <sys/time.h>

void checkDigit(char **str)
{
    int i = 1;
    while (str[i])
    {
        int j = 0;
        while (str[i][j])
        {
            if (!isdigit(str[i][j]))
            {
                throw std::invalid_argument("Error");
            }
            j++;
        }
        i++;
    }
}


long double get_currenet_time()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int main(int c, char **v)
{
    try
    {
       if (c > 2)
        {
            std::vector<int> vec;
            std::deque<int> dec;

            for (int i = 1; i < c; i++)
            {
                checkDigit(v);
                int a = atoi(v[i]);
                if (a < 0)
                {
                    throw std::invalid_argument("error");
                }
                vec.push_back(a);
                dec.push_back(a);
            }
            std::cout << "Before: " << std::endl;
            print(vec);
            std::cout << std::endl;
            double start_time_vec = get_currenet_time();
            MergeInsert(vec, 0, vec.size() - 1);
            double end_time_vec = get_currenet_time();

            double start_time_dec = get_currenet_time();
            MergeInsert(dec, 0, dec.size() - 1);
            double end_time_dec = get_currenet_time();

            std::cout << "Aftr: " << std::endl;
            print(vec);
            std::cout << std::endl;
            std::cout << "Time to process a range of " << dec.size() << " elements with std::deque  : " << end_time_dec - start_time_dec  << " us" << std::endl;
            std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << end_time_vec - start_time_vec  << " us" << std::endl;
        }
        else
        {
            std::cout << "error argument qanak" << std::endl; // TO DO
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    





    // if (c > 2)
    // {
    //     std::vector<int> vec;
    //     std::deque<int> dec;

    //     for (int i = 1; i < c; i++)
    //     {
    //         checkDigit(v);
    //         int a = atoi(v[i]);
    //         if (a < 0)
    //         {
    //             throw std::invalid_argument("error");
    //         }
    //         vec.push_back(a);
    //         dec.push_back(a);
    //     }
    //     std::cout << "Before: " << std::endl;
    //     print(vec);
    //     std::cout << std::endl;
    //     double start_time_vec = get_currenet_time();
    //     MergeInsert(vec, 0, vec.size() - 1);
    //     double end_time_vec = get_currenet_time();

    //     double start_time_dec = get_currenet_time();
    //     MergeInsert(dec, 0, dec.size() - 1);
    //     double end_time_dec = get_currenet_time();

    //     std::cout << "Aftr: " << std::endl;
    //     print(vec);
    //     std::cout << std::endl;
    //     std::cout << "Time to process a range of " << dec.size() << " elements with std::deque  : " << end_time_dec - start_time_dec  << " us" << std::endl;
    //     std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << end_time_vec - start_time_vec  << " us" << std::endl;
    // }
    // else
    // {
    //     std::cout << "error argument qanak" << std::endl; // TO DO
    // }
    // return 0;
}