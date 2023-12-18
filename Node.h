#ifndef INCLUDED_NODE
#define INCLUDED_NODE

#include <iostream>

using namespace std;

class Node {
  
  /* CI: data is defined as integer, (parent, left, right): are
     defined as pointers to another Node objects.
     This class is used for implementation of Binary Search Tree.
  */ 

 private:

  int data;
  Node * parent;
  Node * left;
  Node * right;
  
 public:
  
  // PRE: This object is defined and satisfies the CI.
  // POST: This object has data equal to (0). And has no left,
  // right, and parent Objects. 
  Node();

  // PRE: This object is defined and satisfies the CI. num is defined
  // as an integer.
  // POST: Update the value of data to (num).
  void setData(int num);

  // PRE: This object is defined and satisfies the CI.
  // POST: Get data from this Node object.
  // RV = the integer value of data in this Node object.
  int getData() const;

  // PRE: This object is defined and satisfies the CI. pNode is
  // defined as a pointer to an existing Node object.  
  // POST: Update parent of the current (implicit) object to pNode.
  void setParent(Node * pNode);

  // PRE: This object is defined and satisfies the CI.
  // POST: Get the pointer of the parent Node object.
  // RV = pointer to the parent Node object of the current object.
  Node * getParent() const;

  // PRE: This object is defined and satisfies the CI. pNode is
  // defined as a pointer to an existing Node object.  
  // POST: Update left of the current (implicit) object to pNode.
  void setLeft(Node * pNode);
  
  // PRE: This object is defined and satisfies the CI.
  // POST: Get the pointer of the left Node object.
  // RV = pointer to the left Node object of the current object.
  Node * getLeft() const;

  // PRE: This object is defined and satisfies the CI. pNode is
  // defined as a pointer to an existing Node object.  
  // POST: Update right of the current (implicit) object to pNode.
  void setRight(Node * pNode);

  // PRE: This object is defined and satisfies the CI.
  // POST: Get the pointer of the right Node object.
  // RV = pointer to the right Node object of the current object.
  Node * getRight() const;
  
  // PRE: This object is defined and satisfies the CI.
  // POST: Dynamic memory used by this object is deleted.
  ~Node();
  
};

#endif
