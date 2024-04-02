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
    return (first == nullptr && last == nullptr);
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

  //EFFECTS:  inserts datum into the front of the list
  void push_front(const T &datum) {
    // next and prev initialized to default 0
    Node *p = new Node;
    // give new node passed datum value
    p->datum = datum;
    p->next = nullptr;
    p->prev = nullptr;
    if (empty()) {
      first = last = p;
    }
    else if (size() == 1) {
      first = p;
      last->prev = p;
      p->next = last;
    }
    else {
      p->next = first;
      first->prev = p;
      first = p;
    }
    // // increment size
    ++_size; 
  }

  //EFFECTS:  inserts datum into the back of the list
  void push_back(const T &datum) {
    Node *p = new Node;
    p->datum = datum;
    p->next = nullptr;
    p->prev = nullptr;
    // if new list - use if statement here
    // pop front vs pop back - only 1 thing - what happens?
      // reset last & first to null

    // segfault happens when accessing nullptr
    // should work on an empty list
    if (empty()) {
      first = last = p;
    }
    else if (size() == 1) {
      last = p;
      first->next = p;
      p->prev = first;
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
    assert(!empty());
    Node *aux = first;
    if (size() != 1) {
      first = first->next;
      first->prev = nullptr;
    }
    else {
      first = nullptr;
      last = nullptr;
    }
    delete aux;
    // Decrement the size of the list
    --_size;

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
    if (size() != 1) {
      // save prev ptr of current last node to last ptr in list
      last = last->prev;
      // make next of updated last node = 0 (null ptr)
      last->next = nullptr; 
    }
    else {
      first = nullptr;
      last = nullptr;
    }
    // delete old last node through aux node ptr
    delete aux_ptr;
    // decrease size
    --_size;
  }

  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes all items from the list
  void clear() {
    while (!empty()) {
      pop_front();
      // do we need to assign null values to first and last in list?
    }
    _size = 0;
  }

  // You should add in a default constructor, destructor, copy constructor,
  // and overloaded assignment operator, if appropriate. If these operations
  // will work correctly without defining these, you should omit them. A user
  // of the class must be able to create, copy, assign, and destroy Lists.

// DEFAULT LIST CONSTRUCTOR
  List()
   : first(nullptr), last(nullptr), _size(0) { }

// COPY LIST CONSTRUCTOR
  List(const List &other)
   : first(nullptr), last(nullptr), _size(0) {
    copy_all(other);
  }

// LIST DESTRUCTOR
  ~List() {
    clear();
  }

// OVERLOADED ASSIGNMENT OPERATOR
  List& operator=(const List &rhs) {
    if (this == &rhs) { return *this; }
    clear();
    copy_all(rhs);
    return *this;
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
      : list_ptr(nullptr), node_ptr(nullptr) { }

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

    // returns a dereferenced iterator - which is just the actual datum that
      // the iterator is pointing to
      // e.g. 'r' in 'rat'
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
    return Iterator(this, nullptr);
  }


  //REQUIRES: i is a valid, dereferenceable iterator associated with this list
  //MODIFIES: may invalidate other list iterators
  //EFFECTS: Removes a single element from the list container.
  //         Returns An iterator pointing to the element that followed the
  //         element erased by the function call
  Iterator erase(Iterator i) {
    assert(i.node_ptr != nullptr);
    // i->node_ptr dereferences node_ptr into its T object type

    // for when the cursor is in the middle of the list
      // if next and prev are not null ptrs - not first or last
    if (i.node_ptr->next && i.node_ptr->prev) {
      // nte = node to erase
      // next pointer of prev node to nte repointed to node after nte
      i.node_ptr->prev->next = i.node_ptr->next;
      // prev pointer of next node to nte repointed to node before nte
      i.node_ptr->next->prev = i.node_ptr->prev;

      // pointer to nte
      Node *to_erase = i.node_ptr;
      // i is now node following nte
      i.node_ptr = i.node_ptr->next;
      // erase nte
      delete to_erase;
    }
    // for when the cursor is at the end of the list 
      // if next is not null ptr - not last
    else if (!i.node_ptr->next) {
      // remove last element in list
      pop_back();
      // i points to last
      i.node_ptr = last;
    }
    // for when the cursor is at the beginning of the list
      // if prev is not null ptr - not first
    else if (!i.node_ptr->prev) {
      // remove first element in list
      pop_front();
      // i points to first
      i.node_ptr = first;
    }
    return i;
  }

  //REQUIRES: i is a valid iterator associated with this list
  //EFFECTS: Inserts datum before the element at the specified position.
  //         Returns an iterator to the the newly inserted element.
  Iterator insert(Iterator i, const T &datum) {
    assert(i.list_ptr == this);

    // make new node ptr and attaches to the node pointer to by i
    Node *p = new Node;
    p->datum = datum;
    p->next = p->prev = nullptr;
    // Iterator copy = Iterator(this, p);
    
    if (!i.node_ptr) { // when empty OR past the end
      if (empty()) {
        first = last = p;
      }
      else {
        last->next = p;
        p->prev = last;
        last =  p;
      }
    }
    else { // insert BEFORE the position of i
      if (!i.node_ptr->prev) { // if iterator is at beginning of list
        // sets first element to new node
        first = p;
      }
      else {
        // sets the previous element's "next" to the new node
        i.node_ptr->prev->next = p;
      }
      // sets previous node of new to previous node of current position
      p->prev = i.node_ptr->prev;
      // sets next node of new to the current position node
      p->next = i.node_ptr;
      // sets current node's previous to new node
      i.node_ptr->prev = p;
    }
    ++_size;
    return Iterator(this, p);

    // if (!i.node_ptr) { // when empty OR past the end
    //   if (empty()) { // empty list means first and last are nullptrs
    //     first = last = p;
    //   }
    //   else { // for when i is in the back of a list
    //     first->prev = p;
    //     p->next = p;
        
    //   }
    // }
  }

    // p->next = i.node_ptr;
    // stores a copy of original iterator i into aux

    // // for when cursor is in the middle of the list
    // if (!i.node_ptr || !i.node_ptr->prev) {
    //   // p would be the first element
    //   push_front(datum);
    //   i.node_ptr = first;
    // }
    // else if (!i.node_ptr->next) {
    //   push_back(datum);
    //   i.node_ptr = last;
    // }
    // else if (i.node_ptr->prev && i.node_ptr->next) {
    //   // aux is now at node_ptr->prev (og position - 1)
    //   aux--;
    //   // assigns the next ptr of the element before insertion to p
    //   i.node_ptr->prev = p;
    //   // assigns the prev ptr of inserted element p to the element before insertion
    //   p->prev = aux.node_ptr;
    //   // assigns the og node's prev ptr to inserted element p 
    //   aux.node_ptr->next = p;
    // }
    // i.node_ptr = p;
    // return i;

  //       // for when cursor is in the middle of the list
  //   if (!i.node_ptr || !i.node_ptr->prev) {
  //     // p would be the first element
  //     push_front(datum);
  //   }
  //   else if (!i.node_ptr->next) {
  //     push_back(datum);
  //   }
  //   else if (i.node_ptr->prev && i.node_ptr->next) {
  //     i.node_ptr->prev = p;
  //     p->next = i.node_ptr;
  //     i--;
  //     // i is now at node_ptr->prev (og position - 1)
  //     i.node_ptr->next = p;
  //     p->prev = i.node_ptr;
  //   }
  //   return aux;
  // }

};//List


////////////////////////////////////////////////////////////////////////////////
// Add your member function implementations below or in the class above
// (your choice). Do not change the public interface of List, although you
// may add the Big Three if needed.  Do add the public member functions for
// Iterator.


#endif // Do not remove this. Write all your code above this line.
