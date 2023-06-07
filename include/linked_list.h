

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

    static ListNode* iterate_to_index(ListNode* first, size_t index_to);
public:
    LinkedList() = default;
    LinkedList(int initialValue) : _first(new ListNode(initialValue)) {};
    virtual ~LinkedList();

    void append(int value);
    int& get(size_t index);
    int get(size_t index) const;
    void remove(size_t index);
    void pop();
    size_t size();

    int& operator[](size_t index);
    int operator[](size_t index) const;
};

class list_index_out_of_range : public std::out_of_range {
public:
    list_index_out_of_range() : std::out_of_range("List index out of range") {};
    list_index_out_of_range(const char* message) : std::out_of_range(message) {};
};

#endif //LINKED_LIST_LINKED_LIST_H
