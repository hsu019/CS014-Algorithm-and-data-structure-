#ifndef __NODE_H__
#define __NODE_H__

#include <iostream>
#include <string>

using namespace std;

class Node {
  public:
    Node* left;
    Node* right;
    Node* parent;
    string data;
    Node();
    Node(string data);
};

#endif
