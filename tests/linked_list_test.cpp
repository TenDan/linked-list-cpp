#include <gtest/gtest.h>
#include "linked_list.h"

TEST(LinkedListTest, Size) {
    LinkedList linkedList;
    linkedList.append(2);
    linkedList.append(3);
    linkedList.append(5);

    ASSERT_EQ(linkedList.size(), 3);
}

TEST(LinkedListTest, Get) {
    LinkedList linkedList;
    linkedList.append(1);

    ASSERT_EQ(linkedList.get(0), 1);
}

TEST(LinkedListTest, Remove) {
    LinkedList linkedList;
    linkedList.append(2);
    //linkedList.append(3);
    linkedList.remove(0);

    ASSERT_EQ(linkedList.size(), 0);
}
