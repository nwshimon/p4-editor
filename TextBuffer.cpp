#include <cassert>
#include "TextBuffer.hpp"

//FIX SYNTAX
//EFFECTS: Creates an empty text buffer. Its cursor is at the past-the-end
  //         position, with row 1, column 0, and index 0.
TextBuffer::TextBuffer() : row(1), column(0), index(0) {
  // makes cursor attached to the data by assigning cursor to the returned
    // "past end" cursor"
  cursor = data.end();
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
    // reset col to first col
    column = 0;
    // also increment row
    row++;
  }
  cursor++;

  // where the fuck is the cursor supposed to land when you put a newline
    // is it meant to be at the next row and col = 0?
    // but col = 0 makes it so that the next incrementation eg for forward()
    // puts the node that would be at col = 0 as col = 1
      // is this maybe a problem with how we're assigning new nodes?

  // // if datum of cursor is new line char
  // // ACTUALLY: trying to check if data at cursor is RIGHT AFTER NEWLINE
  //   // AFTER we've already moved cursor forward
  // if (data_at_cursor() == '\n') {
  //   // accounts for when the cursor is at newline,
  //     // but doesn't have a next node
  //     // shouldn't update row, column should already be at end
  //   // cursor is moved forward within this if statement
  //   if (++cursor == data.end()) { }
  //   // accounts for when the cursor is at newline
  //     // and has a next node
  //   else {
  //     // reset col to first col
  //     column = 0;
  //     // also increment row
  //     row++;
  //   }
  // }
  // else {
  //   ++cursor;
  // }
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
  if (cursor == data.begin()) {
    return false;
  }
  // backward cursor position by one 
  cursor--;
  column--;

  // if at begining of a line and you go backwards,
    // you end up with a negative column
  if (column < 0) {
    row--;
    column = compute_column();
  }
  
    // if datum is not new line, increment col and index
  index--;
  return true;
}

// row and col changes for this one
void TextBuffer::insert(char c) {
  cursor = data.insert(cursor, c);
  forward();
}

// row and col doesn't change for this one
// when you try to remove twice: breaks
bool TextBuffer::remove() {
  if (is_at_end()) {
    return false;
  }
  // erase repoints the cursor to the node AFTER the erased node
  cursor = data.erase(cursor);
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
  if (column == 0 && cursor == data.begin()) { // we're alr at row start
    return;
  }

  // check if not at the end iterator then decrement first
  // BEFORE entering while loop
  if (cursor != data.end()) {
    backward();
  }

  // while not new line (bc it would go up a row)
    // so we'd alr be at start of row
  // and not start of list 
    // bc we'd alr be at start of first row (where there's no \n before)
  while (column != 0 && data_at_cursor() != '\n'
         && cursor != data.begin()) {
    backward(); // go backward once -alr accounts for index decrement
  }
}

// use compute column?
// is move to row end meant to be the newline character
  // or the last actual character?
void TextBuffer::move_to_row_end() {
  // for when the cursor is already at newline character
  if (cursor == data.end() || data_at_cursor() == '\n') {
    return;
  }

  // moving the cursor forward until it hits newline or end of data
  // !! evaluated from left to right - order matters in if statements
  while (cursor != data.end() && data_at_cursor() != '\n') {
    forward();
  }
}

  //REQUIRES: new_column >= 0
  //MODIFIES: *this
  //EFFECTS:  Moves the cursor to the given column in the current row,
  //          if it exists. If the row does not have that many columns,
  //          moves to the end of the row (the newline character that
  //          ends the row, or the past-the-end position if the row is
  //          the last one in the buffer).
  //NOTE:     Your implementation must update the row, column, and index
  //          if appropriate to maintain all invariants.
void TextBuffer::move_to_column(int new_column) {
  assert(new_column >= 0);
  if (new_column > column) {
    forward();
  }
  else if (new_column < column) {
    backward();
  }

  // SHOULD account for when new column is past the max col in the row
    // by iterating until the cursor has hit newline
    // or hit past the end
  while (column != new_column && data_at_cursor() != '\n'
         && cursor != data.end()) {
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
      move_to_row_end();
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
  int target_col = column;
  if (row != 1) {
    // at the end, we want our cursor to land on row-1
    int target_row = row - 1;
    // goes back until the row increases by 1 (which is the row we want to be on)
    while (row != target_row) {
      backward();
      // row decrements in backward()
    }
    // if there is an existing node before the newline on the row above
      // (which backward() returns in a bool)
    
    // if the cursor arrives at a column that is less than the target column
      // after going backwards
    if (column < target_col) {
      // move the cursor to the end of the row
      move_to_row_end();
      return true;
    }
    else {
      while (column != target_col) {
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
  int copy_col = column;
  int target_row = row + 1;
  // checks if the cursor has been placed past the end yet
    // - if already at past the end, return false
  if (cursor == data.end()) {
    return false;
  }
// TO CHECK IF AT LAST ROW:
  // while not at newline, keep moving forward
  while (data_at_cursor() != '\n') {
    // moves cursor forward
    forward();
    if (cursor == data.end()) { // if cursor hits end, then return false
      move_to_row_end();
      return false;
      }
    // otherwise: once newline is encountered, break out of the while loop
  }
  while (row != target_row) {
    forward();
    // row increments in forward()
  }
  if (forward()) {
    while (column != copy_col && cursor != data.end()
           && data_at_cursor() != '\n') {
      forward();
    }
  }
  return true;
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

  // compute the column when moving left from the
  //          beginning of a line to the end of the previous one.
int TextBuffer::compute_column() const {
  Iterator copy = cursor;
  int counter = 0;
  // if the cursor is past the end, then find the column
    // of the last element in the row
  if (cursor == data.end()) {
    copy--;
    counter++;
  }
  // if cursor is at the end of the row - still need to compute column
  // even if on newline
    // makes it so the main while loop below can still execute
    // '\n' condition would not let code enter while loop
  else if (*cursor == '\n') {
    copy--;
    counter++;
  }
  while (*copy != '\n' && copy != data.begin() && (*--copy != '\n')) {
    counter++;
  }
  return counter;
}
// need to move cursor back until hitting smth
// make a copy cursor

// postfix vs prefix: if trying to dereference directly on the --it or it-- line


// forward backward compute_column