#ifndef LIST_H
#define LIST_H
/* List.h
 *
 * doubly-linked, double-ended list with Iterator interface
 * Project UID c1f28c309e55405daf00c565d57ff9ad
 * EECS 280 Project 4
 */

#include <iostream>
#include <cassert> //assert
#include <cstddef> //NULL


template <typename T>
class List {
  //OVERVIEW: a doubly-linked, double-ended list with Iterator interface
public:

    //Default Constructor
	List() : first(nullptr), last(nullptr) {}
    
    //Destructor
    ~List()
    {
        pop_all();
    }
    
    // Copy Constructor
    List(const List &other)
    : first(nullptr), last(nullptr)
    {
        copy_all(other);
    }
    
    // Assignment Operator
    List & operator= (const List &rhs)
    {
        if(this == &rhs)
        {
            return *this;
        }
        pop_all();
        copy_all(rhs);
        return *this;
    }


    //EFFECTS:  returns true if the list is empty
	bool empty() const {
		//checks if the first and last element point to a null pointer
		return first == nullptr && last == nullptr;
    }

    //EFFECTS: returns the number of elements in this List
	int size() const {
		//counts each node in the list, setting the next
        //node to the current node if it does not equal
		//a null pointer
		int count = 0;
		Node *current = first;
		while (current != nullptr) {
			current = current->next;
			count++;
		}
		return count;
    }

    //REQUIRES: list is not empty
    //EFFECTS: Returns the first element in the list by reference
	T & front() {
		//assert the requires and returns the first element
		assert(!empty());
		return first->datum;
    }

    //REQUIRES: list is not empty
    //EFFECTS: Returns the last element in the list by reference
	T & back() {
		//assert the requires and return the last element
		assert(!empty());
		return last->datum;
    }

    //EFFECTS:  inserts datum into the front of the list
	void push_front(const T &datum) {
		Node *newNode = new Node;
		newNode->datum = datum;
		newNode->prev = nullptr;
		newNode->next = first;
        
        if(empty())
        {
            first = newNode;
            last = newNode;
        }
        else
        {
            first->prev = newNode;
            first = newNode;
        }
    }

    //EFFECTS:  inserts datum into the back of the list
	void push_back(const T &datum) {
		Node *newNode = new Node;
		newNode->datum = datum;
		newNode->prev = last;
		newNode->next = nullptr;

        if(empty())
        {
            first = newNode;
            last = newNode;
        }
        else
        {
            last->next = newNode;
            last = newNode;
        }
    }

    //REQUIRES: list is not empty
    //MODIFIES: may invalidate list iterators
    //EFFECTS:  removes the item at the front of the list
	void pop_front() {
		//asserts requires, sets first item to be deleted to
        //temporary Node, sets new first then deletes old first
		assert(!empty());
		Node *victim = first;
        
        if(size() == 1)
        {
            first = nullptr;
            last = nullptr;
        }
        else
        {
            first->next->prev = nullptr;
            first = first->next;
        }
        //May not need
        victim->next = nullptr;
        victim->prev = nullptr;
        
		delete victim;
    }

    //REQUIRES: list is not empty
    //MODIFIES: may invalidate list iterators
    //EFFECTS:  removes the item at the back of the list
	void pop_back() {
		assert(!empty());
		Node *victim = last;
        if(size() == 1)
        {
            first = nullptr;
            last = nullptr;
        }
        else
        {
            last->prev->next = nullptr;
            last = last->prev;
        }
        //May not need
        victim->next = nullptr;
        victim->prev = nullptr;
        
		delete victim;
    }

    // You should add in a default constructor, destructor, copy constructor,
    // and overloaded assignment operator, if appropriate. If these operations
    // will work correctly without defining these, you can omit them. A user
    // of the class must be able to create, copy, assign, and destroy Lists

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
        //Creates a transfer node to store the current node so
        //that it doesn't get lost when the current
        //this is updated. Then copies the current other to the
        //current this andn increments the current this and other
        
