#include<iostream>
using namespace std;

template <class T>
class Tank
{
    private:
    size_t capacity;
    size_t len;
    T* ptr;
    public:
    Tank() : capacity(1),len(0),ptr((T*)malloc(sizeof(T)*capacity)) {};
    size_t size() {return len;}
    size_t cap() {return capacity;}
    void push_back(T x) ;
    void pop_back() ;
    T at(int idx) {return ptr[idx];}
    T operator [] (int idx) {return ptr[idx];}
    template<class U>
    friend U accumulate(Tank<U>);
};

template <class T>
T accumulate(Tank<T> tank);