#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>


/**
 * @brief Complexity O(N * logN)
 */

template <typename T>
void merge(std::vector<T>& arr, const int left, const int mid, const int right)
{
    const unsigned int leftArraySize = mid - left + 1;
    const unsigned int rightArraySize = mid + right;

    std::vector<T> leftArray, rightArray;
    leftArray.reserve(leftArraySize);
    rightArray.reserve(rightArraySize);

    //std::copy(arr1.begin(), arr1.end(), std::back_inserter(leftArray));
    //std::copy(arr2.begin(), arr2.end(), std::back_inserter(rightArray));
  
    std::copy(arr.begin() + left, arr.begin() + left + (mid - left) + 1, std::back_inserter(leftArray));
    std::copy(arr.begin() + left + (mid - left) + 1, arr.begin() + right + 1, std::back_inserter(rightArray));
   

    std::vector<int>::iterator arrIt = arr.begin() + left;
    std::vector<int>::iterator leftIt = leftArray.begin();
    std::vector<int>::iterator rightIt = rightArray.begin();
    while (leftIt != leftArray.end() && rightIt != rightArray.end())
    {
        if (*leftIt <= *rightIt)
        {
            *arrIt = *leftIt;
            leftIt++;
        }
        else
        {
            *arrIt = *rightIt;
            rightIt++;
        }

        arrIt++;
    }

    while (leftIt != leftArray.end())
    {
        *arrIt = *leftIt;
        leftIt++;
        arrIt++;
    }
    while (rightIt != rightArray.end())
    {
        *arrIt = *rightIt;
        rightIt++;
        arrIt++;
    }

}

template <typename T>
void MergeSort(std::vector<T>& arr, int const begin, const int end)
{
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    
    MergeSort(arr, begin, mid);
    MergeSort(arr, mid + 1, end);
    merge(arr, begin, mid, end);
}


template <typename T>
void copyVector(std::vector<T>& arr_from, std::vector<T>& leftArr, std::vector<T>& rightArr)
{
    size_t mid = 0 + (arr_from.size() - 1 - 0) / 2;
    printf("mid = %i\n", mid);


    //std::copy(start, end, arr_to.begin());
    std::copy(arr_from.begin(), arr_from.begin() + mid, std::back_inserter(leftArr));
    std::copy(arr_from.begin() + mid, arr_from.end(), std::back_inserter(rightArr));
}

int main()
{
    std::vector<int> arr1 = { 6, 2, 4, 3, 1, 38, 13, 5, 7, 43, 2323};
    std::vector<int> arrL, arrR;

    MergeSort(arr1, 0, arr1.size() - 1);

    for (auto elem : arr1)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    copyVector(arr1, arrL, arrR);

    for (auto elem : arrL)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    auto it = arrR.begin();
    while (it != arrR.end())
    {
        if (*it > 2)
        {

            std::cout << *it << " ";
            /* code */
        }
        it++;
    }

    std::cout << std::endl;
}