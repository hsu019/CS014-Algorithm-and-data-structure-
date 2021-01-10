#include "node.h"
#include <iostream>
#include <string>

node::node( int p, char s){
    priority = p;
    symbol = s;
    left = nullptr;
    right = nullptr;
}

node::node(char s, string str){
    bits = str;
    symbol = s;
    priority = 1;
    left = nullptr;
    right = nullptr;
}

node::node( int p){
    priority = p;
    symbol = '@';
    left = nullptr;
    right = nullptr;
}

void node::setchild(node *l, node *r) {
    left = l;
    right = r;
}

int node::getPriority ( ){
    return priority;
}

string node::getbits() {
    return bits;
}

char node::getsymbol ( ){
    return symbol;
}
