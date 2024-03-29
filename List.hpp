#ifndef LIST_HPP
#define LIST_HPP
/* List.hpp
 *
 * doubly-linked, double-ended list with Iterator interface
 * EECS 280 Project 4
 */

#include <iostream>
#include <iterator> //std::bidirectional_iterator_tag
#include <cassert>  //assert


template <typename T>
class List {
  //OVERVIEW: a doubly-linked, double-ended list with Iterator interface
public:

  //EFFECTS:  returns true if the list is empty
  bool empty() const {
    return first == nullptr;
  }

  //EFFECTS: returns the number of elements in this List
  //HINT:    Traversing a list is really slow. Instead, keep track of the size
  //         with a private member variable. That's how std::list does it.
  int size() const {
    return _size;
  }

  //REQUIRES: list is not empty
  //EFFECTS: Returns the first element in the list by reference
  T & front() {
    assert (!empty());
		return first->datum;
  }

  //REQUIRES: list is not empty
  //EFFECTS: Returns the last element in the list by reference
  T & back() {
    assert (!empty());
    return last->datum;
  }



  //POTENTIAL ISSUE: HOW ARE WE MAKING SURE THAT
    // THIS IS GETTING DELETED OFF THE DYNAM MEM?????
    // ^^^^^
  //EFFECTS:  inserts datum into the front of the list
  void push_front(const T &datum) {
    // note: doesnt matter if the list is empty, this logic would still work
    // make new node
      // next and prev initialized to default 0
    Node *p = new Node;
    // give new node passed datum value
    p->datum = datum;
    // assign new node ptr to current first node
    p->next = first;
    // assign current first node prev ptr to new node
    first->prev = p;
    // reassign first to new node (that is pushed front)
    first = p;
    // increment size
    ++_size; 
  }

  //EFFECTS:  inserts datum into the back of the list
  void push_back(const T &datum) {
    Node *p = new Node;
    p->datum = datum;
    p->next = nullptr;
    delete last;
    last->next = p;
    if (empty()) {
      first = last = p;
      p->prev = p->next = nullptr;
    }
    else {
      p->prev = last;
      last->next = p;
      last = p;
    }
    ++_size;
  }

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the front of the list
  void pop_front() {
    Node *to_delete = first;
    first = first->next;
    delete to_delete;
    
    //copy from push front
    // make new node
      // next and prev initialized to default 0
    Node *p = new Node;
    // assign new node ptr to current first node
    p->next = first;
    // assign current first node prev ptr to new node
    first->prev = p;
    // reassign first to new node (that is pushed front)
    first = p;
    // give new node passed datum value
    p->datum = datum;
    // increment size
    ++_size; 
  }

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the back of the list
  void pop_back() {
    assert(!empty());
    // aux ptr
    Node *aux_ptr = new Node;
    // save address of last node to aux ptr
    aux_ptr = last;
    // save prev ptr of current last node to last ptr in list
    last = last->prev;
    // delete old last node through aux node ptr
    delete aux_ptr;
    // make next of updated last node = 0 (null ptr)
    last->next = nullptr; 
    // decrease size
    --_size;
  }

  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes all items from the list
  void clear() {
    while (!empty()) {
      pop_front();
    }
  }

  // You should add in a default constructor, destructor, copy constructor,
  // and overloaded assignment operator, if appropriate. If these operations
  // will work correctly without defining these, you should omit them. A user
  // of the class must be able to create, copy, assign, and destroy Lists.

// DEFAULT LIST CONSTRUCTOR
  List()
   : first(nullptr), last(nullptr) { }

// COPY LIST CONSTRUCTOR
  List(const List &other) {
    copy_all();
  }

// LIST DESTRUCTOR
  ~List() {
    clear();
  }


private:
  //a private type
  struct Node {
    Node *next;
    Node *prev;
    T datum;
  };

  //REQUIRES: list is empty
  //EFFECTS:  copies all nodes from other to this
  void copy_all(const List<T> &other) {
    for (Node *np = other.first; np; np = np->next) {
      push_back(np->datum);
    }
  }

  Node *first;   // points to first Node in list, or nullptr if list is empty
  Node *last;    // points to last Node in list, or nullptr if list is empty
  size_t _size;

public:
  ////////////////////////////////////////
  class Iterator {
    friend class List;
  public:
    //OVERVIEW: Iterator interface to List

    // Add a default constructor here. The default constructor must set both
    // pointer members to null pointers.
    Iterator()
      : node_ptr(nullptr), list_ptr(nullptr) { }

