program: program.o Node.o RB_Node.o BinSearchTree.o RedBlackTree.o utility.o intUtil.o MyString.o InputStream.o
	g++ program.o Node.o RB_Node.o BinSearchTree.o RedBlackTree.o utility.o intUtil.o MyString.o InputStream.o -o program

program.o: Node.h RB_Node.h BinSearchTree.h RedBlackTree.h program.cc
	g++ -c program.cc

intUtil.o: intUtil.cc intUtil.h MyString.h constants.h
	g++ -c intUtil.cc

MyString.o: MyString.cc MyString.h intUtil.h constants.h
	g++ -c MyString.cc

InputStream.o: InputStream.cc InputStream.h MyString.h constants.h
	g++ -c InputStream.cc

BinSearchTree.o: BinSearchTree.cc BinSearchTree.h Node.h
	g++ -c BinSearchTree.cc

Node.o: Node.cc Node.h
	g++ -c Node.cc

RedBlackTree.o: RedBlackTree.cc RedBlackTree.h RB_Node.h
	g++ -c RedBlackTree.cc

RB_Node.o: RB_Node.cc RB_Node.h
	g++ -c RB_Node.cc

utility: utility.o
	g++ utility.o -o utility

utility.o: utility.cc utility.h
	g++ -c utility.cc
