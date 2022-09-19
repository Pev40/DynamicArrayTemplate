#include <iostream>
#include "DynamicArray.h"

template<typename T>
DynamicArray<T>::DynamicArray(){
    size=0;
    arr=new T[0];
}
template<typename T>
DynamicArray<T>::DynamicArray(const T arr[],int size){
    this->size=size;
    this->arr=new T[size];

    for (int i = 0; i < size; i++)
    {
        this->arr[i]=arr[i];
    }
    
}


template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T> &o){
    this->size=o.size;
    this->arr = new T[o.size];

    for (int i = 0; i < size; i++)
    {
        this->arr[i]=o.arr[i];
    }
}

template<typename T>
int DynamicArray<T>::getSize(){
    return this->size;
}

template<typename T>
void DynamicArray<T>::push_back(T elem){
    this->size = this->getSize()+1;
    T *arrayNuevo = new T[this->getSize()];
    for (int i = 0; i < this->getSize(); i++)
    {
        arrayNuevo[i]=this->arr[i];
    }
    arrayNuevo[this->getSize()-1]=elem;
    delete []this->arr;
    this->arr = arrayNuevo;
    return;
}

template<typename T>
void DynamicArray<T>::remove(int pos){
    if(pos >= size || pos<0){
        std::cout<<std::endl<<"Esa Posicion NO EXISTE"<<std::endl;
        return;
    }
    if(pos == size){
        T *arrayNuevo = new T[size-1];
        for (int i = 0; i < pos-1; i++)
        {
            arrayNuevo[i]= this->arr[i];
        }
        size -=1;
        delete []arr;
        arr = arrayNuevo;
        return;
    }
    else{
        T *arrayNuevo = new T[size-1];
        for (int i = 0; i < pos; i++)
        {
            arrayNuevo[i]= this->arr[i];
        }
        for (int i = pos+1; i < size; i++)
        {
            arrayNuevo[i-1]=this->arr[i];
        }
        size -=1;
        delete []this->arr;
        arr = arrayNuevo;
        return;
    }

}   


template<typename T>
void DynamicArray<T>::insert(T elem, int pos){
    if (pos >= size)
    {   
        if (pos > size)
        {
            std::cout<<std::endl<<"Caso1.1"<<std::endl;
            T *newArray = new T[pos+1];
            T n(0,0);
            for (int i = 0; i < size; i++)
            {
                newArray[i] = this->arr[i];
            }
            for (int i = size; i < pos-1; i++)
            {
                newArray[i] = n;
            }
            newArray[pos-1] = elem; 
            delete []arr;
            arr = newArray;
            size = pos;
        }

        else
        {
            std::cout<<std::endl<<"Caso1.2"<<std::endl;
            T *newArray = new T[size+1];
            T n(0,0);
            for (int i = 0; i < size; i++)
            {
                newArray[i] = this->arr[i];
            }
            newArray[pos] = elem; 
            delete []arr;
            arr = newArray;
            size +=1;
        }
        
        

        return;    
    }
    else{
        std::cout<<std::endl<<"Caso2"<<std::endl;
        T *newArray = new T[size+1];
        for (int i = 0; i < pos; i++)
        {
            newArray[i] = this->arr[i];
        }
        newArray[pos] = elem;

        for (int i = pos; i < size; i++)
        {
            newArray[i+1] = this->arr[i];
        }
        size = size+1;
        delete[] arr;
        arr = newArray;
        return;
    } 
    return ;
}


template<typename T>
void DynamicArray<T>::imprimir(){
    for (int i = 0; i < size; i++)
    {
       arr[i].ver();
    }
}


template<typename T>
DynamicArray<T>::~DynamicArray(){
    delete []arr;
}