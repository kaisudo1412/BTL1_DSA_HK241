/*
 * File:   DLinkedList.h
 */

#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

#include <iostream>
#include <sstream>
#include <type_traits>

#include "list/IList.h"
using namespace std;

template <class T>
class DLinkedList : public IList<T> {
 public:
  class Node;         // Forward declaration
  class Iterator;     // Forward declaration
  class BWDIterator;  // Forward declaration

 protected:
  Node *head;
  Node *tail;
  int count;
  bool (*itemEqual)(T &lhs, T &rhs);
  void (*deleteUserData)(DLinkedList<T> *);

 public:
  DLinkedList(void (*deleteUserData)(DLinkedList<T> *) = 0,
              bool (*itemEqual)(T &, T &) = 0);
  DLinkedList(const DLinkedList<T> &list);
  DLinkedList<T> &operator=(const DLinkedList<T> &list);
  ~DLinkedList();

  // Inherit from IList: BEGIN
  void add(T e);
  void add(int index, T e);
  T removeAt(int index);
  bool removeItem(T item, void (*removeItemData)(T) = 0);
  bool empty();
  int size();
  void clear();
  T &get(int index);
  int indexOf(T item);
  bool contains(T item);
  string toString(string (*item2str)(T &) = 0);
  // Inherit from IList: END

  void println(string (*item2str)(T &) = 0) {
    cout << toString(item2str) << endl;
  }
  void setDeleteUserDataPtr(void (*deleteUserData)(DLinkedList<T> *) = 0) {
    this->deleteUserData = deleteUserData;
  }

  bool contains(T array[], int size) {
    int idx = 0;
    for (DLinkedList<T>::Iterator it = begin(); it != end(); it++) {
      if (!equals(*it, array[idx++], this->itemEqual)) return false;
    }
    return true;
  }

  Iterator begin() { return Iterator(this, true); }
  Iterator end() { return Iterator(this, false); }

  BWDIterator bbegin() { return BWDIterator(this, true); }
  BWDIterator bend() { return BWDIterator(this, false); }

 protected:
  void copyFrom(const DLinkedList<T> &list);
  void removeInternalData();
  Node *getPreviousNodeOf(int index);

  //! FUNTION STATIC
 public:
  static void free(DLinkedList<T> *list) {
    typename DLinkedList<T>::Iterator it = list->begin();
    while (it != list->end()) {
      delete *it;
      it++;
    }
  }

 protected:
  static bool equals(T &lhs, T &rhs, bool (*itemEqual)(T &, T &)) {
    if (itemEqual == 0)
      return lhs == rhs;
    else
      return itemEqual(lhs, rhs);
  }

 public:
  class Node {
   public:
    T data;
    Node *next;
    Node *prev;
    friend class DLinkedList<T>;

   public:
    Node(Node *next = 0, Node *prev = 0) {
      this->next = next;
      this->prev = prev;
    }
    Node(T data, Node *next = 0, Node *prev = 0) {
      this->data = data;
      this->next = next;
      this->prev = prev;
    }
  };

 public:
  class Iterator {
   private:
    DLinkedList<T> *pList;
    Node *pNode;

   public:
    Iterator(DLinkedList<T> *pList = 0, bool begin = true) {
      if (begin) {
        if (pList != 0)
          this->pNode = pList->head->next;
        else
          pNode = 0;
      } else {
        if (pList != 0)
          this->pNode = pList->tail;
        else
          pNode = 0;
      }
      this->pList = pList;
    }

    Iterator &operator=(const Iterator &iterator) {
      this->pNode = iterator.pNode;
      this->pList = iterator.pList;
      return *this;
    }
    void remove(void (*removeItemData)(T) = 0) {
      pNode->prev->next = pNode->next;
      pNode->next->prev = pNode->prev;
      Node *pNext = pNode->prev;  // MUST prev, so iterator++ will go to end
      if (removeItemData != 0) removeItemData(pNode->data);
      delete pNode;
      pNode = pNext;
      pList->count -= 1;
    }

    T &operator*() { return pNode->data; }
    bool operator!=(const Iterator &iterator) {
      return pNode != iterator.pNode;
    }
    // Prefix ++ overload
    Iterator &operator++() {
      pNode = pNode->next;
      return *this;
    }
    // Postfix ++ overload
    Iterator operator++(int) {
      Iterator iterator = *this;
      ++*this;
      return iterator;
    }
  };

  class BWDIterator { 
    // TODO implement
    private:
      Node* curentNode;
      DLinkedList<T> *pList;
    public:
      BWDIterator(DLinkedList<T> *pList =0, bool begin = true){
        if (begin) {
          if (pList != 0)
            this->curentNode = pList->tail->prev;
          else
            curentNode = 0;
        } else {
          if (pList != 0)
            this->curentNode = pList->head;
          else
            curentNode = 0;
        }
        this->pList = pList;
      }

