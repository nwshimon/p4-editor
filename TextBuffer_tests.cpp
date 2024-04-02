#include "TextBuffer.hpp"
#include "unit_test_framework.hpp"

using namespace std;

// Add your test cases here

TEST(textbuffer_insert) {
  TextBuffer buffer;
  buffer.insert('e');
  ASSERT_EQUAL(buffer.data_at_cursor(), 'e');
}

TEST_MAIN()
