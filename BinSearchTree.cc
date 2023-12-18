#include <iostream>
#include "BinSearchTree.h"
#include "Node.h"

using namespace std;

// PRE: This object is defined as BinSearchTree object, and
// satisfies the CI.
// POST: This object has root equal to NULL.
BinSearchTree::BinSearchTree(){
  root = NULL;
  keyComparisons = 0;
  dataMovements = 0;
  ptrAssignments = 0;
  nodesCreated = 0;
  nodesDeleted = 0;
}

// PRE: This object is defined and satisfies the CI.
// POST: Get the root of this BinSearchTree object.
// RV = Pointer to the root of the current BinSearchTree object,
// NULL if the tree is empty, otherwise, it will return the pointer
// to the root object.
Node * BinSearchTree::getRoot() const{
  return (root);
}

// PRE: This obj is defined and satisfies the CI.
// POST: Get the number of keyComparisons.
// RV = The integer value of keyComparisons.
int BinSearchTree::getKeyComparisons() const{
  return (keyComparisons);
}

// PRE: This obj is defined and satisfies the CI.
// POST: Get the number of dataMovements.
// RV = The integer value of dataMovements.
int BinSearchTree::getdataMovements() const{
  return(dataMovements);
}

// PRE: This obj is defined and satisfies the CI.
// POST: Get the number of PtrAssignments.
// RV = The integer value of PtrAssignments.
int BinSearchTree::getPtrAssignments() const{
  return (ptrAssignments);
}

// PRE: This obj is defined and satisfies the CI.
// POST: Get the number of NodesCreated.
// RV = The integer value of NodesCreated.
int BinSearchTree::getNodesCreated() const{
  return(nodesCreated);
}
  
// PRE: This obj is defined and satisfies the CI.
// POST: Get the number of NodesDeleted.
// RV = The integer value of NodesDeleted.
int BinSearchTree::getNodesDeleted() const{
  return (nodesDeleted);
}

// PRE: This object is defined and satisfies the CI, pNode is
// defined as a pointer to a Node object.
// POST: Insert pNode to This BinSearchTree object in the right
// spot, having the Binary Search Tree properties not violated.
void BinSearchTree::Insert(Node * pNode){
  nodesCreated++; ptrAssignments++; // When called in executable file.
  Node * y = NULL;
  Node * x = root;
  ptrAssignments+=2;
  nodesCreated+=2;

  while (x != NULL){
    y = x; ptrAssignments++;

    if ((pNode -> getData()) <= (x -> getData())){
      keyComparisons++;
      x = x -> getLeft(); ptrAssignments++;
    }
    else {
      keyComparisons++;
      x = x -> getRight(); ptrAssignments++;
    }
  }
  pNode -> setParent(y); ptrAssignments++;
  if (y == NULL){
    root = pNode; ptrAssignments++;
  }
  else if ((pNode -> getData()) <= (y -> getData())){
    keyComparisons++;
    y -> setLeft(pNode); ptrAssignments++;
  }
  else{
    keyComparisons++;
    y -> setRight(pNode); ptrAssignments++;
  }
}

// PRE: This object is defined and satisfies the CI. pNode is
// defined as a pointer to a Node object which is the root of the
// subtree where we want to find the miminum of it.
// POST: Find the Minimum of the subtree rooted at pNode. Minimum:
// is the node that has the smallest data.
// RV = pointer to the Node object that has the smallest data of the
// subtree rooted at pNode.
Node * BinSearchTree::treeMinimum(Node * pNode){
  while ((pNode -> getLeft()) != NULL){
    pNode = pNode -> getLeft(); ptrAssignments++;
  }
  return (pNode);
}

