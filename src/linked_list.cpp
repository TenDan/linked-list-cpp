#include "linked_list.h"

/**
 * Clean up list, if destructed
 */
LinkedList::~LinkedList() {
    if (_first == nullptr)
        return;
    auto next = _first->_next;
    delete _first;
    // Going through elements to destruct each one
    while (next != nullptr) {
        auto to_free = next;
        next = next->_next;
        delete to_free;
    }
}

/**
 * Add element to the end of list
 * @param value Value of element that should be added to list
 */
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

ListNode* LinkedList::iterate_to_index(ListNode* first, size_t index_to) {
    size_t i = 0;
    // If first element is empty, no sense to go any further
    if (first == nullptr)
        throw list_index_out_of_range();
    auto element = first;
    // Iterate through the list until you get element you are satisfied with
    while (i < index_to) {
        ++i;
        element = element->_next;
        // If we're out of bounds, then throw exception, no sense to go any further
        if (element == nullptr)
            throw list_index_out_of_range();
    }
    return element;
}

/**
 * Get element of list by index
 * @param index Index of element that should be returned
 * @return Reference to element
 */
int& LinkedList::get(size_t index) {
    auto element = iterate_to_index(this->_first, index);
    return element->_value;
}

/**
 * Get element of list by index
 * @param index Index of element that should be returned
 * @return Value of element
 */
int LinkedList::get(size_t index) const {
    auto element = iterate_to_index(this->_first, index);
    return element->_value;
}


/**
 * Get element of list by index
 * @param index Index of element that should be returned
 * @return Reference to element
 */
int& LinkedList::operator[](size_t index) {
    return this->get(index);
}

/**
 * Get element of list by index
 * @param index Index of element that should be returned
 * @return Value of element
 */
int LinkedList::operator[](size_t index) const {
    return this->get(index);
}

/**
 * Remove element from list by index
 * @param index Index of element that should be removed
 */
void LinkedList::remove(size_t index) {
    auto element = this->_first;

    if (index == 0 && element != nullptr) {
        this->_first = element->_next;
        delete element;
        return;
    }

    // Iterate through the list until you reach to single element before one you want to remove
    auto one_before = iterate_to_index(element, index - 1);
    // Apply to element pointer, that one to remove (according to index)
    element = one_before->_next;
    // If we're out of bounds, then throw exception, no sense to going any further
    if (element == nullptr)
        throw list_index_out_of_range();
    if (element->_next != nullptr) {
        auto one_after = element->_next;
        one_before->_next = one_after;
    }
    delete element;
}

/**
 * Remove last element from list
 */
void LinkedList::pop() {
    auto element = this->_first;

    // Getting element before the last one
    while (element->_next->_next != nullptr) {
        element = element->_next;
    }

    delete element->_next;
    element->_next = nullptr;
}

/**
 * Get size (elements count) of list
 * @return Size of list
 */
size_t LinkedList::size() {
    size_t current_size = 0;
    auto element = this->_first;

    // Counting list size until it reaches the end
    while (element != nullptr) {
        ++current_size;
        element = element->_next;
    }

    return current_size;
}

LinkedList::LinkedList(std::initializer_list<int> initializerList) : _first(new ListNode()) {
    ListNode* current = _first;
    ListNode* lastBefore = current;
    for (int element : initializerList) {
        current->_value = element;
        current->_next = new ListNode();
        lastBefore = current;
        current = current->_next;
    }
    if (initializerList.size() > 0)
        lastBefore->_next = nullptr;
    delete current;
}
