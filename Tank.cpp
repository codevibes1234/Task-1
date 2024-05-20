#include<iostream>
#include"Tank.h"
using namespace std;

template <class T>
void Tank<T> :: push_back(T x)
{
    if(len == capacity)
    {
        T* ptr1 = (T*) realloc(ptr,sizeof(T)*(2*capacity));
        ptr = ptr1;
        capacity *= 2;
        ptr[len] = x;
        len++;
    }
    else
    {
        ptr[len] = x;
        len++;
    }
}

template <class T>
void Tank<T> :: pop_back()
{
    if(capacity == 2*(len-1) && capacity != 1)
    {
        T* ptr1 = (T*)realloc(ptr,(capacity/2)*sizeof(T));
        ptr = ptr1;
        capacity /= 2;
    }
    else
    ptr[len-1].~T();
    len--;
}

template <class T>
T accumulate(Tank<T> tank)
{
    T sum;
    if(tank.len == 0)
    return sum;
    sum = tank.ptr[0];
    for(int i = 1; i < tank.len; i++)
    sum = sum + tank.ptr[i];
    return sum; 
}