#include <iostream>
#include <random>
#include "linked_list.h"

void node_it(ListNode* first) {
    auto element = first;
    while (element != nullptr) {
        std::cout << element->get_value() << ' ';
        element = element->get_next();
    }
}

void fill_list(LinkedList& list, int element_count, int from = 0, int to = 100) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(from, to);
    while(element_count-- > 0)
        list.append((int) distr(gen));
}

void print_list(LinkedList& list) {
    for (int i = 0; i < list.size(); ++i) {
        std::cout << list.get(i) << ' ';
    }
    std::cout << '\n';
}

int main() {
    //ListNode node1(5), node2(2), node3(10);
    //node1.set_next(&node2);
    //node2.set_next(&node3);
    //node_it(&node1);
    LinkedList list;
    fill_list(list, 11);

    print_list(list);

    list.pop();

    print_list(list);

    list.remove(5);

    print_list(list);

    return 0;
}
