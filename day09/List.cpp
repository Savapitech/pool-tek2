#include "List.hpp"

List::List() {}

List::~List() { clear(); }

bool List::empty() const { return _list.empty(); }

std::size_t List::size() const { return _list.size(); }

IObject *&List::front() {
  if (_list.empty())
    throw InvalidOperationException();
  return _list.front();
}

IObject *List::front() const {
  if (_list.empty())
    throw InvalidOperationException();
  return _list.front();
}

IObject *&List::back() {
  if (_list.empty())
    throw InvalidOperationException();
  return _list.back();
}

IObject *List::back() const {
  if (_list.empty())
    throw InvalidOperationException();
  return _list.back();
}

void List::pushBack(IObject *obj) { _list.push_back(obj); }

void List::pushFront(IObject *obj) { _list.push_front(obj); }

void List::popFront() {
  if (_list.empty())
    throw InvalidOperationException();
  if (_list.front() != nullptr)
    delete _list.front();
  _list.pop_front();
}

void List::popBack() {
  if (_list.empty())
    throw InvalidOperationException();
  if (_list.back() != nullptr)
    delete _list.back();
  _list.pop_back();
}

void List::clear() {
  for (auto obj : _list) {
    if (obj != nullptr)
      delete obj;
  }
  _list.clear();
}

void List::forEach(void (*function)(IObject *)) {
  for (auto obj : _list) {
    function(obj);
  }
}

List::Iterator::Iterator(std::list<IObject *>::iterator it,
                         std::list<IObject *>::iterator end, const List *list)
    : _it(it), _end(end), _list(list) {}

IObject *List::Iterator::operator*() const {
  if (_it == _end)
    throw OutOfRangeException();
  return *_it;
}

List::Iterator &List::Iterator::operator++() {
  if (_it == _end)
    throw OutOfRangeException();
  ++_it;
  return *this;
}

bool List::Iterator::operator==(const Iterator &it) const {
  return _it == it._it;
}

bool List::Iterator::operator!=(const Iterator &it) const {
  return _it != it._it;
}

List::Iterator List::begin() const {
  return Iterator(const_cast<std::list<IObject *> &>(_list).begin(),
                  const_cast<std::list<IObject *> &>(_list).end(), this);
}

List::Iterator List::end() const {
  return Iterator(const_cast<std::list<IObject *> &>(_list).end(),
                  const_cast<std::list<IObject *> &>(_list).end(), this);
}

List::Iterator List::erase(Iterator it) {
  if (it._list != this)
    throw InvalidIteratorException();
  if (it._it == _list.end())
    throw InvalidIteratorException();

  if (*it._it != nullptr)
    delete *it._it;

  auto next = _list.erase(it._it);
  return Iterator(next, _list.end(), this);
}

List::Iterator List::insert(Iterator it, IObject *obj) {
  if (it._list != this)
    throw InvalidIteratorException();

  auto inserted = _list.insert(it._it, obj);
  return Iterator(inserted, _list.end(), this);
}
