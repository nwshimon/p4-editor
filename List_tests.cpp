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


// // our tests

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

TEST(check_empty4) { // case where elements all are deleted from front
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

// // NEED FIX

// // TEST FRONT
TEST(check_front1) { // simple int list case
    // empty list
    List<int> list;
    // add 0,1,2,3,4 into list
    for (int i = 0; i < 5; ++i) {
        list.push_back(i);
    }
    ASSERT_TRUE(list.front() == 0);
}

TEST(check_front2) { // simple char list case
    // empty list
    List<char> list;
    // add a, b, c, d, e into list
    for (char i = 'a'; i < 'e'; ++i) {
        list.push_back(i);
    }
    ASSERT_EQUAL(list.front(), 'a');
}

// TEST(check_front3) { // progressive check case with pop front
//     // empty list
//     List<char> list;
//     // add a,b,c,d,e into list
//     for (char i = 'a'; i < 'e'; ++i) {
//         list.push_back(i);
//     }
//     // delete a,b,c,d,e from list
//     for (int i = 0; i < 5; ++i) {
//         list.pop_front();
//     }
// ASSERT_TRUE(list.front() == 'e');
// }

// TEST(check_front4) { // progressive check case with push front
//     // empty list
//     List<char> list;
//     // add 1,2,3,4 into list
//     for (char i = 'a'; i < 'e'; ++i) {
//         list.push_back(i);
//     }
//     // delete 1,2,3,4 from list
//     for (char i = 'e'; i >= 'a'; --i) {
//         list.push_front(i);
//         ASSERT_TRUE(list.front() == 'e' - i);
//     }
// }

// TEST BACK -- recheck logic later its 3am
TEST(check_back1) { // simple int list case
    // empty list
    List<int> list;
    // add 1,2,3,4 into list
    for (int i = 0; i < 5; ++i) {
        list.push_back(i);
    }

    ASSERT_TRUE(list.back() == 4);
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

// TEST(check_back3) { // progressive check case with pop front
//     // empty list
//     List<char> list;
//     // add 1,2,3,4 into list

//     for (char i = 'a'; i < 'e'; ++i) {
//         list.push_back(i);
//     }
//     // delete 1,2,3,4 from list
//     for (char i = 'a'; i < 'e'; ++i) {
//         list.pop_front();
//         ASSERT_TRUE(list.back() == 'e' - i);
//     }
// }

TEST(check_back4) { // progressive check case with push front
    // empty list
    List<int> list;
    // add 0,1,2,3,4 into list
    for (int i = 0; i < 5; i++) {
        list.push_back(i);
        ASSERT_EQUAL(list.back(), i);
    }  
}  

// // NOT WORKING -FIX!!!!
// // TEST PUSH FRONT
// TEST(check_pushf1) { // simple push front
//     // empty list
//     List<int> list;
//     // add 1,2,3,4 into list
//     List<int>::Iterator it = list.begin();
//     int check = *it; // -overloaded deref operator gets datum
//     // List<int>::Iterator it; 
//     for (int i = 0; i < 5; ++i) {
//         list.push_front(i);
//         ASSERT_EQUAL(i, check);
//     }
// }

// TEST(check_begin2) {
//     // empty list
//     List<int> list;
//     // makes an iterator pointing to the beginning of the list
//     List<int>::Iterator it = list.begin();
//     // it should be pointing to a nullptr
//     // ASSERT_FALSE(it);
// }

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

TEST(check_pop_front3) { // checks that first node specifically is deleted
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

TEST(check_push_front1) { // simple push front check
    // empty list
    List<int> list;
    // add 0,1,2,3,4 into list
    for (int i = 0; i < 5; ++i) {
        list.push_front(i);
    }
    ASSERT_TRUE(!list.empty());
}

TEST(check_push_front2) { // simple push front datum check
    // empty list
    List<int> list;
    // add 0,1,2,3,4 into list so it's {4,3,2,1,0}
    for (int i = 0; i < 5; ++i) {
        list.push_front(i);
    }
    ASSERT_TRUE(list.front() == 4);
}

TEST(check_self_assignment_operator) {
    List<int> list1;
    List<int>* list_ptr = &list1;
    list1 = *list_ptr;
    
    for (int i = 0; i < 5; ++i) {
        list1.push_back(i);
    }
    List<int> list2;
    list2 = list1;
}

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
TEST(check_bool_equal) { 
    List<int> list;
    // fills in the list with 0, 1, 2, 3, 4
    for (int i = 0; i < 5; i++) {
        list.push_back(i);
    }
    List<int>::Iterator it1 = list.end();
    List<int>::Iterator it2 = list.begin();
    ASSERT_FALSE(it1 == it2);
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

TEST(check_iterator_insert1) { 
    List<int> list1;
    List<int>::Iterator it1 = list1.begin();
    list1.insert(it1, 5);
    ASSERT_EQUAL(list1.front(), 5);
    ASSERT_EQUAL(list1.back(), 5);
}

TEST(check_iterator_insert2) { 
    List<int> list1;
    List<int>::Iterator it1 = list1.begin();
    List<int>::Iterator it2 = list1.insert(it1, 11);
    ASSERT_EQUAL(*it2, 11);
}

TEST(check_iterator_insert_newline) { 
    List<int> list1;
    List<int>::Iterator it1 = list1.begin();
    for (int i = 0; i < 3; i++) {
        list1.push_back(i);
    }
    List<int>::Iterator it2 = list1.insert(it1, '\n');
    ASSERT_EQUAL(*it2, '\n');
}

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

    // iter = list.erase(iter);
    // assert(list.size() == 4);
    // assert(list.front() == 2);
    
    // // Testing if the returned iterator is pointing at the new first
    // assert(*iter == 2);
    // ASSERT_EQUAL(it1,);
}

// FRIEND'S TESTS !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
TEST(list_def_ctor) {
    cout << "Testing List Default Ctor" << endl;
    List<int> list;
    assert(list.empty());
    assert(list.size() == 0);
    cout << "PASS" << endl;
    list.clear();
}

TEST(list_copy_ctor) {
    cout << "Testing List Copy Ctor" << endl;
    List<int> list;
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);

    // Calling Copy Ctor
    List<int> copy(list);

    assert(list.size() == copy.size());
    assert(list.front() == copy.front());
    assert(list.back() == copy.back());

    cout << "PASS" << endl;

    list.clear();
    copy.clear();
}

TEST(list_ass_optor) {
    cout << "Testing List Assignment Operator" << endl;
    List<int> list;
    list.push_front(7);
    list.push_front(10);
    list.push_front(3);

    // Using Copy Ctor
    List<int> copy_ctor(list);
    
    // Using Assignment Operator
    List<int> copy_ass;
    copy_ass = list;

    // Testing if size matches
    assert(list.size() == copy_ctor.size());
    assert(list.size() == copy_ass.size());

    // Testing if first element matches
    assert(list.front() == copy_ctor.front());
    assert(list.front() == copy_ass.front());

    // Testing if last element matches
    assert(list.back() == copy_ctor.back());
    assert(list.back() == copy_ass.back());

    // Testing Assignment with itself
    List<int> &copy_ass2 = copy_ass;
    copy_ass = copy_ass2;
    assert(list.size() == copy_ass.size());
    assert(list.front() == copy_ass.front());
    assert(list.back() == copy_ass.back());

    cout << "PASS" << endl;
    
    list.clear();
    copy_ctor.clear();
    copy_ass.clear();
}

TEST(list_push_front) {
    cout << "Testing List Push Front" << endl;
    List<int> list;
    list.push_front(3);

    // Testing whether an element is added to the list
    assert(list.size() == 1);
    assert(list.front() == 3);
    assert(list.back() == 3);

    list.push_front(1);
    
    // Testing whether the first element is last-added element
    assert(list.size() == 2);
    assert(list.front() == 1);
    assert(list.back() == 3);
    
    cout << "PASS" << endl;
    list.clear();
}

TEST(list_push_back) {
    cout << "Testing List Push Back" << endl;
    List<int> list;
    list.push_back(2);

    // Testing whether an element is added to the list
    assert(list.size() == 1);
    assert(list.back() == 2);
    assert(list.front() == 2);

    list.push_back(8);

    // Testing whether the last element is the last-added element
    assert(list.size() == 2);
    assert(list.back() == 8);
    assert(list.front() == 2);

    cout << "PASS" << endl;
    list.clear();
}

TEST(list_pop_front) {
    cout << "Testing List Pop Front" << endl;
    List<int> list;
    list.push_front(5);
    list.push_front(4);
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);

    // Current List is 1 -> 2 -> 3 -> 4 -> 5
    assert(list.size() == 5);

    list.pop_front();

    // Testing whether the first element changed
    assert(list.size() == 4);
    assert(list.front() == 2);

    // Testing whether the last element is unchanged
    assert(list.back() == 5);

    list.pop_front();
    list.pop_front();
    list.pop_front();
    list.pop_front();

    // Testing whether the list is empty
    assert(list.size() == 0);
    assert(list.empty());

    cout << "PASS" << endl;
    list.clear();
}

TEST(list_pop_back) {
    cout << "Testing List Pop Back" << endl;
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);

    // Current List is 1 -> 2 -> 3 -> 4 -> 5
    assert(list.size() == 5);

    list.pop_back();

    // Testing whether the last element changed
    assert(list.size() == 4);
    assert(list.back() == 4);

    // Testing whether the first element is unchanged
    assert(list.front() == 1);

    list.pop_back();
    list.pop_back();
    list.pop_back();
    list.pop_back();

    // Testing whether the list is empty
    assert(list.size() == 0);
    assert(list.empty());

    cout << "PASS" << endl;
    list.clear();
}

