#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

template<class T>
class Array
{
    private:

        T* data = nullptr;
        int size = 0;

    public:

        void append(T val);
        int getSize() {return size;}
        void removeElement(const int index);
        void print(const char* separator = " ");
        bool find(T val);

        T& operator[] (const int index) {return data[index];}
		const T& operator[] (const int index) const {return data[index];}


        ~Array();
};

#include "Array.cpp"

#endif
