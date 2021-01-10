#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <stack>
#include <fstream>
#include "arithmeticExpression.h"

using namespace std;

arithmeticExpression::arithmeticExpression(const string &str) {
    infixExpression = str;
    root = nullptr;
}

void arithmeticExpression::buildTree() {
    string poststr = infix_to_postfix();
    stack<TreeNode*> mystack;
    for(unsigned i = 0; i < poststr.size(); ++i){
        char key = 'a' + i;
        char data = poststr.at(i);
        TreeNode *temp = new TreeNode(data, key);
        if (temp -> data == '*'|| temp -> data == '/'|| temp -> data == '+'|| temp -> data == '-') {
            temp -> right = mystack.top();
            mystack.pop();
            temp -> left = mystack.top();
            mystack.pop();
            mystack.push(temp);
        }
        else {
            mystack.push(temp);
        }
    }
    root = mystack.top();
}

void arithmeticExpression::infix(){
    infix(root);
}

void arithmeticExpression::infix(TreeNode *node){
    if(node == nullptr) {
        return;
    }
    if(node -> left != nullptr) {
        cout << "(";
    }
    infix(node -> left);
    cout << node -> data;
    infix(node -> right);
    if(node -> left != nullptr) {
        cout << ")";
    }

    return;

}

void arithmeticExpression::prefix() {
    prefix(root);
}

void arithmeticExpression::prefix(TreeNode *node) {
    if(node == nullptr) {
        return;
    }
    cout << node -> data;
    prefix(node -> left);
    prefix(node -> right);
}

void arithmeticExpression::postfix() {
    postfix(root);
}

void arithmeticExpression::postfix(TreeNode *node) {
    if(node == nullptr){
        return;
    }
    postfix(node -> left);
    postfix(node -> right);
    cout << node -> data;
}

int arithmeticExpression::priority(char op){
    int priority = 0;
    if(op == '('){
        priority =  3;
    }
    else if(op == '*' || op == '/'){
        priority = 2;
    }
    else if(op == '+' || op == '-'){
        priority = 1;
    }
    return priority;
}

string arithmeticExpression::infix_to_postfix(){
    stack<char> s;
    ostringstream oss;
    char c;
    for(unsigned i = 0; i< infixExpression.size();++i){
        c = infixExpression.at(i);
        if(c == ' '){
            continue;
        }
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
            if( c == '('){
                s.push(c);
            }
            else if(c == ')'){
                while(s.top() != '('){
                    oss << s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty() && priority(c) <= priority(s.top())){
                    if(s.top() == '('){
                        break;
                    }
                    oss << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else{ //c is an operand
            oss << c;
        }
    }
    while(!s.empty()){
        oss << s.top();
        s.pop();
    }
    return oss.str();
}

void arithmeticExpression::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error opening "<< outputFilename<<endl;
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

void arithmeticExpression::visualizeTree(ofstream &outFs, TreeNode *node) {
    if(node == root) {
        stack<char> table;
        for (char i = 'a';i != 'z';++i) {
            table.push(i);
        }
        changenode(outFs,root,table);
    }
    if (node -> left == nullptr) {
        return;
    }
    else {
        outFs << "\"" << node -> data << "\"" << " -> " << "\"" <<node -> left -> data<< "\"" << endl;
        visualizeTree(outFs, node -> left);
    }
    if (node -> right == nullptr) {
        return;
    }
    else {
        outFs << "\"" << node -> data << "\"" << " -> " << "\"" <<node -> right -> data<< "\"" << endl;
        visualizeTree(outFs, node -> right);
    }
}

void arithmeticExpression::changenode(ofstream &outFs, TreeNode *node,stack<char>& table) {
    if(node == nullptr) {
        return;
    }

    outFs << table.top() <<  " [color = lightblue, style = filled, label=" << "\"" << node -> data << "\"];" << endl;
    node -> data = table.top();
    table.pop();
    changenode(outFs,node -> left, table);
    changenode(outFs,node -> right, table);
}
