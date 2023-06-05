

#ifndef LINKED_LIST_LINKED_LIST_H
#define LINKED_LIST_LINKED_LIST_H

#include <iostream>

class ListNode {
    int _value;
    ListNode* _next = nullptr;
public:
    ListNode(int value = 0) : _value(value) {}
    virtual ~ListNode() = default;

    int get_value() const { return this->_value; }
    void set_value(int value) { this->_value = value; };
    ListNode* get_next() { return this->_next; };
    void set_next(ListNode* next) { this->_next = next; };

    friend class LinkedList;
};

class LinkedList {
    ListNode* _first = nullptr;
public:
    LinkedList() = default;
    LinkedList(int initialValue) : _first(new ListNode(initialValue)) {};
    virtual ~LinkedList();

    void append(int value);
    int get(int index);
    void remove(int index);
    void pop();
    size_t size();
};

#endif //LINKED_LIST_LINKED_LIST_H
