#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <stack>
#include <fstream>
#include "AVLTree.h"
#include "Node.h"

using namespace std;

AVLTree::AVLTree() {
  root = nullptr;
}

bool AVLTree::search(const string &data) const {
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

void AVLTree::insert(const string &data) {
    Node *temp = new Node(data);
    if(root == nullptr){
        this -> root = temp;
        temp -> parent = nullptr;
    }
    else {
        Node* curr = root;
        while (curr != nullptr) {
            if (curr -> data > data) {
                if (curr -> left == nullptr) {
                    curr -> left = temp;
                    temp -> parent = curr;
                    break;
                }
                else {
                    curr = curr -> left;
                }
            }
            else if (curr -> data == data) {
                return;
            }
            else {
                if (curr -> right == nullptr) {
                    curr -> right = temp;
                    temp -> parent = curr;
                    break;
                }
                else {
                    curr = curr -> right;
                }
            }
        }
        temp = temp -> parent;
        while(temp != nullptr){
            rebalance(temp);
            temp = temp -> parent;
        }
    }
}

void AVLTree::rebalance(Node *node) {
      if (balabceFactor(node) == -2) {
        if(balabceFactor(node -> right) == 1){
            rotateRight(node -> right);
        }
        rotateLeft(node);
        return;
      }
      else if(balabceFactor(node) == 2) {
        if(balabceFactor(node -> left) == -1){
            rotateLeft(node -> left);
        }
        rotateRight(node);
        return;
      }
      else {
        return;
      }
}

void AVLTree::rotateRight(Node *node) {
    Node *LeftRightChild = node -> left -> right;
    if (node -> parent == nullptr) {
        root = node ->left;
        root -> parent = nullptr;
    }
    else {
        replaceChild(node -> parent, node -> left, node);
    }
    setChild(node -> left, node, "Right");
    setChild(node, LeftRightChild, "Left");
}

void AVLTree::replaceChild(Node *parentNode,Node *newNode,Node *oldNode) {
    if(parentNode -> left == oldNode) {
        setChild(parentNode,newNode,"Left");
    }
    else if (parentNode -> right == oldNode) {
        setChild(parentNode,newNode,"Right");
    }
    else {
        return;
    }
}

void AVLTree::setChild(Node *parentNode,Node *childNode,const string& whichChild) {
    if(whichChild != "Left" && whichChild != "Right") {
        return;
    }

    if(whichChild == "Right") {
        parentNode -> right = childNode;
    }
    else {
        parentNode -> left = childNode;
    }

    if(childNode != nullptr) {
        childNode -> parent = parentNode;
    }
}

void AVLTree::rotateLeft(Node *node) {
    Node *RightLeftChild = node -> right -> left;
    if(node -> parent == nullptr) {
        root = node -> right;
        root -> parent = nullptr;
    }
    else {
        replaceChild(node -> parent, node -> right, node);
    }
    setChild(node -> right, node , "Left");
    setChild(node, RightLeftChild, "Right");
    return;
}


int AVLTree::height(const string &str) const {
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

int AVLTree::height(Node *node) const{
    if(node == nullptr) {
        return -1;
    }
    int lefthight = height(node -> left);
    int righthight = height(node -> right);
    return 1 + max(lefthight,righthight);
}

int AVLTree::balabceFactor(Node *node) {
    int leftHeight = height(node -> left);
    int rightHeight = height(node -> right);
    int factor = leftHeight - rightHeight;
    return factor;
}

void AVLTree::printBalanceFactors() {
    inOrder(root);
    cout << endl;
}

void AVLTree::inOrder(Node *node){
    if (node == nullptr) {
        return;
    }
    inOrder(node -> left);
    cout << node -> data << "(" << balabceFactor(node) << ")" << ", ";
    inOrder(node -> right);
}

void AVLTree::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error"<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}

void AVLTree::visualizeTree(ofstream & outFS, Node *n){
    if(n){
        if(n->left){
            visualizeTree(outFS,n->left);
            outFS<<n->data <<" -> " <<n->left->data<<";"<<endl;
        }

        if(n->right){
            visualizeTree(outFS,n->right);
            outFS<<n->data <<" -> " <<n->right->data<<";"<<endl;
        }
    }
}
