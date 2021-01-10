#include "Heap.h"
#include "PrintJob.h"
#include <iostream>

Heap::Heap(){
    numItems = 0;
}

void Heap::enqueue(PrintJob* newjob){
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
    PrintJob* job;
    job = arr[newnode];
    arr[newnode] = arr[oldnode];
    arr[oldnode] = job;
}

void Heap::dequeue(){
    if(numItems == 0){
        return;
    }
    arr[0] = arr[numItems - 1];
    --numItems;
    trickleDown(0);
    return;
}
void Heap::trickleDown(int index) {
    int childIndex = 2 * index + 1;
    int value = arr[index] ->getPriority();

    while (childIndex < numItems) {
        int maxValue = value;
        int maxIndex = -1;
        for(int i = 0; i < 2 && i + childIndex < numItems; ++i) {
            if(arr[i + childIndex] ->getPriority() > maxValue) {
                maxValue = arr[i + childIndex] -> getPriority();
                maxIndex = i + childIndex;
            }
        }

        if(maxValue == value) {
            return;
        }
        else {
            swap(index, maxIndex);
            index = maxIndex;
            childIndex = 2 * index + 1;
        }
    }
}

PrintJob* Heap::highest() {
    if(numItems == 0) {
        return nullptr;
    }
    return arr[0];
}

void Heap::print() {
    if(numItems == 0) {
        return;
    }
    PrintJob* job;
    job = arr[0];
    cout << "Priority: " << job -> getPriority() << ", Job Number: " << job -> getJobNumber()<< ", Number of Pages: " << job ->getPages() << endl;
    return;
}
