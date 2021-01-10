#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

Node::Node() {
    count = 1;
    left = nullptr;
    right = nullptr;
    data = "";
}

Node::Node(string data) {
    count = 1;
    left = nullptr;
    right = nullptr;
    this -> data = data;
}
