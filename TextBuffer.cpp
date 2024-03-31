#include <cassert>
#include "TextBuffer.hpp"

//FIX SYNTAX
//EFFECTS: Creates an empty text buffer. Its cursor is at the past-the-end
  //         position, with row 1, column 0, and index 0.
TextBuffer::TextBuffer() {
  // List<char> list; //should this be char or int should it even be here
  // //data = ; //
  // //make cursor at "past end" position
  // //TextBuffer buffer;
  // cursor = Iterator(); // not the right way to do this FS
  // //cursor = buffer.end(); // ???????? 
  // row = 1;
  // col = 0;
  // index = 0;
}

//MODIFIES: *this
  //EFFECTS:  Moves the cursor one position forward and returns true,
  //          unless the cursor is already at the past-the-end position,
  //          in which case this does nothing and returns false.
  //NOTE:     Your implementation must update the row, column, and index
  //          if appropriate to maintain all invariants.

bool TextBuffer::forward() {
//   // if cursor is not past end position
//   if (end() != cursor) {
//     // forward cursor position by one 
//     cursor++;
//     // if datum of cursor is new line char
//     if (cursor->node_ptr->datum == '/ln') {
//       // increment row
//       row++;
//       // reset col to first col
//       col = 0;
//       // increment index
//       index++;
//       return true;
//     }
//     // if datum is not new line, increment col and index
//     col++;
//     index++;
//     return true;
//   }
//   //if cursor past end position return false
  return false;
}

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
//   // if cursor is not at first position
//   if (!begin()) { // or should it be first != cursor
//   // backward cursor position by one 
//     cursor--;
//     // if datum of cursor is new line char 
//     if (this->datum == '/ln') { 
//       // increment row
//       row--;
//       // decrement col
//       col = index % ;
//       // increment index
//       index++;
//       return true;
//     }
//     // if datum is not new line, increment col and index
//     col++;
//     index++;
//     return true;
//   }
//   //if cursor past end position return false
   return false;
}

void TextBuffer::insert(char c) {
  assert(false);
}

bool TextBuffer::remove() {
  return false;
}

void TextBuffer::move_to_row_start() {
  assert(false);
}

void TextBuffer::move_to_row_end() {
  assert(false);
}

void TextBuffer::move_to_column(int new_column) {}

bool TextBuffer::up() {
  return false;
}

bool TextBuffer::down() {
  return false;
}

bool TextBuffer::is_at_end() const {
  return true;
}

char TextBuffer::data_at_cursor() const {
  return '\0';
}

int TextBuffer::get_row() const {
  return 0;
}

int TextBuffer::get_column() const {
  return 0;
}

int TextBuffer::get_index() const {
  return 0;
}

int TextBuffer::size() const {
  return 0;
}

std::string TextBuffer::stringify() const {
  return "";
}

int TextBuffer::compute_column() const {
  return 0;
}
