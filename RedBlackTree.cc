#include <iostream>
#include "RB_Node.h"
#include "RedBlackTree.h"

using namespace std;

// PRE: This object is defined as RedBlackTree object, and
// satisfies the CI.
// POST: This object has root equal to NULL.
RedBlackTree::RedBlackTree(){
  root = NULL;
  keyComparisons = 0;
  dataMovements = 0;
  ptrAssignments = 0;
  nodesCreated = 0;
  nodesDeleted = 0;
}

// PRE: This object is defined and satisfies the CI.
// POST: Get the root of this RedBlackTree object.
// RV = Pointer to the root of the current RedBlackTree object,
// NULL if the tree is empty, otherwise, it will return the pointer
// to the root object.
RB_Node * RedBlackTree::getRoot() const{
  return (root);
}

// PRE: This obj is defined and satisfies the CI.
// POST: Get the number of keyComparisons.
// RV = The integer value of keyComparisons.
int RedBlackTree::getKeyComparisons() const{
  return (keyComparisons);
}

// PRE: This obj is defined and satisfies the CI.
// POST: Get the number of dataMovements.
// RV = The integer value of dataMovements.
int RedBlackTree::getdataMovements() const{
  return(dataMovements);
}

// PRE: This obj is defined and satisfies the CI.
// POST: Get the number of PtrAssignments.
// RV = The integer value of PtrAssignments.
int RedBlackTree::getPtrAssignments() const{
  return (ptrAssignments);
}

// PRE: This obj is defined and satisfies the CI.
// POST: Get the number of NodesCreated.
// RV = The integer value of NodesCreated.
int RedBlackTree::getNodesCreated() const{
  return(nodesCreated);
}
  
// PRE: This obj is defined and satisfies the CI.
// POST: Get the number of NodesDeleted.
// RV = The integer value of NodesDeleted.
int RedBlackTree::getNodesDeleted() const{
  return (nodesDeleted);
}

// PRE: This object is defined and satisfies the CI, xNode is
// defined as a pointer to a RB_Node object.
// POST: Having xNode's right child (yNode) is not NULL, the
// function pivots around the link from xNode to yNode. It makes
// yNode the new root of the subtree, with xNode as yNode's left
// child, and yNode's left child as xNode's right child.
void RedBlackTree::leftRotate(RB_Node * xNode){
  RB_Node * yNode = xNode -> getRight(); nodesCreated++; ptrAssignments++;

  if ((yNode != NULL) && (!yNode -> isEmpty())){
    
    xNode -> setRight(yNode -> getLeft()); ptrAssignments++;

    (yNode -> getLeft()) -> setParent(xNode); ptrAssignments++;
  
    yNode -> setParent(xNode -> getParent()); ptrAssignments++;

    if ((xNode -> getParent()) == NULL){
      root = yNode; ptrAssignments++;
    }
    else if (xNode == ((xNode -> getParent()) -> getLeft())){
      (xNode -> getParent()) -> setLeft(yNode); ptrAssignments++;
    }
    else {
      (xNode -> getParent()) -> setRight(yNode); ptrAssignments++;
    }

    yNode -> setLeft(xNode); ptrAssignments++;
    xNode -> setParent(yNode); ptrAssignments++;
  }
  
}

// PRE: This object is defined and satisfies the CI, yNode is
// defined as a pointer to a RB_Node object.
// POST: Having yNode's left child (xNode) is not NULL, the
// function pivots around the link from yNode to xNode. It makes
// xNode the new root of the subtree, with yNode as xNode's right
// child, and xNode's right child as yNode's left child.
void RedBlackTree::rightRotate(RB_Node * yNode){
  RB_Node * xNode = yNode -> getLeft(); nodesCreated++; ptrAssignments++;
  if ((xNode != NULL) && (!xNode -> isEmpty())){
    yNode -> setLeft(xNode -> getRight()); ptrAssignments++;

    
   (xNode -> getRight()) -> setParent(yNode); ptrAssignments++;
    
    xNode -> setParent(yNode -> getParent()); ptrAssignments++;

    if ((yNode -> getParent()) == NULL){
      root = xNode; ptrAssignments++;
    }
    else if (yNode == ((yNode -> getParent()) -> getLeft()) ){
      (yNode -> getParent()) -> setLeft(xNode); ptrAssignments++;
    }
    else {
      (yNode -> getParent()) -> setRight(xNode); ptrAssignments++;
    }

    xNode -> setRight(yNode); ptrAssignments++;
    yNode -> setParent(xNode); ptrAssignments++;
  }
}

