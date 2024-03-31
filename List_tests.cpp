#include "List.hpp"
#include "unit_test_framework.hpp"

using namespace std;

// Add your test cases here

// public tests

TEST(test_list_default_ctor) {
    List<int> empty_list;
    ASSERT_TRUE(empty_list.empty());
}

TEST(test_traversal) {
    List<int> list;
    for (int i = 0; i < 5; ++i) {
        list.push_back(i);
    }
    int j = 0;
    for (List<int>::Iterator it = list.begin(); it != list.end(); ++it, ++j) {
        ASSERT_EQUAL(*it, j);
    }
    ASSERT_EQUAL(j, list.size());
}


// our tests

// EMPTY TESTS
TEST(check_empty1) { // case where list initially empty and elements are added from back
    // empty list
    List<int> list;
    // add 1,2,3,4 into list
    for (int i = 0; i < 5; ++i) {
        list.push_back(i);
    }
    ASSERT_FALSE(list.empty());
}

TEST(check_empty2) { // case where list = empty
    // empty list
    List<int> list;
    ASSERT_TRUE(list.empty());
}

TEST(check_empty3) { // case where elements all are deleted from back
    // empty list
    List<int> list;
    // add 1,2,3,4 into list
    for (int i = 0; i < 5; ++i) {
        list.push_back(i);
    }
    // delete 1,2,3,4 from list
    for (int i = 0; i < 5; ++i) {
        list.pop_back();
    }
    ASSERT_TRUE(list.empty());
}

TEST(check_empty4) { // case where elements all are deleted from front
    // empty list
    List<int> list;
    // add 1,2,3,4 into list
    for (int i = 0; i < 5; ++i) {
        list.push_back(i);
    }
    // delete 1,2,3,4 from list
    for (int i = 0; i < 5; ++i) {
        list.pop_front();
    }
    ASSERT_TRUE(list.empty());
}


// SIZE TESTS
TEST(check_size1) { // simple case
    // empty list
    List<int> list;
    // add 1,2,3,4 into list
    for (int i = 0; i < 5; ++i) {
        list.push_back(i);
    }
    ASSERT_TRUE(list.size() == 4);
}

TEST(check_size2) { // case where elements all are deleted from back
    // empty list
    List<int> list;
    // add 1,2,3,4 into list
    for (int i = 0; i < 5; ++i) {
        list.push_back(i);
    }
    // delete 1,2,3,4 from list
    for (int i = 0; i < 5; ++i) {
        list.pop_front();
    }
    ASSERT_TRUE(list.size() == 0);
}

TEST(check_size3) { // progressive check as nodes added 
    // empty list
    List<int> list;
    // add 1,2,3,4 into list
    for (int i = 0; i < 5; ++i) {
        list.push_back(i);
        ASSERT_TRUE(list.size() == i);
    }
}

TEST(check_size4) { // progressive check as nodes deleted 
    // empty list
    List<int> list;
    // add 1,2,3,4 into list
    for (int i = 0; i < 5; ++i) {
        list.push_back(i);
    }
    // delete 1,2,3,4 from list
    for (int i = 0; i < 5; ++i) {
        list.pop_front();
        ASSERT_TRUE(list.size() == i);
    }
}



// NEED FIX

// TEST FRONT
TEST(check_front1) { // simple int list case
    // empty list
    List<int> list;
    // add 1,2,3,4 into list
    for (int i = 0; i < 5; ++i) {
        list.push_back(i);
    }
    ASSERT_TRUE(list.front() == 1);
}

TEST(check_front2) { // simple char list case
    // empty list
    List<char> list;
    // add 1,2,3,4 into list
    for (char i = 'a'; i < 'e'; ++i) {
        list.push_back(i);
    }
    ASSERT_TRUE(list.front() == 'a');
}

TEST(check_front3) { // progressive check case with pop front
    // empty list
    List<char> list;
    // add 1,2,3,4 into list
    for (char i = 'a'; i < 'e'; ++i) {
        list.push_back(i);
    }
    // delete 1,2,3,4 from list
    for (char i = 'a'; i < 'e'; ++i) {
        list.pop_front();
        ASSERT_TRUE(list.front() == 'a' + i);
    }
}

TEST(check_front4) { // progressive check case with push front
    // empty list
    List<char> list;
    // add 1,2,3,4 into list
    for (char i = 'a'; i < 'e'; ++i) {
        list.push_back(i);
    }
    // delete 1,2,3,4 from list
    for (char i = 'e'; i >= 'a'; --i) {
        list.push_front(i);
        ASSERT_TRUE(list.front() == 'e' - i);
    }
}


// TEST BACK -- recheck logic later its 3am
TEST(check_back1) { // simple int list case
    // empty list
    List<int> list;
    // add 1,2,3,4 into list
    for (int i = 0; i < 5; ++i) {
        list.push_back(i);
    }
    //ASSERT_TRUE(list.back() = 4);
}

TEST(check_back2) { // simple char list case
    // empty list
    List<char> list;
    // add 1,2,3,4 into list
    for (char i = 'a'; i < 'e'; ++i) {
        list.push_back(i);
    }
    ASSERT_TRUE(list.back() == 'd');
}

TEST(check_back3) { // progressive check case with pop front
    // empty list
    List<char> list;
    // add 1,2,3,4 into list

    for (char i = 'a'; i < 'e'; ++i) {
        list.push_back(i);
    }
    // delete 1,2,3,4 from list
    for (char i = 'a'; i < 'e'; ++i) {
        list.pop_front();
        ASSERT_TRUE(list.back() == 'e' - i);
    }
}

TEST(check_back4) { // progressive check case with push front
    // empty list
    List<char> list;
    // add 1,2,3,4 into list
    for (char i = 'a'; i < 'e'; ++i) {
        list.push_back(i);
    }
    // delete 1,2,3,4 from list
    for (char i = 'e'; i >= 'a'; --i) {
        list.push_back(i);
        ASSERT_TRUE(list.front() == 'a' + i);
    }  
}  

// NOT WORKING -FIX!!!!
// TEST PUSH FRONT
TEST(check_pushf1) { // simple push front
    // empty list
    List<int> list;
    // add 1,2,3,4 into list
    int check = 0;
    for (int i = 0; i < 5; ++i) {
        list.push_front(i);
        //check = first->datum;
        ASSERT_EQUAL(i, check);
    }
}


// TEST PUSH BACK
// TEST POP FRONT
// TEST POP BACK
// TEST CLEAR



TEST_MAIN()
