#pragma once

#include "Vector.h"

template <typename T>
class Sequence {
public:
    virtual Sequence<T>* GetSubsequence(int startIndex,int endIndex) = 0;
    virtual Sequence<T>* Concat(Sequence<T>* list) = 0;

    virtual T get_first() = 0;
    virtual T get_last() = 0;
    virtual T get(int index) = 0;
    virtual int size() = 0;

    virtual void push_front(T item) = 0;
    virtual void push_back(T item) = 0;
    virtual void insert_at T item,int index) = 0;

    virtual void print() = 0;
};

template<typename T>
class ArraySequence : public Sequence<T> {
private:
    Vector<T> data;
public:
    ArraySequence(){
        auto tmp = new Vector<T>();
        data = *tmp;
    }
};
