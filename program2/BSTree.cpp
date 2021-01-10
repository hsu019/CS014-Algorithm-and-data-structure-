#include <iostream>
#include <string>
#include "BSTree.h"
#include "Node.h"

using namespace std;

BSTree::BSTree() {
  root = nullptr;
}

void BSTree::insert(const string &data) {
    Node *temp = new Node(data);
    if(root == nullptr){
        this -> root = temp;
    }
    else {
        Node* curr = root;
        while (curr != nullptr) {
            if (curr -> data > data) {
                if (curr -> left == nullptr) {
                    curr -> left = temp;
                    break;
                }
                else {
                    curr = curr -> left;
                }
            }
            else if (curr -> data == data) {
                curr -> count = curr -> count + 1;
                break;
            }
            else {
                if (curr -> right == nullptr) {
                    curr -> right = temp;
                    break;
                }
                else {
                    curr = curr -> right;
                }
            }
        }
    }
}

bool BSTree::search(const string &data) const {
    bool check = false;
    if(root == nullptr){
        return check;
    }
    else {
        Node *curr = root;
        while (curr != nullptr) {
            if (curr -> data > data) {
                curr = curr -> left;
            }
            else if (curr -> data == data) {
                check = true;
                return check;
            }
            else {
                curr = curr -> right;
            }
        }
        return check;
    }
}

void BSTree::remove(const string & data) {
    if (search(data) == false){
        return;
    }
    else {
        Node *par = nullptr;
        Node *curr = root;
        while (curr != nullptr) {
            if (curr -> data == data) {
                if (curr -> count > 1) {
                    curr -> count = curr -> count - 1;
                }
                else{
                    if(curr -> left == nullptr && curr -> right == nullptr) {
                        if(par == nullptr) {
                            root = nullptr;
                            delete curr;
                        }
                        else if(par -> left == curr) {
                            par -> left = nullptr;
                            delete curr;
                        }
                        else {
                            par -> right = nullptr;
                            delete curr;
                        }
                    }
                    else if (curr->left != nullptr) {
                        Node *temp = largest(curr -> left);
                        string newstr = temp -> data;
                        int newint = temp -> count;
                        temp -> count = 1;
                        remove(newstr);
                        curr -> data = newstr;
                        curr -> count = newint;
                    }
                    else {
                        Node *suc = smallest(curr -> right);
                        string temp = suc -> data;
                        int swap = suc -> count;
                        suc -> count = 1;
                        remove(temp);
                        curr -> data = temp;
                        curr -> count = swap;
                    }
                }
                return;
            }
            else if (curr -> data < data) {
                par = curr;
                curr = curr -> right;
            }
            else {
                par = curr;
                curr = curr -> left;
            }
        }
    }
}

void BSTree::inOrder( ) const {
    inOrder(root);
}

void BSTree::inOrder(Node* node) const {
    if(node == nullptr) {
        return;
    }
    inOrder(node -> left);
    cout << node -> data << "(" << node -> count << "), ";
    inOrder(node -> right);
}

void BSTree::postOrder( ) const {
    postOrder(root);
}

void BSTree::postOrder(Node* node) const {
    if (node != nullptr) {
        postOrder(node -> left);
        postOrder(node -> right);
        cout << node -> data << "(" << node -> count << "), ";
    }
}

void BSTree::preOrder( ) const {
    preOrder(root);
}

void BSTree::preOrder(Node* node) const {
    if(node != nullptr) {
        cout << node -> data << "(" << node -> count << "), ";
        preOrder(node -> left);
        preOrder(node -> right);
    }
}

Node* BSTree::smallest(Node *temp) const {
    while(temp -> left != nullptr) {
        temp = temp -> left;
    }
    return temp;
}

string BSTree::smallest( ) const {
    if (root == nullptr) {
        return "";
    }
    else {
        return smallest(root) -> data;
    }
}

Node* BSTree::largest(Node *temp) const {
    while (temp -> right != nullptr) {
        temp = temp -> right;
    }
    return temp;
}

string BSTree::largest( ) const {
    if (root == nullptr) {
        return "";
    }
    else {
        return largest(root) -> data;
    }
}

int BSTree::height(const string &str) const {
    if (search(str) == false){
        return -1;
    }
    else {
        Node *temp = root;
        while(temp != nullptr) {
            if(temp -> data > str) {
                temp= temp -> left;
            }
            else if (temp -> data < str) {
                temp = temp -> right;
            }
            else{
                break;
            }
        }
        return height(temp);
    }
}

int BSTree::height(Node *node) const{
    if(node == nullptr) {
        return -1;
    }
    int lefthight = height(node -> left);
    int righthight = height(node -> right);
    return 1 + max(lefthight,righthight);
}