TEST(list_clear) {
    cout << "Testing List Clear" << endl;
    List<int> list;
    list.push_front(2);
    list.push_back(3);
    list.push_front(4);
    list.push_back(5);
    list.push_back(6);
    list.push_front(7);

    assert(list.size() == 6);

    list.clear();

    // Testing whether list is empty and size is 0
    assert(list.empty());
    assert(list.size() == 0);

    // Testing double clear
    list.clear();
    assert(list.empty());
    assert(list.size() == 0);

    cout << "PASS" << endl;
    list.clear();
}

TEST(iter_def_ctor) {
    cout << "Testing Iter Default Ctor" << endl;
    List<int> list;
    List<int>::Iterator iter = list.begin();
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    iter = list.begin();

    ++iter;

    // Testing whether default constructor initialized correctly
    // One Incrementation means pointing at second node
    // Dereferencing the second node
    assert(*(iter) == 2);
    cout << "PASS" << endl;
    list.clear();
}

TEST(iter_deref_op) {
    cout << "Testing Iter Custom Dereference Operator" << endl;
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);

    List<int>::Iterator iter = list.begin();

    // Testing dereferencing first element
    assert(*iter == 1);
    ++iter;

    // Testing dereferencing second element
    assert(*iter == 2);
    ++iter;

    // Testing dereferencing third element
    assert(*iter == 3);
    ++iter;
    
    // Testing dereferencing fourth element
    assert(*iter == 4);
    ++iter;

    // Testing dereferencing fifth element
    assert(*iter == 5);

    cout << "PASS" << endl;
    list.clear();
}

