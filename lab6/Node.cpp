#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

Node::Node() {
    left = nullptr;
    right = nullptr;
    parent = nullptr;
    data = "";
}

Node::Node(string data) {
    left = nullptr;
    right = nullptr;
    parent = nullptr;
    this -> data = data;
}
