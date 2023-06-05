#include "linked_list.h"

/**
 * Clean up list, if destructed
 */
LinkedList::~LinkedList() {
    auto next = _first->_next;
    delete _first;
    // Going through elements to destruct each one
    while (next != nullptr) {
        auto to_free = next;
        next = next->_next;
        delete to_free;
    }
}

void LinkedList::append(int value) {
    auto element = this->_first;
    // Add element to list, if empty
    if (element == nullptr) {
        _first = new ListNode(value);
        return;
    }
    // Get next element unless we found null
    while (element->_next != nullptr) {
        element = element->_next;
    }
    // Add element with value as next to last one of the list
    element->_next = new ListNode(value);
}

int LinkedList::get(int index) {
    int i = 0;
    auto element = this->_first;
    // Iterate through the list until you get element you are satisfied with
    while (i < index) {
        ++i;
        element = element->_next;
        // If we're out of bounds, then throw exception, no sense to going any further
        if (element == nullptr)
            throw std::out_of_range("List index out of range");
    }
    return element->get_value();
}

void LinkedList::remove(int index) {
    int i = 0;
    auto element = this->_first;
    // Iterate through the list until you reach to single element before one you want to remove
    while (i < index - 1) {
        ++i;
        element = element->_next;
        // If we're out of bounds, then throw exception, no sense to going any further
        if (element == nullptr)
            throw std::out_of_range("List index out of range");
    }
    auto one_before = element;
    // Apply to element pointer, that one to remove (according to index)
    element = one_before->_next;
    // If we're out of bounds, then throw exception, no sense to going any further
    if (element == nullptr)
        throw std::out_of_range("List index out of range");
    if (element->_next != nullptr) {
        auto one_after = element->_next;
        one_before->_next = one_after;
    }
    delete element;
}

// TODO: Implement
void LinkedList::pop() {

}

size_t LinkedList::size() {
    size_t current_size = 0;
    auto element = this->_first;

    while (element != nullptr) {
        ++current_size;
        element = element->_next;
    }

    return current_size;
}