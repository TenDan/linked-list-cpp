#include <gtest/gtest.h>
#include "linked_list.h"


/**
 * TODO: Make parametrized test of size method including:
 * 1. Size when list is empty
 * 2. Size when list has one element
 * 3. Size when more elements
 * Scenarios which can help with memory leaks and segmentation faults
 */
TEST(LinkedListTest, Size) {
    LinkedList linkedList;
    linkedList.append(2);
    linkedList.append(3);
    linkedList.append(5);

    ASSERT_EQ(linkedList.size(), 3);
}

/**
 * TODO: Make parametrized test of get method including:
 * 1. Getting from the beginning
 * 2. Getting between beginning and end
 * 3. Getting at the end
 * Scenarios which can help with memory leaks and segmentation faults
 */
TEST(LinkedListTest, Get) {
    LinkedList linkedList;
    linkedList.append(1);

    ASSERT_EQ(linkedList.get(0), 1);
}

/**
 * TODO: Make parametrized test of remove method including:
 * 1. Removing from the beginning
 * 2. Removing between beginning and end
 * 3. Removing at the end
 * Scenarios which can help with memory leaks and segmentation faults
 */
TEST(LinkedListTest, Remove) {
    LinkedList linkedList;
    linkedList.append(2);
    //linkedList.append(3);
    linkedList.remove(0);

    ASSERT_EQ(linkedList.size(), 0);
}

TEST(LinkedListTest, Pop) {
    LinkedList linkedList;
    linkedList.append(5);
    linkedList.append(3);
    linkedList.append(1);

    linkedList.pop();

    EXPECT_ANY_THROW(linkedList.get(2));
    EXPECT_NO_FATAL_FAILURE(linkedList.get(1));
}

TEST(LinkedListTest, Append) {
    LinkedList linkedList;
    linkedList.append(2);

    EXPECT_EQ(linkedList.get(0), 2);
}

TEST(LinkedListTest, ArrayOpOverload) {
    LinkedList linkedList;
    linkedList.append(5);
    linkedList.append(2);

    EXPECT_EQ(linkedList[0], 5);
    EXPECT_EQ(linkedList[1], 2);
}
