#include "WordLadder.h"
#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <string>
#include <fstream>
using namespace std;

WordLadder::WordLadder(const string &dictFile) {
    ifstream inFS;
    string word;
    inFS.open(dictFile);
    if(!inFS.is_open()) {
        cout << "Having an error about open " << dictFile << endl;
        return;
    }
    while(!inFS.eof()) {
        inFS >> word;
        dict.push_back(word);
    }
    inFS.close();
}

void WordLadder::outputLadder(const string &start, const string &end, const string &outputFile) {
    cout << "Finding a word ladder from " << start << " to " << end << endl;
    stack<string> first;
    first.push(start);
    queue<stack<string>> wordladder;
    wordladder.push(first);
    while (!wordladder.empty()) {
        string firstword = wordladder.front().top();
        for(list<string>::iterator it = dict.begin(); it != dict.end();) {
            if (findNextWord(*it,firstword) == true) {
                if(*it == end) {
                    cout << "success!" << endl;
                    stack<string> newstack = wordladder.front();
                    newstack.push(*it);
                    putintofile(outputFile, newstack);
                    return;
                }
                else {
                    stack<string> newstack = wordladder.front();
                    newstack.push(*it);
                    wordladder.push(newstack);
                    it = dict.erase(it);
                }
            }
            else {
                ++it;
            }
        }
        wordladder.pop();
        if(dict.empty()){
            cout << "There is no word ladder, because the dictionary is empty." << endl;
            return;
        }
    }
    cout << "There is no word ladder." << endl;
    return;
}

bool WordLadder::findNextWord(const string &newWord,const string &oldWord) {
    int num = 0;
    for(int i = 0; i < 5; ++i) {
        if(newWord.at(i) == oldWord.at(i)) {
                ++num;
        }
    }
    if(num == 4) {
        return true;
    }
    else{
        return false;
    }
}

void WordLadder::putintofile(const string &outputFile,stack<string> &stack) {
    list<string> s;
    while(!stack.empty()) {
        s.push_front(stack.top());
        stack.pop();
    }
    ofstream outFS;
    outFS.open(outputFile);
    if(!outFS.is_open()) {
        cout << "Could not open file " << outputFile << endl;
    }
    while(s.size() != 1) {
        outFS << s.front() << "-->";
        s.pop_front();
    }
    outFS << s.front() << endl;

    outFS.close();
    return;
}