TEST(iter_plus_plus_op) {
    cout << "Testing Iter ++ Operator" << endl;
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);

    List<int>::Iterator iter = list.begin();

    // Testing Prefix ++ Operator
    int a = *(++iter);
    assert(a == 2);

    int b = *(++++iter);
    assert(b == 4);

    iter = list.begin();

    // Testing Postfix ++ Operator
    int c = *(iter++);
    assert(c == 1);
    assert(*iter == 2);
    iter++;
    assert(*iter == 3);
    cout << "PASS" << endl;
    list.clear();
}

TEST(iter_equal_to_not_equal_to_op) {
    cout << "Testing Equal-To Not-Equal-To Operator" << endl;

    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    // Two Default Constructed Iterators = True
    List<int>::Iterator iter1;
    List<int>::Iterator iter2;

    assert(iter1 == iter2);
    ASSERT_FALSE(iter1 != iter2);

    // Two Iterators Pointing at the same location of the same list = True
    iter1 = list.begin();
    iter2 = list.begin();

    assert(iter1 == iter2);
    ASSERT_FALSE(iter1 != iter2);

    // Two Iterator Pointing at the same list but different location
    ++iter2;
    ASSERT_FALSE(iter1 == iter2);
    assert(iter1 != iter2);
    ++iter1;
    assert(iter1 == iter2);
    ASSERT_FALSE(iter1 != iter2);
    ++iter1;
    ASSERT_FALSE(iter1 == iter2);
    assert(iter1 != iter2);

    // One default constructed Iterator and One regular Iterator
    List<int>::Iterator iter3;
    ASSERT_FALSE(iter3 == iter1);
    assert(iter3 != iter1);

    cout << "PASS" << endl;
    list.clear();
}

