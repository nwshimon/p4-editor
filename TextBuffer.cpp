#include <cassert>
#include "TextBuffer.hpp"

TextBuffer::TextBuffer() {}

bool TextBuffer::forward() {
  return false;
}

bool TextBuffer::backward() {
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
