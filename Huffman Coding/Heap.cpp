#include "Heap.h"
#include "node.h"
#include <iostream>

Heap::Heap(){
    numItems = 0;
}

int Heap::getnumItems(){
    return numItems;
}

void Heap::enqueue(node* newjob){
    if(numItems == MAX_HEAP_SIZE) {
        return;
    }
    if(numItems == 0){
        arr[0] = newjob;
        ++numItems;
        return;
    }
    arr[numItems] = newjob;
    bubbleUp(numItems);
    ++numItems;
}
void Heap::bubbleUp(int index) {
    if(arr[index] -> getPriority() <= arr[(index - 1) / 2] -> getPriority() || index == 0){
        return;
    }
    swap(index,(index - 1) / 2);
    bubbleUp((index - 1) / 2);
}
void Heap::swap(int newnode,int oldnode) {
    node* job;
    job = arr[newnode];
    arr[newnode] = arr[oldnode];
    arr[oldnode] = job;
}

void Heap::dequeue(){
    if(numItems == 0){
        return;
    }
    --numItems;
    return;
}


node* Heap::smallest() {
    if(numItems == 0) {
        return nullptr;
    }
    return arr[numItems - 1];
}

void Heap::print() {
    if(numItems == 0) {
        return;
    }
    node* job;
    job = arr[0];
    cout << "Priority: " << job -> getPriority() << endl;
    return;
}