        for(Node* ptr = other.first; ptr; ptr = ptr->next)
        {
            push_back(ptr->datum);
        }
    }

  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes all nodes
  void pop_all() {
	  //sets current node to the victim, then increments
      //the current node and deletes the victim
      
    while(!empty())
    {
        pop_back();
    }
  }

  Node *first;   // points to first Node in list, or nullptr if list is empty
  Node *last;    // points to last Node in list, or nullptr if list is empty

public:
  ////////////////////////////////////////
  class Iterator {
    //OVERVIEW: Iterator interface to List

    // You should add in a default constructor, destructor, copy constructor,
    // and overloaded assignment operator, if appropriate. If these operations
    // will work correctly without defining these, you can omit them. A user
    // of the class must be able to create, copy, assign, and destroy Iterators.

    // Your iterator should implement the following public operators: *,
    // ++ (prefix), default constructor, == and !=.
	 // friend class List;
  public:
      
      Iterator()
      : node_ptr(nullptr) {}
      
    // This operator will be used to test your code. Do not modify it.
    // Requires that the current element is dereferenceable.
    Iterator& operator--() {
      assert(node_ptr);
      node_ptr = node_ptr->prev;
      return *this;
    }

	Iterator& operator++() {
		assert(node_ptr);
		node_ptr = node_ptr->next;
		return *this;
	}
      
    T & operator* () {
        assert(node_ptr);
        return this->node_ptr->datum;
    }
      
	//Possibly don't need const or & before Iterator. See Lecture 18
	bool operator==(const Iterator& rhs) const {
		if (node_ptr == rhs.node_ptr) {
			return true;
		}
		return false;
	}
	//Possibly don't need const or & before Iterator. See Lecture 18
	bool operator!=(const Iterator& rhs) const {
		if (node_ptr != rhs.node_ptr) {
			return true;
		}
		return false;
	}

  private:
    Node *node_ptr; //current Iterator position is a List node
    // add any additional necessary member variables here

    // add any friend declarations here
      friend class List;
      
    // construct an Iterator at a specific position
    Iterator(Node *p)
      : node_ptr(p) {}

  };//List::Iterator
  ////////////////////////////////////////

  // return an Iterator pointing to the first element
  Iterator begin() const {
    return Iterator(first);
  }

  // return an Iterator pointing to "past the end"
  Iterator end() const {
	  return Iterator(nullptr);
  }

  //REQUIRES: i is a valid, dereferenceable iterator associated with this list
  //MODIFIES: may invalidate other list iterators
  //EFFECTS: Removes a single element from the list container
  void erase(Iterator i) {
	  assert(i.node_ptr);
	  if (i.node_ptr == first) {
		  pop_front();
		  return;
	  }
	  if (i.node_ptr == last) {
		  pop_back();
		  return;
	  }
	  (i.node_ptr->prev)->next = (i.node_ptr->next);
	  (i.node_ptr->next)->prev = (i.node_ptr->prev);
	  delete i.node_ptr;
  }

  //REQUIRES: i is a valid iterator associated with this list
  //EFFECTS: inserts datum before the element at the specified position.
  void insert(Iterator i, const T &datum) {
      if(i.node_ptr == nullptr)
      {
          push_front(datum);
          return;
      }
	  if (i.node_ptr->prev == nullptr) {
		  push_front(datum);
		  return;
	  }
	  Node *new_node = new Node;
      new_node->next = i.node_ptr;
      new_node->prev = i.node_ptr->prev;
	  (new_node->prev)->next = new_node;
	  (new_node->next)->prev = new_node;
	  new_node->datum = datum;
      
  }

};//List


////////////////////////////////////////////////////////////////////////////////
// Add your member function implementations below or in the class above
// (your choice). Do not change the public interface of List, although you
// may add the Big Three if needed.  Do add the public member functions for
// Iterator.



#endif // Do not remove this. Write all your code above this line.
