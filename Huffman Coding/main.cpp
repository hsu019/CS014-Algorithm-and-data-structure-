#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include "node.h"
#include "Heap.h"

using namespace std;

map<char, string> codes;

void pushTable(int *table) {
    ifstream inFS;
    inFS.open("test.txt");
    char letter;
    if(!inFS.is_open()) {
        cout << "Having an error about open test.txt." << endl;
        return;
    }
   while (!inFS.eof()) {
      inFS.get(letter);
      if (!inFS.fail()) {
          if(letter == 'a') {
            table[0]++;
          }
          else if(letter == 'b') {
            table[1]++;
          }
          else if(letter == 'c') {
            table[2]++;
          }
          else if(letter == 'd') {
            table[3]++;
          }
          else if(letter == 'e') {
            table[4]++;
          }
          else if(letter == 'f') {
            table[5]++;
          }
          else if(letter == 'g') {
            table[6]++;
          }
          else if(letter == 'h') {
            table[7]++;
          }
          else if(letter == 'i') {
            table[8]++;
          }
          else if(letter == 'j') {
            table[9]++;
          }
          else if(letter == 'k') {
            table[10]++;
          }
          else if(letter == 'l') {
            table[11]++;
          }
          else if(letter == 'm') {
            table[12]++;
          }
          else if(letter == 'n') {
            table[13]++;
          }
          else if(letter == 'o') {
            table[14]++;
          }
          else if(letter == 'p') {
            table[15]++;
          }
          else if(letter == 'q') {
            table[16]++;
          }
          else if(letter == 'r') {
            table[17]++;
          }
          else if(letter == 's') {
            table[18]++;
          }
          else if(letter == 't') {
            table[19]++;
          }
          else if(letter == 'u') {
            table[20]++;
          }
          else if(letter == 'v') {
            table[21]++;
          }
          else if(letter == 'w') {
            table[22]++;
          }
          else if(letter == 'x') {
            table[23]++;
          }
          else if(letter == 'y') {
            table[24]++;
          }
          else if(letter == 'z') {
            table[25]++;
          }
          else if(letter == ',') {
            table[26]++;
          }
          else if(letter == '.') {
            table[27]++;
          }
          else if(letter == ' ') {
            table[28]++;
          }
      }
   }
    inFS.close();
}

void printTable(int *table){
    for(int i = 0; i < 29 ; ++i) {
        if(i == 0) {
            cout << "'a''s frequencies is " << table[0] << endl;
        }
        else if (i == 1) {
            cout << "'b''s frequencies is " << table[1] << endl;
        }
        else if (i == 2) {
            cout << "'c''s frequencies is " << table[2] << endl;
        }
        else if (i == 3) {
            cout << "'d''s frequencies is " << table[3] << endl;
        }
        else if (i == 4) {
            cout << "'e''s frequencies is " << table[4] << endl;
        }
        else if (i == 5) {
            cout << "'f''s frequencies is " << table[5] << endl;
        }
        else if (i == 6) {
            cout << "'g''s frequencies is " << table[6] << endl;
        }
        else if (i == 7) {
            cout << "'h''s frequencies is " << table[7] << endl;
        }
        else if (i == 8) {
            cout << "'i''s frequencies is " << table[8] << endl;
        }
        else if (i == 9) {
            cout << "'j''s frequencies is " << table[9] << endl;
        }
        else if (i == 10) {
            cout << "'k''s frequencies is " << table[10] << endl;
        }
        else if (i == 11) {
            cout << "'l''s frequencies is " << table[11] << endl;
        }
        else if (i == 12) {
            cout << "'m''s frequencies is " << table[12] << endl;
        }
        else if (i == 13) {
            cout << "'n''s frequencies is " << table[13] << endl;
        }
        else if (i == 14) {
            cout << "'o''s frequencies is " << table[14] << endl;
        }
        else if (i == 15) {
            cout << "'p''s frequencies is " << table[15] << endl;
        }
        else if (i == 16) {
            cout << "'q''s frequencies is " << table[16] << endl;
        }
        else if (i == 17) {
            cout << "'r''s frequencies is " << table[17] << endl;
        }
        else if (i == 18) {
            cout << "'s''s frequencies is " << table[18] << endl;
        }
        else if (i == 19) {
            cout << "'t''s frequencies is " << table[19] << endl;
        }
        else if (i == 20) {
            cout << "'u''s frequencies is " << table[20] << endl;
        }
        else if (i == 21) {
            cout << "'v''s frequencies is " << table[21] << endl;
        }
        else if (i == 22) {
            cout << "'w''s frequencies is " << table[22] << endl;
        }
        else if (i == 23) {
            cout << "'x''s frequencies is " << table[23] << endl;
        }
        else if (i == 24) {
            cout << "'y''s frequencies is " << table[24] << endl;
        }
        else if (i == 25) {
            cout << "'z''s frequencies is " << table[25] << endl;
        }
        else if (i == 26) {
            cout << "',''s frequencies is " << table[26] << endl;
        }
        else if (i == 27) {
            cout << "'.''s frequencies is " << table[27] << endl;
        }
        else if (i == 28) {
            cout << "' ''s frequencies is " << table[28] << endl;
        }
    }
}

void printBinaryTable(node *node,string str) {
    if (!node){
        return;
    }
    if(node->getsymbol() != '@') {
        cout << node -> getsymbol() << ": " << str << endl;
    }
    printBinaryTable(node -> left,str + "0");
    printBinaryTable(node -> right,str + "1");
}

void storecodes(node *node,string str) {
    if (node == nullptr){
        return;
    }
    if(node->getsymbol() != '@') {
        codes[node -> getsymbol()]=str;
    }
    storecodes(node -> left, str + "0");
    storecodes(node -> right, str + "1");
}

void printBits() {
    ifstream inFS;
    inFS.open("test.txt");
    string text;
    if(!inFS.is_open()) {
        cout << "Having an error about open test.txt." << endl;
        return;
    }
    getline(inFS,text);
    inFS.close();

    int num = 0;
    cout << "The huffman code of this .txt is:" << endl;
    for(unsigned i = 0; i < text.size(); ++i){
        cout << codes.find(text.at(i))->second;
        for(unsigned j = 0; j < codes.find(text.at(i))->second.size();++j) {
            ++num;
        }
    }
    cout << endl;
    cout << "the encode length of the binary string is " << num << endl;
    cout << "the length of the binary string befor encode " << text.size() * 8 << endl;
    cout << "the ratio is " << text.size() * 8 / static_cast<double>(num) << endl;

    return;
}

int main() {
    int table[29] ={0};
    pushTable(table);
    printTable(table);
    Heap min_heap;
    char symbol;
    for(int i = 0; i < 26; ++i){
        symbol = 'a' + i;
        min_heap.enqueue(new node(table[i], symbol));
    }
    symbol = ',';
    min_heap.enqueue(new node(table[26], symbol));
    symbol = '.';
    min_heap.enqueue(new node(table[27], symbol));
    symbol = ' ';
    min_heap.enqueue(new node(table[28], symbol));
    while(min_heap.getnumItems() != 1){
        node *temp1 = min_heap.smallest();
        min_heap.dequeue();
        node *temp2 = min_heap.smallest();
        min_heap.dequeue();
        node *temp3 = new node(temp1->getPriority() + temp2->getPriority());
        temp3 -> setchild(temp1,temp2);
        min_heap.enqueue(temp3);
    }
    node *root = min_heap.smallest();
    string binaryTable;
    printBinaryTable(root, binaryTable);
    storecodes(root, binaryTable);
    printBits();


    return 0;
}
