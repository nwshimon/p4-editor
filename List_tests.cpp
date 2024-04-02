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

// LIST TESTS —————————————————
// EMPTY TESTS
// case where list initially empty and elements are added from back
TEST(check_empty1) { 
    // empty list
    List<int> list;
    // add 1,2,3,4 into list
    for (int i = 0; i < 5; ++i) {
        list.push_back(i);
    }
    ASSERT_FALSE(list.empty());
}

// case where list = empty
TEST(check_empty2) { 
    // empty list
    List<int> list;
    ASSERT_TRUE(list.empty());
}

// case where elements all are deleted from back
TEST(check_empty3) { 
    // empty list
    List<int> list;
    // add 0,1,2,3,4 into list
    for (int i = 0; i < 5; ++i) {
        list.push_back(i);
    }
    // delete 0,1,2,3,4 from list
    for (int i = 0; i < 5; ++i) {
        list.pop_back();
    }
    ASSERT_TRUE(list.empty());
}

// case where elements all are deleted from front
TEST(check_empty4) { 
    // empty list
    List<int> list;
    // add 0,1,2,3,4 into list
    for (int i = 0; i < 5; ++i) {
        list.push_back(i);
    }
    // delete 0,1,2,3,4 from list
    for (int i = 0; i < 5; ++i) {
        list.pop_front();
    }
    ASSERT_TRUE(list.empty());
}


// SIZE TESTS
TEST(check_size1) { // simple case
    // empty list
    List<int> list;
    // add 0,1,2,3,4 into list
    for (int i = 0; i < 5; ++i) {
        list.push_back(i);
    }
    ASSERT_EQUAL(list.size(), 5);
}

TEST(check_size2) { // case where elements all are deleted from front
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
    // add 0,1,2,3,4 into list
    for (int i = 0; i < 5; ++i) {
        list.push_back(i);
        ASSERT_EQUAL(list.size(), i + 1);
    }
}

TEST(check_size4) { // progressive check as nodes deleted 
    // empty list
    List<int> list;
    // add 0,1,2,3,4 into list
    for (int i = 0; i < 5; ++i) {
        list.push_back(i);
    }
    // delete 0,1,2,3,4 from list
    for (int i = 0; i < 5; ++i) {
        list.pop_front();
        ASSERT_EQUAL(list.size(), 4 - i);
    }
}

// TEST FRONT
TEST(check_front1) { // simple int list case - pushfront 5x
    // empty list
    List<int> list;
    // add 0,1,2,3,4 into list
    for (int i = 0; i < 5; ++i) {
        list.push_back(i);
    }
    ASSERT_TRUE(list.front() == 0);
}

TEST(check_front2) { // simple char list case - pushfront 1x
    // empty list
    List<int> list;
    list.push_back(11);
    ASSERT_EQUAL(list.front(), 11);
    ASSERT_EQUAL(list.back(), 11);
    ASSERT_EQUAL(list.size(), 1);
}

TEST(check_front3) { // check pop front ending w/ non-empty list
    // empty list
    List<int> list;
    // add 4,3,2,1,0 into list
    for (int i = 0; i < 5; ++i) {
        list.push_front(i);
    }
    // delete 4,3,2 from list
    for (int i = 0; i < 3; ++i) {
        list.pop_front();
    }
    ASSERT_EQUAL(list.front(), 1);
    ASSERT_EQUAL(list.size(), 2);
}

TEST(check_front4) { // progressive check case with push front
    // empty list
    List<int> list;
    // add 0,1,2,3,4 into list
    for (char i = 0; i < 5; ++i) {
        list.push_back(i);
    }
    // delete 0,1,2,3,4 from list
    for (char i = 0; i > 5; --i) {
        list.pop_front();
        if (i != 5) {
            ASSERT_EQUAL(list.front(), i + 1);
        }
        else {
            ASSERT_TRUE(list.empty());
        }
    }
}

// TEST BACK
TEST(check_back1) { // simple int list case
    // empty list
    List<int> list;
    // add 0,1,2,3,4 into list
    for (int i = 0; i < 5; ++i) {
        list.push_back(i);
    }

    ASSERT_TRUE(list.back() == 4);
}

