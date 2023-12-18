#include <iostream>
#include "RB_Node.h"

using namespace std;

class RedBlackTree{
    
  /* CI: root is NULL or points to the root of a
     non-empty red black tree, where each node contains a data item of
     type int. For each node, D, all the data items on the left subtree
     are less than or equal to (according to the < and = operators
     for int) the data item at node D, and all the data items on the
     right subtree are greater than (according to the > operator
     for int) the data item at node D.
     Every node is either red or black.
     The root is black.
     Every leaf (NIL) is black.
     If a node is red, then both of its children are black.
     For each node, all simple path from the node to descendant leaves
     contain the same number of blck nodes.
  */
  
private:
  RB_Node * root;
  int keyComparisons;
  int dataMovements;
  int ptrAssignments;
  int nodesCreated;
  int nodesDeleted;
  
 public:
  
  // PRE: This object is defined as RedBlackTree object, and
  // satisfies the CI.
  // POST: This object has root equal to NULL.
  RedBlackTree();

  // PRE: This object is defined and satisfies the CI.
  // POST: Get the root of this RedBlackTree object.
  // RV = Pointer to the root of the current RedBlackTree object,
  // NULL if the tree is empty, otherwise, it will return the pointer
  // to the root object.
  RB_Node * getRoot() const;

  // PRE: This obj is defined and satisfies the CI.
  // POST: Get the number of keyComparisons.
  // RV = The integer value of keyComparisons.
  int getKeyComparisons() const;

  // PRE: This obj is defined and satisfies the CI.
  // POST: Get the number of dataMovements.
  // RV = The integer value of dataMovements.
  int getdataMovements() const;

  // PRE: This obj is defined and satisfies the CI.
  // POST: Get the number of PtrAssignments.
  // RV = The integer value of PtrAssignments.
  int getPtrAssignments() const;

  // PRE: This obj is defined and satisfies the CI.
  // POST: Get the number of NodesCreated.
  // RV = The integer value of NodesCreated.
  int getNodesCreated() const;
  
  // PRE: This obj is defined and satisfies the CI.
  // POST: Get the number of NodesDeleted.
  // RV = The integer value of NodesDeleted.
  int getNodesDeleted() const;
  
  // PRE: This object is defined and satisfies the CI, xNode is
  // defined as a pointer to a RB_Node object.
  // POST: Having xNode's right child (yNode) is not NULL, the
  // function pivots around the link from xNode to yNode. It makes
  // yNode the new root of the subtree, with xNode as yNode's left
  // child, and yNode's left child as xNode's right child.
  void leftRotate(RB_Node * xNode);

  // PRE: This object is defined and satisfies the CI, yNode is
  // defined as a pointer to a RB_Node object.
  // POST: Having yNode's left child (xNode) is not NULL, the
  // function pivots around the link from yNode to xNode. It makes
  // xNode the new root of the subtree, with yNode as xNode's right
  // child, and xNode's right child as yNode's left child.
  void rightRotate(RB_Node * yNode);

  // PRE: This object is defined and satisfies the CI, zNode is
  // defined as a pointer to a RB_Node object.
  // POST: Insert zNode to This RedBlackTree object in the right
  // spot, having the Red Black Tree property not violated in terms
  // of data values arrangment only, however, other prperties may be
  // violated. For zNode, add two NIL children, and make zNode's color
  // to be Red.
  void RB_Insert(RB_Node * zNode);

  // PRE: This object is defined and satisfies the CI, zNode is
  // defined as a pointer to a RB_Node object. zNode is a newly added
  // node to the tree.
  // POST: Restore the red Black Tree properties.
  void RB_Insert_Fixup(RB_Node * zNode);

  // PRE: This object is defined and satisfies the CI. uNode, vNode
  // are defined as pointers to RB_Node objects.
  // POST: Replace the subtree rooted at node uNode with the subtree
  // rooted at node vNode. uNode's parent becomes vNoode's
  // parent, and uNode's parent ends up having vNode as its
  // appropriate child.
  void RB_Transplant(RB_Node * uNode, RB_Node * vNode);

  // PRE: This object is defined and satisfies the CI. pNode is
  // defined as a pointer to a RB_Node object which is the root of the
  // subtree where we want to find the miminum of it.
  // POST: Find the Minimum of the subtree rooted at pNode. Minimum:
  // is the node that has the smallest data.
  // RV = pointer to the RB_Node object that has the smallest data of the
  // subtree rooted at pNode.
  RB_Node * treeMinimum(RB_Node * pNode);

  // PRE: This object is defined and satisfies the CI. zNode is
  // defined as a pointer to a RB_Node object.
  // POST: Delete zNode from this RedBlackTree object. 
  void RB_Delete(RB_Node * zNode);

  // PRE: This object is defined and satisfies the CI, xNode is
  // defined as a pointer to a RB_Node object.
  // POST: Restore the red Black Tree properties.
  void RB_Delete_Fixup(RB_Node * xNode);

  // PRE: This object is defined and satisfies the CI. pData is
  // defined as int. 
  // POST: Find the node that has (pData) as its data.
  // RV = pointer to the Node object which its data is equal to
  // (pData), or NULL of there is not any node in the tree that has
  // (pData) in it.  
  RB_Node * Search(int pData);  
  
  // PRE: This object satisfies the CI.
  // POST: OS contains the data elements in the tree traversed using
  //         inorder traversal, i.e.,
  //           traverse left
  //           "visit" (in this case print data) at the node
  //           traverse right
  void printInOrder (RB_Node * pNode) const;
  
  // PRE: This object satisfies the CI.
  // POST: OS contains the data elements in the tree traversed using
  //         inorder traversal, i.e.,
  //           "visit" (in this case print data) at the node
  //           traverse left
  //           traverse right
  void printPreOrder (RB_Node * pNode) const;

  // PRE: This object satisfies the CI.
  // POST: OS contains the data elements in the tree traversed using
  //         inorder traversal, i.e.,
  //           traverse left
  //           traverse right
  //           "visit" (in this case print data) at the node
  void printPostOrder (RB_Node * pNode) const;
  
  // PRE: This object is defined.
  // POST: Dynamic memory used by this object is deleted.
  ~RedBlackTree();
  
};
