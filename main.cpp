#include <iostream>
#include "linked_list.h"

void node_it(ListNode* first) {
    auto element = first;
    while (element != nullptr) {
        std::cout << element->get_value() << ' ';
        element = element->get_next();
    }
}

int main() {
    //ListNode node1(5), node2(2), node3(10);
    //node1.set_next(&node2);
    //node2.set_next(&node3);
    //node_it(&node1);
    LinkedList list;
    list.append(2);
    list.append(5);
    list.append(3);

    for (int i = 0; i < 3; ++i)
        std::cout << list.get(i) << " ";

    std::cout << "\n" << list.get(1) << "\n";

    list.remove(1);

    for (int i = 0; i < 2; ++i)
        std::cout << list.get(i) << " ";

    std::cout << '\n';

    try {
        std::cout << list.get(2) << "\n";
    } catch (std::out_of_range& ex) {
        std::cout << ex.what() << '\n';
    }

    return 0;
}
