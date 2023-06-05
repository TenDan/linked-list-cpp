#include "linked_list.h"

LinkedList::~LinkedList() {
    auto next = _first->_next;
    delete _first;
    while (next != nullptr) {
        auto to_free = next;
        next = next->_next;
        delete to_free;
    }
}

void LinkedList::append(int value) {
    auto element = this->_first;
    if (element == nullptr) {
        _first = new ListNode(value);
        return;
    }
    while (element->_next != nullptr) {
        element = element->_next;
    }
    // Add element with value as next to last one of the list
    element->_next = new ListNode(value);
}

// TODO: need to throw exception if index is out of range
int LinkedList::get(int index) {
    int i = 0;
    auto element = this->_first;
    // Iterate through the list until you get element you are satisfied with
    while (i < index) {
        ++i;
        element = element->_next;
        if (element == nullptr)
            throw std::out_of_range("List index out of range");
    }
    return element->get_value();
}

// TODO: need to throw exception if index is out of range
void LinkedList::remove(int index) {
    int i = 0;
    auto element = this->_first;
    // Iterate through the list until you reach to single element before one you want to remove
    while (i < index - 1) {
        ++i;
        element = element->_next;
        if (element == nullptr)
            throw std::out_of_range("List index out of range");
    }
    auto one_before = element;
    element = one_before->_next;
    if (element == nullptr)
        throw std::out_of_range("List index out of range");
    if (element->_next != nullptr) {
        auto one_after = element->_next;
        one_before->_next = one_after;
    }
    delete element;
}

void LinkedList::pop() {

}

size_t LinkedList::size() {
    return 0;
}