#pragma once

#include <cstddef>
#include <exception>
#include <list>

#include "IObject.hpp"

class List {
private:
  std::list<IObject *> _list;

public:
  class InvalidOperationException : public std::exception {
  public:
    const char *what() const noexcept override {
      return "Invalid operation on a list";
    }
  };

  class InvalidIteratorException : public std::exception {
  public:
    const char *what() const noexcept override { return "Invalid iterator"; }
  };

  class Iterator {
  private:
    std::list<IObject *>::iterator _it;
    std::list<IObject *>::iterator _end;
    const List *_list;

  public:
    class OutOfRangeException : public std::exception {
    public:
      const char *what() const noexcept override {
        return "Iterator out of range";
      }
    };

    Iterator(std::list<IObject *>::iterator it,
             std::list<IObject *>::iterator end, const List *list);
    IObject *operator*() const;
    Iterator &operator++();
    bool operator==(const Iterator &it) const;
    bool operator!=(const Iterator &it) const;

    friend class List;
  };

  List();
  List(const List &) = delete;
  List &operator=(const List &) = delete;
  ~List();

  bool empty() const;
  std::size_t size() const;
  IObject *&front();
  IObject *front() const;
  IObject *&back();
  IObject *back() const;
  void pushBack(IObject *obj);
  void pushFront(IObject *obj);
  void popFront();
  void popBack();
  void clear();
  void forEach(void (*function)(IObject *));

  Iterator begin() const;
  Iterator end() const;
  Iterator erase(Iterator it);
  Iterator insert(Iterator it, IObject *obj);
};
