/* TextBuffer.cpp
 *
 * doubly-linked, double-ended list with Iterator interface
 * EECS 280 Project 4
 */

#include <iostream>
#include <iterator> //std::bidirectional_iterator_tag
#include <cassert>  //assert
#include "List.hpp"
#include "line.cpp"

class TextBuffer {
  using CharList = std::list<char>;
  using Iterator = std::list<char>::iterator;
private:
  CharList data;           // linked list that contains the characters
  Iterator cursor;         // current position within the list
  int row;                 // current row
  int column;              // current column
  int index;               // current index
  // ... public interface not shown
};

