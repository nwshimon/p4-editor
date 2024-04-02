#include <cassert>
#include "TextBuffer.hpp"

//FIX SYNTAX
//EFFECTS: Creates an empty text buffer. Its cursor is at the past-the-end
  //         position, with row 1, column 0, and index 0.
TextBuffer::TextBuffer() {
  // makes cursor attached to the data by assigning cursor to the returned
    // "past end" cursor"
  cursor = data.end();
  // initialize member vars to default
  row = 1;
  column = 0;
  index = 0;
}

//MODIFIES: *this
  //EFFECTS:  Moves the cursor one position forward and returns true,
  //          unless the cursor is already at the past-the-end position,
  //          in which case this does nothing and returns false.
  //NOTE:     Your implementation must update the row, column, and index
  //          if appropriate to maintain all invariants.
bool TextBuffer::forward() {
  if (is_at_end()) {
    return false;
  }
   // if datum is not new line, do simple forward update 
    // increment col and index, keep same row
  column++;
  index++;
  // if datum of cursor is new line char
  if (data_at_cursor() == '\n') {
    // also increment row
    row++;
    // reset col to first col
    column = 0;
  }
    
   // moves cursor forward
  cursor++;
  return true;
    // so when Hello|\n --> should land on Hello\n|
    // when Hello\n| --> go to next row
} // is at end closes

//MODIFIES: *this
  //EFFECTS:  Moves the cursor one position backward and returns true,
  //          unless the cursor is is already at the first character in
  //          the buffer, in which case this does nothing and returns false.
  //HINT:     Implement and use the private compute_column() member
  //          function to compute the column when moving left from the
  //          beginning of a line to the end of the previous one.
  //NOTE:     Your implementation must update the row, column, and index
  //          if appropriate to maintain all invariants.
bool TextBuffer::backward() {
  // if cursor is not at first position
  if (cursor != data.begin()) { 
  // backward cursor position by one 
    cursor--;
    // if datum of cursor is new line char 
    if (data_at_cursor() == '\n') { 
      // decrement row
      row--;
      // decrement col
      column = compute_column();
      // increment index
      index -= 2;
      return true;
    }
    // if datum is not new line, increment col and index
    column--;
    index--;
    return true;
  }
  //if cursor past end position return false
  return false;
}

// row and col changes for this one
void TextBuffer::insert(char c) {
  data.insert(cursor, c);
  forward();
}

// row and col doesn't change for this one
bool TextBuffer::remove() {
  if (is_at_end()) {
    return false;
  }
  // erase repoints the cursor to the node AFTER the erased node
  data.erase(cursor);
  return true;
}

  //MODIFIES: *this
  //EFFECTS:  Moves the cursor to the start of the current row (column 0).
  //NOTE:     Your implementation must update the row, column, and index
  //          if appropriate to maintain all invariants.
void TextBuffer::move_to_row_start() {
  // cursor will never land on newline b/c 
    // already accounted for by other functions
    // this is assuming we've kept the cursor iterator invariant
    // and the row/column invariant
  if (column == 0) { // we're alr at row start
    return;
  }
  // while not new line (bc it would go up a row)
    // so we'd alr be at start of row
  // and not start of list 
    // bc we'd alr be at start of first row (where there's no \n before)
  while (data_at_cursor() != '\n' && cursor != data.begin()) {
    backward(); // go backward once -alr accounts for index decrement
  }
  assert(column == 0);
}

// use compute column?
// is move to row end meant to be the newline character
  // or the last actual character?
void TextBuffer::move_to_row_end() {
  // for when the cursor is already at newline character
  if (data_at_cursor() == '\n' || cursor == data.end()) {
    return;
  }

  // moving the cursor forward until it hits newline or end of data
  while (data_at_cursor() != '\n' && cursor != data.end()) {
    forward();
  }
}

void TextBuffer::move_to_column(int new_column) {
  assert(new_column >= 0);

  // SHOULD account for when new column is past the max col in the row
    // by iterating until the cursor has hit newline
    // or hit past the end
  while (column != new_column && data_at_cursor() != '\n' && cursor != data.end()) {
    // for when the desired column is to the right of the current column
    if (new_column > column) {
      forward();
    }
    // for when the desired column is to the left of the current column
    else if (new_column < column) {
      backward();
    }
    // for when new column is the same as the current column
    else {
      return;
    }
  }
  // check if row, column, index are all kept within invariant here
}

  //MODIFIES: *this
  //EFFECTS:  Moves the cursor to the previous row, retaining the
  //          current column if possible. If the previous row is
  //          shorter than the current column, moves to the end of the
  //          previous row (the newline character that ends the row).
  //          Does nothing if the cursor is already in the first row.
  //          Returns true if the position changed, or false if it did
  //          not (i.e. if the cursor was already in the first row).
  //NOTE:     Your implementation must update the row, column, and index
  //          if appropriate to maintain all invariants.
bool TextBuffer::up() {
  int copy_col = column;
  if (row != 1) {
    // goes back until the row increases by 1 (which is the row we want to be on)
    while (row != row - 1) {
      backward();
      // row decrements in backward()
    }
    // if there is an existing node before the newline on the row above
      // (which backward() returns in a bool)
    if (backward()) {
      // goes back until the cursor hits the original column
      while (column != copy_col) {
        backward();
      }
    }
    return true;
  }
  return false;
}

  //MODIFIES: *this
  //EFFECTS:  Moves the cursor to the next row, retaining the current
  //          column if possible. If the next row is shorter than the
  //          current column, moves to the end of the next row (the
  //          newline character that ends the row, or the past-the-end
  //          position if the row is the last one in the buffer). Does
  //          nothing if the cursor is already in the last row.
  //          Returns true if the position changed, or false if it did
  //          not (i.e. if the cursor was already in the last row).
  //NOTE:     Your implementation must update the row, column, and index
  //          if appropriate to maintain all invariants.
bool TextBuffer::down() {
  return false;
}

bool TextBuffer::is_at_end() const {
 return (cursor == data.end());
}

char TextBuffer::data_at_cursor() const {
  return *cursor;
}

int TextBuffer::get_row() const {
  return row;
}

int TextBuffer::get_column() const {
  return column;
}

int TextBuffer::get_index() const {
  return index;
}

int TextBuffer::size() const {
  return data.size();
}

std::string TextBuffer::stringify() const {
  return std::string(data.begin(), data.end());
}


// assuming that compute_column() is just meant for backward()
  // compute the column when moving left from the
  //          beginning of a line to the end of the previous one.
int TextBuffer::compute_column() const {
  // meant to be at the newline character
  // row would alraedy be changed but 
  TextBuffer copy = *this; // what if textbuffer is long lolz
  // iterator copy
  // no need to make copy
  copy.up();
  // do copy -- --> reaches row start
  int counter = 0;
  while (copy.data_at_cursor() != '\n') {
    copy.forward();
    counter++;
  }
  return counter; 
}
// need to move cursor back until hitting smth
// make a copy cursor

// postfix vs prefix: if trying to dereference directly on the --it or it-- line


// forward backward compute_column