TEST(check_back2) { // simple char list case
    // empty list
    List<int> list;
    // add 0,1,2,3,4 into list
    for (int i = 0; i < 5; ++i) {
        list.push_back(i);
    }
    ASSERT_TRUE(list.back() == 4);
}

TEST(check_back3) { // progressive check case with pop front
    // empty list
    List<int> list;
    // add 0,1,2,3,4 into list
    for (int i = 1; i < 5; ++i) {
        list.push_back(i);
    }
    // delete 0,1,2,3,4 from list
    for (char i = 0; i > 5; --i) {
        list.pop_back();
        if (i != 5) {
            ASSERT_EQUAL(list.back(), 5 - i);
        }
        else {
            ASSERT_TRUE(list.empty());
        }
    }
}

TEST(check_back4) { // progressive check case with push front
    // empty list
    List<int> list;
    // add 0,1,2,3,4 into list
    for (int i = 0; i < 5; i++) {
        list.push_back(i);
        ASSERT_EQUAL(list.back(), i);
    }  
}  

// TEST PUSH FRONT
    // push front 1x - checks insertion into empty list
TEST(check_pushf1) {
    List<int> list;
    list.push_front(6);
    ASSERT_EQUAL(list.front(), 6);
    ASSERT_EQUAL(list.back(), 6);
}

    // push front 2x - checks if actually adds element from front
TEST(check_pushf2) {
    List<int> list;
    list.push_front(3);
    list.push_front(2);
    ASSERT_EQUAL(list.front(), 2);
}

    // push front 5x - progressive check case for front
TEST(check_pushf3) {
    // empty list
    List<int> list;
    // add 4,3,2,1,0 into list
    for (char i = 0; i < 5; ++i) {
        list.push_front(i);
    }
    // delete 4,3,2,1,0 from list
    for (char i = 0; i > 5; --i) {
        list.pop_front();
        int subtractor = i+1;
        if (i != 5) {
            ASSERT_EQUAL(list.front(), 5-subtractor);
        }
        else {
            ASSERT_TRUE(list.empty());
        }
    }
}

TEST(check_pushf4) { // simple push front check
    // empty list
    List<int> list;
    // add 0,1,2,3,4 into list
    for (int i = 0; i < 5; ++i) {
        list.push_front(i);
    }
    ASSERT_TRUE(!list.empty());
}

TEST(check_pushf5) { // simple push front datum check
    // empty list
    List<int> list;
    // add 0,1,2,3,4 into list so it's {4,3,2,1,0}
    for (int i = 0; i < 5; ++i) {
        list.push_front(i);
    }
    ASSERT_TRUE(list.front() == 4);
}

// TEST POP FRONT
TEST(check_pop_front1) { // simple case with one node deleted
    List<int> list;
    // 1 is in list
    list.push_back(1);
    ASSERT_EQUAL(list.size(), 1);
    list.pop_front(); 
    ASSERT_TRUE(list.empty());
}

TEST(check_pop_front2) { // simple case with all nodes deleted
    List<int> list;
    // adds 0,1,2,3,4
    for (int i = 0; i < 5; ++i) {
        list.push_back(i);
    }
    // pops front elements 0 thru 4
    for (int j = 0; j < 5; ++j) {
        list.pop_front();
    }
    ASSERT_EQUAL(list.size(), 0); 
}

// checks that first node specifically is deleted
TEST(check_pop_front3) { 
    List<int> list;
    // adds 0,1,2,3,4
    for (int i = 0; i < 5; ++i) {
        list.push_back(i); 
    } 
    // pops front element '0'
    list.pop_front(); 
    int size = list.size();
    int curr_first_node = list.front();
    cout << size << curr_first_node;
    // new first->datum should be 2 bc 1 was 'popped' from front
    ASSERT_EQUAL(list.front(), 1); 
}

TEST(check_pop_back1) {
    List<int> list;
    // fills in the list with 0,1, 2, 3, 4
    list.push_back(1);
    ASSERT_EQUAL(list.size(), 1);
    list.pop_back(); 
    ASSERT_TRUE(list.empty());
}

