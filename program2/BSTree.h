#ifndef __BSTREE_H__
#define __BSTREE_H__

#include "Node.h"

using namespace std;

class BSTree {

private:
  Node *root;

private:
  void preOrder(Node *) const;
  void inOrder(Node *) const;
  void postOrder(Node *) const;
  int height(Node *) const;
  Node* smallest(Node *) const;
  Node* largest(Node *) const;

public:
  BSTree();
  void insert(const string &);
  bool search(const string &) const;
  void inOrder( ) const;
  void postOrder( ) const;
  void preOrder( ) const;
  string largest( ) const;
  string smallest( ) const;
  int height(const string &) const;
  void remove(const string &);
};

#endif
