#ifndef __BSTREE_H__
#define __BSTREE_H__

#include "Node.h"

using namespace std;

class AVLTree {
private:
  Node *root;

private:
  void inOrder(Node *);
  int height(Node *) const;
  int height(const string &) const;
  void rebalance(Node *);
  void rotateLeft(Node *);
  void rotateRight(Node *);
  void visualizeTree(ofstream & , Node *);
  void replaceChild(Node *,Node *,Node *);
  void setChild(Node *,Node *,const string& );
  bool search(const string &) const;

public:
  AVLTree();
  void insert(const string &);
  int balabceFactor(Node *);
  void printBalanceFactors();
  void visualizeTree(const string &);
};

#endif