TEST(check_pop_back2) {
    List<char> list;
    // adds 0,1,2,3,4 to list
    for (char i = 0; i < 5; ++i) {
        list.push_back(i);
    }
    // pops back elements 4 thru 1
    for (int i = 0; i < 5; ++i) {
        list.pop_back();
    }
    ASSERT_TRUE(list.size()== 0);
}

TEST(check_pop_back3) { // checks that first node specifically is deleted
    List<int> list;
    // adds 0,1,2,3,4
    for (int i = 0; i < 5; ++i) {
        list.push_back(i); 
    } 
    // pops back element '4'
    list.pop_back(); 
    // new first->datum should be 3 bc 4 was 'popped' from back
    ASSERT_EQUAL(list.back(), 3); 
}

// TEST CLEAR
    // clearing on a multiple-node list
TEST(check_clear1) {
    List<int> list;
    for (int i = 0; i < 5; i++) {
        list.push_back(i);
    }
    list.clear();
    ASSERT_TRUE(list.empty());
    ASSERT_EQUAL(list.size(), 0);
}

    // clearing on 1 node list
TEST(check_clear2) {
    List<int> list;
    list.push_front(7);
    list.clear();
    ASSERT_TRUE(list.empty());
    ASSERT_EQUAL(list.size(), 0);
}

// LIST BIG THREE TESTS ——————————————————————
TEST(check_default_ctor) {
    List<int> list;
    ASSERT_TRUE(list.empty());
    ASSERT_EQUAL(list.size(), 0);
    list.clear();
}

TEST(check_assignment_operator) {
    // tests copying into another list
    List<int> list;
    list.push_front(6);
    list.push_front(2);
    list.push_back(5);
    list.push_back(7);
    // 2 6 5 7

    // uses the assignment operator to copy into a List variable
    List<int> copy = list;
    // checks if size & front of copy and list are the same
    ASSERT_EQUAL(list.size(), copy.size());
    ASSERT_EQUAL(list.front(), copy.front());

    // tests self assignment
    List<int> list1;
    List<int>* list_ptr = &list1;
    list1 = *list_ptr;
    
    for (int i = 0; i < 5; ++i) {
        list1.push_back(i);
    }
    List<int> list2;
    list2 = list1;
    ASSERT_EQUAL(list1.size(), list2.size());
    ASSERT_EQUAL(list1.front(), list2.front());
    ASSERT_EQUAL(list1.back(), list2.back());
    list1.clear();
    list2.clear();
    copy.clear();
}

TEST(check_copy_ctor) {
    List<int> list;
    list.push_front(6);
    list.push_front(2);
    list.push_back(5);
    list.push_back(7);
    List<int> copy(list);
    ASSERT_EQUAL(list.size(), copy.size());
    ASSERT_EQUAL(list.front(), copy.front());
    list.clear();
}

// TEST ITERATOR ————————————————————————————
// TEST BEGIN & END
    // checks iterator begin & end on a 1-node list
TEST(check_iterator_begin_end1) {
    // empty list
    List<int> list;
    list.push_back(5);
    // makes an iterator pointing to the beginning of the list
    List<int>::Iterator it = list.begin();
    ASSERT_EQUAL(*it, 5);
    // List<int>::Iterator it2 = list.end();
    // // it2 should be past the end
    // ASSERT_EQUAL(it2, nullptr);
}

    // checks iterator on multiple node list w/ mix of pushf & pushb
    // checks if iterator is past the end
TEST(check_iterator_begin_end2) {
    List<int> list;
    list.push_back(6);
    list.push_back(3);
    list.push_front(9);
    // 9 6 3
    List<int>::Iterator it = list.begin();
    // gives first element?
    ASSERT_EQUAL(*it, 9);
    it++;
    // gives middle element?
    ASSERT_EQUAL(*it, 6);
    it++;
    // moves cursor past the end
    it++;
    ASSERT_EQUAL(it, list.end());
}

// on an empty list: check if begin and end are the same

// TEST DEFAULT CTOR
TEST(check_iterator_defctor) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    // 1 2 3
    List<int>::Iterator it = list.begin();
    ASSERT_EQUAL(*it, 1);
    // incrementation prefix returns incremented value
    ASSERT_EQUAL(*(++it), 2);
    // incrementation postfix returns og value
    ASSERT_EQUAL(*(it++), 2);
    list.clear();
}

