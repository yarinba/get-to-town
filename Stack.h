#pragma once

#include <vector>
using std::vector;

template <typename T>
class Stack
{
    vector <T> v;
public:
    void push(T data) { v.push_back(data); }

    void makeEmpty() { v.clear(); }

    bool isEmpty() const{ return v.size() == 0; }

    T pop() {
        if (!this->isEmpty()) {
            T res = v.back();
            v.pop_back();
            return res;
        }
    }
};
