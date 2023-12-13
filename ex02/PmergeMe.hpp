#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>

const int K = 5;
class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &obj);
        ~PmergeMe();
        PmergeMe& operator=(const PmergeMe& obj);
};

template <typename T>
void print(T &A)
{
    for (size_t i = 0; i < A.size(); ++i)
    {
        std::cout << A[i] << " ";
    }
}

template <typename T>
void InsertionSort(T &A, int p, int q)
{
    // std::cout << __PRETTY_FUNCTION__ << std::endl;
    for (int i = p; i < q; i++)
    {
        int tmp = A[i + 1];
        int j = i + 1;
        while (j > p && A[j - 1] > tmp)
        {
            A[j] = A[j - 1];
            j--;
        }
        A[j] = tmp;
    }
}

template <typename T>
void Merge(T &m_vec, int start, int mid, int end)
{
    // std::cout << __PRETTY_FUNCTION__ << std::endl;
    int i = start;
    int j = mid + 1;

    std::vector<int> tmp;

    while (i <= mid && j <= end)
    {
        if (m_vec[i] <= m_vec[j])
        {
            tmp.push_back(m_vec[i]);
            ++i;
        }
        else
        {
            tmp.push_back(m_vec[j]);
            ++j;
        }
    }
    while (i <= mid)
    {
        tmp.push_back(m_vec[i]);
        ++i;
    }
    while (j <= end)
    {
        tmp.push_back(m_vec[j]);
        ++j;
    }

    for (int i = start; i <= end; ++i)
    {
        m_vec[i] = tmp[i - start];
    }
}

template <typename T>
void MergeInsert(T &A, int p, int r)
{
    // std::cout << __PRETTY_FUNCTION__ << std::endl;
    if (r - p > K)
    {
        int q = (r - p) / 2 + p;
        MergeInsert(A, p, q);
        MergeInsert(A, q + 1, r);
        Merge(A, p, q, r);
    }
    else
        InsertionSort(A, p, r);
}