#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <cstdlib>

using namespace std;

const int MAX_SIZE = 20;

template <class T>
class stack {
 private:
    int size;
    T data[MAX_SIZE];
 public:
    stack(){
        size = 0;
    }
    void push(T val){
        if (size == MAX_SIZE) {
            throw overflow_error("Called push on full stack.");
        }
        else {
            data[size] = val;
            ++size;
        }
    }

    void pop() {
        if(empty()) {
            throw out_of_range("Called pop on empty stack.");
        }
        else {
            --size;
        }
    }
    T top() {
        if(empty()) {
            throw underflow_error("Called top on empty stack.");
        }
        else {
            return data[size - 1];
        }
    }
    bool empty() {
        if(size == 0) {
            return true;
        }
        else {
            return false;
        }
    }

};

#endif