// TEST ITERATOR INSERT
// checks inserting into an empty list
TEST(check_iterator_insert1) { 
    List<int> list1;
    List<int>::Iterator it1 = list1.begin();
    list1.insert(it1, 5);
    ASSERT_EQUAL(list1.front(), 5);
    ASSERT_EQUAL(list1.back(), 5);
}

// checks progressive iterator traversal with inserts
TEST(check_iterator_insert2) { 
    List<int> list1;
    List<int>::Iterator it1 = list1.begin();
    List<int>::Iterator it2 = list1.insert(it1, 11);
    // it2 should point to the new inserted node - 11
    ASSERT_EQUAL(*it2, 11);
    List<int>::Iterator it3 = list1.insert(it2, 2);
    ASSERT_EQUAL(*it3, 2);
    // it3 points to newly inserted node - 2 (which is BEFORE 11)
    it3++;
    ASSERT_EQUAL(*it3, 11);
}

// checks inserting new line - where would iterator land?
TEST(check_iterator_insert_newline) { 
    List<int> list1;
    List<int>::Iterator it1 = list1.begin();
    // 0,1,2
    for (int i = 0; i < 3; i++) {
        list1.push_back(i);
        it1++;
        // when i = 2: lands it1 past the end
    }
    ASSERT_EQUAL(it1, list1.end());
    // goes to 2
    it1--;
    List<int>::Iterator it1 = list1.insert(it1, '\n');
    // inserts \n BEFORE 2
    ASSERT_EQUAL(*it1, '\n');
    it1++;
    ASSERT_EQUAL(*it1, 2);
}

// tests erase on multiple node list
TEST(check_erase1) {
    List<int> list1;
    for (int i = 0; i < 5; i++) {
        list1.push_back(i);
    }
    List<int>::Iterator it1 = list1.begin();
    List<int>::Iterator deletor = list1.begin();
    
    // testing if erase deletes first element
    it1 = list1.erase(deletor);
    ASSERT_EQUAL(list1.size(), 4);
    ASSERT_EQUAL(list1.front(), 1);

    // testing if returned iterator is pointing at the new first
    ASSERT_EQUAL(*it1, 1);

    // delete the last element
    deletor = list1.end();
    --deletor;
    it1 = list1.erase(deletor);
    ASSERT_EQUAL(list1.size(), 3);
    ASSERT_EQUAL(list1.front(), 1);
}

// checks what it means to "invalidate iterator"
TEST(check_erase2) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    List<int>::Iterator middle = list.begin();
    middle++;
    List<int>::Iterator new_iter = list.erase(middle);
    // middle SHOULD be invalidated here
    ASSERT_EQUAL(*new_iter, 3);
}

// erases elements from multiple node list
TEST(check_erase3) {
    List<int> list;
    for (int i = 0; i < 10; i++) {
        list.push_back(i);
    }

    // erases first element
        // 0
    List<int>::Iterator cursor = list.begin();
    cursor = list.erase(cursor);
    ASSERT_EQUAL(*cursor, 1)

    // erases element not first not last
        // 2
    cursor++;
    cursor = list.erase(cursor);
    ASSERT_EQUAL(*cursor, 3);
    // erases last element
        // 9
    cursor = list.end();
    cursor--;
    cursor = list.erase(cursor);
    ASSERT_TRUE(cursor == list.end());
    // where does the cursor land if the last element is being deleted?
        // past the end or on the newline?
    // ASSERT FOR INVALIDATED ITERATOR

    // existing nodes: 1 3 4 5 6 7 8

    // erase entire list except for first element (1)
    for (int i = 0; i < 6; i++) {
        cursor--;
        cursor = list.erase(cursor);
    }
    cursor--;
    ASSERT_EQUAL(*cursor, 1);
    cursor = list.erase(cursor);
    ASSERT_TRUE(list.empty());
}

