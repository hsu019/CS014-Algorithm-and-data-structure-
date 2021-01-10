#include "HashTable.h"
#include "WordEntry.h"

/* HashTable constructor
*  input s is the size of the array
*  set s to be size
*  initialize array of lists of WordEntry
*/
HashTable::HashTable (int s) {
    size = s;
    //创建一个新的list<wordEntry>数组。将哈希表（指针）设置为数组第一个地址的值，并且从这里可以访问这个数组的其他元素。
    hashTable = new list<WordEntry>[size];
}


/* computeHash
*  return an integer based on the input string
*  used for index into the array in hash table
*  be sure to use the size of the array to
*  ensure array index doesn't go out of bounds
*/

int HashTable::computeHash(const string &s)
{
    int hash = 0;
    for(unsigned i = 0; i < s.size(); ++i) //The idea is it finds the prime values in the string, adds them
    {
        hash += s[i];
        if(i % 2 != 0) //if prime
        {
            hash += s[i]; //add to hash index
        }
        else
        {
            ++hash; //makes value prime
        }
    }
    int index = hash%size;
    return index;
}


/* put
*  input: string word and int score to be inserted
*  First, look to see if word already exists in hash table
*   if so, addNewAppearence with the score to the WordEntry
*   if not, create a new Entry and push it on the list at the
*   appropriate array index
*/
void HashTable::put(const string &s, int score) {
    int index = computeHash(s); //获取字符串的哈希值当作索引

    //If word already exists in the hash table, update the score and number of occurrences to the record
    if(contains(s)) {
        //遍历位于索引处的列表，查找对应的word
        for(list<WordEntry>::iterator itr = hashTable[index].begin(); itr != hashTable[index].end(); ++itr) {
            if(itr->getWord() == s) {
                //更新记录的分数和出现次数
                itr->addNewAppearance(score);
                return;
            }
        }
        return;
    }

    //如果没有越界就将word push进去
    if(index < size) {
        hashTable[index].push_back(WordEntry(s,score));
    }
}

/* getAverage
*  input: string word
*  output: the result of a call to getAverage()
*          from the WordEntry
*  Must first find the WordEntry in the hash table
*  then return the average
*  If not found, return the value 2.0 (neutral result)
*/

double HashTable::getAverage(const string &s) {
    int index = computeHash(s);//获取字符串的哈希值当作索引

    // 遍历列表，查看值是否在链接列表中
    for(list<WordEntry>::iterator itr = hashTable[index].begin(); itr != hashTable[index].end(); ++itr) {
        //存在，返回平均值
        if(itr->getWord() == s) {
            return itr->getAverage(); //return average
        }
    }

    //If not found, return the value 2.0
    return 2.0;
}

/* contains
* input: string word
* output: true if word is in the hash table
*         false if word is not in the hash table
*/
bool HashTable::contains(const string &s) {
    int index = computeHash(s);//获取字符串的哈希值当作索引

    //遍历列表，查看值是否在链接列表中
    for(list<WordEntry>::iterator itr = hashTable[index].begin(); itr != hashTable[index].end(); ++itr) {
        //true if word is in the hash table
        if(itr->getWord() == s) {
            return true;
        }
    }

    //false if word is not in the hash table
    return false;
}

