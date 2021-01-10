
#include <iostream>
#include "IntList.h"

using namespace std;

    IntList::IntList(){
        dummyHead = nullptr;
        dummyTail = nullptr;
    }
    IntList::~IntList() {
        while(dummyHead != nullptr) {
            IntNode* temp = dummyHead;
            if(temp -> next == nullptr) {
                dummyHead = nullptr;
                dummyTail = nullptr;
                delete temp;
            }
            else {
                dummyHead = temp -> next;
                temp -> next -> prev = nullptr;
                delete temp;
            }
        }
    }
    void IntList::push_front(int value) {
        IntNode *temp = new IntNode(value);
        if(dummyHead != nullptr) {
            IntNode* curr = dummyHead;
            curr -> prev = temp;
            temp -> next = dummyHead;
            dummyHead = temp;
        }
        else {
            dummyHead = temp;
            dummyTail = temp;
        }
    }
    void IntList::pop_front() {
        if(dummyHead != nullptr) {
            IntNode* temp = dummyHead;
            if(dummyHead -> next == nullptr) {
                dummyHead = nullptr;
                dummyTail = nullptr;
                delete temp;
            }
            else {
                dummyHead = temp -> next;
                temp -> next -> prev = nullptr;
                delete temp;
            }
        }
    }
    void IntList::push_back(int value) {
        IntNode *temp = new IntNode(value);
        if(dummyHead != nullptr) {
            IntNode* curr = dummyTail;
            temp -> prev = dummyTail;
            curr -> next = temp;
            dummyTail = temp;
        }
        else {
            dummyHead = temp;
            dummyTail = temp;
        }
    }
    void IntList::pop_back() {
        if(dummyHead != nullptr) {
            IntNode* temp = dummyTail;
            if(dummyHead -> next == nullptr) {
                dummyHead = nullptr;
                dummyTail = nullptr;
                delete temp;
            }
            else {
                dummyTail = temp -> prev;
                temp -> prev -> next = nullptr;
                delete temp;
            }
        }
    }
    bool IntList::empty() const {
        if(dummyHead == nullptr) {
            return true;
        }
        return false;
    }
    ostream & operator<<(ostream &out, const IntList &rhs){
        IntNode* temp;
        temp = rhs.dummyHead;
        if(rhs.empty() != true) {
            while(temp -> next != nullptr) {
                out << temp -> data << " ";
                temp = temp -> next;
            }
            out << temp -> data;
        }
        return out;
    }
    void IntList::printReverse() const {
        if (empty() != true) {
            IntNode* temp = dummyTail;
            while (temp != dummyHead) {
                cout << temp -> data << " ";
                temp = temp -> prev;
            }
            cout << temp -> data;
        }
    }
