#include <iostream>
#include "IntList.h"

using namespace std;

    IntList::IntList(){
        dummyHead = new IntNode(0);
        dummyTail = new IntNode(0);
        head = dummyHead;
        tail = dummyTail;
        dummyHead -> next = dummyTail;
        dummyTail -> prev = dummyHead;
    }
    IntList::~IntList() {
        while(head -> next != tail) {
            IntNode* temp = head -> next;
            temp -> prev -> next = temp -> next;
            temp -> next -> prev = temp -> prev;
            delete temp;
        }
    }
    void IntList::push_front(int value) {
        IntNode *temp = new IntNode(value);
        temp -> next = head -> next;
        head -> next -> prev = temp;
        head -> next = temp;
        temp -> prev = head;
    }
    void IntList::pop_front() {
        if(head -> next != tail) {
            IntNode* temp = head -> next;
            head -> next = temp -> next;
            temp -> next -> prev = head;
            delete temp;
        }
    }
    void IntList::push_back(int value) {
    IntNode *temp = new IntNode(value);
        temp -> prev = tail -> prev;
        temp -> next = tail;
        tail -> prev -> next = temp;
        tail -> prev = temp;
    }
    void IntList::pop_back() {
        if(head -> next != tail) {
            IntNode* temp = tail -> prev;
            tail -> prev = temp -> prev;
            temp -> prev -> next = tail;
            delete temp;
        }
    }
    bool IntList::empty() const {
        if(head -> next == tail) {
            return true;
        }
        return false;
    }
    ostream & operator<<(ostream &out, const IntList &rhs){
        IntNode* temp;
        temp = rhs.head;
        if(rhs.empty() == true) {
            out << "There is no node in the list." << endl;
            return out;
        }
        temp = temp -> next;
        while(temp != rhs.tail -> prev) {
            out << temp -> data << " ";
            temp = temp -> next;
        }
        out << temp -> data;
        return out;
    }
    void IntList::printReverse() const {
        if (empty() == true) {
            cout << "There is no node in the list" << endl;
            return;
        }
        else {
            IntNode* temp = tail -> prev;
            while (temp -> prev != head) {
                cout << temp -> data << " ";
                temp = temp -> prev;
            }
            cout << temp -> data;
            return;
        }
    }
