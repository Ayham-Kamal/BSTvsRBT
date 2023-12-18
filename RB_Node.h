#ifndef INCLUDED_RB_NODE
#define INCLUDED_RB_NODE

#include <iostream>

using namespace std;

class RB_Node {
  /* CI: data is defined as integer, (parent, left, right): are
    defined as pointers to another RB_Node objects, color is defined
    as character and has two possible values (R: for Red, B: for
    Black), empty is defined as boolean (True: for NIL nodes (Leaves)
    "External Nodes", False: for normal, key-bearing nodes "Internal
    Nodes") 
    This class is used for implementation of Red Black Tree.
  */
  
private:
  int data;
  RB_Node * parent;
  RB_Node * left;
  RB_Node * right;
  char color;
  bool empty;
  
public:
  
  // PRE: This object is defined and satisfies the CI.
  // POST: This object has data equal to (0). And has no left,
  // right, and parent Objects, and color equal to white space, and
  // empty equal to True. 
  RB_Node();
  
  // PRE: This object is defined and satisfies the CI. update is
  // defined as a boolean and holds the new value of empty.   
  // POST: Update the value of empty to (update).
  void setEmpty(bool update);

  // PRE: This object is defined and satisfies the CI.
  // POST: Get the value of the boolean variable empty of this object.
  // RV = the boolean value of empty in this RB_Node object. Return
  // True if it's an external node, otherwise, return False if it's an
  // internal node.
  bool isEmpty() const;  

  // PRE: This object is defined and satisfies the CI. num is defined
  // as an integer.
  // POST: Update the value of data to (num).
  void setData(int num);

  // PRE: This object is defined and satisfies the CI.
  // POST: Get data from this RB_Node object.
  // RV = the integer value of data in this RB_Node object.
  int getData() const;

  // PRE: This object is defined and satisfies the CI. pNode is
  // defined as a pointer to an existing RB_Node object.
  // POST: Update parent of the current (implicit) object to pNode.
  void setParent(RB_Node * pNode);

  // PRE: This object is defined and satisfies the CI.
  // POST: Get the pointer of the parent RB_Node object.
  // RV = pointer to the parent RB_Node object of the current object.
  RB_Node * getParent() const;

  // PRE: This object is defined and satisfies the CI. pNode is
  // defined as a pointer to an existing RB_Node object.
  // POST: Update left of the current (implicit) object to pNode.
  void setLeft(RB_Node * pNode);

  // PRE: This object is defined and satisfies the CI.
  // POST: Get the pointer of the left RB_Node object.
  // RV = pointer to the left RB_Node object of the current object.
  RB_Node * getLeft() const;

  // PRE: This object is defined and satisfies the CI. pNode is
  // defined as a pointer to an existing RB_Node object.
  // POST: Update right of the current (implicit) object to pNode.
  void setRight(RB_Node * pNode);

  // PRE: This object is defined and satisfies the CI.
  // POST: Get the pointer of the right RB_Node object.
  // RV = pointer to the right RB_Node object of the current object.
  RB_Node * getRight() const;

  // PRE: This object is defined and satisfies the CI. pColor is
  // defined as a character holding the new value of color ('R' / 'B').
  // POST: Update the value of color to pColor.
  void setColor(char pColor);

  // PRE: This object is defined and satisfies the CI.
  // POST: Get the value of the character variable color of this object. 
  // RV = the charcter value of color in this RB_Node object. Return
  // 'R' if it's a red RB_Node, otherwise, return 'B' if it's a black
  // RB_Node.
  char getColor() const;

  // PRE: This object is defined and satisfies the CI.
  // POST: Dynamic memory used by this object is deleted.
  ~RB_Node();
};


#endif
