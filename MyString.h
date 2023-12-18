#ifndef INCLUDED_MYSTRING
#define INCLUDED_MYSTRING

#include <iostream>

using namespace std;

class MyString {

  /* CI: capacity >= 0.
     0 <= size < capacity.
     word[0] .. word[size-1] are defined as characters.
   */
  
 private:
  int size;
  int capacity;
  char * word;

  
 public:
  
  // PRE:
  // POST: This object has a list of characters of size (1) having end of
  // string character. size = 0, capacity = 1.
  MyString();

  // PRE: This object satisfies the CI
  // POST: Get the token that is read from the file.
  // RV = list of characters in token.
  char * getWord();

  // PRE: This object satisfies the CI.
  // POST: Get the size of this object.
  // RV = The integer value of the size of this object.
  int getSize();
  
  // PRE: ch is defined as character, end of string is at the end of
  // array of characters.
  // POST: ch is added to the array in place of the end of string
  // character if there is free room for it, otherwise, the list size
  // will be doubled and  ch will be added. end of string character is
  // add at the end of characters.
  void append(char ch);

  // PRE: This object satisfies the CI.
  // POST: Check whether this object has an empty string or not.
  // RV = true iff the list of characters (word) has no characters.
  bool isEmpty();

  
  // PRE: This object satisfies the CI.
  // POST: check whther all the characters of (word) are numerical
  // digits or not.
  // RV = true iff all the character of (word) are numerical digits.
  bool isAllDigits();

  // PRE: This object satisfies the CI.
  // POST: Convert the list of numerical digits to an integer.
  // RV = the integer value of string of characters that has all of its
  // characters as numerical digits. 
  int toInt();
  
  // PRE: stream is a defined output stream.
  //      pList is defined and satisfies the CI.
  // POST: stream contains the elements of pList.
  //       RV is a reference to the modifed stream
  friend ostream & operator << (ostream & stream, 
				const MyString & pList);

  // COPY CONSTRUCTOR
  // PRE: pList is defined and satisfies the CI
  // POST: This object is constructed to be a deep copy of pList.
  MyString (const MyString & pList);

  // ASSIGNMENT OPERATOR
  // PRE: pList is defined and satisfies the CI. This object is defined
  //        and satisfies the CI.
  // POST: This object is a deep copy of pList.
  //       RV is a reference to this object.
  MyString & operator= (const MyString & pList);

  // PRE: This object is defined.
  // POST: Dynamic memory used by this object is deleted.
  //       capacity = 0. size = 0. word = NULL.			   
  ~MyString();
  
};

#endif
