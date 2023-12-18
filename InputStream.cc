#include <iostream>
#include "InputStream.h"
#include "MyString.h"
#include "constants.h"

using namespace std;

// PRE:
// POST: endOfFileSeen = false
InputStream::InputStream() {
  endOfFileSeen = false;
}

// PRE: This object satisfies the CI
// POST: RV = true iff end of file character has been read.
bool InputStream::eof() const {
  return (endOfFileSeen);
}

// PRE: ch is defined.
// POST: RV = true iff ch is ' ', or '\t' or '\n'
bool InputStream::whitespace (char ch) {
  return ( (ch == SPACE) || (ch == TAB) || (ch == NEWLINE) );
}

// PRE: This object satisfies the CI, and endOfFileSeen = false
// POST: ch is the first non-white space character read.
//        endOfFileSeen = true iff end of file was read.
void InputStream::skipWhiteSpace (char & ch) {
  cin.get(ch);
  while ( (!endOfFileSeen) && (whitespace(ch)) ) {
    cin.get(ch);
    if (cin.eof()) {
      endOfFileSeen = true;
    }
  }
  // ASSERT: ch is the next non-white space character or
  //         endOfFileSeen = true.
}

// PRE: This object satisfies the CI, and endOfFileSeen = false
//        ch = x is the last character read, and it is not white space
//        pToken is an empty MyString object
// POST: pToken is the non-white space string on input starting with
//        x.
//       ch is the first non-white space character, if any, read.
//       endOfFileSeen = true iff end of file was read while reading
//        the token.
void InputStream::readToken (MyString & pToken, char & ch) {
  while ( (!endOfFileSeen) && (!whitespace(ch)) ) {
    pToken.append (ch);
    // ASSERT: ch is added to the end of the string in pToken
    cin.get(ch);
    if (cin.eof()) {
      endOfFileSeen = true;
    }
  }
  // ASSERT: pToken contains the next non-white space string
  //         endOfFileSeen = true iff end of file character was read.
}

// PRE: This object satisfies the CI. pToken is an empty MyString
//        object.
// POST: pToken contains the next non-blank string of characters, if
//        any. 
//        endOfFileSeen = true iff the end of string character was read.
void InputStream::nextToken (MyString & pToken) {
  if (!endOfFileSeen) {
    char ch;
    skipWhiteSpace (ch);
    // ASSERT: ch is the first non-white space character, if any.
    //         endOfFileSeen = true iff end of file was read while
    //           reading white space characters.
    if (!endOfFileSeen) {
      // ASSERT: ch = x is a non-white space character
      readToken (pToken, ch);
      // ASSERT: pToken is the non-white space string starting with x.
      //         ch is a white space character, or end of file was
      //           read. 
    } // end of if (!endOfFileSeen)
  }
}


