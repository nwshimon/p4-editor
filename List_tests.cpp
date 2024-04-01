#include "List.hpp"
#include "unit_test_framework.hpp"

using namespace std;

// Add your test cases here

// public tests

// TEST(test_list_default_ctor) {
//     List<int> empty_list;
//     ASSERT_TRUE(empty_list.empty());
// }

// TEST(test_traversal) {
//     List<int> list;
//     for (int i = 0; i < 5; ++i) {
//         list.push_back(i);
//     }
//     int j = 0;
//     for (List<int>::Iterator it = list.begin(); it != list.end(); ++it, ++j) {
//         ASSERT_EQUAL(*it, j);
//     }
//     ASSERT_EQUAL(j, list.size());
// }


// // our tests

// // EMPTY TESTS
// TEST(check_empty1) { // case where list initially empty and elements are added from back
//     // empty list
//     List<int> list;
//     // add 1,2,3,4 into list
//     for (int i = 0; i < 5; ++i) {
//         list.push_back(i);
//     }
//     ASSERT_FALSE(list.empty());
// }

// TEST(check_empty2) { // case where list = empty
//     // empty list
//     List<int> list;
//     ASSERT_TRUE(list.empty());
// }

// TEST(check_empty3) { // case where elements all are deleted from back
//     // empty list
//     List<int> list;
//     // add 1,2,3,4 into list
//     for (int i = 0; i < 5; ++i) {
//         list.push_back(i);
//     }
//     // delete 1,2,3,4 from list
//     for (int i = 0; i < 5; ++i) {
//         list.pop_back();
//     }
//     ASSERT_TRUE(list.empty());
// }

// TEST(check_empty4) { // case where elements all are deleted from front
//     // empty list
//     List<int> list;
//     // add 1,2,3,4 into list
//     for (int i = 0; i < 5; ++i) {
//         list.push_back(i);
//     }
//     // delete 1,2,3,4 from list
//     for (int i = 0; i < 5; ++i) {
//         list.pop_front();
//     }
//     ASSERT_TRUE(list.empty());
// }


// // SIZE TESTS
// TEST(check_size1) { // simple case
//     // empty list
//     List<int> list;
//     // add 1,2,3,4 into list
//     for (int i = 0; i < 5; ++i) {
//         list.push_back(i);
//     }
//     ASSERT_TRUE(list.size() == 4);
// }

// TEST(check_size2) { // case where elements all are deleted from back
//     // empty list
//     List<int> list;
//     // add 1,2,3,4 into list
//     for (int i = 0; i < 5; ++i) {
//         list.push_back(i);
//     }
//     // delete 1,2,3,4 from list
//     for (int i = 0; i < 5; ++i) {
//         list.pop_front();
//     }
//     ASSERT_TRUE(list.size() == 0);
// }

// TEST(check_size3) { // progressive check as nodes added 
//     // empty list
//     List<int> list;
//     // add 1,2,3,4 into list
//     for (int i = 0; i < 5; ++i) {
//         list.push_back(i);
//         ASSERT_TRUE(list.size() == i);
//     }
// }

// TEST(check_size4) { // progressive check as nodes deleted 
//     // empty list
//     List<int> list;
//     // add 1,2,3,4 into list
//     for (int i = 0; i < 5; ++i) {
//         list.push_back(i);
//     }
//     // delete 1,2,3,4 from list
//     for (int i = 0; i < 5; ++i) {
//         list.pop_front();
//         ASSERT_TRUE(list.size() == i);
//     }
// }



// // NEED FIX

// // TEST FRONT
// TEST(check_front1) { // simple int list case
//     // empty list
//     List<int> list;
//     // add 1,2,3,4 into list
//     for (int i = 0; i < 5; ++i) {
//         list.push_back(i);
//     }
//     ASSERT_TRUE(list.front() == 1);
// }

// TEST(check_front2) { // simple char list case
//     // empty list
//     List<char> list;
//     // add 1,2,3,4 into list
//     for (char i = 'a'; i < 'e'; ++i) {
//         list.push_back(i);
//     }
//     ASSERT_TRUE(list.front() == 'a');
// }

