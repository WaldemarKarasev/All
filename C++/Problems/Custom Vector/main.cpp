#include <iostream>
#include <string>
#include "Vector.h"
//#include <cstddef>
//using namespace std;




struct Vector3{
    float x = 0.0f, y = 0.0f, z = 0.0f;
    int* MemoryBlock = nullptr;

    Vector3() { MemoryBlock = new int[5]; }
    Vector3(float scalar)
        : x(scalar), y(scalar), z(scalar) {
            MemoryBlock = new int[5];
        }
    Vector3(float x, float y, float z)
        : x(x), y(y), z(z) {
            MemoryBlock = new int[5];
        }

    //Disable copying
    Vector3(const Vector3& other) = delete;
    /////////////////

    Vector3(Vector3&& other)
        : x(other.x), y(other.y), z(other.z)
    {
        MemoryBlock = other.MemoryBlock;
        other.MemoryBlock = nullptr;
        std::cout << "Move\n";
    }   
  
    ~Vector3()
    {
        std::cout << "Destroy\n";
        delete[] MemoryBlock;
    }

    
    //Disable copying operator=
    Vector3& operator=(const Vector3& other) = delete;
    ///////////////// 
    Vector3& operator=(Vector3&& other)
    {
        MemoryBlock = other.MemoryBlock;
        other.MemoryBlock = nullptr;
        std::cout << "Move\n";
        x = other.x;
        y = other.y;
        z = other.z;
        
        return *this;
    }

};


template <typename T>
void PrintVector(const Vector<T>& vector)
{
    for (size_t i = 0; i < vector.Size(); ++i)
        std::cout << vector[i] << std::endl;

    std::cout << "--------------------\n";    
}

void PrintVector3(const Vector<Vector3>& vector)
{
    for (size_t i = 0; i < vector.Size(); ++i)
        std::cout << vector[i].x << ", " << vector[i].y << ", " << vector[i].z << std::endl;

    std::cout << "--------------------\n";    
}

int main()
{
    Vector<Vector3> vector;

    vector.EmplaseBack(1.0f);
    vector.EmplaseBack(1.0f, 2.0f, 3.0f);
    vector.EmplaseBack();
    PrintVector3(vector);
    vector.PopBack();
    vector.PopBack();
    PrintVector3(vector);
    vector.EmplaseBack(3.0f, 5.0f, 9.0f);
    vector.EmplaseBack();
    PrintVector3(vector);

    vector.Clear();
    PrintVector3(vector);
    vector.EmplaseBack(1.0f, 2.0f, 3.0f);
    vector.EmplaseBack(1.0f, 4.0f, 3.0f);
    vector.EmplaseBack(7.0f, 2.0f, 3.0f);
    
    PrintVector3(vector);


    Vector<int> arr;
    arr.PushBack(1);
    arr.PushBack(6);
    arr.EmplaseBack(10);
    arr.PushBack(1);
    arr.PushBack(6);
    arr.PushBack(9);
    PrintVector(arr);


    return 0;
}

