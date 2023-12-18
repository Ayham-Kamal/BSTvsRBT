#ifndef INCLUDED_intUtil
#define INCLUDED_intUtil
#include "MyString.h"


// PRE: size > 0.
//      arr1[0] .. arr1[N-1] is defined as integers.
//      arr2 has space for (size) integers.
// POST:     for 0 <= i < size, arr2[i] = arr1[i]
void copyArray (int * arr1, int * arr2, int numElements);


// PRE: arr1 has characters and the end of string character.
//      arr1[0] .. arr1[size - 1] is defined as chracters.
//      arr2 has space for (size) characters.
// POST:     for 0 <= i < size, arr2[i] = arr1[i] (copy the string of
//      characters.
void copyArray1 (char * arr1, char * arr2);


// PRE: size > 0.
//      arr1[0] .. arr1[size - 1] is defined as MyString objects.
//      arr2 has space for (size) objects.
// POST:     for 0 <= i < size, arr2[i] = arr1[i] (Copy the list of
//      objects using Assignment operator).
void copyArray2 (MyString * arr1, MyString * arr2, int size);

#endif
