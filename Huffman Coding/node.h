#ifndef __NODE_H
#define __NODE_H

#include <string>

using namespace std;

class node {
private:
  int priority;
  char symbol;
  string bits = "";

public:
  node *left;
  node *right;
  node ( int, char);
  node( int );
  node(char, string);
  int getPriority ( );
  char getsymbol ( );
  string getbits();
  void setchild(node *, node *);
  //You can add additional functions here
};
#endif
