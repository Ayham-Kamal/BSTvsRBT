#include <iostream>
#include "Node.h"

using namespace std;

// PRE: This object is defined and satisfies the CI.
// POST: This object has data equal to (0). And has no left,
// right, and parent Objects.
Node::Node(){
  parent = NULL;
  left = NULL;
  right = NULL;
  data = 0;
}

// PRE: This object is defined and satisfies the CI. num is defined
// as an integer.
// POST: Update the value of data to (num).
void Node::setData(int num){
  data = num;
}

// PRE: This object is defined and satisfies the CI.
// POST: Get data from this Node object.
// RV = the integer value of data in this Node object.
int Node::getData() const{
  return (data);
}

// PRE: This object is defined and satisfies the CI. pNode is
// defined as a pointer to an existing Node object.
// POST: Update parent of the current (implicit) object to pNode.
void Node::setParent(Node * pNode){
  parent = pNode;
}

// PRE: This object is defined and satisfies the CI.
// POST: Get the pointer of the parent Node object.
// RV = pointer to the parent Node object of the current object.
Node * Node::getParent() const{
  return (parent);
}

// PRE: This object is defined and satisfies the CI. pNode is
// defined as a pointer to an existing Node object.
// POST: Update left of the current (implicit) object to pNode.
void Node::setLeft(Node * pNode){
  left = pNode;
}

// PRE: This object is defined and satisfies the CI.
// POST: Get the pointer of the left Node object.
// RV = pointer to the left Node object of the current object.
Node * Node::getLeft() const{
  return (left);
}

// PRE: This object is defined and satisfies the CI. pNode is
// defined as a pointer to an existing Node object.
// POST: Update right of the current (implicit) object to pNode.
void Node::setRight(Node * pNode){
  right = pNode;
}

// PRE: This object is defined and satisfies the CI.
// POST: Get the pointer of the right Node object.
// RV = pointer to the right Node object of the current object.
Node * Node::getRight() const{
  return (right);
}

// PRE: This object is defined and satisfies the CI.
// POST: Dynamic memory used by this object is deleted.
Node::~Node(){
  
  if (left != NULL){
    delete left;
  }
  if (right != NULL){
    delete right;
  }
  data = 0;  
}