// PRE: This object is defined and satisfies the CI, zNode is
// defined as a pointer to a RB_Node object.
// POST: Insert zNode to This RedBlackTree object in the right
// spot, having the Red Black Tree property not violated in terms
// of data values arrangment only, however, other prperties may be
// violated. For zNode, add two NIL children, and make zNode's color
// to be Red.
void RedBlackTree::RB_Insert(RB_Node * zNode){
  nodesCreated++; ptrAssignments++; // When called in executable file.
  zNode -> setEmpty(false);
  
  RB_Node * yNode = NULL; nodesCreated++; ptrAssignments++;
  RB_Node * xNode = root; nodesCreated++; ptrAssignments++;

  while ((xNode != NULL) && (!xNode -> isEmpty())){
    yNode = xNode; ptrAssignments++;

    if ( (zNode -> getData()) <= (xNode -> getData()) ){
      keyComparisons++;
      xNode = xNode -> getLeft(); ptrAssignments++;
    }
    else {
      keyComparisons++;
      xNode = xNode -> getRight(); ptrAssignments++;
    }
  }
  zNode -> setParent(yNode); ptrAssignments++;
  
  if (yNode == NULL){
    root = zNode; ptrAssignments++;
  }
  else if ((zNode -> getData()) <= (yNode -> getData())){
    keyComparisons++;
    delete (yNode -> getLeft()); // Delte Empty nodes (NIL) alreday
                                 // existing.  
    nodesDeleted++;
    yNode -> setLeft(zNode); ptrAssignments++;
  }
  else {
    keyComparisons++;
    delete (yNode -> getRight()); // Delte Empty nodes alreday existing.
    nodesDeleted++;
    yNode -> setRight(zNode); ptrAssignments++;
  }

  RB_Node * zLeftNode = new RB_Node(); nodesCreated++;
  zLeftNode -> setEmpty(true); // Safety Check
  zLeftNode -> setParent(zNode); ptrAssignments++;
  zLeftNode -> setColor('B');
  zNode -> setLeft(zLeftNode); ptrAssignments++;

  RB_Node * zRightNode = new RB_Node(); nodesCreated++;
  zRightNode -> setEmpty(true); // Safety Check
  zRightNode -> setParent(zNode); ptrAssignments++;
  zRightNode -> setColor('B');
  zNode -> setRight(zRightNode); ptrAssignments++;

  zNode -> setColor('R');

  RB_Insert_Fixup(zNode);
}

// PRE: This object is defined and satisfies the CI, zNode is
// defined as a pointer to a RB_Node object. zNode is a newly added
// node to the tree.
// POST: Restore the red Black Tree properties.
void RedBlackTree::RB_Insert_Fixup(RB_Node * zNode){
  RB_Node * yNode = NULL; nodesCreated++; ptrAssignments++;
  
  while ((zNode->getParent() != NULL)&&(((zNode -> getParent()) -> getColor())=='R') ){
    if ( (zNode -> getParent()) == (((zNode -> getParent()) -> getParent()) -> getLeft())){
      yNode = ((zNode -> getParent()) -> getParent()) -> getRight();
      ptrAssignments++;
	
	if (yNode -> getColor() == 'R'){
	  (zNode -> getParent()) -> setColor('B');
	  yNode -> setColor('B');
	  ((zNode -> getParent()) -> getParent()) -> setColor('R');
	  zNode = (zNode -> getParent()) -> getParent(); ptrAssignments++;
	}

	else {
	  if ((zNode -> getParent() != NULL) &&((zNode -> getParent())->getParent() != NULL)){
	    if (zNode == ((zNode -> getParent()) -> getRight())){
	      zNode = zNode -> getParent(); ptrAssignments++;
	      leftRotate(zNode);
	    }
	    (zNode -> getParent()) -> setColor('B');
	    ((zNode -> getParent()) -> getParent()) -> setColor('R');
	    rightRotate((zNode -> getParent()) -> getParent());
	  }
	  
	}

    }
      
      else {
	yNode = ((zNode -> getParent()) -> getParent()) -> getLeft();
	ptrAssignments++;
	
	if (yNode -> getColor() == 'R'){
	  (zNode -> getParent()) -> setColor('B');
	  yNode -> setColor('B');
	  ((zNode -> getParent()) -> getParent()) -> setColor('R');
	  zNode = (zNode -> getParent()) -> getParent(); ptrAssignments++;
	}

	else {
	  if ((zNode -> getParent() != NULL) &&((zNode -> getParent())->getParent() != NULL)){
	    if (zNode == ((zNode -> getParent()) -> getLeft())){
	      zNode = zNode -> getParent(); ptrAssignments++;
	      rightRotate(zNode);
	    }
	    (zNode -> getParent()) -> setColor('B');
	    ((zNode -> getParent()) -> getParent()) -> setColor('R');
	    leftRotate((zNode -> getParent()) -> getParent());
	  }
	  
	}
	
	
      }
  }
  
  root -> setColor('B');
}

