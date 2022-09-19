#ifndef __DYNAMICARRAY_H__
#define __DYNAMICARRAY_H__

#include "Point.h"
template<typename T>
class DynamicArray
{
private:
    T *arr;
    int size;

public:
    DynamicArray();    
    DynamicArray(const T arr[],int size);
    DynamicArray(const DynamicArray<T> &o);

    void push_back(T elem);

    void insert(T elem, int pos);
    void remove(int pos);

    int getSize();

    void imprimir();
    ~DynamicArray();


};


#endif
