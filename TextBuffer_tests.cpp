#include "TextBuffer.hpp"
#include "unit_test_framework.hpp"

using namespace std;

// Add your test cases here

TEST(textbuffer_insert) {
  TextBuffer buffer;
  buffer.insert('e');
  buffer.insert('f');
  buffer.backward();
  ASSERT_EQUAL(buffer.data_at_cursor(), 'f');
}

TEST(textbuffer_insert_newline) {
// on line.exe: steady^<<<<^>>^>>^@<<@^^
  TextBuffer buffer;
  buffer.insert('s');
  buffer.insert('t');
  buffer.insert('e');
  buffer.insert('a');
  buffer.insert('d');
  buffer.insert('y');
  buffer.insert('\n');
  ASSERT_EQUAL(buffer.get_row(), 2);
  ASSERT_EQUAL(buffer.get_column(), 0);
  buffer.backward();
  ASSERT_EQUAL(buffer.get_row(), 1);
  ASSERT_EQUAL(buffer.get_column(), 6);
  buffer.backward();
  ASSERT_EQUAL(buffer.get_row(), 1);
  ASSERT_EQUAL(buffer.get_column(), 5);
  buffer.insert('\n');
  ASSERT_EQUAL(buffer.stringify(), "stead\ny\n");
  ASSERT_EQUAL(buffer.data_at_cursor(), 'y');
  ASSERT_EQUAL(buffer.get_row(), 2);
  ASSERT_EQUAL(buffer.get_column(), 0);
  // ASSERT_EQUAL(buffer.get_index(), )
  buffer.up();
  buffer.up();
  ASSERT_EQUAL(buffer.get_row(), 1);
  ASSERT_EQUAL(buffer.get_column(), 0);
}

TEST_MAIN()