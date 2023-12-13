#include "PmergeMe.hpp"
#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
    (void)obj;
}

PmergeMe::~PmergeMe()
{

}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj)
{
    (void)obj;
    return (*this);
}