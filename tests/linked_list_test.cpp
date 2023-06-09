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

TEST(LinkedListTest, InsertAt) {
    LinkedList linkedList{1, 3, 5, 9};

    ASSERT_EQ(linkedList[0], 1);
    ASSERT_EQ(linkedList[1], 3);
    ASSERT_EQ(linkedList[2], 5);
    ASSERT_EQ(linkedList[3], 9);

    linkedList.insert_at(2, 4);

    EXPECT_EQ(linkedList[0], 1);
    EXPECT_EQ(linkedList[1], 3);
    EXPECT_EQ(linkedList[2], 4);
    EXPECT_EQ(linkedList[3], 5);
    EXPECT_EQ(linkedList[4], 9);
}

TEST(LinkedListTest, CopyConstructor) {
    LinkedList linkedList1;
    linkedList1.append(3);
    linkedList1.append(2);

    LinkedList linkedList2(linkedList1);
    EXPECT_EQ(linkedList2[0], 3);
    EXPECT_EQ(linkedList2[1], 2);

    linkedList2[0] = 4;
    linkedList2[1] = 5;

    EXPECT_NE(linkedList2[0], linkedList1[0]);
    EXPECT_NE(linkedList2[1], linkedList1[1]);
}

TEST(LinkedListTest, CopyConstructorForMoreThanTwoElements) {
    LinkedList linkedList1;
    linkedList1.append(3);
    linkedList1.append(2);
    linkedList1.append(5);
    linkedList1.append(1);

    LinkedList linkedList2(linkedList1);
    EXPECT_EQ(linkedList2[0], 3);
    EXPECT_EQ(linkedList2[1], 2);
    EXPECT_EQ(linkedList2[2], 5);
    EXPECT_EQ(linkedList2[3], 1);

    linkedList2[0] = 4;
    linkedList2[1] = 5;
    linkedList2[2] = 7;
    linkedList2[3] = 9;

    EXPECT_NE(linkedList2[0], linkedList1[0]);
    EXPECT_NE(linkedList2[1], linkedList1[1]);
    EXPECT_NE(linkedList2[2], linkedList1[2]);
    EXPECT_NE(linkedList2[3], linkedList1[3]);
}

TEST(LinkedListTest, InitializerListConstructor) {
    LinkedList linkedList{1, 3, 5};

    EXPECT_EQ(linkedList[0], 1);
    EXPECT_EQ(linkedList[1], 3);
    EXPECT_EQ(linkedList[2], 5);
}

TEST(LinkedListTest, EmptyInitializerListConstructor) {
    LinkedList linkedList{};

    EXPECT_ANY_THROW(linkedList[0]);
}

TEST(LinkedListTest, ArrayOpOverloadReadValue) {
    LinkedList linkedList;
    linkedList.append(5);
    linkedList.append(2);

    EXPECT_EQ(linkedList[0], 5);
    EXPECT_EQ(linkedList[1], 2);
}

TEST(LinkedListTest, ArrayOpOverloadChangeValue) {
    LinkedList linkedList;
    linkedList.append(2);

    ASSERT_EQ(linkedList[0], 2);

    linkedList[0] = 5;
    EXPECT_EQ(linkedList[0], 5);
}