// TEST(check_front3) { // progressive check case with pop front
//     // empty list
//     List<char> list;
//     // add 1,2,3,4 into list
//     for (char i = 'a'; i < 'e'; ++i) {
//         list.push_back(i);
//     }
//     // delete 1,2,3,4 from list
//     for (char i = 'a'; i < 'e'; ++i) {
//         list.pop_front();
//         ASSERT_TRUE(list.front() == 'a' + i);
//     }
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

// // TEST BACK -- recheck logic later its 3am
// TEST(check_back1) { // simple int list case
//     // empty list
//     List<int> list;
//     // add 1,2,3,4 into list
//     for (int i = 0; i < 5; ++i) {
//         list.push_back(i);
//         cout << i;
//     }

//     ASSERT_TRUE(list.back() == 4);
// }

// TEST(check_back2) { // simple char list case
//     // empty list
//     List<char> list;
//     // add 1,2,3,4 into list
//     for (char i = 'a'; i < 'e'; ++i) {
//         list.push_back(i);
//     }
//     ASSERT_TRUE(list.back() == 'd');
// }

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

// TEST(check_back4) { // progressive check case with push front
//     // empty list
//     List<char> list;
//     // add 1,2,3,4 into list
//     for (char i = 'a'; i < 'e'; ++i) {
//         list.push_back(i);
//     }
//     // delete 1,2,3,4 from list
//     for (char i = 'e'; i >= 'a'; --i) {
//         list.push_back(i);
//         ASSERT_TRUE(list.front() == 'a' + i);
//     }  
// }  

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



// TEST(check_begin1) {
//     List<int> list;
//     // fills in the list with 1, 2, 3, 4
//     for (int i = 0; i < 5; ++i) {
//         list.push_back(i);
//     }
//     // makes an iterator pointing at the first node of the list
//     List<int>::Iterator it = list.begin();
//     ASSERT_EQUAL(*it, 1); // it dereferenced should give first element
// }

// TEST(check_begin2) {
//     // empty list
//     List<int> list;
//     // makes an iterator pointing to the beginning of the list
//     // List<int>::Iterator it = list.begin();
//     // it should be pointing to a nullptr
//     // ASSERT_FALSE(it);
// }

TEST(check_pop_front1) { // simple case with one node deleted
    List<int> list;
    // fills in the list with 1, 2, 3, 4
    list.push_back(1);
    ASSERT_EQUAL(list.size(), 1);
    list.pop_front(); 
    ASSERT_TRUE(list.empty());
}

TEST(check_pop_front2) { // simple case with all nodes deleted
    List<int> list;
    // adds 1,2,3,4
    for (int i = 0; i < 5; ++i) {
        list.push_back(i);
    }
    // pops front elements 1 thru 4
    for (int i = 0; i < 5; ++i) {
        list.pop_front();
    }
    ASSERT_EQUAL(list.size(), 0);
}

TEST(check_pop_front3) { // checks that first node specifically is deleted
    List<int> list;
    // adds 1,2,3,4
    for (int i = 0; i < 5; ++i) {
        list.push_back(i); 
    } 
    // pops front element '1'
    list.pop_front(); 
    // new first->datum should be 2 bc 1 was 'popped' from front
    ASSERT_EQUAL(list.front(), 2); 
}

TEST(check_pop_back1) {
    List<int> list;
    // fills in the list with 1, 2, 3, 4
    list.push_back(1);
    ASSERT_EQUAL(list.size(), 1);
    list.pop_back(); 
    ASSERT_TRUE(list.empty());
}

TEST(check_pop_back2) {
    List<char> list;
    // adds 1,2,3,4 to list
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
    // adds 1,2,3,4
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
    // add 1,2,3,4 into list
    for (int i = 0; i < 5; ++i) {
        list.push_front(i);
    }
    ASSERT_TRUE(!list.empty());
}

TEST(check_push_front2) { // simple push front datum check
    // empty list
    List<int> list;
    // add 1,2,3,4 into list so it's {4,3,2,1}
    for (int i = 0; i < 5; ++i) {
        list.push_front(i);
    }
    ASSERT_TRUE(list.front() == 4);
}
// TEST PUSH BACK
// TEST POP FRONT
// TEST POP BACK
// TEST CLEAR



TEST_MAIN();