      BWDIterator &operator=(const BWDIterator &iterator){
        this->curentNode = iterator.curentNode;
        this->pList = iterator.pList;
        return *this;
      }

      void remove(void (*removeItemData)(T) = 0) {
        curentNode->prev->next = curentNode->next;
        curentNode->next->prev = curentNode->prev;
        Node *pNext = curentNode->next;  // MUST prev, so iterator++ will go to end
        if (removeItemData != 0) removeItemData(curentNode->data);
        delete curentNode;
        curentNode = pNext;
        pList->count -= 1;
      }

      T &operator*(){
        return this->curentNode->data;
      }

      bool operator !=(const BWDIterator &iterator){
        return curentNode != iterator.curentNode;
      }

      BWDIterator &operator ++(){
        if(curentNode != NULL) this->curentNode = curentNode->prev;
        return *this;
      }

      BWDIterator operator ++(int){
        BWDIterator iterator = *this;
        ++*this;
        return iterator;
    };
  };
};

template <class T>
using List = DLinkedList<T>;

//! ////////////////////////////////////////////////////////////////////
//! //////////////////////     METHOD DEFNITION      ///////////////////
//! ////////////////////////////////////////////////////////////////////

template <class T>
DLinkedList<T>::DLinkedList(void (*deleteUserData)(DLinkedList<T> *),
                            bool (*itemEqual)(T &, T &)) {
  // TODO implement
  this->deleteUserData = deleteUserData;
  this->itemEqual = itemEqual;
  this->head = new Node();
  this->tail = new Node();
  head->next = tail;
  tail->prev = head;
  count = 0;
}

template <class T>
DLinkedList<T>::DLinkedList(const DLinkedList<T> &list) {
  // TODO implement
  
    this->head = new Node();
    this->tail = new Node();
    this->head->next = tail;
    this->tail->prev = head;
    this->count = 0;
    this->itemEqual = list.itemEqual;
    this->deleteUserData = list.deleteUserData;

  Node* tmp = list.head->next;
  for(int i = 0; i<list.count; i++){
     this->add(tmp->data);
     tmp = tmp->next;
  }
}

template <class T>
DLinkedList<T> &DLinkedList<T>::operator=(const DLinkedList<T> &list) {
  // TODO implement
  this->copyFrom(list);
  return *this;
}

template <class T>
DLinkedList<T>::~DLinkedList() {
  // TODO implement
  if(deleteUserData != NULL) deleteUserData(this);
    while (head) 
      {
          Node * tmp = head;
          head = head->next;
          delete tmp;
      }
      head = NULL;
      tail = NULL;
      count = 0;
      deleteUserData = NULL;
      itemEqual = NULL;
}

template <class T>
void DLinkedList<T>::add(T e) {
  // TODO implement
  Node* tmp = new Node(e);
  if(count == 0){
     tail->prev = tmp;
     head->next = tmp;
     tmp->prev = head;
     tmp->next = tail;
  }
  else{
    tmp->next = tail;
    tmp->prev = tail->prev;
    tmp->prev->next = tmp;
    tail->prev = tmp;
  }
   count++;
}
template <class T>
void DLinkedList<T>::add(int index, T e) {
  // TODO implement
  if(index < 0 || index > count) throw std :: out_of_range("Index is out of range!");

  if(count == 0 || index == count) {
    this->add(e);
    return;
  }

  if(index == 0){
    Node* newtmp = new Node(e);
    newtmp->next = head->next;
    newtmp->prev = head;
    head->next->prev = newtmp;
    head->next = newtmp;
  }

  else{
      Node* newtmp = new Node(e);
      Node* tmp = head->next;
      for(int i = 0; i < index; i++){
        tmp = tmp->next;
      }
      newtmp->next = tmp;
      newtmp->prev = tmp->prev;
      tmp->prev->next = newtmp;
      tmp->prev = newtmp;
  }
  count++;
}

template <class T>
T DLinkedList<T>::removeAt(int index) {
  // TODO implement
  if(index < 0 || index >= count) throw std :: out_of_range("Index is out of range!");
  Node*tmp = this->head->next;

  if(index == 0){
    head->next = tmp->next;
    if(count == 1)  tail->prev = head;
    
    T Dataremoved = tmp->data;
    delete tmp;
    count --;
    return Dataremoved;
  }

  for(int i =0 ; i<index ; i++){
    tmp = tmp->next;
  }

  Node* previous = tmp->prev;
  Node* nextNode = tmp->next;
  previous->next = nextNode;

  if(nextNode) nextNode->prev = previous;
  else tail = previous;

  T Dataremoved = tmp->data;
  delete tmp;
  count--;
  return Dataremoved;
}

template <class T>
bool DLinkedList<T>::empty() {
  // TODO implement
  if(head->next == tail || tail->prev == head) return true;
  return false;
}

template <class T>
int DLinkedList<T>::size() {
  // TODO implement
  return count;
}