TEST(iter_begin) {
    cout << "Testing Iter Begin()" << endl;
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);

    List<int>::Iterator iter = list.begin();

    // List has multiple elements
    // Testing if dereferencing iter gives the first element
    assert(list.size() == 5);
    assert(*iter == 1);

    // Adding element through begin iterator
    // Testing if element is added at the beginning
    list.insert(iter, 10);
    assert(list.size() == 6);
    assert(list.front() == 10);

    list.clear();

    list.push_back(10);
    iter = list.begin();

    // List has one element
    // Testing if dereferencing iter gives the first element
    assert(list.size() == 1);
    assert(*iter == 10);

    // Adding element through begin iterator
    // testing if element is added at the beginning
    list.insert(iter, 9);
    assert(list.size() == 2);
    assert(list.front() ==9);

    list.clear();
    iter = list.begin();

    // List has no elements
    // Testing if begin is the same as end
    List<int>::Iterator iter2 = list.end();
    assert(iter == iter2);

    // Adding element through begin iterator
    // Testing if element is added at the beginning
    list.insert(iter, 100);
    assert(list.size() == 1);
    assert(list.front() == 100);

    cout << "PASS" << endl;
    list.clear();
}

TEST(iter_end) {
    cout << "Testing Iter End()" << endl;
    List<int> list;
    list.push_back(10);
    list.push_back(11);
    list.push_back(12);
    list.push_back(13);
    list.push_back(14);

    List<int>::Iterator iter = list.end();
    
    // List has multiple elements
    // Testing if dereferencing iter after --iter gives the last element
    --iter;
    assert(list.size() == 5);
    assert(*iter == 14);

    // Adding element through end iterator
    // Testing if element is added at the location one before the end
    iter = list.end();
    list.insert(iter, 15);
    assert(list.size() == 6);
    assert(list.back() == 15);
    --iter;
    assert(*iter == 15);
    assert(*iter == list.back());
    --iter;
    assert(*iter == 14);

    list.clear();
    list.push_back(7);
    iter = list.end();

    // List has one element
    // Testing if dereferencing iter after --iter gives the last element
    --iter;
    assert(list.size() == 1);
    assert(*iter == 7);

    // Adding element through end iterator
    // Testing if element is added at the end
    iter = list.end();
    list.insert(iter, 77);
    assert(list.size() == 2);
    assert(list.back() == 77);
    --iter;
    assert(*iter == 77);
    assert(*iter == list.back());
    --iter;
    assert(*iter == 7);

    list.clear();
    iter = list.end();

    // List has no elements
    // Testing if end() is the same as begin()
    List<int>::Iterator iter2 = list.begin();
    assert(iter == iter2);

    // Adding element to list through end()
    // Testing if element is added
    list.insert(iter, 10);
    assert(list.size() == 1);
    assert(iter == iter2);
    --iter;
    assert(iter != iter2);
    assert(*iter == 10);

    cout << "PASS" << endl;
    list.clear();
}

TEST(iter_erase) {
    cout << "Testing iter Erase()" << endl;
    
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    assert(list.size() == 5);

    // List has multiple elements
    // Deleting the first element in the list through begin()
    // Testing if erase() erased the first element
    List<int>::Iterator iter = list.begin();
    iter = list.erase(iter);
    ASSERT_EQUAL(list.size(), 4);
    ASSERT_EQUAL(list.front(), 2);
    
    // Testing if the returned iterator is pointing at the new first
    assert(*iter == 2);

    // Deleting the last element in the list through end()
    // Testing if erase() erased the last element
    iter = list.end();
    --iter;
    iter = list.erase(iter);
    assert(list.size() == 3);
    assert(list.back() == 4);

    // Testing if the returned iterator is a past_the_end iterator
    List<int>::Iterator iter_PTE = list.end();
    ASSERT_EQUAL(iter, list.end());

    // Deleting element in the middle
    // Testing if erase() erased the correct element
    --iter;
    --iter;
    iter = list.erase(iter);
    ASSERT_EQUAL(list.size(), 2);
    ASSERT_EQUAL(list.front(), 2);
    ASSERT_EQUAL(list.back(), 4);

    list.clear();
    list.push_back(20);
    assert(list.size() == 1);
    iter = list.begin();

    // List has one element
    // Deleting the first element in the list through begin()
    iter = list.erase(iter);
    assert(list.size() == 0);
    assert(list.empty());

    // Testing if the returned iterator is pointing at past_the_end 
    iter_PTE = list.end();
    assert(iter == iter_PTE);

    list.push_back(15);
    assert(list.size() == 1);
    iter = list.end();

    // Deleting the first element in the list through end()
    --iter;
    iter = list.erase(iter);
    assert(list.size() == 0);
    assert(list.empty());

    // Testing if the returned iterator is pointing at past_the_end
    iter_PTE = list.end();
    assert(iter == iter_PTE);

    cout << "PASS" << endl;
    list.clear();
}

