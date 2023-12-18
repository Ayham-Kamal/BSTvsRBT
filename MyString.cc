#include <iostream>
#include "MyString.h"
#include "intUtil.h"
#include "constants.h"

using namespace std;

// PRE:
// POST: This object has a list of characters of size (1) having end of
// string character. size = 0, capacity = 1. 
MyString::MyString(){
  size = 0;
  capacity = 1;
  word = new char[capacity];
  word[0] = ENDOFSTR;
}

// PRE: This object satisfies the CI
// POST: Get the word that is read from the file.
// RV = list of characters in token.
char * MyString::getWord(){
  return (word);
}

// PRE: This object satisfies the CI.
// POST: Get the size of this object.
// RV = The integer value of the size of this object.
int MyString::getSize(){
  return(size);
}

// PRE: ch is defined as character, end of string is at the end of
// array of characters.
// POST: ch is added to the array in place of the end of string
// character if there is free room for it, otherwise, the list size
// will be doubled and  ch will be added. end of string character is
// add at the end of characters.  
void MyString::append(char ch){

  if ((size+1) < capacity){
      word[size] = ch;
      size++;
      word[size] = ENDOFSTR;
  }
  else{
    capacity*=TWO;
    char *temp = new char[capacity];

    copyArray1 (word, temp);
    
    temp[size] = ch;
    size++;
    temp[size] = ENDOFSTR;
    delete[]word;
    word = temp;
  }
}


// PRE: This object satisfies the CI.
// POST: Check whether this object has an empty string or not.
// RV = true iff the list of characters (word) has no characters.
bool MyString::isEmpty (){
  bool isempty=false;
  if (size == 0){
    isempty = true;
  }
  return (isempty);
}

// PRE: This object satisfies the CI.
// POST: check whther all the characters of (word) are numerical
// digits or not.
// RV = true iff all the character of (word) are numerical digits.
bool MyString::isAllDigits (){
  bool digits = false;
  int counter = 0;
  
  for (int loc = 0; loc < size; loc++){
    if ((word[loc] >= ZERO) && (word[loc] <= NINE)){
      counter++;
    }
  }
  if (counter == size){
    digits = true;
  }

  return (digits);
}

// PRE: This object satisfies the CI.
// POST: Convert the list of numerical digits to an integer.
// RV = the integer value of string of characters that has all of its
// characters as numerical digits. 
int MyString::toInt (){
  int num = 0;
  int power = 1;
  
  for (int loc = (size - 1); loc >= 0; loc--){
    int digit = ((int)word[loc] - (int)ZERO);
    num+= (digit)*(power);
    power*=10;
  }

  return (num);
}

// PRE: stream is a defined output stream.
//      pList is defined and satisfies the CI.
// POST: stream contains the elements of pList.
//       RV is a reference to the modifed output stream
ostream & operator << (ostream & stream, 
                               const MyString & pList) {

  stream << pList.word;

  return (stream);
}

// PRE: pList is defined and satisfies the CI
// POST: This object is constructed to be a deep copy of pList.
MyString::MyString (const MyString & pList) {
  capacity = pList.capacity;
  size = pList.size;
  word = new char[capacity];
  copyArray1 (pList.word, word);
}

// PRE: pList is defined and satisfies the CI. This object is defined
//        and satisfies the CI.
// POST: This object is a deep copy of pList.
//       RV is a reference to this object.
MyString & MyString::operator= (const MyString & pList) {
  capacity = pList.capacity;
  size = pList.size;
  delete [] word;
  word = new char[capacity];
  copyArray1 (pList.word, word);
  return (*this);
}

// PRE: This object is defined.
// POST: Dynamic memory used by this object is deleted.
//       capacity = 0. size = 0. word = NULL.
MyString::~MyString() {
  delete [] word;
  capacity = 0;
  size = 0;
}

