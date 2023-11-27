#include "PmergeMe.hpp"
#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>

// const int K = 5;

// PmergeMe<T>::PmergeMe()
// {

// }

// PmergeMe<T>::PmergeMe(const std::vector<int>& cont) /* : _cont(cont) */
// {

// }

// PmergeMe<T>::PmergeMe(const PmergeMe& obj)
// {
//     this->_cont = obj._cont;
// }


// PmergeMe<T>::~PmergeMe()
// {

// }

// PmergeMe& PmergeMe<T>::operator=(const  PmergeMe& obj)
// {
//     if (this != &obj)
//     {
//         this->_cont = obj._cont;
//     }
//     return(*this);
// }

// void PmergeMe<T>::print_vec()
// {
//     // for(std::vector<int>::iterator it = this->_vec.begin(); it != this->_vec.end(); ++it)
//     // {
//     //     std::cout << *it << " " ;
//     // }
//     // std::cout << std::endl;
// }

// void InsertionSort(std::vector<int>& cont, int start, int end)
// {
//     std::cout << __PRETTY_FUNCTION__ << std::endl;
//     for (int i = start; i < end; i++)
//     {
//         int tmp = cont[i + 1];
//         int j = i + 1;
//         while (j > start && cont[j - 1] > tmp)
//         {
//             cont[j] = cont[j - 1];
//             j--;
//         }
//         cont[j] = tmp;
//     }

//     std::cout << "in Insretionsort\n";
//     for (int i = start; i <= end; ++i)
//     {
//         std::cout << cont[i] << " ";
//     }
//     std::cout << std::endl;
// }


// void MergeSort(std::vector<int>& cont, int start, int mid, int end)
// {
//     std::cout << __PRETTY_FUNCTION__ << std::endl;
//     int i = start;
//     int j = mid + 1;

//     std::vector<int> tmp;
//     while (i <= mid && j <= end)
//     {
//         if (cont[i] <= cont[j])
//         {
//             tmp.push_back(cont[i]);
//             ++i;
//         }
//         else
//         {
//             tmp.push_back(cont[j]);
//             ++j;
//         }
//     }
//     while (i <= mid)
//     {
//         tmp.push_back(cont[i]);
//         ++i;
//     }
//     while (j <= end)
//     {
//         std::cout << "cont[j] = " << cont[j] << "\n";
//         tmp.push_back(cont[j]);
//         ++j;
//     }

//     for (int i = start; i <= end; ++i)
//     {
//         cont[i] = tmp[i - start];
//     }


//     std::cout << "offff = " << std::endl;
//     for (int i = start; i <= end; ++i)
//     {
//         std::cout << tmp[i] << " ";
//     }
// }

// void MergeInsert(std::vector<int>& cont, int start, int end)
// {
//     std::cout << __PRETTY_FUNCTION__ << std::endl;
//     if (end - start > K)
//     {
//         // int q = (start + r) / 2;
//         int mid  = (end - start) / 2 + start;
//         MergeInsert(cont, start, mid);
//         MergeInsert(cont, mid + 1, end);
//         MergeSort(cont, start, mid, end);
//     } 
//     else 
//         InsertionSort(cont, start, end);
// }