TEST(iter_insert) {
    cout << "Testing Iter Insert()" << endl;
    List<int> list;
    List<int>::Iterator iter;

    // List is empty
    assert(list.empty());

    // Iterator points at begin()
    iter = list.begin();
    
    // Testing insert in an empty list using begin() iter
    iter = list.insert(iter, 7);
    assert(list.size() == 1);
    assert(list.front() == 7);
    assert(list.back() == 7);
    
    // Testing whether returned iterator points at added element
    assert(*iter == 7);

    // List is empty
    list.clear();
    assert(list.empty());

    // Iterator points at end()
    iter = list.end();

    // Testing insert in an empty list using end() iter
    iter = list.insert(iter, 400);
    assert(list.size() == 1);
    assert(list.front() == 400);
    assert(list.back() == 400);

    // testing whether returned iterator points at added element
    assert(*iter == 400);

    list.clear();

    // list is empty; iter points at past the end
    assert(list.empty());
    iter = list.end();

    // Testing 3 consecutive insert operations
    iter = list.insert(iter, 3);
    iter = list.insert(iter, 2);
    iter = list.insert(iter, 1);

    assert(list.size() == 3);
    assert(list.front() == 1);
    assert(list.back() == 3);
    assert(*iter == 1);

    // List now has three elements, 1 -> 2 -> 3
    // Testing to add element to the front
    iter = list.begin();
    iter = list.insert(iter, 0);
    assert(list.size() == 4);
    assert(list.front() == 0);
    assert(*iter == 0);


    // List now has four elements, 0 -> 1 -> 2 -> 3
    // Testing to add element to the back
    iter = list.end();
    iter = list.insert(iter, 4);
    assert(list.size() == 5);
    assert(list.back() == 4);
    assert(*iter == 4);

    // List now has five elements, 0 -> 1 -> 2 -> 3 -> 4
    // Testing to add element between 2 and 3
    iter = list.begin();
    ++iter;
    ++iter;
    ++iter;

    // Iterator should now be pointing at 3
    assert(*iter == 3);
    iter = list.insert(iter, 6);
    assert(list.size() == 6);
    assert(list.front() == 0);
    assert(list.back() == 4);
    assert(*iter == 6);

    cout << "PASS" << endl;

    list.clear();
}



    // // fills in the list with 0, 1, 2, 3, 4
    // for (int i = 0; i < 5; i++) {
    //     list1.insert(it1, i);
    // }
    

    // List<int> list2;
    // // fills in the list with 4, 3, 2, 1, 0
    // for (int i = 0; i < 5; i++) {
    //     list2.push_front(i);
    // }

    // List<int>::Iterator it1 = list1.begin();
    // List<int>::Iterator it2 = list2.begin();
    // for (int i = 0; i < 3; i++) {
    //     it1++;
    //     it2++;
    // }

//     ASSERT_TRUE(it1 != it2);
// }

// ITERATOR
//     List<int> list;
//     // fills in the list with 0, 1, 2, 3, 4
//     for (int i = 0; i < 5; ++i) {
//         list.push_back(i);
//     }
//     // makes an iterator pointing at the first node of the list
//     List<int>::Iterator it = list.begin();
//     ASSERT_EQUAL(*it, 0); // it dereferenced should give first element
// }

// TEST PUSH BACK
// TEST POP FRONT
// TEST POP BACK
// TEST CLEAR



TEST_MAIN();
