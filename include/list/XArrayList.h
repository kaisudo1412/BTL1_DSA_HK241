/*
 * File:   XArrayList.h
 */

#ifndef XARRAYLIST_H
#define XARRAYLIST_H
#include <memory.h>

#include <iostream>
#include <sstream>
#include <type_traits>

#include "list/IList.h"
using namespace std;

template <class T>
class XArrayList : public IList<T>
{
public:
  class Iterator; // forward declaration

protected:
  T *data;
  int capacity;
  int count = 0;
  bool (*itemEqual)(T &lhs, T &rhs);
  void (*deleteUserData)(XArrayList<T> *);

public:
  XArrayList(void (*deleteUserData)(XArrayList<T> *) = 0,
             bool (*itemEqual)(T &, T &) = 0, int capacity = 10);
  XArrayList(const XArrayList<T> &list);
  XArrayList<T> &operator=(const XArrayList<T> &list);
  ~XArrayList();

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
  // Inherit from IList: BEGIN

  void println(string (*item2str)(T &) = 0)
  {
    cout << toString(item2str) << endl;
  }
  void setDeleteUserDataPtr(void (*deleteUserData)(XArrayList<T> *) = 0)
  {
    this->deleteUserData = deleteUserData;
  }

  Iterator begin() { return Iterator(this, 0); }
  Iterator end() { return Iterator(this, count); }

protected:
  void checkIndex(int index);     // check validity of index for accessing
  void ensureCapacity(int index); // auto-allocate if needed
  void copyFrom(const XArrayList<T> &list);
  void removeInternalData();

  //! FUNTION STATIC
protected:
  static bool equals(T &lhs, T &rhs, bool (*itemEqual)(T &, T &))
  {
    if (itemEqual == 0)
      return lhs == rhs;
    else
      return itemEqual(lhs, rhs);
  }

public:
  static void free(XArrayList<T> *list)
  {
    typename XArrayList<T>::Iterator it = list->begin();
    while (it != list->end())
    {
      delete *it;
      it++;
    }
  }

public:
  class Iterator
  {
  private:
    int cursor;
    XArrayList<T> *pList;

  public:
    Iterator(XArrayList<T> *pList = 0, int index = 0)
    {
      this->pList = pList;
      this->cursor = index;
    }
    Iterator &operator=(const Iterator &iterator)
    {
      cursor = iterator.cursor;
      pList = iterator.pList;
      return *this;
    }
    void remove(void (*removeItemData)(T) = 0)
    {
      T item = pList->removeAt(cursor);
      if (removeItemData != 0)
        removeItemData(item);
      cursor -= 1; // MUST keep index of previous, for ++ later
    }

    T &operator*() { return pList->data[cursor]; }
    bool operator!=(const Iterator &iterator)
    {
      return cursor != iterator.cursor;
    }
    // Prefix ++ overload
    Iterator &operator++()
    {
      this->cursor++;
      return *this;
    }
    // Postfix ++ overload
    Iterator operator++(int)
    {
      Iterator iterator = *this;
      ++*this;
      return iterator;
    }
  };
};

//! ////////////////////////////////////////////////////////////////////
//! //////////////////////     METHOD DEFNITION      ///////////////////
//! ////////////////////////////////////////////////////////////////////

template <class T>
XArrayList<T>::XArrayList(void (*deleteUserData)(XArrayList<T> *),
                          bool (*itemEqual)(T &, T &), int capacity)
{
  // TODO implement
  this->capacity = capacity;
  data = new T[capacity];
  this->deleteUserData = deleteUserData;
  this->itemEqual = itemEqual;
}

template <class T>
XArrayList<T>::XArrayList(const XArrayList<T> &list)
{
  // TODO implement
  this->deleteUserData = list.deleteUserData;
  this->itemEqual = list.itemEqual;
  this->count = list.count;
  this->capacity = list.capacity;
  data = new T[capacity];

  for(int i = 0; i < list.count ; i++){
    data[i] = list.data[i];
  }
}

template <class T>
XArrayList<T> &XArrayList<T>::operator =(const XArrayList<T> &list)
{
  // TODO implement
  copyFrom(list);
  return *this;
}

template <class T>
XArrayList<T>::~XArrayList()
{
  //TODO implement
  //if(count != 0)if(deleteUserData && this != NULL)deleteUserData(this);
    if(deleteUserData && this != NULL) deleteUserData(this);    
    delete[] data;
    this->capacity = 0;
    this->count = 0;
    data = NULL;
    deleteUserData = NULL;
    itemEqual = NULL;
 
  //removeInternalData();
}

template <class T>
void XArrayList<T>::add(T e)
{
  // TODO implement
  if (count == capacity) this->ensureCapacity(count);
  data[count] = e;
  count++;
}

template <class T>
void XArrayList<T>::add(int index, T e)
{
  // TODO implement
  if (index < 0 || index > count)
    throw std::out_of_range("Index is out of range!");
  if (count == capacity)
    this->ensureCapacity(count);
  for (int i = count; i > index; i--)
  {
    data[i] = data[i - 1];
  }
  data[index] = e;
  count++;
}

template <class T>
T XArrayList<T>::removeAt(int index)
{
  // TODO implement
  if (index < 0 || index >= count )
    throw std ::out_of_range("Index is out of range!");

  T tmp = data[index];
  for (int i = index; i < count - 1; i++)
  {
    data[i] = data[i + 1];
  }
  //data[count--] = 0;
  count--;
  return tmp;
}

