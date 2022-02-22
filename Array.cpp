#ifndef ARRAY_INL
#define ARRAY_INL

#include "Array.hpp"

template<typename T>
void Array<T>::append(T val)
{
    if (!data)
    {
        data = new T[1];
        size++;

        data[0] = val;
    }

    else
    {
        T* buf = new T[size];

        for (int i = 0; i < size; i++)
        {
            buf[i] = data[i];
        }

        data = new T[size + 1];

        for (int i = 0; i < size; i++)
        {
            data[i] = buf[i];
        }

        data[size] = val;
        size++;

        delete [] buf;
    }
}

template<typename T>
void Array<T>::removeElement(const int index)
{
    T* buf = new T[size - 1];

    for (int i = 0; i < index; i++)
    {
        buf[i] = data[i];
    }

    for (int i = index + 1; i < size; i++)
    {
        buf[i - 1] = data[i];
    }

    size--;
    data = new T[size];

    for (int i = 0; i < size; i++)
    {
        data[i] = buf[i];
    }

    delete [] buf;
}

template<typename T>
void Array<T>::print(const char* separator)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << data[i] << separator;
    }
}

template<typename T>
bool Array<T>::find(T val)
{
    for (int i = 0; i < size; i++)
    {
        if (val == data[i])
            return true;
    }

    return false;
}

template<typename T>
Array<T>::~Array()
{
    delete [] data;
}

#endif
