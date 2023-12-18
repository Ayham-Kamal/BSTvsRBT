#ifndef INCLUDED_BINSEARCHTREE
#define INCLUDED_BINSEARCHTREE

#include <iostream>
#include "Node.h"

using namespace std;

class BinSearchTree {
   
  /* CI: root is NULL or points to the root of a
     non-empty binary search tree, where each node contains a data item of
     type int. For each node, D, all the data items on the left subtree
     are less than or equal to (according to the < and = operators
     for int) the data item at node D, and all the data items on the
     right subtree are greater than (according to the > operator
     for int) the data item at node D.
  */

  
 private:
  Node * root;
  int keyComparisons;
  int dataMovements;
  int ptrAssignments;
  int nodesCreated;
  int nodesDeleted;
  
 public:

  // PRE: This object is defined as BinSearchTree object, and
  // satisfies the CI.
  // POST: This object has root equal to NULL.
  BinSearchTree();

  // PRE: This object is defined and satisfies the CI.
  // POST: Get the root of this BinSearchTree object.
  // RV = Pointer to the root of the current BinSearchTree object,
  // NULL if the tree is empty, otherwise, it will return the pointer
  // to the root object.
  Node * getRoot() const;

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
  
  // PRE: This object is defined and satisfies the CI, pNode is
  // defined as a pointer to a Node object.
  // POST: Insert pNode to This BinSearchTree object in the right
  // spot, having the Binary Search Tree properties not violated.
  void Insert(Node * pNode);

  // PRE: This object is defined and satisfies the CI. pNode is
  // defined as a pointer to a Node object which is the root of the
  // subtree where we want to find the miminum of it. 
  // POST: Find the Minimum of the subtree rooted at pNode. Minimum:
  // is the node that has the smallest data.
  // RV = pointer to the Node object that has the smallest data of the
  // subtree rooted at pNode.
  Node * treeMinimum(Node * pNode);

  // PRE: This object is defined and satisfies the CI. uNode, vNode
  // are defined as pointers to Node objects.
  // POST: Replace the subtree rooted at node uNode with the subtree
  // rooted at node vNode. uNode's parent becomes vNoode's
  // parent, and uNode's parent ends up having vNode as its
  // appropriate child. 
  void Transplant(Node * uNode, Node * vNode);

  // PRE: This object is defined and satisfies the CI. zNode is
  // defined as a pointer to a Node object.
  // POST: Delete zNode from this BinSearchTree object, having the
  // Binary Search Tree Property not violated.
  void Delete(Node * zNode);

  // PRE: This object is defined and satisfies the CI. pData is defined
  // as int.
  // POST: Find the node that has (pData) as its data.
  // RV = pointer to the Node object which its data is equal to (pData), or
  // NULL of there is not any node in the tree that has (pData) in it.
  Node * Search(int pData); 
  
  // PRE: This object satisfies the CI.
  // POST: OS contains the data elements in the tree traversed using
  //         inorder traversal, i.e.,
  //           traverse left
  //           "visit" (in this case print data) at the node
  //           traverse right
  void printInOrder (Node * pNode) const;
  
  // PRE: This object satisfies the CI.
  // POST: OS contains the data elements in the tree traversed using
  //         inorder traversal, i.e.,
  //           "visit" (in this case print data) at the node
  //           traverse left
  //           traverse right
  void printPreOrder (Node * pNode) const;
  
  // PRE: This object satisfies the CI.
  // POST: OS contains the data elements in the tree traversed using
  //         inorder traversal, i.e.,
  //           traverse left
  //           traverse right
  //           "visit" (in this case print data) at the node
  void printPostOrder (Node * pNode) const;

  // PRE: This object is defined.
  // POST: Dynamic memory used by this object is deleted.
  ~BinSearchTree();
  
};

#endif
