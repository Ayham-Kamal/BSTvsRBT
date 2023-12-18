#ifndef INCLUDED_InputStream
#define INCLUDED_InputStream

#include "MyString.h"

class InputStream {

  /* CI: endOfFileSeen = true iff the end of file character has been read. */
 private:
  bool endOfFileSeen;

  // PRE: ch is defined.
  // POST: RV = true iff ch is ' ', or '\t' or '\n'
  bool whitespace (char ch);

  // PRE: This object satisfies the CI, and endOfFileSeen = false
  // POST: ch is the first non-white space character read.
  //        endOfFileSeen = true iff end of file was read.
  void skipWhiteSpace (char & ch);

  // PRE: This object satisfies the CI, and endOfFileSeen = false
  //        ch = x is the last character read, and it is not white space
  //        pToken is an empty MyString object
  // POST: pToken is the non-white space string on input starting with
  //        x.
  //       ch is the first non-white space character, if any, read.
  //       endOfFileSeen = true iff end of file was read while reading
  //        the token.
  void readToken (MyString & pToken, char & ch);  
  
 public:

  // PRE:
  // POST: endOfFileSeen = false
  InputStream();

  // PRE: This object satisfies the CI
  // POST: RV = true iff end of file character has been read.
  bool eof() const;
  
  // PRE: This object satisfies the CI. pToken is an empty MyString
  //        object.  
  // POST: 
  void nextToken (MyString & pToken);
  
};
#endif
