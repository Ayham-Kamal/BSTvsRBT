#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Node.h"
#include "RB_Node.h"
#include "RedBlackTree.h"
#include "BinSearchTree.h"
#include "utility.h"
#include "MyString.h"
#include "InputStream.h"

using namespace std;

int main(int argc, char * argv[]){
  
  if (((argv[1][0] == '-') && (argv[1][1] == 'p'))){
    double insertProp = getFraction(argv[2]);
    double deleteProp = getFraction(argv[3]);
    double searchProp = getFraction(argv[4]);
    
    // cout << insertProp << " " << deleteProp << " " << searchProp << endl;

    double * propArray = new double[3];
    propArray[0] = insertProp;
    propArray[1] = deleteProp;
    propArray[2] = searchProp;

    int iterations = 1500;
    int high = 3;
    int low = 1;
   
    // ofstream out1("result.txt");
    ofstream out1("result1.txt");
    
    BinSearchTree bTree;
    RedBlackTree rTree;

    /*
      int * count = new int[high-low+1];
      for (int loc = 0; loc < 3; loc++){
        count[loc] = 0;
      }
      ASSERT: COMMENTED STATEMTS HERE, TO CHECK FOR PROPRTION
      GENERATED TO MAKE SURE THEY ARE THE SAME AS INPUT.
    */

      for (int loc1 = 0; loc1 < iterations; loc1++){
        int operationIndex = myRandom2(low, high, propArray);
	// count[operationIndex-low]++;
	int num = random() % 1000;

	if (operationIndex == 1){
	    Node * bInsert = new Node();
	    RB_Node * rInsert = new RB_Node();
	    bInsert -> setData(num);
	    rInsert -> setData(num);
	    bTree.Insert(bInsert);
	    rTree.RB_Insert(rInsert);
	  }
	
	  else if (operationIndex == 2){
	    Node * bDelete = bTree.Search(num);
	    RB_Node * rDelete = rTree.Search(num);
	  
	    if ((bDelete != NULL) && (rDelete != NULL)){
	      bTree.Delete(bDelete);
	      rTree.RB_Delete(rDelete);
	    }
	  }
	
	  else if (operationIndex == 3){
	    Node * bSearch = bTree.Search(num);
	    RB_Node * rSearch = rTree.Search(num);	  
	  }
		
	
	out1 << (loc1+1) <<  " " <<  bTree.getKeyComparisons() << " " << bTree.getdataMovements() << " " << bTree.getPtrAssignments() << " " << bTree.getNodesCreated() << " " << bTree.getNodesDeleted() << " " << rTree.getKeyComparisons() << " " << rTree.getdataMovements() << " " << rTree.getPtrAssignments() << " " << rTree.getNodesCreated() << " " << rTree.getNodesDeleted() << endl;
 
      }
      /*
      for (int loc = 0; loc < 3; loc++){
	cout << loc+low << ": " << (double)count[loc]/(double)iterations << " ";
      }
      cout << endl;
      */    
}
  
  // Getting input from a file.
  else if (((argv[1][0] == '-') && (argv[1][1] == 'f'))){
    InputStream IS;  // The object dealing with the input.
    bool operation = false;
    int operationIndex = 0;
    
    BinSearchTree bTree;
    RedBlackTree rTree;
  
    while (!IS.eof()) {
      MyString token;// will hold the next token, if any, read
      // from input.
      
      IS.nextToken(token);
      // ASSERT: token is the next non-blank string, if any, on input
      if (!token.isEmpty()) {
        if (token.isAllDigits() && (operation)) {
	  int tokenNumber = token.toInt(); 
	  tokenNumber = token.toInt();
	 
	  if (operationIndex == 1){
	    Node * bInsert = new Node();
	    RB_Node * rInsert = new RB_Node();
	    bInsert -> setData(tokenNumber);
	    rInsert -> setData(tokenNumber);
	    bTree.Insert(bInsert);
	    rTree.RB_Insert(rInsert);
	  }
	
	
	  else if (operationIndex == 2){
	    Node * bDelete = bTree.Search(tokenNumber);
	    RB_Node * rDelete = rTree.Search(tokenNumber);
	  
	    if ((bDelete != NULL) && (rDelete != NULL)){
	      bTree.Delete(bDelete);
	      rTree.RB_Delete(rDelete);
	    }
	  }
	
	  else if (operationIndex == 3){
	    Node * bSearch = bTree.Search(tokenNumber);
	    RB_Node * rSearch = rTree.Search(tokenNumber);
	  
	    if ((bSearch != NULL) && (rSearch != NULL)){
	      cout << "Found: " << tokenNumber << endl;
	    }
	    else {
	      cout << "Not Found: " << tokenNumber << endl;
	    }
	  
	  }
		
	}
	
	else {
	  // Print the tree after only insertion and deletion operation
	  if ((operation == true) && (operationIndex != 3)){
	    
	    cout << endl;
	    cout << "-> InOrder:" << endl;
	    cout << "BST:" << endl;
	    bTree.printInOrder(bTree.getRoot());
	    cout << endl;
	    cout << "RBT:" << endl;
	    rTree.printInOrder(rTree.getRoot());
	    cout << endl;
    
	    cout << "-> PreOrder:" << endl;
	    cout << "BST:" << endl;
	    bTree.printPreOrder(bTree.getRoot());
	    cout << endl;
	    cout << "RBT:" << endl;
	    rTree.printPreOrder(rTree.getRoot());
	    cout  << endl;
    
	    cout << "-> PostOrder:" << endl;
	    cout << "BST:" << endl;
	    bTree.printPostOrder(bTree.getRoot());
	    cout << endl;
	    cout << "RBT:" << endl;
	    rTree.printPostOrder(rTree.getRoot());
	    cout << endl;
	    cout << endl;
	  }
	  
	  char * word = token.getWord();
	  int size = token.getSize();
	  if ((word[0] == 'i') && (size == 1)){
	    operation = true;
	    operationIndex = 1;
	  }
	  else if ((word[0] == 'd') && (size == 1)){
	    operation = true;
	    operationIndex = 2;
	  }
	  else if ((word[0] == 's') && (size == 1)){
	    operation = true;
	    operationIndex = 3;
	  }
	  else { // IF the word is neither of the opertions shortcuts.
	    operation = false;
	    operationIndex = 0;
	  }
        }
      }
    }
    cout << endl;
    cout << "-> InOrder:" << endl;
    cout << "BST:" << endl;
    bTree.printInOrder(bTree.getRoot());
    cout << endl;
    cout << "RBT:" << endl;
    rTree.printInOrder(rTree.getRoot());
    cout << endl;
    
    cout << "-> PreOrder:" << endl;
    cout << "BST:" << endl;
    bTree.printPreOrder(bTree.getRoot());
    cout << endl;
    cout << "RBT:" << endl;
    rTree.printPreOrder(rTree.getRoot());
    cout  << endl;
    
    cout << "-> PostOrder:" << endl;
    cout << "BST:" << endl;
    bTree.printPostOrder(bTree.getRoot());
    cout << endl;
    cout << "RBT:" << endl;
    rTree.printPostOrder(rTree.getRoot());
    cout << endl;
    cout << endl;
  }
  
  return (0);
}
