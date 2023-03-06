#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>


/**
 * @brief Complexity O(N^2) 
 */
template <typename T>
void printVector(const std::vector<T>& arr)
{
    std::cout << "[ ";
    for (size_t i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " "; 
    }
    std::cout << "]\n";
}

/**
 * @brief Complexity O(N^2) 
 */
template <typename T>
void SelectionSort(std::vector<T>& arr)
{
    for (size_t i = 0; i < arr.size() - 1; i++)
    {
        size_t min = i;
        for (size_t j = i+1; j < arr.size(); j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
                        
        }
        if (i != min)
        {
            T tmp = arr[i];
            arr[i] = arr[min];
            arr[min] = tmp;
        }
        
        
    }
}

/**
 * @brief Complexity O(N^2) 
 */
template <typename T>
void BubbleSort(std::vector<T>& arr)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        for (size_t j = 0; j < arr.size() - 1 - i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                T tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
            
        }
        
    }
    
}

/**
 * @brief Complexity O(N^2) 
 */
template <typename T>
void InsertionSort(std::vector<T>& arr)
{
    T key;
    int j; // important to use int, because when j=0 && arr[j] > key We have in while loop j-- => (int j = -1) and size_t (j = MAX(size_t))
    for (size_t i = 1; i < arr.size(); i++)
    {
        key = arr[i];
        j = i - 1;

        while (arr[j] > key && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    
}


/**
 * @brief Function for merging arrays for MergeSort function
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

/**
 * @brief Complexity O(N * logN) 
 */
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
    size_t mid = 0 + (arr_from.size()-1 - 0)/2;
    printf("mid = %i\n", mid);

    
    //std::copy(start, end, arr_to.begin());
    std::copy(arr_from.begin(), arr_from.begin() + mid, std::back_inserter(leftArr));
    std::copy(arr_from.begin() + mid, arr_from.end(), std::back_inserter(rightArr));
}

int main()
{
    std::vector<int> arr1 = {6, 5, 8, 2, 3, 1, 9, 23, 47};
    std::vector<int> arrL, arrR;

    MergeSort(arr1, 0, arr1.size() - 1);

    for (auto elem : arr1)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}