// PRE: This object is defined and satisfies the CI. uNode, vNode
// are defined as pointers to Node objects.
// POST: Replace the subtree rooted at node uNode with the subtree
// rooted at node vNode. uNode's parent becomes vNoode's
// parent, and uNode's parent ends up having vNode as its
// appropriate child.
void BinSearchTree::Transplant(Node * uNode, Node * vNode){
  if ((uNode -> getParent()) == NULL){
    root = vNode; ptrAssignments++;
  }
  else if (uNode == ((uNode -> getParent()) -> getLeft())){
    (uNode -> getParent()) -> setLeft(vNode); ptrAssignments++;
  }
  else {
    (uNode -> getParent()) -> setRight(vNode); ptrAssignments++;
  }
  if (vNode != NULL){
    vNode -> setParent((uNode -> getParent())); ptrAssignments++;
  }
}

// PRE: This object is defined and satisfies the CI. zNode is
// defined as a pointer to a Node object.
// POST: Delete zNode from this BinSearchTree object, having the
// Binary Search Tree Property not violated.
void BinSearchTree::Delete(Node * zNode){
  nodesCreated++; ptrAssignments++; // When called in executable file.
  if ((zNode -> getLeft())==NULL){
    Transplant(zNode, zNode->getRight());
  }
  else if ((zNode -> getRight())==NULL){
    Transplant(zNode, zNode->getLeft());
  }
  else {
    Node * yNode; nodesCreated++;
    yNode = treeMinimum(zNode -> getRight()); ptrAssignments++;
    if ((yNode -> getParent()) != zNode){
      Transplant(yNode, yNode -> getRight());
      yNode -> setRight(zNode -> getRight()); ptrAssignments++;
      (yNode -> getRight()) -> setParent(yNode); ptrAssignments++;
    }
    Transplant(zNode, yNode);
    yNode -> setLeft(zNode -> getLeft()); ptrAssignments++;
    (yNode -> getLeft()) -> setParent(yNode); ptrAssignments++;
  }
  zNode -> setLeft(NULL); ptrAssignments++; 
  zNode -> setRight(NULL); ptrAssignments++;
  delete zNode; nodesDeleted++;
}

// PRE: This object is defined and satisfies the CI. pData is defined
// as int.
// POST: Find the node that has (pData) as its data.
// RV = pointer to the Node object which its data is equal to (pData), or
// NULL of there is not any node in the tree that has (pData) in it.
Node * BinSearchTree::Search(int pData){
  Node * xNode = root; nodesCreated++;
  while ((xNode != NULL) && (pData != xNode -> getData())){
    keyComparisons++;
    // Iterative way since in most computers it's more efficient.
    if (pData < xNode -> getData()){
      keyComparisons++;
      xNode = xNode -> getLeft(); ptrAssignments++;
    }
    else{
      keyComparisons++;
      xNode = xNode -> getRight(); ptrAssignments++;
    }
  }
  return (xNode);
}


// PRE: This object satisfies the CI.
// POST: OS contains the data elements in the tree traversed using
//         inorder traversal, i.e.,
//           traverse left
//           "visit" (in this case print data) at the node
//           traverse right
void BinSearchTree::printInOrder(Node * pNode) const{
  if (pNode != NULL){
    printInOrder(pNode -> getLeft());
    cout << (pNode -> getData()) << " ";
    printInOrder(pNode -> getRight());
  }
}


// PRE: This object satisfies the CI.
// POST: OS contains the data elements in the tree traversed using
//         inorder traversal, i.e.,
//           "visit" (in this case print data) at the node
//           traverse left
//           traverse right
void BinSearchTree::printPreOrder(Node * pNode) const{
  if (pNode != NULL){
    cout << (pNode -> getData()) << " ";
    printPreOrder(pNode -> getLeft());
    printPreOrder(pNode -> getRight());
  }
}

// PRE: This object satisfies the CI.
// POST: OS contains the data elements in the tree traversed using
//         inorder traversal, i.e.,
//           traverse left
//           traverse right
//           "visit" (in this case print data) at the node
void BinSearchTree::printPostOrder(Node * pNode) const{
  if (pNode != NULL){
    printPostOrder(pNode -> getLeft());
    printPostOrder(pNode -> getRight());
    cout << (pNode -> getData()) << " ";
  }
}

// PRE: This object is defined.
// POST: Dynamic memory used by this object is deleted.
BinSearchTree::~BinSearchTree(){
  if (root != NULL){
      delete root;
  }
}