// OVERLOADED OPERATOR TESTS ——————————————
TEST(check_pointer_star) {
    List<int> list;
    list.push_back(2);
    list.push_back(4);
    list.push_front(7);
    // 7, 2, 4
    List<int>::Iterator it = list.begin();
    ASSERT_EQUAL(*it, 7);
    for (int i = 0; i < 2; i++) {
        it++;
    }
    ASSERT_EQUAL(*it, 4);
}

TEST(check_incrementation_prefix) { 
    List<int> list;
    // fills in the list with 0, 1, 2, 3, 4
    for (int i = 0; i < 5; ++i) {
        list.push_back(i);
    }
    // makes an iterator pointing at the first node of the list
    List<int>::Iterator it = list.begin();
    // prefix ++ 
    for (int i = 0; i < 3; i++) {
        ++it;
    }
    ASSERT_TRUE(*it == 3);
}

TEST(check_incrementation_postfix) { 
    List<int> list;
    // fills in the list with 0, 1, 2, 3, 4
    for (int i = 0; i < 5; i++) {
        list.push_back(i);
    }
    List<int>::Iterator it = list.begin();
    int result = *it++;
    ASSERT_EQUAL(result, 0);
    ASSERT_EQUAL(*it, 1);
}

TEST(check_decrementation_prefix) { 
    List<int> list;
    // fills in the list with 0, 1, 2, 3, 4
    for (int i = 0; i < 5; ++i) {
        list.push_back(i);
    }
    // makes an iterator pointing at the first node of the list
    List<int>::Iterator it = list.begin();
    // prefix ++ 
    for (int i = 0; i < 2; i++) {
        ++it;
    }
    --it;
    ASSERT_TRUE(*it == 1);
}

TEST(check_decrementation_postfix) { 
    List<int> list;
    // fills in the list with 0, 1, 2, 3, 4
    for (int i = 0; i < 5; i++) {
        list.push_back(i);
    }
    List<int>::Iterator it = list.begin();
    it++;
    // for (int i = 0; i < 5; i++) {
    //     it++;
    // }
    int result = *it--;
    ASSERT_EQUAL(result, 1);
    ASSERT_EQUAL(*it, 0);
}

    // for when it1 and it2 
TEST(check_bool_equal_and_unequal) { 
    List<int> list;
    // fills in the list with 0, 1, 2, 3, 4
    for (int i = 0; i < 5; i++) {
        list.push_back(i);
    }
    // iterators pointing to same list but diff nodes should be unequal
    List<int>::Iterator it1 = list.end();
    List<int>::Iterator it2 = list.begin();
    ASSERT_FALSE(it1 == it2);
    ASSERT_TRUE(it1 != it2);
    // default iterator constructors should be equal
    List<int>::Iterator it3;
    List<int>::Iterator it4;
    ASSERT_TRUE(it3 == it4);
    ASSERT_FALSE(it3 != it4)
    // 2 iterators pointing to same list and same node
    List<int>::Iterator it5 = list.begin();
    ASSERT_TRUE(it2 == it5);
    ASSERT_FALSE(it2 != it5);
    // default constructor and assigned iterator should be unequal
    ASSERT_FALSE(it2 == it3);
    ASSERT_TRUE(it2 != it3);
    // iterators pointing to same location after moving around should be equal
    for (int i = 0; i < 3; i++) {
        it1--;
        if (i != 2) {
            it2++;
            ASSERT_FALSE(it1 == it2);
        }
        // should both point to 2 at the end
    }
    ASSERT_TRUE(it1 == it2);
    ASSERT_EQUAL(*it1, *it2);
}

    // for when it1 and it2 are pointing to different lists
    // but the same datum
TEST(check_bool_unequal) { 
    List<int> list1;
    // fills in the list with 0, 1, 2, 3, 4
    for (int i = 0; i < 5; i++) {
        list1.push_back(i);
    }
    List<int> list2;
    // fills in the list with 4, 3, 2, 1, 0
    for (int i = 0; i < 5; i++) {
        list2.push_front(i);
    }

    List<int>::Iterator it1 = list1.begin();
    List<int>::Iterator it2 = list2.begin();
    for (int i = 0; i < 3; i++) {
        it1++;
        it2++;
    }

    ASSERT_TRUE(it1 != it2);
}



TEST_MAIN();
