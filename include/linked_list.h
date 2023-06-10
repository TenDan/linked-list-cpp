

#ifndef LINKED_LIST_LINKED_LIST_H
#define LINKED_LIST_LINKED_LIST_H

#include <iostream>

template <typename T>
class ListNode {
private:
    // Fields
    T _value;
    ListNode* _next = nullptr;
public:
    // Constructors and destructors
    ListNode(T value = 0) : _value(value) {}
    ListNode(const ListNode<T>& listNode) : _value(listNode._value) {}; // Copying only value
    virtual ~ListNode() = default;

    // Methods
    T get_value() const { return this->_value; }
    void set_value(T value) { this->_value = value; };
    ListNode<T>* get_next() { return this->_next; };
    void set_next(ListNode<T>* next) { this->_next = next; };

    // Friendships
    template<typename Tp>
    friend class LinkedList;
};


template <typename Tp>
class LinkedList {
private:
    // Fields
    ListNode<Tp>* _first = nullptr;

    // Static methods
    static ListNode<Tp>* iterate_to_index(ListNode<Tp>* first, size_t index_to);
public:
    // Constructors and destructors
    LinkedList() = default;
    LinkedList(Tp firstElementValue) : _first(new ListNode<Tp>(firstElementValue)) {};
    LinkedList(std::initializer_list<Tp> initializerList);
    LinkedList(const LinkedList<Tp>& linkedList);
    virtual ~LinkedList();

    // Methods
    void append(Tp value);
    Tp& get(size_t index);
    Tp get(size_t index) const;
    void insert_at(size_t index, Tp value);
    void remove(size_t index);
    void pop();
    size_t size();

    // Overloaded operators
    Tp& operator[](size_t index);
    Tp operator[](size_t index) const;
};

class list_index_out_of_range : public std::out_of_range {
public:
    list_index_out_of_range() : std::out_of_range("List index out of range") {};
    list_index_out_of_range(const char* message) : std::out_of_range(message) {};
};

#endif //LINKED_LIST_LINKED_LIST_H