    // Your iterator should implement the following public operators:
    // *, ++ (both prefix and postfix), == and !=.
    // Equality comparisons must satisfy the following rules:
    // - two default-constructed iterators must compare equal
    // - a default-constructed iterator must compare unequal to an
    //   iterator obtained from a list, even if it is the end iterator
    // - two iterators to the same location in the same list must
    //   compare equal
    // - two iterators to different locations in the same list must
    //   compare unequal
    // - comparipng iterators obtained from different lists results in
    //   undefined behavior
    //   - Your implementation can handle this however you like, but
    //     don't assume any particular behavior in your test cases --
    //     comparing iterators from different lists essentially
    //     violates the REQURES clause.
    // Note: comparing both the list and node pointers should be
    // sufficient to meet these requirements.
    T& operator*() const {
      assert(node_ptr);
      return node_ptr->datum;
    }

    Iterator& operator++() { // prefix ++ (e.g. ++it)
      assert(list_ptr);
      if (node_ptr) {
        node_ptr = node_ptr->next;
      } else { // decrementing an end Iterator moves it to the last element
        node_ptr = list_ptr->first;
      }
      return *this;
    }

    Iterator operator++(int /*postfix*/) {
      Iterator copy = *this;
      operator++();
      return copy;
    }
    
    // two default-constructed iterators must compare equal 
    // a default-constructed iterator must compare unequal to an
      //   iterator obtained from a list, even if it is the end iterator
    // comparing iterators obtained from different lists results in
      //   undefined behavior
    bool operator==(const Iterator& other) const {
    // - comparing iterators obtained from different lists results in
    //   undefined behavior
      assert(this->list_ptr == other.list_ptr);
      // using *this means that *this actually has the same object type
      // as the class in which the operator overloading is implemented

    // - two default-constructed iterators must compare equal
    // - a default-constructed iterator must compare unequal to an
    //   iterator obtained from a list, even if it is the end iterator 
      if (!this->list_ptr && !other.list_ptr) {
        return true;
      }

    // - two iterators to the same location in the same list must
    //   compare equal
      if (this->node_ptr == other.node_ptr) {
        return true;
      }

    // - two iterators to different locations in the same list must
    //   compare unequal
      return false; // can just use else { } ???
    }

    bool operator!=(const Iterator& other) const { // reference to "other"
      return !(*this == other);
    }

    // Type aliases required to work with STL algorithms. Do not modify these.
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;

    // This operator will be used to test your code. Do not modify it.
    // REQUIRES: Iterator is either dereferenceable or an end Iterator
    // EFFECTS:  moves this Iterator to point to the previous element
    //           and returns a reference to this Iterator
    Iterator& operator--() { // prefix -- (e.g. --it)
      assert(list_ptr);
      if (node_ptr) {
        node_ptr = node_ptr->prev;
      } else { // decrementing an end Iterator moves it to the last element
        node_ptr = list_ptr->last;
      }
      return *this;
    }

    // This operator will be used to test your code. Do not modify it.
    // REQUIRES: Iterator is either dereferenceable or an end Iterator
    // EFFECTS:  moves this Iterator to point to the previous element
    //           and returns a copy of the original Iterator
    Iterator operator--(int /*dummy*/) { // postfix -- (e.g. it--)
      Iterator copy = *this;
      operator--();
      return copy;
    }

    // REQUIRES: Iterator is dereferenceable
    // EFFECTS: returns the underlying element by pointer
    // NOTE: T must be a class type to use the syntax it->. If T has a
    //       member variable f, then it->f accesses f on the
    //       underlying T element.
    T* operator->() const {
      return &operator*();
    }

  private:
    const List *list_ptr; //pointer to the List associated with this Iterator
    Node *node_ptr; //current Iterator position is a List node
    // add any additional necessary member variables here


    // add any friend declarations here


    // construct an Iterator at a specific position in the given List
    Iterator(const List *lp, Node *np)
      : list_ptr(lp), node_ptr(np) { }

  };//List::Iterator
  ////////////////////////////////////////

  // return an Iterator pointing to the first element
  Iterator begin() const {
    return Iterator(this, first);
  }

  // return an Iterator pointing to "past the end"
  Iterator end() const {
    return Iterator(this, last);
  }


  //REQUIRES: i is a valid, dereferenceable iterator associated with this list
  //MODIFIES: may invalidate other list iterators
  //EFFECTS: Removes a single element from the list container.
  //         Returns An iterator pointing to the element that followed the
  //         element erased by the function call
  Iterator erase(Iterator i) {  
    // assert that i current node ptr is dereferenceable 
      // aka not null ptr
    assert(i->node_ptr != nullptr); // if it's empty nothing can be erased

    // make new node ptr                      
    Node *p = new Node;
    
    Iterator it;
    return it;
  }

  //REQUIRES: i is a valid iterator associated with this list
  //EFFECTS: Inserts datum before the element at the specified position.
  //         Returns an iterator to the the newly inserted element.
  Iterator insert(Iterator i, const T &datum) {
    assert(false);
    Iterator it;
    return it;
  }

};//List


////////////////////////////////////////////////////////////////////////////////
// Add your member function implementations below or in the class above
// (your choice). Do not change the public interface of List, although you
// may add the Big Three if needed.  Do add the public member functions for
// Iterator.


#endif // Do not remove this. Write all your code above this line.