// PRE: This object is defined and satisfies the CI. uNode, vNode
// are defined as pointers to RB_Node objects.
// POST: Replace the subtree rooted at node uNode with the subtree
// rooted at node vNode. uNode's parent becomes vNoode's
// parent, and uNode's parent ends up having vNode as its
// appropriate child.
void RedBlackTree::RB_Transplant(RB_Node * uNode, RB_Node * vNode){
  if (uNode -> getParent() == NULL){
    root = vNode; ptrAssignments++;
  }
  else if (uNode == ((uNode -> getParent()) -> getLeft())){
    (uNode -> getParent()) -> setLeft(vNode); ptrAssignments++;
  }
  else {
    (uNode -> getParent()) -> setRight(vNode); ptrAssignments++;
  }
  vNode -> setParent(uNode -> getParent()); ptrAssignments++;
}

// PRE: This object is defined and satisfies the CI. pNode is
// defined as a pointer to a RB_Node object which is the root of the
// subtree where we want to find the miminum of it.
// POST: Find the Minimum of the subtree rooted at pNode. Minimum:
// is the node that has the smallest data.
// RV = pointer to the RB_Node object that has the smallest data of the
// subtree rooted at pNode.
RB_Node * RedBlackTree::treeMinimum(RB_Node * pNode){
  while (((pNode -> getLeft()) != NULL) && (!((pNode -> getLeft()) -> isEmpty()))){ 
    pNode = pNode -> getLeft(); ptrAssignments++;
  }
  return (pNode);
}

// PRE: This object is defined and satisfies the CI. zNode is
// defined as a pointer to a RB_Node object.
// POST: Delete zNode from this RedBlackTree object.
void RedBlackTree::RB_Delete(RB_Node * zNode){
  nodesCreated++; ptrAssignments++; // When called in executable file.
  RB_Node * yNode = zNode; nodesCreated++; ptrAssignments++;
  char yOrigColor = yNode -> getColor();
  RB_Node * xNode; nodesCreated++;
  
  if ((zNode -> getLeft()) -> isEmpty()){
    xNode = zNode -> getRight(); ptrAssignments++;
    RB_Transplant(zNode, zNode -> getRight());
  }
  else if ((zNode -> getRight()) -> isEmpty()){
    xNode = zNode -> getLeft(); ptrAssignments++;
    RB_Transplant(zNode, zNode -> getLeft());
  }
  else{
    yNode = treeMinimum(zNode -> getRight()); ptrAssignments++;
    yOrigColor = yNode -> getColor();
    xNode = yNode -> getRight(); ptrAssignments++;

    if ((yNode -> getParent()) == zNode){
      xNode -> setParent(yNode); ptrAssignments++;
    }
    else {
      RB_Transplant(yNode, yNode -> getRight());
      yNode -> setRight(zNode -> getRight()); ptrAssignments++;
      (yNode -> getRight()) -> setParent(yNode); ptrAssignments++;
    }

    RB_Transplant(zNode, yNode);
    yNode -> setLeft(zNode -> getLeft()); ptrAssignments++;
    (yNode -> getLeft()) -> setParent(yNode); ptrAssignments++;
    yNode -> setColor(zNode -> getColor());
    
  }

  if (yOrigColor == 'B'){
    RB_Delete_Fixup(xNode);
  }
  zNode -> setLeft(NULL);
  zNode -> setRight(NULL);
  delete zNode; nodesDeleted++;
}

