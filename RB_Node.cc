#include "RB_Node.h"
#include <iostream>

using namespace std;

// PRE: This object is defined and satisfies the CI.
// POST: This object has data equal to (0). And has no left,
// right, and parent Objects, and color equal to white space, and
// empty equal to True.
RB_Node::RB_Node(){
  parent = NULL;
  left = NULL;
  right = NULL;
  data = 0;
  color = ' ';
  empty = true;
}

// PRE: This object is defined and satisfies the CI. update is
// defined as a boolean and holds the new value of empty.
// POST: Update the value of empty to (update).
void RB_Node::setEmpty(bool update){
  empty = update;
}


// PRE: This object is defined and satisfies the CI.
// POST: Get the value of the boolean variable empty of this object.
// RV = the boolean value of empty in this RB_Node object. Return
// True if it's an external node, otherwise, return False if it's an
// internal node.
bool RB_Node::isEmpty() const{
  return (empty);
}


// PRE: This object is defined and satisfies the CI. num is defined
// as an integer.
// POST: Update the value of data to (num).
void RB_Node::setData(int num){
  data = num;
}

// PRE: This object is defined and satisfies the CI.
// POST: Get data from this RB_Node object.
// RV = the integer value of data in this RB_Node object.
int RB_Node::getData() const{
  return (data);
}

// PRE: This object is defined and satisfies the CI. pNode is
// defined as a pointer to an existing RB_Node object.
// POST: Update parent of the current (implicit) object to pNode.
void RB_Node::setParent(RB_Node * pNode){
  parent = pNode;
}

// PRE: This object is defined and satisfies the CI.
// POST: Get the pointer of the parent RB_Node object.
// RV = pointer to the parent RB_Node object of the current object.
RB_Node * RB_Node::getParent() const{
  return (parent);
}

// PRE: This object is defined and satisfies the CI. pNode is
// defined as a pointer to an existing RB_Node object.
// POST: Update left of the current (implicit) object to pNode.
void RB_Node::setLeft(RB_Node * pNode){
  left = pNode;
}

// PRE: This object is defined and satisfies the CI.
// POST: Get the pointer of the left RB_Node object.
// RV = pointer to the left RB_Node object of the current object.
RB_Node * RB_Node::getLeft() const{
  return (left);
}

// PRE: This object is defined and satisfies the CI. pNode is
// defined as a pointer to an existing RB_Node object.
// POST: Update right of the current (implicit) object to pNode.
void RB_Node::setRight(RB_Node * pNode){
  right = pNode;
}

// PRE: This object is defined and satisfies the CI.
// POST: Get the pointer of the right RB_Node object.
// RV = pointer to the right RB_Node object of the current object.
RB_Node * RB_Node::getRight() const{
  return (right);
}

// PRE: This object is defined and satisfies the CI. pColor is
// defined as a character holding the new value of color ('R' / 'B').
// POST: Update the value of color to pColor.
void RB_Node::setColor(char pColor){
  color = pColor;
}

// PRE: This object is defined and satisfies the CI.
// POST: Get the value of the character variable color of this object.
// RV = the charcter value of color in this RB_Node object. Return
// 'R' if it's a red RB_Node, otherwise, return 'B' if it's a black
// RB_Node.
char RB_Node::getColor() const{
  return (color);
}

// PRE: This object is defined and satisfies the CI.
// POST: Dynamic memory used by this object is deleted.
RB_Node::~RB_Node(){
  if (left != NULL){
    delete left;
  }
  if (right != NULL){
    delete right;
  }
  data = 0;
  color = ' ';
  empty = true;
}

