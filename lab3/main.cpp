#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <cstdlib>

using namespace std;

template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index) {
    int minindex = index;
    for(unsigned num = index + 1; num < vals.size(); ++num) {
        if(vals.at(minindex) > vals.at(num)) {
            minindex = num;
        }
    }

    return minindex;
}

template<typename T>
void selection_sort(vector<T> &vals) {
    for (unsigned i = 0; i < vals.size(); ++i) {
        int min = min_index(vals,i);
        T temp = vals.at(i);
        vals.at(i) = vals.at(min);
        vals.at(min) = temp;
    }
}

vector<char> createVector(){
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }
    return vals;
}

template<typename T>
T getElement(vector<T> vals, int index) {
    unsigned i = index;
    if (i >= vals.size()) {
        throw runtime_error("std::outofrange");
    }

    return vals.at(index);
}

int main(){

    //Part B
     srand(time(0));
     vector<char> vals = createVector();
     char curChar;
     int index;
     int numOfRuns = 10;
     while(--numOfRuns >= 0){
         cout << "Enter a number: " << endl;
         cin >> index;
         try {
         curChar = getElement(vals,index);
         cout << "Element located at " << index << ": is " << curChar << endl;
         }
        catch (const out_of_range &excpt){
        cout << excpt.what() << endl;
        cout <<  "out of range exception occured"  << endl;
        }
    }

    return 0;
}
