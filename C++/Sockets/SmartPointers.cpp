#include <iostream>
#include <string>
#include <memory>



using namespace std;

template <typename T>
class SmartPointer
{
public:

    SmartPointer(T* ptr)
    {
        this->ptr = ptr;
    }

    ~SmartPointer()
    {
        delete ptr;
    }

    T& operator *()
    {
        return *ptr;
    }

private:

    T* ptr;

};


int main()
{
    int size;
    cin >> size;

    shared_ptr<int[]> ptr(new int[size]{ 1,2,3,4,5 });
    
    for (int i = 0; i < size; i++)
    {
        ptr[i] = rand() % 10;
        cout << ptr[i] << endl;
    }



    return 0;
}