template <class T>
void DLinkedList<T>::clear() {
  // TODO implement
  if(deleteUserData && this != NULL) deleteUserData(this);
  while (head) 
    {
        Node * tmp = head;
        head = head->next;
        delete tmp;
    }
    tail = NULL;
    head = NULL;
    tail = new Node();
    head = new Node();
    head->next = tail;
    tail->prev = head;
    count = 0;
}

template <class T>
T &DLinkedList<T>::get(int index) {
  // TODO implement
  if(index < 0 || index >=count) throw std :: out_of_range("Index is out of range!");
  return getPreviousNodeOf(index)->next->data;
}

template <class T>
int DLinkedList<T>::indexOf(T item) {
  // TODO implement
  Node*tmp = head->next;
  int i;
  if(itemEqual != NULL){
    for(i =0 ; i<count ; i++){
      if(equals(tmp->data,item,itemEqual)) return i;
      tmp=tmp->next;
    }
  }
  else{
    for(i =0 ; i<count ; i++){
      if(tmp->data == item) return i;
      tmp=tmp->next;
    }
  }
  return -1;
}

template <class T>
bool DLinkedList<T>::removeItem(T item, void (*removeItemData)(T)) {
  // TODO implement
  //if(!contains(item)) return false;
  int index = indexOf(item);
  if(index != -1){
      if(removeItemData != NULL){ 
        Node*tmp = getPreviousNodeOf(index)->next;
        if(index == 0){
          head->next = tmp->next;
          if(count == 1)  tail->prev = head;
        }
        else{
          tmp->next->prev = tmp->prev;
          tmp->prev->next = tmp->next;
        }
        removeItemData(tmp->data);
        delete tmp;       
        --count;
      }
      else{
        removeAt(index);
      }
    return true;
  }
  return false;
}

template <class T>
bool DLinkedList<T>::contains(T item) {
  // TODO implement
  if(indexOf(item) != -1) return true;
  return false;
}

template <class T>
string DLinkedList<T>::toString(string (*item2str)(T &)) {
  // TODO implement
  Node* tmp = head->next;
  stringstream ss ;
  ss << "[";
  for(int i = 0; i<count ; i++){
    if(item2str != NULL){
      ss<<item2str(tmp->data);
      if(i != count -1) ss << ", ";
    }

    else{
      ss << tmp->data;
      if(i != count -1) ss << ", ";
    }
    tmp = tmp->next;
  }
  ss << ']';
  return ss.str();
}

//! ////////////////////////////////////////////////////////////////////
//! ////////////////////// (private) METHOD DEFNITION //////////////////
//! ////////////////////////////////////////////////////////////////////
template <class T>
void DLinkedList<T>::copyFrom(const DLinkedList<T> &list) {
  /**
   * Copies the contents of another doubly linked list into this list.
   * Initializes the current list to an empty state and then duplicates all data
   * and pointers from the source list. Iterates through the source list and
   * adds each element, preserving the order of the nodes.
   */
  // TODO implement
  if(list.head == this->head) return;
  
  if(this->count > 0) this->clear();
  else{
    this->head = new Node();
    this->tail = new Node();
    this->head->next = tail;
    this->tail->prev = head;
    this->count = 0;
  }
    this->itemEqual = list.itemEqual;
    this->deleteUserData = list.deleteUserData;

  Node* tmp = list.head->next;
  for(int i = 0; i<list.count; i++){
     this->add(tmp->data);
     tmp = tmp->next;
  }

}

template <class T>
void DLinkedList<T>::removeInternalData() {
  /**
   * Clears the internal data of the list by deleting all nodes and user-defined
   * data. If a custom deletion function is provided, it is used to free the
   * user's data stored in the nodes. Traverses and deletes each node between
   * the head and tail to release memory.
   */
  // TODO implement
  if(deleteUserData) deleteUserData(this);
  while (head) 
    {
        Node * tmp = head;
        head = head->next;
        delete tmp;
    }
    tail = new Node();
    head = new Node();
    tail->prev = head;
    head->next = tail;
    count = 0;
}

template <class T>
typename DLinkedList<T>::Node *DLinkedList<T>::getPreviousNodeOf(int index) {
  /**
   * Returns the node preceding the specified index in the doubly linked list.
   * If the index is in the first half of the list, it traverses from the head;
   * otherwise, it traverses from the tail. Efficiently navigates to the node by
   * choosing the shorter path based on the index's position.
   */
  // TODO implement
  
  if(index == 0) return head;
  Node* tmp = NULL;

  if(index <= count/2 ){
    tmp = head;
    for(int i = 0; i< index; i++){
      tmp = tmp->next;
    }
  }

  else if(index > count/2){
     tmp = tail->prev->prev;
    for(int i = count -1; i > index; i--){
      tmp = tmp->prev;
    }
  }
  return tmp;
}

#endif /* DLINKEDLIST_H */