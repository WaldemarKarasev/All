#pragma once

///for ussing size_t because g++ has strictly requires <cstdef> library
#include <cstddef>
using namespace std;

template <typename T>
class Vector
{
private:
    T* m_Data = nullptr;

    size_t m_Size = 0;
    size_t m_Capacity = 0;

public:

    Vector()
    {
        //allocate 2 elements
        ReAlloc(2);
    }

    ~Vector()
    {
        Clear();
        ::operator delete(m_Data, m_Capacity * sizeof(T));
    }

    void PushBack(const T& value)
    {
        if (m_Size >= m_Capacity)
            ReAlloc(m_Capacity + m_Capacity / 2);

        m_Data[m_Size] = value;
        m_Size++;
    }

    void PushBack(T&& value)
    {
        if (m_Size >= m_Capacity)
            ReAlloc(m_Capacity + m_Capacity / 2);

        m_Data[m_Size] = std::move(value);
        m_Size++;
    }

    void PopBack()
    {
        if (m_Size > 0)
        {
            m_Size--;
            m_Data[m_Size].~T();
        }

    }

    void Clear()
    {
        for (size_t i = 0; i < m_Size; i++)
            m_Data[i].~T();

        m_Size = 0;
    }

    template<typename... Args>
    T& EmplaseBack(Args&&... args)
    {
        if (m_Size >= m_Capacity)
            ReAlloc(m_Capacity + m_Capacity / 2);

        new(&m_Data[m_Size]) T(std::forward<Args>(args)...);
        //m_Data[m_Size] = T(std::forward<Args>(args)...);

        return m_Data[m_Size++];
    }

    const T& operator[](size_t index) const
    {
        if (index >= m_Size)
        {
            //assert
        }

        return m_Data[index];
    }

    T& operator[] (size_t index)
    {
        if (index >= m_Size)
        {
            //assert
        }

        return m_Data[index];
    }

    size_t Size() const
    {
        return m_Size;
    }

    void ReAlloc(size_t newCapacity)
    {
        // 1. alocate a new block of memory
        T* newBlock = (T*)::operator new(newCapacity * sizeof(T));

        // 2. copy/move old elements into new block 
        // 2. if nnewCapacity < m_Size
        size_t size = m_Size;

        if (newCapacity < size)
            size = newCapacity;


        for (size_t i = 0; i < m_Size; ++i)
            newBlock[i] = std::move(m_Data[i]);

        // 3. delete
        for (size_t i = 0; i < m_Size; i++)
            m_Data[i].~T();

        ::operator delete(m_Data, m_Capacity * sizeof(T));
        m_Data = newBlock;
        m_Capacity = newCapacity;

    }

};