// PRE: This object is defined and satisfies the CI, xNode is
// defined as a pointer to a RB_Node object.
// POST: Restore the red Black Tree properties.
void RedBlackTree::RB_Delete_Fixup(RB_Node * xNode){
  RB_Node * wNode; nodesCreated++;
  while ((xNode != root) && (xNode -> getColor() == 'B')){ // ADD if
							   // it's
							   // NULL 
    	
    if (xNode == ((xNode -> getParent()) -> getLeft())){
      wNode = (xNode -> getParent()) -> getRight(); ptrAssignments++;
      
      if ((wNode -> getColor()) == 'R'){
	wNode -> setColor('B');
	(xNode -> getParent()) -> setColor('R');
	leftRotate(xNode -> getParent());
	wNode = (xNode -> getParent()) -> getRight(); ptrAssignments++;
      }
	
      if (((wNode->getLeft())->getColor()=='B') && ((wNode -> getRight()) -> getColor() == 'B')){
	wNode -> setColor('R');
	xNode = xNode -> getParent(); ptrAssignments++;
      }

      else {

	if ((wNode -> getRight()) -> getColor() == 'B'){
	  (wNode -> getLeft()) -> setColor('B');
	  wNode -> setColor('R');
	  rightRotate(wNode);
	  wNode = (xNode -> getParent()) -> getRight(); ptrAssignments++;
	}
        wNode -> setColor((xNode -> getParent()) -> getColor()); 
	(xNode -> getParent()) -> setColor('B');
	(wNode -> getRight()) -> setColor('B');
	leftRotate(xNode -> getParent()); ptrAssignments++;
	xNode = root; ptrAssignments++;
      }
	
    }

    else {

      wNode = (xNode -> getParent()) -> getLeft(); ptrAssignments++;
      
      if ((wNode -> getColor()) == 'R'){
	wNode -> setColor('B');
	(xNode -> getParent()) -> setColor('R');
	rightRotate(xNode -> getParent());
	wNode = (xNode -> getParent()) -> getLeft(); ptrAssignments++;
      }
	
      if (((wNode->getRight())->getColor()=='B') && ((wNode -> getLeft()) -> getColor() == 'B')){
	wNode -> setColor('R');
	xNode = xNode -> getParent(); ptrAssignments++;
      }

      else {

	if ((wNode -> getLeft()) -> getColor() == 'B'){
	  (wNode -> getRight()) -> setColor('B');
	  wNode -> setColor('R');
	  leftRotate(wNode);
	  wNode = (xNode -> getParent()) -> getLeft(); ptrAssignments++;
	}
        wNode -> setColor((xNode -> getParent()) -> getColor()); 
	(xNode -> getParent()) -> setColor('B');
	(wNode -> getLeft()) -> setColor('B');
	rightRotate(xNode -> getParent()); 
	xNode = root; ptrAssignments++;
      }

	
    }
      
  }
    

  xNode -> setColor('B');
}

// PRE: This object is defined and satisfies the CI. pData is
// defined as int.
// POST: Find the node that has (pData) as its data.
// RV = pointer to the Node object which its data is equal to
// (pData), or NULL of there is not any node in the tree that has
// (pData) in it.
RB_Node * RedBlackTree::Search(int pData){
  RB_Node * xNode = root; nodesCreated++; ptrAssignments++;

  while ((xNode != NULL) && (pData != xNode -> getData())){
    if (pData < (xNode -> getData())){
      keyComparisons++;
      xNode = xNode -> getLeft(); ptrAssignments++;
    }
    else {
      keyComparisons++;
      xNode = xNode -> getRight(); ptrAssignments++;
    }
  }

  
  // SAFETY CHECK:
  if ((xNode != NULL) && (xNode -> isEmpty())){
    xNode = NULL; ptrAssignments++;
  }
  
  
  return (xNode);
}


// PRE: This object satisfies the CI.
// POST: OS contains the data elements in the tree traversed using
//         inorder traversal, i.e.,
//           traverse left
//           "visit" (in this case print data) at the node
//           traverse right
void RedBlackTree::printInOrder (RB_Node * pNode) const{
  if ((pNode != NULL)){
    printInOrder(pNode -> getLeft());
    if (!pNode -> isEmpty()){
      cout << (pNode -> getData()) << ":" << (pNode -> getColor()) << " ";
    }
    printInOrder(pNode -> getRight());
  }
}

// PRE: This object satisfies the CI.
// POST: OS contains the data elements in the tree traversed using
//         inorder traversal, i.e.,
//           "visit" (in this case print data) at the node
//           traverse left
//           traverse right
void RedBlackTree::printPreOrder (RB_Node * pNode) const{
  if (pNode != NULL){
    if (!pNode -> isEmpty()){
      cout << (pNode -> getData()) << ":" << (pNode -> getColor()) << " ";
    }
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
void RedBlackTree::printPostOrder (RB_Node * pNode) const{
  if (pNode != NULL){
    printPostOrder(pNode -> getLeft());
    printPostOrder(pNode -> getRight());
    if (!pNode -> isEmpty()){
      cout << (pNode -> getData()) << ":" << (pNode -> getColor()) << " ";
    }
  }
}

// PRE: This object is defined.
// POST: Dynamic memory used by this object is deleted.
RedBlackTree::~RedBlackTree() {
  if (root != NULL){
      delete root;
  }
}
