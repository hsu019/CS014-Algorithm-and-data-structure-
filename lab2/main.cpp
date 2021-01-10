#include <iostream>
#include "IntList.h"

using namespace std;

int main() {
    IntList list1;
    list1.push_front(1);
    list1.push_back(2);
    list1.push_front(3);
    list1.push_back(4);
    cout << "-----------------------test display---------------" << endl;
    cout << list1;
    cout << endl;
    list1.printReverse();
    cout << "------------------------test delete------------------" << endl;
    list1.pop_back();
    list1.pop_front();
    cout << "-------------------------test empty----------------" << endl;
    if(list1.empty() == true){
        cout << "the list is empty" << endl;
    }
    else {
        cout << "the list is not empty" << endl;
    }
    list1.pop_back();
    list1.pop_front();
    if(list1.empty() == true){
        cout << "the list is empty" << endl;
    }
    else {
        cout << "the list is not empty" << endl;
    }    
    return 0;
}