template <class T>
bool XArrayList<T>::removeItem(T item, void (*removeItemData)(T))
{
  // TODO implement
  if (!contains(item)) return false;

  int index = indexOf(item);
  if (removeItemData != NULL)
  {
    removeItemData(data[index]);
    removeAt(index);
  }

  else
  {
    removeAt(index);
  }
  return true;
}

template <class T>
bool XArrayList<T>::empty()
{
  // TODO implement
  if (count == 0)
    return true;
  return false;
}

template <class T>
int XArrayList<T>::size()
{
  // TODO implement
  return count;
}

template <class T>
void XArrayList<T>::clear()
{
  // TODO implement
  //if(count == 0) return;
  //removeInternalData();
  if(deleteUserData && this != NULL)deleteUserData(this);
  if(data != NULL){
      delete[] this->data;
      data = NULL;
  }
    this->capacity = 10;
    this->count = 0;
    this->data = new T[capacity];
}

template <class T>
T &XArrayList<T>::get(int index)
{
  // TODO implement
  if (index >= count || index < 0)
    throw std ::out_of_range("Index is out of range!");
  return data[index];
}

template <class T>
int XArrayList<T>::indexOf(T item)
{
  // TODO implement
  int i = -1;
  for (i = 0; i < count; i++)
  {
    if (this->itemEqual != NULL)
    {
      if (equals(data[i],item,itemEqual)) break;
    }
    else
    {
      if (data[i] == item) break;
    }
  }
  if(i==count) return -1;
  return i;
}

template <class T>
bool XArrayList<T>::contains(T item)
{
  // TODO implement
  if (indexOf(item) != -1)
    return true;
  return false;
}

template <class T>
string XArrayList<T>::toString(string (*item2str)(T &))
{
  // TODO implement
  stringstream ss;
  ss << '[';
  if (item2str)
  {
    for (int i = 0; i < count; i++)
    {
      ss << item2str(data[i]);
      if (i != count - 1)
        ss << ", ";
    }
  }
  else
  {
    for (int i = 0; i < count; i++)
    {
      ss << data[i];
      if (i != count - 1)
        ss << ", ";
    }
  }
  ss << ']';
  return ss.str();
}

//! ////////////////////////////////////////////////////////////////////
//! ////////////////////// (private) METHOD DEFNITION //////////////////
//! ////////////////////////////////////////////////////////////////////
template <class T>
void XArrayList<T>::checkIndex(int index)
{
  /**
   * Validates whether the given index is within the valid range of the list.
   * Throws an std::out_of_range exception if the index is negative or exceeds
   * the number of elements. Ensures safe access to the list's elements by
   * preventing invalid index operations.
   */
  // TODO implement

  if (index < 0 || index > this->count)
    throw exception(std ::out_of_range("Index is out of range!"));
}
template <class T>
void XArrayList<T>::ensureCapacity(int index)
{
  /**
   * Ensures that the list has enough capacity to accommodate the given index.
   * If the index is out of range, it throws an std::out_of_range exception. If
   * the index exceeds the current capacity, reallocates the internal array with
   * increased capacity, copying the existing elements to the new array. In case
   * of memory allocation failure, catches std::bad_alloc.
   */
  // TODO implement
  if (index < 0)
    throw std::out_of_range("Index is out of range!");
  else if (index < this->capacity)
    return;
  else
  {
    T *newdata = NULL;
    int newcap = this->capacity;
    while (index >= newcap)
    {
      newcap = newcap*1.5 + 1;
    }

    try
  {
    newdata = new T[newcap];
  }
  catch (const std::bad_alloc)
  {
    cout << "memory allocation failure ";
  }
    
    for (int i = 0; i < count; i++)
    {
      newdata[i] = data[i];
    }
    this->capacity = newcap;
    delete[] data;
    data = NULL;
    data = newdata;
    //delete[] newdata;
  }
  // try{this->data = new T[capacity]; throw std:: bad_alloc}
  // catch() {std::bad_alloc}
  // try
  // {
  //   this->data = new T[capacity];
  // }
  // catch (const std::bad_alloc)
  // {
  //   cout << "memory allocation failure ";
  // }
}

template <class T>
void XArrayList<T>::copyFrom(const XArrayList<T> &list)
{
  /*
   * Copies the contents of another XArrayList into this list.
   * Initializes the list with the same capacity as the source list and copies
   * all elements. Also duplicates user-defined comparison and deletion
   * functions, if applicable.
   */
  // TODO implement
  if(this->data == list.data) return;
  this->deleteUserData = list.deleteUserData;
  this->itemEqual = list.itemEqual;
  this->count = list.count;
  this->capacity = list.capacity;
  
  T* newdata = new T[list.capacity];
  for(int i = 0; i < list.count ; i++){
    newdata[i] = list.data[i];
  }

  if(count) delete[] data;
  data = new T[capacity];
  data = newdata; 
}

template <class T>
void XArrayList<T>::removeInternalData()
{
  /*
   * Clears the internal data of the list by deleting the dynamic array and any
   * user-defined data. If a custom deletion function is provided, it is used to
   * free the stored elements. Finally, the dynamic array itself is deallocated
   * from memory.
   */
  // TODO implement
  delete[] data;
  count = 0;
  data = NULL;
  itemEqual = NULL;
  if (deleteUserData != NULL)
    deleteUserData(this);
}

#endif /* XARRAYLIST_H */